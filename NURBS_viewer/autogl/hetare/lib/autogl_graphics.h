/* AutoGL */

#ifndef __AUTOGL_GRAPHICS__
#define __AUTOGL_GRAPHICS__



/* $B%l%s%@%j%s%0(B */

/* $B%S%e!<$NGX7J?'$r@_Dj$9$k!#(B */
void AutoGL_SetBackgroundColor 
(double red, double green, double blue);  
/* red, green, blue : $B@V!"NP!"@D$K$D$$$F!"$=$l$>$l(B0.0 - 1.0$B$N%l%s%8$N6/EY!#(B */

/* $B8=:_$N?'$r@_Dj$9$k!#(B */
void AutoGL_SetColor 
(double red, double green, double blue);  
/* red, green, blue : $B@V!"NP!"@D$K$D$$$F!"$=$l$>$l(B0.0 - 1.0$B$N%l%s%8$N6/EY!#(B */

/* $B@~J,$r8=:_$N?'$GIA2h$9$k!#(B*/
void AutoGL_DrawLine 
(double x0, double y0, double z0,    
 double x1, double y1, double z1); 
/* (x0, y0, z0), (x1, y1, z1) : $BFsE@$N@$3&:BI8(B */

/* $B;03Q7A$r8=:_$N?'$GEI$jDY$9!#(B */
void AutoGL_DrawTriangle 
(double x0, double y0, double z0,  
 double x1, double y1, double z1,  
 double x2, double y2, double z2); 
/* (x0, y0, z0), (x1, y1, z1), (x2, y2, z2) : $B;0E@$N@$3&:BI8(B */

/* $B;03Q7A$r?'Jd4V$K$h$jEI$jDY$9!#(B */
void AutoGL_DrawColorInterpolatedTriangle 
(double x0, double y0, double z0, double red0, double green0, double blue0,  
 double x1, double y1, double z1, double red1, double green1, double blue1,  
 double x2, double y2, double z2, double red2, double green2, double blue2); 
/* (x0, y0, z0), (x1, y1, z1), (x2, y2, z2) : $B;0E@$N@$3&:BI8(B */
/* (red0, green0, blue0), (red1, green1, blue1), (red2, green2, blue2) : $B;0E@$N?'(B */

/* $B;MJU7A$r8=:_$N?'$GEI$jDY$9!#(B */
void AutoGL_DrawQuadrangle 
(double x0, double y0, double z0,
 double x1, double y1, double z1,
 double x2, double y2, double z2,
 double x3, double y3, double z3);
/* (x0, y0, z0), (x1, y1, z1), (x2, y2, z2), (x3, y3, z3) : $B;ME@$N@$3&:BI8(B */
/* $B;ME@$OF10lJ?LL>e$K$J$/$F$b$h$$!#(B */

/* $BJ8;zNs$r8=:_$N?'$GIA2h$9$k!#(B */
void AutoGL_DrawString 
(double x, double y, double z,
 const char *str);
/* (x, y, z) : $BJ8;zNs$N86E@$N@$3&:BI8(B */
/* str : $BIA2h$5$l$kJ8;zNs(B */




/* $B%S%e!<%$%s%0%Q%i%a!<%?$H:BI8JQ49(B */

/* $B@$3&:BI87O(B : $B%b%G%k$,CV$+$l$F$$$k:BI87O!#(B */
/*   $B;0<!85$N<B?t:BI87O!#(B*/

/* $B;kE@:BI87O(B : $B@$3&:BI87O$,;kLnJQ49$5$l$?$b$N!#(B */
/*   $B;0<!85$N<B?t:BI87O!#(B*/
/*   $B2hLL$NCf?4$,(B(0, 0, 0)$B$KBP1~$9$k!#(B*/
/*   $B1&J}8~$,(BX$BJ}8~(B, $B>e$,(BY$BJ}8~(B, $B1|9T$-$N<jA0B&$K(BZ$BJ}8~!#(B*/

/* $B%G%P%$%9:BI87O(B : $B;kE@:BI87O$,<B:]$N2hLL%5%$%:$K%9%1!<%k$5$l$?$b$N!#;0<!85!#(B*/
/*   $B;0<!85$N@0?t:BI87O!#(B*/
/*   $B2hLL$NCf?4$,(B(0, 0, 0)$B$KBP1~$9$k!#(B*/
/*   $B1&J}8~$,(BX$BJ}8~(B, $B>e$,(BY$BJ}8~(B, $B1|9T$-$N<jA0B&$K(BZ$BJ}8~!#(B*/
/*   X Window System$B$d(BWindows$B$N%G%P%$%9:BI87O$H$O0[$J$k$3$H$KCm0U!*!*!*(B */

/* $B%S%e!<$N%5%$%:$r@_Dj$9$k!#(B*/
void AutoGL_SetViewSize (double size);
/* size : $B<B:]$N2hLL$NH>J,$NBg$-$5$KBP1~$9$k(B,$B@$3&:BI8$K$*$1$k%S%e!<$N%5%$%:!#(B*/

