c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

c     $B3J;R$NJ,3d?t(B 
      integer CELLS
      parameter (CELLS = 100)

c     $B3J;R>e$N%9%+%i!<CM(B 
      real*8 grid_values(CELLS + 1, CELLS + 1)
      common/value/ grid_values

      real*8 min_range, max_range
      real*8 z_scale
      integer n_grades, contour_type
      common/parameter/ min_range, max_range, z_scale,
     c     contour_type, n_grades

      integer grid_is_shown, contour_is_shown, graph3d_is_shown
      common/flag/ grid_is_shown, contour_is_shown, graph3d_is_shown

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

c     $B%3%s%?(B-$B$N:GBg!&:G>.CM!"%0%l!<%I?t!"I=<(7A<0$N<oN`(B
      min_range = -1.0d0
      max_range = 5.0d0
      n_grades = 20
      contour_type = 0

c     $B;0<!85%0%i%U$N(BZ$BJ}8~$N3HBgN((B 
      z_scale = 5.0d0

c     $B3J;R$rI=<($9$k$+(B 
      grid_is_shown = 0

c     $B%3%s%?(B-$B$rI=<($9$k$+(B 
      contour_is_shown = 0

c     $B;0<!85%0%i%U$rI=<($9$k$+(B 
      graph3d_is_shown = 0
   


c     $B%S%e!<$r=`Hw$9$k!#(B 

c     $B%S%e!<$NGX7J?'(B 
      call autogl_set_background_color(0.7d0, 0.7d0, 0.7d0)
c     $B%S%e!<$NBg$-$5(B 
      call autogl_set_view_size(80.0d0)

c     $B$*$^$8$J$$(B 
      call autogl_set_default_callback_in_mode3d()
      call autogl_enable_drag_in_mode3d()

c     $B%Q%M%k$r=`Hw$9$k!#(B 
c     $B%\%?%sMQ%5%V%k!<%A%sHV9f$d%3%s%H%m!<%kMQJQ?t$rEPO?$9$k!#(B
      call autogl_add_group('model')
      call autogl_set_panel_in_mode3d()

c     $B%3%a%s%H$NEPO?(B : $B%i%Y%k(B 
      call autogl_add_comment()
      call autogl_set_label('Model Parameters')

c     $B3J;R(B 
      call autogl_add_boolean(grid_is_shown, 'grid_is_shown')
      call autogl_set_label('grid')

c     $B%3%s%?(B- 
      call autogl_add_boolean(contour_is_shown, 'contour_is_shown')
      call autogl_set_label('contour')
      call autogl_add_integer(contour_type, 'contour_type')
      call autogl_set_label('type')
      call autogl_add_integer_item('smooth')
      call autogl_add_integer_item('line')
      call autogl_add_integer_item('band')
      call autogl_add_real(min_range, 'min_range')
      call autogl_set_label('min')
      call autogl_add_real(max_range, 'max_range')
      call autogl_set_label('max')
      call autogl_add_integer(n_grades, 'n_grades')
      call autogl_set_label('num. grades')

c     $B;0<!85%0%i%U(B 
      call autogl_add_boolean(graph3d_is_shown, 'graph3d_is_shown')
      call autogl_set_label('3-D graph')
      call autogl_add_real(z_scale, 'z_scale')

      call autogl_set_button(0, 'UpdateModel')

c     AutoGL$B$N%a%$%s%k!<%W(B
c     $BFsEY$HLa$i$J$$(B
      call autogl_main()

      end



c     $B3J;R$rIA2h$9$k!#(B 
      subroutine draw_grid
      implicit none

      integer CELLS
      parameter (CELLS = 100)

      real*8 grid_values(CELLS + 1, CELLS + 1)
      common/value/ grid_values

      real*8 min_range, max_range
      real*8 z_scale
      integer n_grades, contour_type
      common/parameter/ min_range, max_range, z_scale,
     c     contour_type, n_grades

      real*8 cell_size
      integer i, j
      real*8 x00, y00
      real*8 x10, y10
      real*8 x11, y11
      real*8 x01, y01

      cell_size = 60.0d0 / CELLS

      call autogl_set_color(1.0d0, 1.0d0, 1.0d0)

      do i = 1, CELLS
         do j = 1, CELLS
            x00 = (i - 1 - CELLS / 2) * cell_size
            y00 = (j - 1 - CELLS / 2) * cell_size

            x10 = x00 + cell_size
            y10 = y00

            x11 = x00 + cell_size
            y11 = y00 + cell_size

            x01 = x00
            y01 = y00 + cell_size

            call autogl_draw_line(
     c           x00, y00, 0.0d0,
     c           x10, y10, 0.0d0)
            call autogl_draw_line(
     c           x10, y10, 0.0d0,
     c           x11, y11, 0.0d0)
            call autogl_draw_line(
     c           x11, y11, 0.0d0,
     c           x01, y01, 0.0d0)
            call autogl_draw_line(
     c           x01, y01, 0.0d0,
     c           x00, y00, 0.0d0)
         enddo
      enddo

      end



c     $B%3%s%?(B-$B$rIA2h$9$k!#(B 
      subroutine draw_contour
      implicit none

      integer CELLS
      parameter (CELLS = 100)

      real*8 grid_values(CELLS + 1, CELLS + 1)
      common/value/ grid_values

      real*8 min_range, max_range
      real*8 z_scale
      integer n_grades, contour_type
      common/parameter/ min_range, max_range, z_scale,
     c     contour_type, n_grades

      real*8 cell_size
      integer i, j
      real*8 x00, y00, value00
      real*8 x10, y10, value10
      real*8 x11, y11, value11
      real*8 x01, y01, value01

      cell_size = 60.0d0 / CELLS

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

            if (contour_type .eq. 0) then
c     $B%9%`!<%:%3%s%?(B-$B$D$-$N;MJU7A$rI=<($9$k!#(B 
               call autogl_draw_smooth_contour_quadrangle(
     c              min_range, max_range,
     c              x00, y00, 0.0d0, value00,
     c              x10, y10, 0.0d0, value10,
     c              x11, y11, 0.0d0, value11,
     c              x01, y01, 0.0d0, value01)
            else if (contour_type .eq. 1) then
c     $B@~%3%s%?(B-$B$D$-$N;MJU7A$rI=<($9$k!#(B 
               call autogl_draw_line_contour_quadrangle(
     c              min_range, max_range, n_grades,
     c              x00, y00, 0.0d0, value00,
     c              x10, y10, 0.0d0, value10,
     c              x11, y11, 0.0d0, value11,
     c              x01, y01, 0.0d0, value01)
            else if (contour_type .eq. 2) then
c     $B%P%s%I%3%s%?(B-$B$D$-$N;MJU7A$rI=<($9$k!#(B 
               call autogl_draw_band_contour_quadrangle(
     c              min_range, max_range, n_grades,
     c              x00, y00, 0.0d0, value00,
     c              x10, y10, 0.0d0, value10,
     c              x11, y11, 0.0d0, value11,
     c              x01, y01, 0.0d0, value01)
            endif
         enddo
      enddo

      end



c     $B;0<!85%0%i%U$rIA2h$9$k!#(B 
      subroutine draw_graph3d
      implicit none

      integer CELLS
      parameter (CELLS = 100)

      real*8 grid_values(CELLS + 1, CELLS + 1)
      common/value/ grid_values

      real*8 min_range, max_range
      real*8 z_scale
      integer n_grades, contour_type
      common/parameter/ min_range, max_range, z_scale,
     c     contour_type, n_grades

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
c     $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B 
c     $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B 
      subroutine autogl_redraw
      implicit none

      real*8 min_range, max_range
      real*8 z_scale
      integer n_grades, contour_type
      common/parameter/ min_range, max_range, z_scale,
     c     contour_type, n_grades

      integer grid_is_shown, contour_is_shown, graph3d_is_shown
      common/flag/ grid_is_shown, contour_is_shown, graph3d_is_shown

c     $B2hLL:82<$K;0<!85:BI87O$rIA2h$9$k!#(B 
      call autogl_draw_coordinate_system3d(20)

      if (contour_is_shown .eq. 1) then
c     $B2hLL1&B&$K%3%s%?(B-$B$N%P!<$rIA2h$9$k!#(B 
         if (contour_type .eq. 0) then
            call autogl_draw_contour_map(80, min_range, max_range)
         else if (contour_type .eq. 1) then
            call autogl_draw_line_contour_map
     c           (80, min_range, max_range, n_grades)
         else if (contour_type .eq. 2) then
            call autogl_draw_band_contour_map
     c           (80, min_range, max_range, n_grades)
         endif
      endif

c     $B%G%#%9%W%l%$%j%9%H$KF~$l$?IA2hL?Na$r<B:]$KIA2h$9$k!#(B 
      call autogl_draw_display_list()

      end



c     $BIA2h%"%C%W%G!<%H%3%^%s%I$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B
c     "UpdateModel"$B%\%?%s$rA*$V$H8F$P$l$k!#(B 
      subroutine update_model_button
      implicit none

      integer grid_is_shown, contour_is_shown, graph3d_is_shown
      common/flag/ grid_is_shown, contour_is_shown, graph3d_is_shown

c     $B%G%#%9%W%l%$%j%9%H$r3+$-!"$3$l$r6u$K$9$k!#(B 
      call autogl_open_display_list()

c     $B0J2<$NIA2hL?Na$r%G%#%9%W%l%$%j%9%H$K=g<!F~$l$F$$$/!#(B 
c     $B<B:]$NIA2h$O$3$3$G$O$^$@9T$o$l$J$$!#(B 

      if (grid_is_shown .eq. 1) then
         call draw_grid()
      endif

      if (contour_is_shown .eq. 1) then
         call draw_contour()
      endif

      if (graph3d_is_shown .eq. 1) then
         call draw_graph3d()
      endif

c     $B%G%#%9%W%l%$%j%9%H$rJD$8$k!#(B 
      call autogl_close_display_list()

c     $B%S%e!<$r:FIA2h$9$k!#(B
      call autogl_draw_view()
c     $BEPO?$5$l$?%S%e!<$N:FIA2h%5%V%k!<%A%s!J$3$N>l9g$O(Bautogl_redraw$B!K$,8F$P$l$k!#(B 

      end



c     $B%3!<%k%P%C%/%5%V%k!<%A%s(B
      subroutine autogl_callback(id)
      implicit none

      integer id

      if (id .eq. 0) then
         call update_model_button()
      endif

      end



      subroutine autogl_handle_event
      end

      subroutine autogl_idle
      end

