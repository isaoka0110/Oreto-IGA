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

/* $BFs<!85M-8BMWAGK!2r@O7k2L$N2D;k2=(B */
/* $B@~%3%s%?(B-,$BLL%3%s%?(B-$B$HJQ7A?^$rI=<($9$k!#(B */
/* $B$3$l$O!"E57?E*$JFs<!85%"%W%j%1!<%7%g%s$NNc$G$"$k!#(B */

/* $B%f!<%F%#%j%F%#$N2D;k2=!J@~%3%s%?(B-$B!K$NMxMQ(B */
/* $B0z?t$J$I>\$7$$>pJs$O(B, autogl_utility3d.h$B$r;2>H!#(B*/
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

/* $BJQ0LCM(B */
double Displacement[MAX_NODES][2] = {
  {  0.0,  0.0 }, {  0.1,  0.05 }, {  0.2,  0.15 }, {  0.3,  0.3 }, 
  {  0.0,  0.0 }, {  0.0,  0.05 }, {  0.0,  0.15 }, {  0.0,  0.3 }, 
  {  0.0,  0.0 }, { -0.1,  0.05 }, { -0.2,  0.15 }, { -0.3,  0.3 }
};

/* $B%3%s%?(B-$B$N:GBg!&:G>.CM(B */
double MinRange = 0.0;
double MaxRange = 1000.0;

/* $BJQ7A?^$N3HBgN((B */
double Scale = 3.0;

/* $B%a%C%7%e$rI=<($9$k$+(B */
int MeshIsShown = 1;

/* $B$J$K$bI=<($7$J$$(B */
#define PLOT_NONE 0
/* $B%9%+%i!<CM$NLL%3%s%?(B- */
#define PLOT_CONTOUR 1
/* $B%9%+%i!<CM$N@~%3%s%?(B- */
#define PLOT_LINE_CONTOUR 2
/* $BJQ7A?^(B */
#define PLOT_DEFORMATION 3

/* $BI=<($5$l$k%W%m%C%H$N%?%$%W(B */
int PlotType = PLOT_NONE;



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

/* $B%9%+%i!<CM$NLL%3%s%?(B-$B$rIA2h$9$k!#(B */
static void PlotContour (void) 
{
  int iElement;
  int taskId = AutoNOSim_MyTaskId ();
  int nTasks = AutoNOSim_NTasks ();

  AutoGL_DrawContourMap (80, MinRange, MaxRange);

  AutoGL_SetColor (1, 1, 1);
  for (iElement = 0; iElement < NElements; iElement++) {
    int nodeId0 = Nop[iElement][0];
    int nodeId1 = Nop[iElement][1];
    int nodeId2 = Nop[iElement][2];
    double grades[3];

    if (iElement % nTasks != taskId) continue;

    grades[0] = (Scalar[nodeId0] - MinRange) / (MaxRange - MinRange);
    grades[1] = (Scalar[nodeId1] - MinRange) / (MaxRange - MinRange);
    grades[2] = (Scalar[nodeId2] - MinRange) / (MaxRange - MinRange);

    AutoGL_DrawContourTriangle 
      (Coord[nodeId0][0], Coord[nodeId0][1], 0, grades[0],
       Coord[nodeId1][0], Coord[nodeId1][1], 0, grades[1], 
       Coord[nodeId2][0], Coord[nodeId2][1], 0, grades[2]);
  }
}

