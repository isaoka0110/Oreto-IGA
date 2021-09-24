/*  AutoGL $B!c$*<j7Z!d(B $B$N%5%s%W%k%W%m%0%i%`Nc(B */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/* AutoGL $B!I$*$F$,$k!I$r;H$&$K$O(B,$B$3$N%X%C%@%U%!%$%k$r%$%s%/%k!<%I$9$k!#(B*/
#include <autogl.h>

/* $BFs<!85:9J,K!2r@O7k2L$N2D;k2=(B */
/* $BLL%3%s%?(B-$B$H;0<!85%0%i%U$rI=<($9$k!#(B */
/* $B$3$l$O!"E57?E*$J;0<!85%"%W%j%1!<%7%g%s$NNc$G$"$k!#(B */

/* $B%f!<%F%#%j%F%#$N2D;k2=!JLL%3%s%?(B-$B!K$NMxMQ(B */
/* $B0z?t$J$I>\$7$$>pJs$O(B, autogl_visualization.h$B$r;2>H!#(B*/
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
static int NGrades = 20;

/* $B;0<!85%0%i%U$N(BZ$BJ}8~$N3HBgN((B */
static double ZScale = 5.0;

/* $B3J;R$rI=<($9$k$+(B */
static int GridIsShown = 0;

/* $B%3%s%?(B-$B$rI=<($9$k$+(B */
static int ContourIsShown = 0;

/* $B%3%s%?(B-$B$N%?%$%W(B : 0 - 2 $B$N@0?t(B (CONTOUR_) */
#define CONTOUR_SMOOTH 0
#define CONTOUR_LINE 1
#define CONTOUR_BAND 2
static int ContourType = 0;

/* $B;0<!85%0%i%U$rI=<($9$k$+(B */
static int Graph3DIsShown = 0;



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

/* $B3J;R$rIA2h$9$k!#(B */
static void DrawGrid (void) 
{
  double cellSize = 60.0 / CELLS;
  int i, j;

  AutoGL_SetColor (1, 1, 1);

  for (i = 0; i < CELLS; i++) {
    for (j = 0; j < CELLS; j++) {
      double x00 = (i - CELLS / 2) * cellSize;
      double y00 = (j - CELLS / 2) * cellSize;
      double x10 = x00 + cellSize;
      double y10 = y00;
      double x11 = x00 + cellSize;
      double y11 = y00 + cellSize;
      double x01 = x00;
      double y01 = y00 + cellSize;

      AutoGL_DrawLine (x00, y00, 0.0,
		       x10, y10, 0.0);
      AutoGL_DrawLine (x10, y10, 0.0,
		       x11, y11, 0.0);
      AutoGL_DrawLine (x11, y11, 0.0,
		       x01, y01, 0.0);
      AutoGL_DrawLine (x01, y01, 0.0,
		       x00, y00, 0.0);
    }
  }
}

/* $B%3%s%?(B-$B$rIA2h$9$k!#(B */
static void DrawContour (void) 
{
  double cellSize = 60.0 / CELLS;
  int i, j;

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

      switch (ContourType) {
      case CONTOUR_SMOOTH:
	/* $B%9%`!<%:%3%s%?(B-$B$D$-$N;MJU7A$rI=<($9$k!#(B */
	AutoGL_DrawSmoothContourQuadrangle 
	  (MinRange, MaxRange,
	   x00, y00, 0.0, value00,
	   x10, y10, 0.0, value10,
	   x11, y11, 0.0, value11,
	   x01, y01, 0.0, value01);
	break;
      case CONTOUR_LINE:
	/* $B@~%3%s%?(B-$B$D$-$N;MJU7A$rI=<($9$k!#(B */
	AutoGL_DrawLineContourQuadrangle 
	  (MinRange, MaxRange, NGrades,
	   x00, y00, 0.0, value00,
	   x10, y10, 0.0, value10,
	   x11, y11, 0.0, value11,
	   x01, y01, 0.0, value01);
	break;
      case CONTOUR_BAND:
	/* $B%P%s%I%3%s%?(B-$B$D$-$N;MJU7A$rI=<($9$k!#(B */
	AutoGL_DrawBandContourQuadrangle 
	  (MinRange, MaxRange, NGrades,
	   x00, y00, 0.0, value00,
	   x10, y10, 0.0, value10,
	   x11, y11, 0.0, value11,
	   x01, y01, 0.0, value01);
	break;
      }
    }
  }
}

/* $B;0<!85%0%i%U$rIA2h$9$k!#(B */
static void DrawGraph3D (void) 
{
  double cellSize = 60.0 / CELLS;
  int i, j;

  AutoGL_SetColor (1, 1, 1);

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

      AutoGL_DrawTriangle (x00, y00, value00 * ZScale,
			   x10, y10, value10 * ZScale,
			   x11, y11, value11 * ZScale);
      AutoGL_DrawTriangle (x11, y11, value11 * ZScale,
			   x01, y01, value01 * ZScale,
			   x00, y00, value00 * ZScale);
    }
  }

}



