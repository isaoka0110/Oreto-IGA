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

/* GUI$B$NMxMQ(B */
/* $B0z?t$J$I>\$7$$>pJs$O(B, autogl_uims.h$B$r;2>H!#(B*/
/* $B$J$*!"$3$l$O(Bautogl.h$B$+$i(Binclude$B$5$l$F$$$k!#(B*/



/* $B%S%e!<>e$KI=<($5$l$k%b%G%k$rI=8=$9$k$?$a$NJQ?t72(B */

/* $B86E@$N%i%Y%k(B : $BJ8;zNs(B */
static char OriginLabel[256];

/* $B:BI8<4$rI=<($9$k$+$I$&$+(B : 0$B$^$?$O(B1$B$N@0?t!JO@M}CM!K(B */
static int AxisIsShown;

/* $B%b%G%k$N7A$N%?%$%W(B : 0 - 2 $B$N@0?t(B (SHAPE_) */
#define SHAPE_LINE 0
#define SHAPE_TRIANGLE 1
#define SHAPE_BOX 2
static int Shape;

/* $B@0?tJQ?t(B */
static int Number;

/* $B<B?tJQ?t(B */
static double Value;



/* $B%3!<%k%P%C%/4X?t72(B */

/* $B0u:~%3%^%s%I$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* "Print"$B%\%?%s$rA*$V$H8F$P$l$k!#(B */
static void Print (void) 
{
  printf (" PRINT \n");

  /* $B8=:_$N86E@%i%Y%k$rI=<($9$k!#(B */
  printf (" OriginLabel is <<%s>> \n", OriginLabel);
  
  /* $B8=:_:BI8<4$,I=<($5$l$F$$$k$+$I$&$+$rI=<($9$k!#(B */
  printf (" AxisIsShown is %d \n", AxisIsShown);

  /* $B8=:_$N%b%G%k$N7A$N%?%$%W$rI=<($9$k!#(B */
  printf (" Shape is ");
  switch (Shape) {
  case SHAPE_LINE:
    printf ("SHAPE_LINE");
    break;
  case SHAPE_TRIANGLE:
    printf ("SHAPE_TRIANGLE");
    break;
  case SHAPE_BOX:
    printf ("SHAPE_BOX");
    break;
  }
  printf ("\n");

  /* $B@0?tJQ?t(BNumber$B$NCM$rI=<($9$k!#(B */
  printf (" Number is %d \n", Number);

  /* $B<B?tJQ?t(BValue$B$NCM$rI=<($9$k!#(B */
  printf (" Value is %f \n", Value);
}