/* $B%S%e!<$NCm;kE@$r@_Dj$9$k!#(B*/
void AutoGL_SetViewCenter (double x, double y, double z);
/* (x, y, z) : $BCm;kE@$N:BI8(B */

/* $B%S%e!<$N;k@~J}8~$r@_Dj$9$k!#(B */
void AutoGL_SetViewDirection (double x, double y, double z);
/* (x, y, z) : $B;k@~J}8~%Y%/%H%k(B */

/* $B%S%e!<$N;k@~>e8~$-J}8~$r@_Dj$9$k!#(B */
void AutoGL_SetViewUpVector (double x, double y, double z);
/* (x, y, z) : $B;k@~>e8~$-J}8~%Y%/%H%k(B */

/* $B%S%e!<$N%5%$%:$rF@$k!#(B */
double AutoGL_GetViewSize (void);

/* $B%S%e!<$NCm;kE@$rF@$k!#(B */
void AutoGL_GetViewCenter 
(double *x_OUT, double *y_OUT, double *z_OUT);
/* (x_OUT, y_OUT, z_OUT) : $BCm;kE@$N:BI8(B */

/* $B%S%e!<$N;k@~J}8~$rF@$k!#(B */
void AutoGL_GetViewDirection 
(double *x_OUT, double *y_OUT, double *z_OUT);
/* (x_OUT, y_OUT, z_OUT) : $B;k@~J}8~%Y%/%H%k(B */

/* $B%S%e!<$N;k@~>e8~$-J}8~$rF@$k!#(B */
void AutoGL_GetViewUpVector 
(double *x_OUT, double *y_OUT, double *z_OUT);
/* (x_OUT, y_OUT, z_OUT) : $B;k@~>e8~$-J}8~%Y%/%H%k(B */

/* $B%S%e!<$N%G%P%$%9:BI87O$G$N9b$5$HI}$rF@$k!#(B */
void AutoGL_GetViewRangeDc 
(int *widthDc_OUT, int *heightDc_OUT);
/* widthDc_OUT : $B%S%e!<$NI}(B */
/* heightDc_OUT : $B%S%e!<$N9b$5(B */

/* $B%S%e!<$N%G%P%$%9:BI87O$G$N%5%$%:$rF@$k!#(B */
int AutoGL_GetViewSizeDc (void); 

/* $B%G%P%$%9:BI8$+$i;kE@:BI8$rF@$k!#(B */
void AutoGL_GetVcOfDc 
(double *vcX_OUT, double *vcY_OUT, double *vcZ_OUT,
 int dcX, int dcY, int dcZ);
/* (dcX, dcY, dcZ) : $B%G%P%$%9:BI8(B */
/* (vcX_OUT, vcY_OUT, vcZ_OUT) : $B;kE@:BI8(B */

/* $B;kE@:BI8$+$i@$3&:BI8$rF@$k!#(B */
void AutoGL_GetPositionOfVc 
(double *x_OUT, double *y_OUT, double *z_OUT,
 double vcX, double vcY, double vcZ);
/* (vcX, vcY, vcZ) : $B;kE@:BI8(B */
/* (x_OUT, y_OUT, z_OUT) : $B@$3&:BI8(B */

/* $B%G%P%$%9:BI8$+$i@$3&:BI8$rF@$k!#(B */
void AutoGL_GetPositionOfDc 
(double *x_OUT, double *y_OUT, double *z_OUT,
 int dcX, int dcY, int dcZ);
/* (dcX, dcY, dcZ) : $B%G%P%$%9:BI8(B */
/* (x_OUT, y_OUT, z_OUT) : $B@$3&:BI8(B */



/* $B%$%Y%s%H=hM}(B */

/* AUTOGL_EVENT_ $B%$%Y%s%H$N%?%$%W(B */
/* $B%]%$%s%?$N%\%?%s$,2!$5$l$?!#(B */
#define AUTOGL_EVENT_POINTING_DEVICE_PRESS 0
/* $B%]%$%s%?$,%I%i%C%0$5$l$?!#(B */
#define AUTOGL_EVENT_POINTING_DEVICE_DRAG 1
/* $B%]%$%s%?$N%\%?%s$,N%$5$l$?!#(B */
#define AUTOGL_EVENT_POINTING_DEVICE_RELEASE 2

/* $B%$%Y%s%H$N%?%$%W$rF@$k!#(B */
int AutoGL_GetViewEvent (void);   /* AUTOGL_EVENT_ */

/* $B%]%$%s%F%#%s%0%G%P%$%9$N0LCV$rF@$k!#(B */
void AutoGL_GetPointingDevicePositionDc 
(int *dcX_OUT, int *dcY_OUT, int *dcZ_OUT);
/* dcX_OUT, dcY_OUT, dcZ_OUT : $B%]%$%s%?$N%G%P%$%9:BI8(B */



#endif  /* __AUTOGL_GRAPHICS__ */



