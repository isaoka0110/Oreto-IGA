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

/* $BFs<!85:9J,K!2r@O7k2L$N2D;k2=(B */
/* $BLL%3%s%?(B-$B$rI=<($9$k!#(B */

/* $B%f!<%F%#%j%F%#$N2D;k2=!JLL%3%s%?(B-$B!K$NMxMQ(B */
/* $B0z?t$J$I>\$7$$>pJs$O(B, autogl_utility.h$B$r;2>H!#(B*/
/* $B$J$*!"$3$l$O(Bautogl.h$B$+$i(Binclude$B$5$l$F$$$k!#(B*/




/* $B%S%e!<>e$KI=<($5$l$k%b%G%k$rI=8=$9$k$?$a$NJQ?t72(B */

/* $BD>8r:9J,3J;R$K$h$kFs<!85%9%+%i!<>l(B */

/* $B3J;R$NJ,3d?t(B */
#if 0
#define CELLS 20
#else
#define CELLS 100
#endif

/* $B3J;R>e$N%9%+%i!<CM(B */
static double GridValues[CELLS + 1][CELLS + 1];

/* $B%3%s%?(B-$B$N:GBg!&:G>.CM(B */
static double MinRange = -1.0;
static double MaxRange = 5.0;



/* $BFs<!85%9%+%i!<>l$NDj5A(B */
static double Function (double x, double y)
{
  return sin (x * M_PI) + y * y;
}

/* $BFs<!853J;R$r=i4|2=$9$k!#(B */
static void InitializeGrid ()
{
  int i, j;

  /* $B%b%G%kMQJQ?t$r=i4|2=$9$k!#(B */
  for (i = 0; i <= CELLS; i++) {
    for (j = 0; j <= CELLS; j++) {
      double scale = 4.0 / CELLS;
      
      GridValues[i][j] 
	= Function ((i - CELLS / 2) * scale, 
		    (j - CELLS / 2) * scale);
    }
  }
}

/* $B%3%s%?(B-$B$rIA2h$9$k!#(B */
static void PlotContour (void) 
{
  double cellSize = 60.0 / CELLS;
  int i, j;
  int taskId = AutoNOSim_MyTaskId ();

  for (i = 0; i < CELLS; i++) {
    for (j = 0; j < CELLS; j++) {
      double x00 = (i - CELLS / 2) * cellSize;
      double y00 = (j - CELLS / 2) * cellSize;
      double value00 = GridValues[i + 0][j + 0];
      
      double x10 = x00 + cellSize;
      double y10 = y00;
      double value10 = GridValues[i + 1][j + 0];
      
      double x11 = x00 + cellSize;
      double y11 = y00 + cellSize;
      double value11 = GridValues[i + 1][j + 1];
      
      double x01 = x00;
      double y01 = y00 + cellSize;
      double value01 = GridValues[i + 0][j + 1];

      switch (taskId) {
      case 0:
	if (i <= CELLS / 2 && j <= CELLS / 2) {} else continue;
	break;
      case 1:
	if (i <= CELLS / 2 && CELLS / 2 < j) {} else continue;
	break;
      case 2:
	if (CELLS / 2 < i  && j <= CELLS / 2) {} else continue;
	break;
      case 3:
	if (CELLS / 2 < i  && CELLS / 2 < j) {} else continue;	
	break;
      default: 
	continue; 
	break;
      }

      /* $B%9%`!<%:%3%s%?(B-$B$D$-$N;MJU7A$rI=<($9$k!#(B */
      AutoGL_DrawSmoothContourQuadrangle 
	(MinRange, MaxRange,
	 x00, y00, 0.0, value00,
	 x10, y10, 0.0, value10,
	 x11, y11, 0.0, value11,
	 x01, y01, 0.0, value01);
    }
  }
}



/* $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
static void RedrawView (void) 
{
  static int modelIsRendered = 0;

  /* $B$^$:!"0lEY$@$1%b%G%k$r%G%#%9%W%l%$%j%9%H$XIA2h$7$F$*$/!#(B */
  if (!modelIsRendered) {

    /* $B%G%#%9%W%l%$%j%9%H$r3+$-!"$3$l$r6u$K$9$k!#(B */
    AutoGL_OpenDisplayList ();
    
    PlotContour ();

    /* $B%G%#%9%W%l%$%j%9%H$rJD$8$k!#(B */
    AutoGL_CloseDisplayList ();

    modelIsRendered = 1;
  }

  /* $B2hLL1&B&$K%3%s%?(B-$B$N%P!<$rIA2h$9$k!#(B */
  AutoGL_DrawContourMap (80, MinRange, MaxRange);

  /* $B%G%#%9%W%l%$%j%9%H$KF~$l$?IA2hL?Na$r<B:]$KIA2h$9$k!#(B */
  AutoGL_DrawDisplayList ();
}

/* $B4X?t(BAutoGL_SetUp$B$O%f!<%6!<B&%W%m%0%i%`$4$H$KI,$:0l$DMQ0U$9$k$3$H!#(B*/
/* $B$3$3$G!"%3!<%k%P%C%/4X?t$d@)8fJQ?t$J$I$rEPO?$9$k!#(B*/
void AutoGL_SetUp (int argc, char *argv[]) 
{
  InitializeGrid ();

  AutoGL_SetViewSize (60);   /* $B%S%e!<$N%5%$%:(B */

  /* $B$*$^$8$J$$(B */
  AutoGL_SetViewRedrawCallback (RedrawView);    
  AutoGL_SetMode2D (AUTOGL_MODE_2D_SCALE);     /* $B%^%&%9$G3HBg=L>.(B */
  AutoGL_SetDefaultCallbackInMode2D (NULL);    /* $BFs<!85%"%W%jMQ%$%Y%s%H=hM}(B */
  AutoGL_SetPanelInMode2D ();

#if 0
  /* $B$b$7IA2h$,=E$1$l$P%I%i%C%0Cf$OIA2h$5$;$J$$$[$&$,$h$$!#(B */
  AutoGL_EnableDragInMode2D ();
#endif
}


