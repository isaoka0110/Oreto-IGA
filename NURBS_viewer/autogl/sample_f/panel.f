c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

c     $B%S%e!<>e$KI=<($5$l$k%b%G%k$rI=8=$9$k$?$a$NJQ?t72(B 

c     $B86E@$N%i%Y%k(B : $BJ8;zNs(B 
      character*80 origin_label

c     $B:BI8<4$rI=<($9$k$+$I$&$+(B : 0$B$^$?$O(B1$B$N@0?t!JO@M}CM!K(B 
      integer axis_is_shown

c     $B%b%G%k$N7A$N%?%$%W(B : 0 - 2 $B$N@0?t(B (SHAPE_) 
      integer shape

c     $B@0?tJQ?t(B 
      integer number

c     $B<B?tJQ?t(B 
      real*8 value

      common value, origin_label, axis_is_shown, shape, number

c     $B%S%e!<$*$h$S%Q%M%k#1$D$NNc(B 



c     $B%b%G%kMQJQ?t$r=i4|2=$9$k!#(B 
      origin_label = 'hello, world !'
      axis_is_shown = 1
      shape = 2
      number = 20
      value = 0.5d0



c     $B%S%e!<$r=`Hw$9$k!#(B 

c     $B%S%e!<%$%s%0%Q%i%a!<%?!J%5%$%:(B,$B;k@~J}8~$J$I!K$r@_Dj$9$k!#(B
c     $B%S%e!<$NBg$-$5(B 
      call autogl_set_view_size(70.0d0)
c     $BCm;kE@(B 
      call autogl_set_view_center(10.0d0, 10.0d0, 10.0d0)
c     $B;k@~J}8~(B 
      call autogl_set_view_direction(3.0d0, 1.0d0, 2.0d0)

c     $B$*$^$8$J$$(B 
      call autogl_set_default_callback_in_mode3d()
      call autogl_enable_drag_in_mode3d()

c     $B%Q%M%k$r=`Hw$9$k!#(B 
c     $B%\%?%sMQ%5%V%k!<%A%sHV9f$d%3%s%H%m!<%kMQJQ?t$rEPO?$9$k!#(B
      call autogl_set_panel_in_mode3d()

c     $B%3%a%s%H$NEPO?(B : $B%i%Y%k(B 
      call autogl_add_comment()
      call autogl_set_label('Model Parameters')

c     $BJ8;zNsJQ?t$NEPO?(B : $B%F%-%9%HF~NO(B 
c     $B%U%#!<%k%I(B origin_label 
c     ???
c      call autogl_add_string(origin_label, 'origin_label', 80)
c     ???
c     $BJ8;zNs!"JQ?tL>!"J8;zNs$ND9$5(B 

c     $B@0?tJQ?t$NEPO?(B : $B%F%-%9%HF~NO(B 
c     $B%U%#!<%k%I(B number 
      call autogl_add_integer(number, 'number')
c     integer$B7?JQ?t$HJQ?tL>(B 

c     $B<B?tJQ?t$NEPO?(B : $B%F%-%9%HF~NO(B 
c     $B%U%#!<%k%I(B value 
      call autogl_add_real(value, 'value')
c     real*8$B7?JQ?t$HJQ?tL>(B 

c     $BO@M}JQ?t$NEPO?(B : $B%H%0%kF~NO(B 
c     $B%H%0%k(B show axis 
      call autogl_add_boolean(axis_is_shown, 'axis_is_shown')
c     integer$B7?JQ?t$HJQ?tL>(B 
c     axis_is_shown$B$O(B0$B$^$?$O(B1$B$NCM$r<h$k!#(B 
      call autogl_set_label('show axis')
c     $B%i%Y%k$r;XDj$7$F$b$h$$!#(B 
c     $B%G%U%)%k%H$G$OJQ?tL>$,%i%Y%k$H$7$F;HMQ$5$l$k!#(B 

c     $B@0?tJQ?t$NEPO?(B : $B%i%8%*%\%?%sF~NO(B 
c     $B%A%g%$%9(B shape 
      call autogl_add_integer(shape, 'shape')
c     integer$B7?JQ?t$HJQ?tL>(B
c     shape$B$O(B0$B$+$i(B2$B$^$G$NCM$r<h$k!#(B 
c     $BCM(B0$B$N%"%$%F%`(B 
      call autogl_add_integer_item('line')
c     $BCM(B1$B$N%"%$%F%`(B 
      call autogl_add_integer_item('triangle')
c     $BCM(B2$B$N%"%$%F%`(B 
      call autogl_add_integer_item('box')     

c     $B%3!<%k%P%C%/%5%V%k!<%A%s$NEPO?(B : $B%\%?%s(B 
c     $BIA2h%"%C%W%G!<%H%\%?%s(B Draw 
      call autogl_set_button(0, 'Draw')
c     $B%3!<%k%P%C%/%5%V%k!<%A%s$NHV9f$H%\%?%sL>(B
c     $B%5%V%k!<%A%s(Bdraw_button$B$r;XDj(B
      
c     $B%3!<%k%P%C%/%5%V%k!<%A%s$NEPO?(B : $B%\%?%s(B 
c     $B0u:~%\%?%s(B Print 
      call autogl_set_button(1, 'Print')
c     $B%3!<%k%P%C%/%5%V%k!<%A%s$NHV9f$H%\%?%sL>(B
c     $B%5%V%k!<%A%s(Bprint_button$B$r;XDj(B

c     AutoGL$B$N%a%$%s%k!<%W(B
c     $BFsEY$HLa$i$J$$(B
      call autogl_main()

      end



c     $B%5%V%k!<%A%s(Bautogl_redraw
c     $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B 
c     $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B 
      subroutine autogl_redraw
      implicit none

      real*8 value
      character*80 origin_label
      integer axis_is_shown
      integer shape
      integer number
      common value, origin_label, axis_is_shown, shape, number

      character*80 buf

      if (axis_is_shown .eq. 1) then

c     X$B<4$rIA2h$9$k!#(B
         call autogl_set_color(1.0d0, 0.0d0, 0.0d0) 
         call autogl_draw_line(
     c        0.0d0, 0.0d0, 0.0d0,
     c        50.0d0, 0.0d0, 0.0d0)
         
c     Y$B<4$rIA2h$9$k!#(B
         call autogl_set_color(0.0d0, 1.0d0, 0.0d0) 
         call autogl_draw_line(
     c        0.0d0, 0.0d0, 0.0d0,
     c        0.0d0, 50.0d0, 0.0d0)
         
c     Z$B<4$rIA2h$9$k!#(B
         call autogl_set_color(0.0d0, 0.0d0, 1.0d0) 
         call autogl_draw_line(
     c        0.0d0, 0.0d0, 0.0d0,
     c        0.0d0, 0.0d0, 50.0d0)
      endif

c     $B86E@%i%Y%k$rI=<($9$k!#(B 
      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
      call autogl_draw_string(0.0d0, 0.0d0, 0.0d0, origin_label)

c     $B7A$N%?%$%W$K1~$8$F(B, 
      if (shape .eq. 0) then
c     SHAPE_LINE
c     $BD>J}BN$N#1#2K\$NNG@~$r@~J,$H$7$FIA2h$9$k!#(B 
         call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
         call autogl_draw_line(
     c        0.0d0, 0.0d0, 0.0d0,
     c        10.0d0, 0.0d0, 0.0d0)
         call autogl_draw_line(
     c        10.0d0, 0.0d0, 0.0d0,
     c        10.0d0, 20.0d0, 0.0d0)
         call autogl_draw_line(
     c        10.0d0, 20.0d0, 0.0d0,
     c        0.0d0, 20.0d0, 0.0d0)
         call autogl_draw_line(
     c        0.0d0, 20.0d0, 0.0d0,
     c        0.0d0, 0.0d0, 0.0d0)
         call autogl_draw_line(
     c        0.0d0, 0.0d0, 30.0d0,
     c        10.0d0, 0.0d0, 30.0d0)
         call autogl_draw_line(
     c        10.0d0, 0.0d0, 30.0d0,
     c        10.0d0, 20.0d0, 30.0d0)
         call autogl_draw_line(
     c        10.0d0, 20.0d0, 30.0d0,
     c        0.0d0, 20.0d0, 30.0d0)
         call autogl_draw_line(
     c        0.0d0, 20.0d0, 30.0d0,
     c        0.0d0, 0.0d0, 30.0d0)
         call autogl_draw_line(
     c        0.0d0, 0.0d0, 0.0d0,
     c        0.0d0, 0.0d0, 30.0d0)
         call autogl_draw_line(
     c        0.0d0, 20.0d0, 0.0d0,
     c        0.0d0, 20.0d0, 30.0d0)
         call autogl_draw_line(
     c        10.0d0, 20.0d0, 0.0d0,
     c        10.0d0, 20.0d0, 30.0d0)
         call autogl_draw_line(
     c        10.0d0, 0.0d0, 0.0d0,
     c        10.0d0, 0.0d0, 30.0d0)

      elseif (shape .eq. 1) then
c     SHAPE_TRIANGLE
c     $B86E@$rDL$k#3Kg$N;03Q7A$rIA2h$9$k!#(B
         call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
         call autogl_draw_triangle(
     c        0.0d0, 0.0d0, 0.0d0, 
     c        0.0d0, 20.0d0, 0.0d0, 
     c        0.0d0, 0.0d0, 30.0d0)
         call autogl_draw_triangle(
     c        10.0d0, 0.0d0, 0.0d0, 
     c        0.0d0, 0.0d0, 0.0d0, 
     c        0.0d0, 0.0d0, 30.0d0)
         call autogl_draw_triangle(
     c        10.0d0, 0.0d0, 0.0d0, 
     c        0.0d0, 20.0d0, 0.0d0, 
     c        0.0d0, 0.0d0, 0.0d0)

      elseif (shape .eq. 2) then
c     SHAPE_BOX
c     $BD>J}BN(B(0, 0, 0) -$B!J(B10, 20, 30)$B$N(B6$BKg$NLL!J;MJU7A!K$rIA2h$9$k!#(B
         call autogl_set_color(0.0d0, 1.0d0, 1.0d0) 
         call autogl_draw_quadrangle(
     c        0.0d0, 0.0d0, 0.0d0, 
     c        10.0d0, 0.0d0, 0.0d0, 
     c        10.0d0, 20.0d0, 0.0d0, 
     c        0.0d0, 20.0d0, 0.0d0)
         call autogl_draw_quadrangle(
     c        0.0d0, 0.0d0, 30.0d0, 
     c        10.0d0, 0.0d0, 30.0d0, 
     c        10.0d0, 20.0d0, 30.0d0, 
     c        0.0d0, 20.0d0, 30.0d0)
         call autogl_draw_quadrangle(
     c        0.0d0, 0.0d0, 0.0d0, 
     c        0.0d0, 20.0d0, 0.0d0, 
     c        0.0d0, 20.0d0, 30.0d0, 
     c        0.0d0, 0.0d0, 30.0d0)
         call autogl_draw_quadrangle(
     c        10.0d0, 0.0d0, 0.0d0, 
     c        10.0d0, 20.0d0, 0.0d0, 
     c        10.0d0, 20.0d0, 30.0d0, 
     c        10.0d0, 0.0d0, 30.0d0)
         call autogl_draw_quadrangle(
     c        0.0d0, 0.0d0, 0.0d0, 
     c        10.0d0, 0.0d0, 0.0d0, 
     c        10.0d0, 0.0d0, 30.0d0, 
     c        0.0d0, 0.0d0, 30.0d0)
         call autogl_draw_quadrangle(
     c        0.0d0, 20.0d0, 0.0d0, 
     c        10.0d0, 20.0d0, 0.0d0, 
     c        10.0d0, 20.0d0, 30.0d0, 
     c        0.0d0, 20.0d0, 30.0d0)

      endif

c     $B0LCV(B(10, 20, 30)$B$K@0?tJQ?t(Bnumber$B$NCM$rI=<($9$k!#(B 
      write(buf,*) 'number:', number
      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
      call autogl_draw_string(10.0d0, 20.0d0, 30.0d0, buf)

c     $B2hLL$N:82<6y$+$iHfN($G(B(0.1, 0.1)$B$N>l=j$K<B?tJQ?t(Bvalue$B$NCM$rI=<($9$k!#(B 
      write(buf,*) 'value = ', value
      call autogl_set_color(0.0d0, 0.0d0, 1.0d0) 
      call autogl_draw_string_at_scaled_position(0.1d0, 0.1d0, buf)

      end



c     $BIA2h%"%C%W%G!<%H%3%^%s%I$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B
c     "Draw"$B%\%?%s$rA*$V$H8F$P$l$k!#(B 
      subroutine draw_button
      implicit none

c     $B%S%e!<$r:FIA2h$9$k!#(B 
      call autogl_draw_view()

      end



c     $B0u:~%3%^%s%I$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B
c     "Print"$B%\%?%s$rA*$V$H8F$P$l$k!#(B 
      subroutine print_button
      implicit none

      real*8 value
      character*80 origin_label
      integer axis_is_shown
      integer shape
      integer number
      common value, origin_label, axis_is_shown, shape, number

      write(*,*) 'PRINT'

c     $B8=:_$N86E@%i%Y%k$rI=<($9$k!#(B 
      write(*,*) ' origin_label is ', origin_label

c     $B8=:_:BI8<4$,I=<($5$l$F$$$k$+$I$&$+$rI=<($9$k!#(B 
      write(*,*) ' axis_is_shown is ', axis_is_shown

c     $B8=:_$N%b%G%k$N7A$N%?%$%W$rI=<($9$k!#(B 
      if (shape .eq. 0) then
         write(*,*) ' shape is SHAPE_LINE (0)'
      elseif (shape .eq. 1) then
         write(*,*) ' shape is SHAPE_TRIANGLE (1)'
      elseif (shape .eq. 2) then
         write(*,*) ' shape is SHAPE_BOX (2)'
      endif

c     $B@0?tJQ?t(Bnumber$B$NCM$rI=<($9$k!#(B 
      write(*,*) ' number is ', number

c     $B<B?tJQ?t(Bvalue$B$NCM$rI=<($9$k!#(B 
      write(*,*) ' value is ', value

      end



c     $B%3!<%k%P%C%/%5%V%k!<%A%s(B
      subroutine autogl_callback(id)
      implicit none

      integer id

      if (id .eq. 0) then
         call draw_button()
      elseif (id .eq. 1) then
         call print_button()
      endif

      end



      subroutine autogl_handle_event
      end

      subroutine autogl_idle
      end

