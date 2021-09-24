c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

c     $B%S%e!<%$%s%0%Q%i%a!<%?!J%5%$%:(B,$B;k@~J}8~$J$I!K$r@_Dj$9$k!#(B
c     $B%S%e!<$NBg$-$5(B 
      call autogl_set_view_size(70.0d0)
c     $BCm;kE@(B 
      call autogl_set_view_center(10.0d0, 10.0d0, 10.0d0)
c     $B;k@~J}8~(B 
      call autogl_set_view_direction(1.0d0, 2.0d0, 3.0d0)

c     $B$*$^$8$J$$(B 
      call autogl_set_default_callback_in_mode3d()
      call autogl_set_panel_in_mode3d()
      call autogl_enable_drag_in_mode3d()

c     AutoGL$B$N%a%$%s%k!<%W(B
c     $BFsEY$HLa$i$J$$(B
      call autogl_main()

      end



c     $B%5%V%k!<%A%s(Bautogl_redraw
c     $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B */
c     $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
      subroutine autogl_redraw
      implicit none

      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 

c     $B86E@%i%Y%k$rI=<($9$k!#(B
      call autogl_draw_string(0.0d0, 0.0d0, 0.0d0, 'O')

c     X$B<4$rIA2h$9$k!#(B
      call autogl_draw_line(
     c     0.0d0, 0.0d0, 0.0d0,
     c     50.0d0, 0.0d0, 0.0d0)
      call autogl_draw_string(50.0d0, 0.0d0, 0.0d0, 'X')

c     Y$B<4$rIA2h$9$k!#(B
      call autogl_draw_line(
     c     0.0d0, 0.0d0, 0.0d0,
     c     0.0d0, 50.0d0, 0.0d0)
      call autogl_draw_string(0.0d0, 50.0d0, 0.0d0, 'Y')

c     Z$B<4$rIA2h$9$k!#(B
      call autogl_draw_line(
     c     0.0d0, 0.0d0, 0.0d0,
     c     0.0d0, 0.0d0, 50.0d0)
      call autogl_draw_string(0.0d0, 0.0d0, 50.0d0, 'Z')

c     $B;03Q7A$rIA2h$9$k!#(B 

      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
c     $B;0E@$r;XDj$7$F;03Q7A(B 
      call autogl_draw_triangle(
     c     -20.0d0, 0.0d0, 0.0d0, 
     c     0.0d0, -20.0d0, 0.0d0, 
     c     0.0d0, 0.0d0, -20.0d0)

c     $BD>J}BN(B(0, 0, 0) -$B!J(B10, 20, 30)$B$N(B6$BKg$NLL!J;MJU7A!K$rIA2h$9$k!#(B

      call autogl_set_color(0.0d0, 1.0d0, 1.0d0) 
c     $B;ME@$r;XDj$7$F;MJU7A(B 
      call autogl_draw_quadrangle(
     c     0.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 0.0d0, 
     c     0.0d0, 20.0d0, 0.0d0)
      call autogl_set_color(1.0d0, 1.0d0, 0.0d0) 
      call autogl_draw_quadrangle(
     c     0.0d0, 0.0d0, 30.0d0, 
     c     10.0d0, 0.0d0, 30.0d0, 
     c     10.0d0, 20.0d0, 30.0d0, 
     c     0.0d0, 20.0d0, 30.0d0)
      call autogl_set_color(1.0d0, 0.0d0, 1.0d0) 
      call autogl_draw_quadrangle(
     c     0.0d0, 0.0d0, 0.0d0, 
     c     0.0d0, 20.0d0, 0.0d0, 
     c     0.0d0, 20.0d0, 30.0d0, 
     c     0.0d0, 0.0d0, 30.0d0)
      call autogl_set_color(0.0d0, 0.0d0, 1.0d0) 
      call autogl_draw_quadrangle(
     c     10.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 30.0d0, 
     c     10.0d0, 0.0d0, 30.0d0)
      call autogl_set_color(0.0d0, 1.0d0, 0.0d0) 
      call autogl_draw_quadrangle(
     c     0.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 0.0d0, 30.0d0, 
     c     0.0d0, 0.0d0, 30.0d0)
      call autogl_set_color(1.0d0, 0.0d0, 0.0d0) 
      call autogl_draw_quadrangle(
     c     0.0d0, 20.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 30.0d0, 
     c     0.0d0, 20.0d0, 30.0d0)

      end



      subroutine autogl_handle_event
      end

      subroutine autogl_idle
      end

      subroutine autogl_callback(id)
      implicit none
      integer id
      end
