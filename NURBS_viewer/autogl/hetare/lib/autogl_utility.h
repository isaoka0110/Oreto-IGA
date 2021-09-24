/* AutoGL */

#ifndef __AUTOGL_UTILITY__
#define __AUTOGL_UTILITY__

/* $B%f!<%F%#%j%F%#(B */



/* $BIA2h%W%j%_%F%#%V(B */

/* $B%3%s%?(B-$B$NCM$KBP1~$9$k?'$rF@$k!#(B */
void AutoGL_GetContourColor 
(double *red_OUT, double *green_OUT, double *blue_OUT,
 double grade);
/* red_OUT, green_OUT, blue_OUT : $B@V!"NP!"@D$K$D$$$F!"$=$l$>$l(B0.0 - 1.0$B$N%l%s%8$N6/EY!#(B */
/* grade : 0.0 - 1.0$B$K5,3J2=$5$l$?CM!#(B */

/* $B;03Q7A$r%3%s%?(B-$B$GEI$jDY$9!#(B */
void AutoGL_DrawContourTriangle 
(double x0, double y0, double z0, double grade0,  
 double x1, double y1, double z1, double grade1,  
 double x2, double y2, double z2, double grade2); 
/* (x0, y0, z0), (x1, y1, z1), (x2, y2, z2) : $B;0E@$N@$3&:BI8(B */
/* grade0, grade1, grade2 : $B;0E@$N%9%+%i!<CM!J(B0.0 - 1.0$B$K5,3J2=!K(B */



/* $B;0<!85%S%e!<%$%s%0%Q%i%a!<%?A`:n(B */

/* $B%S%e!<%$%s%0%Q%i%a!<%?@_Dj5!G=$r%Q%M%k$K=`Hw$9$k!#(B */
void AutoGL_SetPanelInView3D (void);

/* $B%S%e!<$rAjBPE*$K2sE>$9$k!#(B */
void AutoGL_RotateView 
(double offsetX, double offsetY, double offsetZ);
/* offsetX, offsetY, offsetZ     around -1.0 ... 1.0 */



/* $B;0<!85%$%Y%s%H=hM}(B */

/*  AUTOGL_MODE_3D_  */
/* $B%f!<%6!<Dj5A%$%Y%s%H=hM}%b!<%I(B */
#define AUTOGL_MODE_3D_OTHER 0
/* $B0\F0%b!<%I(B */
#define AUTOGL_MODE_3D_TRANSLATE 1
/* $B2sE>%b!<%I!J(BXY$B<4$^$o$j!K(B */
#define AUTOGL_MODE_3D_ROTATE_XY 2
/* $B2sE>%b!<%I!J(BZ$B<4$^$o$j!K(B */
#define AUTOGL_MODE_3D_ROTATE_Z 3
/* $B3HBg=L>.%b!<%I(B */
#define AUTOGL_MODE_3D_SCALE 4

/* $B0\F02sE>3HBg=L>.5!G=$r%Q%M%k$K=`Hw$9$k!#(B */
void AutoGL_SetPanelInMode3D (void);

/* $B%$%Y%s%H=hM}%b!<%I$r@_Dj$9$k!#(B */
void AutoGL_SetMode3D (int mode);    /*  AUTOGL_MODE_3D_  */

/* $B%$%Y%s%H=hM}%b!<%I$r@_Dj$9$k!#(B */
void AutoGL_SetDefaultCallbackInMode3D 
(AutoGL_CallbackType otherCallback);
/* otherCallback : $B%f!<%6!<Dj5A%$%Y%s%H=hM}%3!<%k%P%C%/(B */
/* $B$3$l$O(BNULL$B$G$b$h$$!#(B */

/* $B%I%i%C%0Cf$KIA2h$r9T$&!#(B */
void AutoGL_EnableDragInMode3D (void);

/* $B%$%Y%s%H=hM}%b!<%I$rF@$k!#(B */
int AutoGL_GetMode3D (void);    /*  AUTOGL_MODE_3D_  */

/* $B%]%$%s%F%#%s%0%G%P%$%9$,%R%C%H$7$?$+$rD4$Y$k!#(B */
int AutoGL_PointingDeviceIsHit3D 
(double *parameter_OUT,
 double pX, double pY, double pZ,
 int toleranceDc);
/* parameter_OUT : $B?<$5>pJs(B */
/* (pX, pY, pZ) : $B@$3&:BI8(B */
/* toleranceDc : $B%G%P%$%9:BI87O$G$NI}(B */



#endif  /* __AUTOGL_UTILITY__ */



