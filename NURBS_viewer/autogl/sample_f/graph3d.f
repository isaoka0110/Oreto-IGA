c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

      integer CELLS
      parameter (CELLS = 100)
      real*8 grid_values(CELLS + 1, CELLS + 1)
      real*8 z_scale
      integer model_is_rendered
      common grid_values, z_scale, model_is_rendered

      integer i, j
      real*8 scale, x, y

      do i = 1, CELLS + 1
         do j = 1, CELLS + 1
            scale = 4.0d0 / CELLS
            x = (i - 1 - CELLS / 2) * scale
            y = (j - 1 - CELLS / 2) * scale
            grid_values(i, j) = sin(x * 3.1415) + y * y
         enddo
      enddo

      z_scale = 5.0d0
      model_is_rendered = 0

c     $B%S%e!<$NBg$-$5(B 
      call autogl_set_view_size(60.0d0)

c     $B$*$^$8$J$$(B 
      call autogl_set_default_callback_in_mode3d()
      call autogl_set_panel_in_mode3d()
      call autogl_enable_drag_in_mode3d()

c     AutoGL$B$N%a%$%s%k!<%W(B
c     $BFsEY$HLa$i$J$$(B
      call autogl_main()

      end



      subroutine plot_graph3d
      implicit none

      integer CELLS
      parameter (CELLS = 100)
      real*8 grid_values(CELLS + 1, CELLS + 1)
      real*8 z_scale
      integer model_is_rendered
      common grid_values, z_scale, model_is_rendered

      real*8 cell_size
      integer i, j
      real*8 x00, y00, value00
      real*8 x10, y10, value10
      real*8 x11, y11, value11
      real*8 x01, y01, value01

      cell_size = 60.0d0 / CELLS

      call autogl_set_color(1.0d0, 1.0d0, 1.0d0)

      do i = 1, CELLS
         do j = 1, CELLS
            x00 = (i - 1 - CELLS / 2) * cell_size
            y00 = (j - 1 - CELLS / 2) * cell_size
            value00 = grid_values(i + 0, j + 0)
            
            x10 = x00 + cell_size
            y10 = y00
            value10 = grid_values(i + 1, j + 0)
            
            x11 = x00 + cell_size
            y11 = y00 + cell_size
            value11 = grid_values(i + 1, j + 1)
            
            x01 = x00
            y01 = y00 + cell_size
            value01 = grid_values(i + 0, j + 1)
            
            call autogl_draw_triangle(
     c           x00, y00, value00 * z_scale,
     c           x10, y10, value10 * z_scale,
     c           x11, y11, value11 * z_scale)
            call autogl_draw_triangle(
     c           x11, y11, value11 * z_scale,
     c           x01, y01, value01 * z_scale,
     c           x00, y00, value00 * z_scale)
         enddo
      enddo

      end



c     $B%5%V%k!<%A%s(Bautogl_redraw
c     $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B */
c     $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
      subroutine autogl_redraw
      implicit none

      integer CELLS
      parameter (CELLS = 100)
      real*8 grid_values(CELLS + 1, CELLS + 1)
      real*8 z_scale
      integer model_is_rendered
      common grid_values, z_scale, model_is_rendered

c     $B$^$:!"0lEY$@$1%b%G%k$r%G%#%9%W%l%$%j%9%H$XIA2h$7$F$*$/!#(B 
      if (model_is_rendered .eq. 0) then

c     $B%G%#%9%W%l%$%j%9%H$r3+$-!"$3$l$r6u$K$9$k!#(B 
         call autogl_open_display_list()

         call plot_graph3d()

c     $B%G%#%9%W%l%$%j%9%H$rJD$8$k!#(B 
         call autogl_close_display_list()

         model_is_rendered = 1
      endif

c     $B6@LLH?<M$r%*%s$K$9$k!#(B
      call autogl_turn_on_specular()

c     $B2hLL:82<$K;0<!85:BI87O$rIA2h$9$k!#(B 
      call autogl_draw_coordinate_system3d(20)

c     $B%G%#%9%W%l%$%j%9%H$KF~$l$?IA2hL?Na$r<B:]$KIA2h$9$k!#(B 
      call autogl_draw_display_list()

      end



      subroutine autogl_handle_event
      end

      subroutine autogl_idle
      end

      subroutine autogl_callback(id)
      implicit none
      integer id
      end