/* $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
static void RedrawView (void) 
{
  int taskId = AutoNOSim_MyTaskId ();

  if (taskId == 0) {

    /* $B$b$7:BI8<4$rI=<($9$k$J$i$P!"(B */
    if (AxisIsShown) {
      
      /* X$B<4$rIA2h$9$k!#(B */
      AutoGL_SetColor (1, 0, 0); 
      AutoGL_DrawLine (0, 0, 0,
		       50, 0, 0);
      
      /* Y$B<4$rIA2h$9$k!#(B*/
      AutoGL_SetColor (0, 1, 0); 
      AutoGL_DrawLine (0, 0, 0,
		       0, 50, 0);
      
      /* Z$B<4$rIA2h$9$k!#(B*/
      AutoGL_SetColor (0, 0, 1); 
      AutoGL_DrawLine (0, 0, 0,
		       0, 0, 50);
    }
    
    /* $B86E@%i%Y%k$rI=<($9$k!#(B */
    AutoGL_SetColor (1, 1, 1);
    AutoGL_DrawString (0, 0, 0, OriginLabel); 
  }
  
  /* $B7A$N%?%$%W$K1~$8$F(B, */
  switch (Shape) {
  case SHAPE_LINE:
    if (taskId == 1) {

      /* $BD>J}BN$N#1#2K\$NNG@~$r@~J,$H$7$FIA2h$9$k!#(B */
      AutoGL_SetColor (1, 1, 1);
      AutoGL_DrawLine (0, 0, 0,
		       10, 0, 0);
      AutoGL_DrawLine (10, 0, 0,
		       10, 20, 0);
      AutoGL_DrawLine (10, 20, 0,
		       0, 20, 0);
      AutoGL_DrawLine (0, 20, 0,
		       0, 0, 0);
      AutoGL_DrawLine (0, 0, 30,
		       10, 0, 30);
      AutoGL_DrawLine (10, 0, 30,
		       10, 20, 30);
      AutoGL_DrawLine (10, 20, 30,
		       0, 20, 30);
      AutoGL_DrawLine (0, 20, 30,
		       0, 0, 30);
      AutoGL_DrawLine (0, 0, 0,
		       0, 0, 30);
      AutoGL_DrawLine (0, 20, 0,
		       0, 20, 30);
      AutoGL_DrawLine (10, 20, 0,
		       10, 20, 30);
      AutoGL_DrawLine (10, 0, 0,
		       10, 0, 30);
    }
    break;

  case SHAPE_TRIANGLE:
    if (taskId == 2) {

      /* $B86E@$rDL$k#3Kg$N;03Q7A$rIA2h$9$k!#(B */
      AutoGL_SetColor (1, 1, 1);
      AutoGL_DrawTriangle (0, 0, 0,
			   0, 20, 0,
			   0, 0, 30);
      AutoGL_DrawTriangle (10, 0, 0,
			   0, 0, 0, 
			   0, 0, 30);
      AutoGL_DrawTriangle (10, 0, 0,
			   0, 20, 0, 
			   0, 0, 0);
    }
    break;

  case SHAPE_BOX:
    if (taskId == 3) {

      /* $BD>J}BN(B(0, 0, 0) -$B!J(B10, 20, 30)$B$N(B6$BKg$NLL!J;MJU7A!K$rIA2h$9$k!#(B */
      AutoGL_SetColor (0, 1, 1);
      AutoGL_DrawQuadrangle (0, 0, 0,
			     10, 0, 0,
			     10, 20, 0,
			     0, 20, 0);
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
    break;
  }

  if (taskId == 0) {

    /* $B0LCV(B(10, 20, 30)$B$K@0?tJQ?t(BNumber$B$NCM$rI=<($9$k!#(B */
    char buf[256];

    sprintf (buf, "Number:%d", Number);
    AutoGL_SetColor (1, 1, 1);
    AutoGL_DrawString (10, 20, 30,
		       buf);

  }

  if (taskId == 0) {

    /* $B2hLL$N:82<6y$K<B?tJQ?t(BValue$B$NCM$rI=<($9$k!#(B */
    int widthDc, heightDc;
    int dx, dy;
    double x, y, z;
    char buf[256];

    /* $B2hLL$NI}$H9b$5$rF@$k!#(B */
    AutoGL_GetViewRangeDc (&widthDc, &heightDc);

    /* $B2hLL:82<$+$i(B50, 50$B$NE@$N%G%P%$%9:BI8$r7W;;$9$k!#(B */
    dx = -widthDc / 2 + 50;
    dy = -heightDc / 2 + 50;

    /* $B%G%P%$%9:BI8$r@$3&:BI8!J%b%G%k:BI8!K$KJQ49$9$k!#(B */
    AutoGL_GetPositionOfDc (&x, &y, &z,
			    dx, dy, 0);

    sprintf (buf, "Value = %f", Value);
    AutoGL_SetColor (0, 0, 1);
    AutoGL_DrawString (x, y, z,
		       buf);
  }
}

/* $BIA2h%"%C%W%G!<%H%3%^%s%I$N$?$a$N%3!<%k%P%C%/4X?t(B */
/* "Draw"$B%\%?%s$rA*$V$H8F$P$l$k!#(B */
static void Draw (void) 
{
  /* $B%S%e!<$r:FIA2h$9$k!#(B */
  AutoGL_DrawView ();
  /* $BEPO?$5$l$?%S%e!<$N:FIA2h4X?t!J$3$N>l9g$O(BRedrawView ()$B!K$,8F$P$l$k!#(B */
}



