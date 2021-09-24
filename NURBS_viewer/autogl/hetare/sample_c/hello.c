/*  AutoGL $B!c$*<j7Z!d(B $B$N%5%s%W%k%W%m%0%i%`Nc(B */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/* AutoGL $B!I$*$F$,$k!I$r;H$&$K$O(B,$B$3$N%X%C%@%U%!%$%k$r%$%s%/%k!<%I$9$k!#(B*/
#include <autogl.h>



/* $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
static void RedrawView (void) 
{
  /* $B:BI8<4$rGr$GIA2h$9$k!#(B*/
  AutoGL_SetColor (1, 1, 1);
  AutoGL_DrawString (0, 0, 0, "O");   /* $B86E@$K86E@%i%Y%k$NJ8;zNs(B */

  AutoGL_DrawLine (0, 0, 0,
		   50, 0, 0);         /* $B86E@$+$i(B(50, 0, 0)$B$X$N@~J,(B */
  AutoGL_DrawString (50, 0, 0, "X");  /* X$B<4(B */
  
  AutoGL_DrawLine (0, 0, 0,
		   0, 50, 0);         /* $B86E@$+$i(B(0, 50, 0)$B$X$N@~J,(B */
  AutoGL_DrawString (0, 50, 0, "Y");  /* Y$B<4(B */
  
  AutoGL_DrawLine (0, 0, 0,
		   0, 0, 50);         /* $B86E@$+$i(B(0, 0, 50)$B$X$N@~J,(B */
  AutoGL_DrawString (0, 0, 50, "Z");  /* Z$B<4(B */


  /* $B;03Q7A$r@V$GIA2h$9$k!#(B */
  AutoGL_SetColor (1, 0, 0);
  AutoGL_DrawTriangle (-20, 0, 0,
		       0, -20, 0,
		       0, 0, -20);    /* $B;0E@$r;XDj$7$F;03Q7A(B */

  /* $BD>J}BN(B(0, 0, 0) -$B!J(B10, 20, 30)$B$r%7%"%s$GIA2h$9$k!#(B */
  AutoGL_SetColor (0, 1, 1);
  AutoGL_DrawQuadrangle (0, 0, 0,
			 10, 0, 0,
			 10, 20, 0,
			 0, 20, 0);   /* $B;ME@$r;XDj$7$F;MJU7A(B */
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

  /* $B$$$o$f$k$*7h$^$j$N%;%j%U(B */
  AutoGL_SetColor (1, 1, 0);
  AutoGL_DrawString (10, 20, 30, "HelloWorld");
}

/* $B$3$N4X?t$O%W%m%0%i%`5/F0D>8e$K(BAutoGL$B%i%$%V%i%j$+$i8F$S=P$5$l$k!#(B*/
void AutoGL_SetUp (int argc, char *argv[]) 
{
  /* $B%5%$%:$d;k@~J}8~$J$I$r@_Dj$9$k!#(B*/
  AutoGL_SetViewSize (70);                 /* $B%S%e!<$NBg$-$5(B */
  AutoGL_SetViewCenter (10, 10, 10);       /* $BCm;kE@(B */
  AutoGL_SetViewDirection (1, 2, 3);       /* $B;k@~J}8~(B */

  /* $B$*$^$8$J$$(B */
  AutoGL_SetViewRedrawCallback (RedrawView); 
  AutoGL_SetMode3D (AUTOGL_MODE_3D_ROTATE_XY);
  AutoGL_SetDefaultCallbackInMode3D (NULL);    
  AutoGL_EnableDragInMode3D ();               
}






