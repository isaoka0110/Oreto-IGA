/*  AutoGL $B!c$*<j7Z!d(B $B$N%5%s%W%k%W%m%0%i%`Nc(B */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/* AutoGL $B!I$*$F$,$k!I$r;H$&$K$O(B,$B$3$N%X%C%@%U%!%$%k$r%$%s%/%k!<%I$9$k!#(B*/
#include <autogl.h>

/* $B%f!<%F%#%j%F%#$N;0<!85%$%Y%s%H=hM}$NMxMQ(B */
/* $B0z?t$J$I>\$7$$>pJs$O(B, autogl_utility3d.h$B$r;2>H!#(B*/
/* $B$J$*!"$3$l$O(Bautogl.h$B$+$i(Binclude$B$5$l$F$$$k!#(B*/




/* $B%S%e!<>e$KI=<($5$l$k%b%G%k$rI=8=$9$k$?$a$NJQ?t72(B */

/* $B8=:_A*Br$5$l$F$$$kD:E@$NHV9f(B */
static int SelectedVertexId = -1;

/* $BD:E@$N:BI8(B */
static double Vertexs[8][3] = {
  { 0, 0, 0 },
  { 10, 0, 0 },
  { 10, 20, 0 },
  { 0, 20, 0 },
  { 0, 0, 30 },
  { 10, 0, 30 },
  { 10, 20, 30 },
  { 0, 20, 30 }
};



/* $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
static void RedrawView (void) 
{
  int i;
  int markSizeDc;
  int isFilled;

  AutoGL_SetColor (0, 1, 0);  

  AutoGL_DrawLine (-50, 0, 0,
		   50, 0, 0); 
  AutoGL_DrawString (50, 0, 0, "X = 5O");  
  AutoGL_DrawString (-50, 0, 0, "X = -5O");  
  
  AutoGL_DrawLine (0, -50, 0,
		   0, 50, 0); 
  AutoGL_DrawString (0, 50, 0, "Y = 5O");  
  AutoGL_DrawString (0, -50, 0, "Y = -5O");  
    
  AutoGL_DrawLine (0, 0, -50,
		   0, 0, 50); 
  AutoGL_DrawString (0, 0, 50, "Z = 5O");  
  AutoGL_DrawString (0, 0, -50, "Z = -5O");  
    
  AutoGL_SetColor (1, 1, 1);
  AutoGL_DrawString (0, 0, 0, "O"); 

  AutoGL_SetColor (1, 1, 1);
  AutoGL_DrawQuadrangle (0, 0, 0,
			 10, 0, 0,
			 10, 20, 0,
			 0, 20, 0);
  AutoGL_DrawQuadrangle (0, 0, 30,
			 10, 0, 30,
			 10, 20, 30,
			 0, 20, 30);
  AutoGL_DrawQuadrangle (0, 0, 0,
			 0, 20, 0,
			 0, 20, 30,
			 0, 0, 30);
  AutoGL_DrawQuadrangle (10, 0, 0,
			 10, 20, 0,
			 10, 20, 30,
			 10, 0, 30);
  AutoGL_DrawQuadrangle (0, 0, 0,
			 10, 0, 0,
			 10, 0, 30,
			 0, 0, 30);
  AutoGL_DrawQuadrangle (0, 20, 0,
			 10, 20, 0,
			 10, 20, 30,
			 0, 20, 30);

  /* $B3FD:E@$K$D$$$F!"$=$l$,A*Br$5$l$F$$$k$+$I$&$+$rIA2h$9$k!#(B */
  AutoGL_SetColor (1, 0, 0);
  for (i = 0; i < 8; i++) {
    isFilled = 0;
    if (i == SelectedVertexId) {
      isFilled = 1;
    }
    markSizeDc = 10;

    /* $B%@%$%"%b%s%I$N%^!<%/$rI=<($9$k!#(B */
    AutoGL_DrawDiamondMark3D 
      (Vertexs[i][0], Vertexs[i][1], Vertexs[i][2], 
       markSizeDc , isFilled);
    /* markSizeDc$B$K$h$j!"(B10 pixel$B$0$i$$$NBg$-$5$H$J$k!#(B */
    /* isFilled == 1$B$J$i!"$3$ND:E@$OA*Br$5$l$F$$$k!#(B */
  }
}

/* $B%S%e!<$N%$%Y%s%H=hM}$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$K%$%Y%s%H$,H/@8$9$k$4$H$K8F$P$l$k!#(B */
static void HandleEvent (void)
{
  int event = AutoGL_GetViewEvent ();

  /* $B$b$7!"%^%&%9%/%j%C%/$,$"$l$P(B */
  if (event == AUTOGL_EVENT_POINTING_DEVICE_RELEASE) {
    int i;

    /* $B3FD:E@$K$D$$$F!"%^%&%9%]%$%s%?$,%R%C%H$7$?$+$I$&$+D4$Y$k!#(B */
    SelectedVertexId = -1;
    for (i = 0; i < 8; i++) {
      int toleranceDc = 10;
      double parameter;

      /* $B$3$ND:E@$,%^%&%9%]%$%s%?$N$=$P$K$"$l$P(B */
      if (AutoGL_PointingDeviceIsHit3D 
	  (&parameter,
	   Vertexs[i][0], Vertexs[i][1], Vertexs[i][2], 
	   toleranceDc)) {
	/* $BE@$N:BI8$O@$3&:BI8!J;0<!85!K$GM?$($k!#(B */
	SelectedVertexId = i;
	break;
      }
    }
    if (SelectedVertexId != -1) {
      printf (" vertex %d is selected. \n",
	      SelectedVertexId);
    }

    /* $B%S%e!<$r:FIA2h$9$k!#(B */
    AutoGL_DrawView ();
    /* $BEPO?$5$l$?%S%e!<$N:FIA2h4X?t!J$3$N>l9g$O(BRedrawView ()$B!K$,8F$P$l$k!#(B */

  } else if (event == AUTOGL_EVENT_KEY) {
    AutoGL_HandleDefaultKeyEventInMode3D ();
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
  AutoGL_SetDefaultCallbackInMode3D (HandleEvent);
  /* $B%$%Y%s%H=hM}%3!<%k%P%C%/4X?t$H$7$F>e$K$"$k(BHandleEvent ()$B$r;XDj!#(B */
  /* $BFCJL$J%$%Y%s%H=hM}$,MW$i$J$1$l$P!"(BNULL$B$G$h$$!#(B*/

  /* $B=i4|>uBV$G$O!"%f!<%6!<Dj5A%$%Y%s%H=hM}$r9T$&!#(B */
  AutoGL_SetMode3D (AUTOGL_MODE_3D_OTHER); 

#if 0
  /* $B%$%Y%s%H=hM}Cf(B, $B%I%i%C%0$rM-8z$K$9$k!#(B*/
  AutoGL_EnableDragInMode3D ();
#endif

  /* $B%Q%M%k>e$K;0<!85%"%W%jMQ%$%Y%s%H=hM}5!G=$r=`Hw$9$k!#(B */
  AutoGL_SetPanelInMode3D ();
}

