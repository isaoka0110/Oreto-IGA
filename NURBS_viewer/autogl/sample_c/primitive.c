/*  AutoGL $B!c$*<j7Z!d(B $B$N%5%s%W%k%W%m%0%i%`Nc(B */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/* AutoGL $B!I$*$F$,$k!I$r;H$&$K$O(B,$B$3$N%X%C%@%U%!%$%k$r%$%s%/%k!<%I$9$k!#(B*/
#include <autogl.h>

/* $B4pK\;0<!85IA2h%W%j%_%F%#%V$NMxMQ(B */
/* $B0z?t$J$I>\$7$$>pJs$O(B, autogl_graphics.h$B$r;2>H!#(B*/
/* $B$J$*!"$3$l$O(Bautogl.h$B$+$i(Binclude$B$5$l$F$$$k!#(B*/



/* $B%3!<%k%P%C%/4X?t72(B */

/* $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
static void RedrawView (void) 
{
  AutoGL_SetColor (1, 1, 1);

  /* $B86E@%i%Y%k$rI=<($9$k!#(B*/
  AutoGL_DrawString (0, 0, 0, "O");  /* $B86E@$K86E@%i%Y%k$NJ8;zNs(B */

  /* X$B<4$rIA2h$9$k!#(B*/
  AutoGL_DrawLine (0, 0, 0,
		   50, 0, 0);  /* $B86E@$+$i(B(50, 0, 0)$B$X$N@~J,(B */
  AutoGL_DrawString (50, 0, 0, "X");  
  
  /* Y$B<4$rIA2h$9$k!#(B*/
  AutoGL_DrawLine (0, 0, 0,
		   0, 50, 0);  /* $B86E@$+$i(B(0, 50, 0)$B$X$N@~J,(B */
  AutoGL_DrawString (0, 50, 0, "Y");  
  
  /* Z$B<4$rIA2h$9$k!#(B*/
  AutoGL_DrawLine (0, 0, 0,
		   0, 0, 50);  /* $B86E@$+$i(B(0, 0, 50)$B$X$N@~J,(B */
  AutoGL_DrawString (0, 0, 50, "Z");  


  /* $B;03Q7A$rIA2h$9$k!#(B */
  AutoGL_SetColor (1, 1, 1);
  AutoGL_DrawTriangle (-20, 0, 0,
		       0, -20, 0,
		       0, 0, -20);  /* $B;0E@$r;XDj$7$F;03Q7A(B */

  /* $BD>J}BN(B(0, 0, 0) -$B!J(B10, 20, 30)$B$N(B6$BKg$NLL!J;MJU7A!K$rIA2h$9$k!#(B */

  AutoGL_SetColor (0, 1, 1);
  AutoGL_DrawQuadrangle (0, 0, 0,
			 10, 0, 0,
			 10, 20, 0,
			 0, 20, 0);  /* $B;ME@$r;XDj$7$F;MJU7A(B */
  AutoGL_SetColor (1, 1, 0);
  AutoGL_DrawQuadrangle (0, 0, 30,
			 10, 0, 30,
			 10, 20, 30,
			 0, 20, 30);
  AutoGL_SetColor (1, 0, 1);
  AutoGL_DrawQuadrangle (0, 0, 0,
			 0, 20, 0,
			 0, 20, 30,
			 0, 0, 30);
  AutoGL_SetColor (0, 0, 1);
  AutoGL_DrawQuadrangle (10, 0, 0,
			 10, 20, 0,
			 10, 20, 30,
			 10, 0, 30);
  AutoGL_SetColor (0, 1, 0);
  AutoGL_DrawQuadrangle (0, 0, 0,
			 10, 0, 0,
			 10, 0, 30,
			 0, 0, 30);
  AutoGL_SetColor (1, 0, 0);
  AutoGL_DrawQuadrangle (0, 20, 0,
			 10, 20, 0,
			 10, 20, 30,
			 0, 20, 30);
}



/* $B4X?t(BAutoGL_SetUp$B$O%f!<%6!<B&%W%m%0%i%`$4$H$KI,$:0l$DMQ0U$9$k$3$H!#(B*/
/* $B$3$N4X?t$O%W%m%0%i%`5/F0D>8e$K(BAutoGL$B%i%$%V%i%j$+$i8F$S=P$5$l$k!#(B*/
/* $B$3$N$H$-!"(Bargc, argv$B$O(Bmain$B4X?t$+$iD>@\EO$5$l$k!#(B*/
/* $B$3$3$G!"%3!<%k%P%C%/4X?t$d@)8fJQ?t$J$I$rEPO?$9$k!#(B*/
void AutoGL_SetUp (int argc, char *argv[]) 
{
  /* $B%S%e!<$N$_$N9=@.Nc(B */

  /* $B%S%e!<%$%s%0%Q%i%a!<%?!J%5%$%:(B,$B;k@~J}8~$J$I!K$r@_Dj$9$k!#(B*/
  AutoGL_SetViewSize (70);                 /* $B%S%e!<$NBg$-$5(B */
  AutoGL_SetViewCenter (10, 10, 10);       /* $BCm;kE@(B */
  AutoGL_SetViewDirection (1, 2, 3);       /* $B;k@~J}8~(B */

  /* $B$*$^$8$J$$(B */
  AutoGL_SetViewRedrawCallback (RedrawView); 
  AutoGL_SetMode3D (AUTOGL_MODE_3D_ROTATE_XY); /* $B%^%&%9$G2sE>(B */
  AutoGL_SetDefaultCallbackInMode3D (NULL);    
  AutoGL_SetPanelInMode3D ();
  AutoGL_EnableDragInMode3D ();                /* $B%I%i%C%0M-8z(B */
}