/* $B%9%+%i!<CM$N@~%3%s%?(B-$B!JEy9b@~(B, $BEyCM@~!K$rIA2h$9$k!#(B */
static void PlotLineContour (void) 
{
  int nGrades = 20;
  int iGrade;
  int taskId = AutoNOSim_MyTaskId ();
  int nTasks = AutoNOSim_NTasks ();

  AutoGL_DrawLineContourMap (80, MinRange, MaxRange, nGrades);

  for (iGrade = 1; iGrade < nGrades; iGrade++) {
    double grade = 1.0 / nGrades * iGrade;
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

/* $BJQ7A?^$rI=<($9$k!#(B */
static void PlotDeformation (void) 
{
  int iElement;
  int taskId = AutoNOSim_MyTaskId ();
  int nTasks = AutoNOSim_NTasks ();

  AutoGL_SetColor (0, 1, 1);
  for (iElement = 0; iElement < NElements; iElement++) {
    int nodeId0 = Nop[iElement][0];
    int nodeId1 = Nop[iElement][1];
    int nodeId2 = Nop[iElement][2];
    double p0X = Coord[nodeId0][0] + Displacement[nodeId0][0] * Scale;
    double p0Y = Coord[nodeId0][1] + Displacement[nodeId0][1] * Scale;
    double p1X = Coord[nodeId1][0] + Displacement[nodeId1][0] * Scale;
    double p1Y = Coord[nodeId1][1] + Displacement[nodeId1][1] * Scale;
    double p2X = Coord[nodeId2][0] + Displacement[nodeId2][0] * Scale;
    double p2Y = Coord[nodeId2][1] + Displacement[nodeId2][1] * Scale;

    if (iElement % nTasks != taskId) continue;

    AutoGL_DrawLine (p0X, p0Y, 0,
		     p1X, p1Y, 0);
    AutoGL_DrawLine (p1X, p1Y, 0,
		     p2X, p2Y, 0);
    AutoGL_DrawLine (p2X, p2Y, 0,
		     p0X, p0Y, 0);
  }
}



/* $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
static void RedrawView (void) 
{
  if (MeshIsShown) {
    PlotMesh ();
  }

  switch (PlotType) {
  case PLOT_NONE:
    break;
  case PLOT_CONTOUR:
    PlotContour ();
    break;
  case PLOT_LINE_CONTOUR:
    PlotLineContour ();
    break;
  case PLOT_DEFORMATION:
    PlotDeformation ();
    break;
  }
}

/* $BIA2h%"%C%W%G!<%H%3%^%s%I$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* "UpdateModel"$B%\%?%s$rA*$V$H8F$P$l$k!#(B */
static void UpdateModel (void) 
{
  /* $B%S%e!<$r:FIA2h$9$k!#(B */
  AutoGL_DrawView ();  
  /* $BEPO?$5$l$?%S%e!<$N:FIA2h4X?t!J$3$N>l9g$O(BRedrawView ()$B!K$,8F$P$l$k!#(B */
}



/* $B4X?t(BAutoGL_SetUp$B$O%f!<%6!<B&%W%m%0%i%`$4$H$KI,$:0l$DMQ0U$9$k$3$H!#(B*/
/* $B$3$3$G!"%3!<%k%P%C%/4X?t$d@)8fJQ?t$J$I$rEPO?$9$k!#(B*/
void AutoGL_SetUp (int argc, char *argv[]) 
{
  /* $B%S%e!<$r=`Hw$9$k!#(B */

  AutoGL_SetViewSize (30); 
  AutoGL_SetViewCenter (15, 10, 0); 

  AutoGL_SetViewRedrawCallback (RedrawView);   
  AutoGL_SetDefaultCallbackInMode2D (NULL);  /* $BFs<!85%"%W%jMQ%$%Y%s%H=hM}(B */
#if 0
  AutoGL_EnableDragInMode2D ();              /* $B%I%i%C%0M-8z(B */
#endif

  /* $B%Q%M%k(Bviewing$B$r=`Hw$9$k!#(B */

#if 0
  AutoGL_AddGroup ("viewing");    
  AutoGL_SetPanelInView2D ();        /* $BFs<!85%"%W%jMQ%S%e!<%$%s%0JQ?t(B */
  AutoGL_SetPanelForInterpreter ();  /* $B%3%^%s%I%i%$%s=hM}(B */
  AutoGL_SetPanelForSave ();         /* $B2hLL%;!<%V5!G=(B */
#endif

  /* $B%Q%M%k(Bmodel$B$r=`Hw$9$k!#(B */

  AutoGL_AddGroup ("model");    
  AutoGL_SetPanelInMode2D ();        /* $BFs<!85%"%W%jMQ%$%Y%s%H=hM}(B */

  AutoGL_AddComment ();
  AutoGL_SetLabel ("Model Parameters");
  AutoGL_AddBoolean (&MeshIsShown, "MeshIsShown");
  AutoGL_AddInteger (&PlotType, "PlotType");
  AutoGL_AddIntegerItem ("none");      
  AutoGL_AddIntegerItem ("contour"); 
  AutoGL_AddIntegerItem ("line_contour"); 
  AutoGL_AddIntegerItem ("deformation");    
  AutoGL_AddReal (&MinRange, "MinRange");
  AutoGL_AddReal (&MaxRange, "MaxRange");
  AutoGL_AddReal (&Scale, "Scale");
  AutoGL_AddCallback (UpdateModel, "UpdateModel");
}






