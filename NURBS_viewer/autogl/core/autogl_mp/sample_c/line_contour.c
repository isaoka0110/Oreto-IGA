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

/* $BFs<!85;03Q7AMWAG%a%C%7%e$rMQ$$$?M-8BMWAGK!2r@O(B */

#define MAX_NODES 100
#define MAX_ELEMENTS 100

/* $B@aE@:BI8(B */
int NNodes = 12;
double Coord[MAX_NODES][2] = {
  {  0.0,  0.0 }, { 10.0,  0.0 }, { 20.0,  0.0 }, { 30.0,  0.0 }, 
  {  0.0, 10.0 }, { 10.0, 10.0 }, { 20.0, 10.0 }, { 30.0, 10.0 }, 
  {  0.0, 20.0 }, { 10.0, 20.0 }, { 20.0, 20.0 }, { 30.0, 20.0 }
};

/* $BMWAG%3%M%/%F%#%S%F%#(B */
int NElements = 12;
int Nop[MAX_ELEMENTS][3] = {
  { 0, 1, 4 }, { 1, 5, 4 }, 
  { 1, 2, 5 }, { 2, 6, 5 }, 
  { 2, 3, 6 }, { 3, 7, 6 }, 
  { 4, 5, 8 }, { 5, 9, 8 },
  { 5, 6, 9 }, { 6, 10, 9 },
  { 6, 7, 10 }, { 7, 11, 10 }
};

/* $BE,Ev$J%9%+%i!<CM(B, $B29EY$H$+(B, $B1~NO$H$+(B */
double Scalar[MAX_NODES] = {
    0,  200,  400,   500,
  200,  500,  700,   900,
  400,  600,  900,  1000
};

/* $B%3%s%?(B-$B$N:GBg!&:G>.CM(B */
double MinRange = 0.0;
double MaxRange = 1000.0;

/* $B%3%s%?(B-$B$NJ,3d?t(B */
int NGrades = 20;



/* $B%a%C%7%e$r=i4|2=$9$k!#(B */
static void InitializeMesh ()
{
  /* $BFC$K$J$K$b$J$7!#(B */
}

/* $B%a%C%7%e$rIA2h$9$k!#(B */
static void PlotMesh (void) 
{
  int iElement;
  int taskId = AutoNOSim_MyTaskId ();
  int nTasks = AutoNOSim_NTasks ();

  AutoGL_SetColor (1, 1, 1);
  for (iElement = 0; iElement < NElements; iElement++) {
    int nodeId0 = Nop[iElement][0];
    int nodeId1 = Nop[iElement][1];
    int nodeId2 = Nop[iElement][2];

    if (iElement % nTasks != taskId) continue;

    AutoGL_DrawLine (Coord[nodeId0][0], Coord[nodeId0][1], 0,
		     Coord[nodeId1][0], Coord[nodeId1][1], 0);
    AutoGL_DrawLine (Coord[nodeId1][0], Coord[nodeId1][1], 0,
		     Coord[nodeId2][0], Coord[nodeId2][1], 0);
    AutoGL_DrawLine (Coord[nodeId2][0], Coord[nodeId2][1], 0,
		     Coord[nodeId0][0], Coord[nodeId0][1], 0);
  }
}

/* $B%9%+%i!<CM$N@~%3%s%?(B-$B!JEy9b@~(B, $BEyCM@~!K$rIA2h$9$k!#(B */
static void PlotLineContour (void) 
{
  int iGrade;
  int taskId = AutoNOSim_MyTaskId ();
  int nTasks = AutoNOSim_NTasks ();

  for (iGrade = 1; iGrade < NGrades; iGrade++) {
    double grade = 1.0 / NGrades * iGrade;
    double levelValue = MinRange + (MaxRange - MinRange) * grade;
    double red, green, blue;
    int iElement;

    /* 0.0 - 1.0 $B$N%0%l!<%ICM$KBP1~$9$k?'$rF@$k!#(B */
    AutoGL_GetContourColor (&red, &green, &blue,
			    grade);
    AutoGL_SetColor (red, green, blue);
  
    for (iElement = 0; iElement < NElements; iElement++) {
      int nodeId0 = Nop[iElement][0];
      int nodeId1 = Nop[iElement][1];
      int nodeId2 = Nop[iElement][2];
      double triPoints[3][3];
      double triValues[3];

      if (iElement % nTasks != taskId) continue;

      triPoints[0][0] = Coord[nodeId0][0];
      triPoints[0][1] = Coord[nodeId0][1];
      triPoints[0][2] = 0.0;
      triPoints[1][0] = Coord[nodeId1][0];
      triPoints[1][1] = Coord[nodeId1][1];
      triPoints[1][2] = 0.0;
      triPoints[2][0] = Coord[nodeId2][0];
      triPoints[2][1] = Coord[nodeId2][1];
      triPoints[2][2] = 0.0;

      triValues[0] = Scalar[nodeId0];
      triValues[1] = Scalar[nodeId1];
      triValues[2] = Scalar[nodeId2];
      
      /* $B$3$N;03Q7AFb$N(BlevelValue$B$G$NEy9b@~$rI=<($9$k!#(B */
      AutoGL_DrawTriangleIsoline
	(levelValue, triPoints, triValues);
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
    
    PlotMesh ();
    PlotLineContour ();

    /* $B%G%#%9%W%l%$%j%9%H$rJD$8$k!#(B */
    AutoGL_CloseDisplayList ();

    modelIsRendered = 1;
  }

  /* $B2hLL1&B&$K@~%3%s%?(B-$B$N%P!<$rIA2h$9$k!#(B */
  AutoGL_DrawLineContourMap (80, MinRange, MaxRange, NGrades);

  /* $B%G%#%9%W%l%$%j%9%H$KF~$l$?IA2hL?Na$r<B:]$KIA2h$9$k!#(B */
  AutoGL_DrawDisplayList ();
}

/* $B4X?t(BAutoGL_SetUp$B$O%f!<%6!<B&%W%m%0%i%`$4$H$KI,$:0l$DMQ0U$9$k$3$H!#(B*/
/* $B$3$3$G!"%3!<%k%P%C%/4X?t$d@)8fJQ?t$J$I$rEPO?$9$k!#(B*/
void AutoGL_SetUp (int argc, char *argv[]) 
{
  InitializeMesh ();

  AutoGL_SetViewCenter (15, 10, 0);   /* $B%S%e!<$NCm;kE@(B */
  AutoGL_SetViewSize (40);            /* $B%S%e!<$N%5%$%:(B */

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


