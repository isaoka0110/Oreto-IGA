/*  AutoGL $B!c$*<j7Z!d(B $B$N%5%s%W%k%W%m%0%i%`Nc(B */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/* AutoGL $B!I$*$F$,$k!I$r;H$&$K$O(B,$B$3$N%X%C%@%U%!%$%k$r%$%s%/%k!<%I$9$k!#(B*/
#include <autogl.h>

/* AutoNOSim $B!I$*$?$N$7$_!I$r;H$&$K$O(B,$B$3$N%X%C%@%U%!%$%k$r%$%s%/%k!<%I$9$k!#(B*/
#include <autonosim.h>

/* $B%f!<%F%#%j%F%#$NFs<!85%$%Y%s%H=hM}$NMxMQ(B */
/* $B0z?t$J$I>\$7$$>pJs$O(B, autogl_utility2d.h$B$r;2>H!#(B*/
/* $B$J$*!"$3$l$O(Bautogl.h$B$+$i(Binclude$B$5$l$F$$$k!#(B*/



/* $B%S%e!<>e$KI=<($5$l$k%b%G%k$rI=8=$9$k$?$a$NJQ?t72(B */

/* $B8=:_A*Br$5$l$F$$$kD:E@$NHV9f(B */
static int SelectedEdgeId = -1;

/* $BD:E@$N:BI8(B */
static double Vertexs[6][2] = {
  { 10, 0 },
  { 10, 20 },
  { 0, 20 },
  { -10, 0 },
  { 0, -20 },
  { 30, -20 }
};



/* $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
static void RedrawView (void) 
{
  int i;
  int nTasks = AutoNOSim_NTasks ();
  int taskId = AutoNOSim_MyTaskId ();

  AutoGL_SetColor (0, 1, 0);  

  AutoGL_DrawLine (-50, 0, 0,
		   50, 0, 0); 
  AutoGL_DrawString (50, 0, 0, "X = 5O");  
  AutoGL_DrawString (-50, 0, 0, "X = -5O");  
  
  AutoGL_DrawLine (0, -50, 0,
		   0, 50, 0); 
  AutoGL_DrawString (0, 50, 0, "Y = 5O");  
  AutoGL_DrawString (0, -50, 0, "Y = -5O");  
    
  AutoGL_SetColor (1, 1, 1);
  AutoGL_DrawString (0, 0, 0, "O"); 

  for (i = 0; i < 6 - 1; i++) {
    if (i % nTasks != taskId) continue;

    if (i == SelectedEdgeId) {
      AutoGL_SetColor (1, 0, 0);
    } else {
      AutoGL_SetColor (1, 1, 1);
    }
    AutoGL_DrawLine (Vertexs[i][0], Vertexs[i][1], 0,
		     Vertexs[i + 1][0], Vertexs[i + 1][1], 0);
  }
}

/* $B%S%e!<$N%$%Y%s%H=hM}$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$K%$%Y%s%H$,H/@8$9$k$4$H$K8F$P$l$k!#(B */
static void HandleEvent (void)
{
  int event = AutoGL_GetViewEvent ();
  int nTasks = AutoNOSim_NTasks ();
  int taskId = AutoNOSim_MyTaskId ();

  /* $B$b$7!"%^%&%9%/%j%C%/$,$"$l$P(B */
  if (event == AUTOGL_EVENT_POINTING_DEVICE_RELEASE) {
    int dcX, dcY, dcZ;
    int toleranceDc = 10;
    int i;

    AutoGL_GetPointingDevicePositionDc 
      (&dcX, &dcY, &dcZ);

    AutoGL_StartSelection (dcX, dcY, toleranceDc);
    
    for (i = 0; i < 6 - 1; i++) {
      if (i % nTasks != taskId) continue;

      AutoGL_SetSelectionId (i);
      AutoGL_DrawLine (Vertexs[i][0], Vertexs[i][1], 0,
		       Vertexs[i + 1][0], Vertexs[i + 1][1], 0);
    }

    AutoGL_EndSelection ();
    SelectedEdgeId = AutoGL_GetSelectedId ();

    fprintf (stderr, " selected edge ID is %d \n", SelectedEdgeId);

    /* $B%S%e!<$r:FIA2h$9$k!#(B */
    AutoGL_DrawView ();
    /* $BEPO?$5$l$?%S%e!<$N:FIA2h4X?t!J$3$N>l9g$O(BRedrawView ()$B!K$,8F$P$l$k!#(B */

  } else if (event == AUTOGL_EVENT_KEY) {
    int keyChar = AutoGL_GetKeyChar ();

    if (keyChar == ' ') {
      fprintf (stderr, " hit space \n");
    } else {
      AutoGL_HandleDefaultKeyEventInMode2D ();
    }
  }
}



/* $B4X?t(BAutoGL_SetUp$B$O%f!<%6!<B&%W%m%0%i%`$4$H$KI,$:0l$DMQ0U$9$k$3$H!#(B*/
/* $B$3$3$G!"%3!<%k%P%C%/4X?t$d@)8fJQ?t$J$I$rEPO?$9$k!#(B*/
void AutoGL_SetUp (int argc, char *argv[]) 
{
  AutoGL_SetViewSize (70);   

  /* $B%S%e!<$N:FIA2h%3!<%k%P%C%/$NEPO?(B */
  AutoGL_SetViewRedrawCallback (RedrawView);   

  /* $B%S%e!<$N%$%Y%s%H=hM}%3!<%k%P%C%/$NEPO?(B */
  AutoGL_SetDefaultCallbackInMode2D (HandleEvent);
  /* $B%$%Y%s%H=hM}%3!<%k%P%C%/4X?t$H$7$F>e$K$"$k(BHandleEvent ()$B$r;XDj!#(B */
  /* $BFCJL$J%$%Y%s%H=hM}$,MW$i$J$1$l$P!"(BNULL$B$G$h$$!#(B*/

  /* $B=i4|>uBV$G$O!"%f!<%6!<Dj5A%$%Y%s%H=hM}$r9T$&!#(B */
  AutoGL_SetMode2D (AUTOGL_MODE_2D_OTHER); 

#if 0
  /* $B%$%Y%s%H=hM}Cf(B, $B%I%i%C%0$rM-8z$K$9$k!#(B*/
  AutoGL_EnableDragInMode2D ();
#endif

  /* $B%Q%M%k>e$KFs<!85%"%W%jMQ%$%Y%s%H=hM}5!G=$r=`Hw$9$k!#(B */
  AutoGL_SetPanelInMode2D ();
}

