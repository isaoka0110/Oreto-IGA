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

/* $B%f!<%F%#%j%F%#$N;0<!85IA2h%W%j%_%F%#%V!J5e!"1_Cl$J$I!K$NMxMQ(B */
/* $B0z?t$J$I>\$7$$>pJs$O(B, autogl_utility3d.h$B$r;2>H!#(B*/
/* $B$J$*!"$3$l$O(Bautogl.h$B$+$i(Binclude$B$5$l$F$$$k!#(B*/



/* $B%3!<%k%P%C%/4X?t72(B */

/* $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
static void RedrawView (void) 
{
  double radius = 10.0;
  int nDivisions = 4;
  int taskId = AutoNOSim_MyTaskId ();
  
  /* $B6@LLH?<M$r%*%s$K$9$k!#(B*/
  AutoGL_TurnOnSpecular ();

  if (taskId == 0) {

    AutoGL_SetColor (1, 1, 1);
    AutoGL_DrawString (0, 0, 0, "O");
    AutoGL_DrawLine (0, 0, 0,
		     50, 0, 0);
    AutoGL_DrawString (50, 0, 0, "X");  
    AutoGL_DrawLine (0, 0, 0,
		     0, 50, 0);
    AutoGL_DrawString (0, 50, 0, "Y");  
    AutoGL_DrawLine (0, 0, 0,
		     0, 0, 50);
    AutoGL_DrawString (0, 0, 50, "Z");  

    /* $B5e$rIA2h$9$k!#(B*/
    AutoGL_SetColor (1, 1, 0);
    AutoGL_DrawSphere3D (10, 10, 0,
			 radius, nDivisions);
  }

  if (taskId == 1) {

    /* $B1_Cl$rIA2h$9$k!#(B*/
    AutoGL_SetColor (0, 1, 1);
    AutoGL_DrawCylinder3D (-10, -20, 30,
			   10, 20, 30,
			   radius, nDivisions);
  }

  if (taskId == 2) {

    /* $B1_?m$rIA2h$9$k!#(B*/
    AutoGL_SetColor (1, 0, 1);
    AutoGL_DrawCone3D (-10, -20, -30,
		       10, 20, -30,
		       radius, nDivisions);
  }
  
  if (taskId == 3) {

    /* $B1_$rIA2h$9$k!#(B*/
    AutoGL_SetColor (1, 0, 0);
    AutoGL_DrawCircle3D (-10, -10, 0,
			 1, 1, 0,
			 radius, nDivisions);
  }

}



/* $B4X?t(BAutoGL_SetUp$B$O%f!<%6!<B&%W%m%0%i%`$4$H$KI,$:0l$DMQ0U$9$k$3$H!#(B*/
/* $B$3$3$G!"%3!<%k%P%C%/4X?t$d@)8fJQ?t$J$I$rEPO?$9$k!#(B*/
void AutoGL_SetUp (int argc, char *argv[]) 
{
  /* $B%S%e!<$N$_$N9=@.Nc(B */

  /* $B%S%e!<%$%s%0%Q%i%a!<%?!J%5%$%:(B,$B;k@~J}8~$J$I!K$r@_Dj$9$k!#(B*/
  AutoGL_SetViewSize (70);                 /* $B%S%e!<$NBg$-$5(B */
  AutoGL_SetViewCenter (10, 10, 10);       /* $BCm;kE@(B */
  AutoGL_SetViewDirection (1, 2, 3);       /* $B;k@~J}8~(B */

  /* $BF);kEj1F%b!<%I$K$9$k!#(B*/
  AutoGL_SetPerspectiveViewFlag (1);

  /* $B$*$^$8$J$$(B */
  AutoGL_SetViewRedrawCallback (RedrawView); 
  AutoGL_SetMode3D (AUTOGL_MODE_3D_ROTATE_XY); /* $B%^%&%9$G2sE>(B */
  AutoGL_SetDefaultCallbackInMode3D (NULL);
  AutoGL_SetPanelInMode3D ();
#if 0
  AutoGL_EnableDragInMode3D ();                /* $B%I%i%C%0M-8z(B */
#endif
}