/* $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
static void RedrawView (void) 
{
  /* $B2hLL:82<$K;0<!85:BI87O$rIA2h$9$k!#(B */
  AutoGL_DrawCoordinateSystem3D (20);

  if (ContourIsShown) {
    /* $B2hLL1&B&$K%3%s%?(B-$B$N%P!<$rIA2h$9$k!#(B */
    switch (ContourType) {
    case CONTOUR_SMOOTH:
      AutoGL_DrawContourMap (80, MinRange, MaxRange);
      break;
    case CONTOUR_LINE:
      AutoGL_DrawLineContourMap (80, MinRange, MaxRange, NGrades);
      break;
    case CONTOUR_BAND:
      AutoGL_DrawBandContourMap (80, MinRange, MaxRange, NGrades);
      break;
    }
  }

  /* $B%G%#%9%W%l%$%j%9%H$KF~$l$?IA2hL?Na$r<B:]$KIA2h$9$k!#(B */
  AutoGL_DrawDisplayList ();
}

/* $BIA2h%"%C%W%G!<%H%3%^%s%I$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* "UpdateModel"$B%\%?%s$rA*$V$H8F$P$l$k!#(B */
static void UpdateModel (void) 
{
  /* $B%G%#%9%W%l%$%j%9%H$r3+$-!"$3$l$r6u$K$9$k!#(B */
  AutoGL_OpenDisplayList ();

  /* $B0J2<$NIA2hL?Na$r%G%#%9%W%l%$%j%9%H$K=g<!F~$l$F$$$/!#(B */
  /* $B<B:]$NIA2h$O$3$3$G$O$^$@9T$o$l$J$$!#(B */

  if (GridIsShown) {
    DrawGrid ();
  }
  if (ContourIsShown) {
    DrawContour ();
  }
  if (Graph3DIsShown) {
    DrawGraph3D ();
  }

  /* $B%G%#%9%W%l%$%j%9%H$rJD$8$k!#(B */
  AutoGL_CloseDisplayList ();

  /* $B%S%e!<$r:FIA2h$9$k!#(B */
  AutoGL_DrawView ();  
  /* $BEPO?$5$l$?%S%e!<$N:FIA2h4X?t!J$3$N>l9g$O(BRedrawView ()$B!K$,8F$P$l$k!#(B */
}



/* $B4X?t(BAutoGL_SetUp$B$O%f!<%6!<B&%W%m%0%i%`$4$H$KI,$:0l$DMQ0U$9$k$3$H!#(B*/
/* $B$3$3$G!"%3!<%k%P%C%/4X?t$d@)8fJQ?t$J$I$rEPO?$9$k!#(B*/
void AutoGL_SetUp (int argc, char *argv[]) 
{
  InitializeGrid ();

  /* $B%S%e!<$r=`Hw$9$k!#(B */

  AutoGL_SetBackgroundColor (0.7, 0.7, 0.7);   /* $B%S%e!<$NGX7J?'(B */
  AutoGL_SetViewSize (80); 

  AutoGL_SetViewRedrawCallback (RedrawView);    
  AutoGL_SetDefaultCallbackInMode3D (NULL);  /* $B;0<!85%"%W%jMQ%$%Y%s%H=hM}(B */

  /* $B$b$7IA2h$,=E$1$l$P%I%i%C%0Cf$OIA2h$5$;$J$$$[$&$,$h$$!#(B */
  AutoGL_EnableDragInMode3D ();

#if 1
  /* $B%Q%M%k(Bviewing$B$r=`Hw$9$k!#(B */
  /* $B%f!<%6!<$,IaCJMQ$$$J$$Hf3SE*%^%$%J!<$J5!G=!#(B */

  AutoGL_AddGroup ("viewing");    
  AutoGL_SetPanelInView3D ();        /* $B;0<!85%"%W%jMQ%S%e!<%$%s%0JQ?t(B */
  AutoGL_SetPanelForInterpreter ();  /* $B%3%^%s%I%i%$%s=hM}(B */
  AutoGL_SetPanelForSave ();         /* $B2hLL%;!<%V5!G=(B */
#endif

  /* $B%Q%M%k(Bmodel$B$r=`Hw$9$k!#(B */
  /* $B%f!<%6!<$,IQHK$KMQ$$$k5!G=!#(B */
  /* $B$*$h$S!"3F%W%m%0%i%`$4$H$KFCM-$J5!G=!#(B */

  AutoGL_AddGroup ("model");    
  AutoGL_SetPanelInMode3D ();       /* $B;0<!85%"%W%jMQ%$%Y%s%H=hM}(B */

  AutoGL_AddComment ();
  AutoGL_SetLabel ("Model Parameters");

  /* $B3J;R(B */
  AutoGL_AddBoolean (&GridIsShown, "GridIsShown"); 
  AutoGL_SetLabel ("grid");

  /* $B%3%s%?(B- */
  AutoGL_AddBoolean (&ContourIsShown, "ContourIsShown"); 
  AutoGL_SetLabel ("contour");
  AutoGL_AddInteger (&ContourType, "ContourType");
  AutoGL_SetLabel ("type");
  AutoGL_AddIntegerItem ("smooth");    
  AutoGL_AddIntegerItem ("line");
  AutoGL_AddIntegerItem ("band");     
  AutoGL_AddReal (&MinRange, "MinRange");      
  AutoGL_SetLabel ("min");
  AutoGL_AddReal (&MaxRange, "MaxRange");      
  AutoGL_SetLabel ("max");
  AutoGL_AddInteger (&NGrades, "NGrades");      
  AutoGL_SetLabel ("num. grades");

  /* $B;0<!85%0%i%U(B */
  AutoGL_AddBoolean (&Graph3DIsShown, "Graph3DIsShown"); 
  AutoGL_SetLabel ("3-D graph");
  AutoGL_AddReal (&ZScale, "ZScale");      

  AutoGL_AddCallback (UpdateModel, "UpdateModel");
}