/* $B4X?t(BAutoGL_SetUp$B$O%f!<%6!<B&%W%m%0%i%`$4$H$KI,$:0l$DMQ0U$9$k$3$H!#(B*/
/* $B$3$N4X?t$O%W%m%0%i%`5/F0D>8e$K(BAutoGL$B%i%$%V%i%j$+$i8F$S=P$5$l$k!#(B*/
/* $B$3$N$H$-!"(Bargc, argv$B$O(Bmain$B4X?t$+$iD>@\EO$5$l$k!#(B*/
/* $B$3$3$G!"%3!<%k%P%C%/4X?t$d@)8fJQ?t$J$I$rEPO?$9$k!#(B*/
void AutoGL_SetUp (int argc, char *argv[]) 
{
  /* $B%S%e!<$*$h$S%Q%M%k#1$D$NNc(B */



  /* $B%b%G%kMQJQ?t$r=i4|2=$9$k!#(B */
  strcpy (OriginLabel, "Hello, world !");
  AxisIsShown = 1;
  Shape = SHAPE_BOX;
  Number = 20;
  Value = 0.5;

  

  /* $B%S%e!<$r=`Hw$9$k!#(B */

  /* $B%S%e!<%$%s%0%Q%i%a!<%?!J%5%$%:(B,$B;k@~J}8~$J$I!K$r@_Dj$9$k!#(B */
  AutoGL_SetViewSize (70);            /* $B%S%e!<$NBg$-$5(B */
  AutoGL_SetViewCenter (10, 10, 10);       /* $BCm;kE@(B */
  AutoGL_SetViewDirection (3, 1, 2);       /* $B;k@~J}8~(B */
  
  AutoGL_SetViewRedrawCallback (RedrawView);
  /* $B:FIA2h%3!<%k%P%C%/4X?t$H$7$F>e$K$"$k(BRedrawView ()$B$r;XDj!#(B */

  /* $B$*$^$8$J$$(B */
  AutoGL_SetDefaultCallbackInMode3D (NULL);
#if 0
  AutoGL_EnableDragInMode3D ();              /* $B%I%i%C%0M-8z(B */
#endif



  /* $B%Q%M%k$r=`Hw$9$k!#(B */
  /* $B@)8fJQ?t$H%3!<%k%P%C%/4X?t$rEPO?$9$k!#(B */

  /* $B$*$^$8$J$$(B */
  AutoGL_SetPanelInMode3D ();                /* $B0\F02sE>3HBg=L>.$J$I(B */
#if 0
  AutoGL_SetPanelForInterpreter ();          /* $B%3%^%s%I%i%$%s=hM}(B */
#endif

  /* $B%3%a%s%H$NEPO?(B : $B%i%Y%k(B */
  AutoGL_AddComment ();
  AutoGL_SetLabel ("Model Parameters");

  /* $BJ8;zNsJQ?t$NEPO?(B : $B%F%-%9%HF~NO(B */
  /* $B%U%#!<%k%I(B OriginLabel */
  AutoGL_AddString (OriginLabel, "OriginLabel", 80);
  /* char$BG[Ns!"@)8fJQ?tL>!"G[Ns$ND9$5(B */

  /* $B@0?tJQ?t$NEPO?(B : $B%F%-%9%HF~NO(B */
  /* $B%U%#!<%k%I(B Number */
  AutoGL_AddInteger (&Number, "Number");
  /* int$B7?JQ?t$N%]%$%s%?$H@)8fJQ?tL>(B */

  /* $B<B?tJQ?t$NEPO?(B : $B%F%-%9%HF~NO(B */
  /* $B%U%#!<%k%I(B Value */
  AutoGL_AddReal (&Value, "Value");
  /* double$B7?JQ?t$N%]%$%s%?$H@)8fJQ?tL>(B */

  /* $BO@M}JQ?t$NEPO?(B : $B%H%0%kF~NO(B */
  /* $B%H%0%k(B show axis */
  AutoGL_AddBoolean (&AxisIsShown, "AxisIsShown"); 
  /* int$B7?JQ?t$N%]%$%s%?$H@)8fJQ?tL>(B */
  /* AxisIsShown$B$O(B0$B$^$?$O(B1$B$NCM$r<h$k!#(B */
  AutoGL_SetLabel ("show axis"); 
  /* $B%i%Y%k$r;XDj$7$F$b$h$$!#(B */
  /* $B%G%U%)%k%H$G$O@)8fJQ?tL>$,%i%Y%k$H$7$F;HMQ$5$l$k!#(B */

  /* $B@0?tJQ?t$NEPO?(B : $B%i%8%*%\%?%sF~NO(B */
  /* $B%A%g%$%9(B Shape */
  AutoGL_AddInteger (&Shape, "Shape");  /* int$B7?JQ?t(B */
  /* int$B7?JQ?t$N%]%$%s%?$H@)8fJQ?tL>(B */
  /* Shape$B$O(B0$B$+$i(B2$B$^$G$NCM$r<h$k!#(B */
  AutoGL_AddIntegerItem ("line");       /* $BCM(B0$B$N%"%$%F%`(B */
  AutoGL_AddIntegerItem ("triangle");   /* $BCM(B1$B$N%"%$%F%`(B */
  AutoGL_AddIntegerItem ("box");        /* $BCM(B2$B$N%"%$%F%`(B */

  /* $B%3!<%k%P%C%/4X?t$NEPO?(B : $B%\%?%s(B */
  /* $BIA2h%"%C%W%G!<%H%\%?%s(B Draw */
  AutoGL_AddCallback (Draw, "Draw");      
  /* $B4X?t$X$N%]%$%s%?$H%3!<%k%P%C%/4X?tL>(B */
  /* $B%3!<%k%P%C%/4X?t$H$7$F>e$K$"$k(BDraw ()$B$r;XDj!#(B */

  /* $B%3!<%k%P%C%/4X?t$NEPO?(B : $B%\%?%s(B */
  /* $B0u:~%\%?%s(B Print */
  AutoGL_AddCallback (Print, "Print");  
  /* $B4X?t$X$N%]%$%s%?$H%3!<%k%P%C%/4X?tL>(B */
  /* $B%3!<%k%P%C%/4X?t$H$7$F>e$K$"$k(BPrint ()$B$r;XDj!#(B */
}






