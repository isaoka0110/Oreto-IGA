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

c     $BF);kEj1F%b!<%I$K$9$k!#(B
      call autogl_set_perspective_view_flag(1)

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

      real*8 radius
      integer n_divisions
      
      radius = 10.0d0
      n_divisions = 4

c     $B6@LLH?<M$r%*%s$K$9$k!#(B
      call autogl_turn_on_specular

      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
      call autogl_draw_string(0.0d0, 0.0d0, 0.0d0, 'O')
      call autogl_draw_line(
     c     0.0d0, 0.0d0, 0.0d0,
     c     50.0d0, 0.0d0, 0.0d0)
      call autogl_draw_string(50.0d0, 0.0d0, 0.0d0, 'X')
      call autogl_draw_line(
     c     0.0d0, 0.0d0, 0.0d0,
     c     0.0d0, 50.0d0, 0.0d0)
      call autogl_draw_string(0.0d0, 50.0d0, 0.0d0, 'Y')
      call autogl_draw_line(
     c     0.0d0, 0.0d0, 0.0d0,
     c     0.0d0, 0.0d0, 50.0d0)
      call autogl_draw_string(0.0d0, 0.0d0, 50.0d0, 'Z')

c     $B5e$rIA2h$9$k!#(B
      call autogl_set_color(1.0d0, 1.0d0, 0.0d0) 
      call autogl_draw_sphere3d(
     c     10.0d0, 10.0d0, 0.0d0, 
     c     radius, n_divisions)

c     $B1_Cl$rIA2h$9$k!#(B
      call autogl_set_color(0.0d0, 1.0d0, 1.0d0) 
      call autogl_draw_cylinder3d(
     c     -10.0d0, -20.0d0, 30.0d0, 
     c     10.0d0, 20.0d0, 30.0d0, 
     c     radius, n_divisions)

c     $B1_?m$rIA2h$9$k!#(B
      call autogl_set_color(1.0d0, 0.0d0, 1.0d0) 
      call autogl_draw_cone3d(
     c     -10.0d0, -20.0d0, -30.0d0, 
     c     10.0d0, 20.0d0, -30.0d0, 
     c     radius, n_divisions)

c     $B1_$rIA2h$9$k!#(B
      call autogl_set_color(1.0d0, 0.0d0, 0.0d0) 
      call autogl_draw_circle3d(
     c     -10.0d0, -10.0d0, 0.0d0, 
     c     1.0d0, 1.0d0, 0.0d0, 
     c     radius, n_divisions)

      end



      subroutine autogl_handle_event
      end

      subroutine autogl_idle
      end

      subroutine autogl_callback(id)
      implicit none
      integer id
      end
