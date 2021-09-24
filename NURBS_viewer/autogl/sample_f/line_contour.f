c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

      integer CELLS
      parameter (CELLS = 100)
      real*8 grid_values(CELLS + 1, CELLS + 1)
      real*8 min_range, max_range
      integer n_grades
      integer model_is_rendered
      common grid_values, min_range, max_range, n_grades, 
     c     model_is_rendered

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

      min_range = -1.0d0
      max_range = 5.0d0
      n_grades = 20
      model_is_rendered = 0
   
c     $B%S%e!<$NBg$-$5(B 
      call autogl_set_view_size(60.0d0)

c     $B$*$^$8$J$$(B 
      call autogl_set_default_callback_in_mode2d()
      call autogl_set_mode2d(2)
      call autogl_set_panel_in_mode2d()
      call autogl_enable_drag_in_mode2d()

c     AutoGL$B$N%a%$%s%k!<%W(B
c     $BFsEY$HLa$i$J$$(B
      call autogl_main()

      end



      subroutine plot_line_contour
      implicit none

      integer CELLS
      parameter (CELLS = 100)
      real*8 grid_values(CELLS + 1, CELLS + 1)
      real*8 min_range, max_range
      integer n_grades
      integer model_is_rendered
      common grid_values, min_range, max_range, n_grades, 
     c     model_is_rendered

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

c     $B@~%3%s%?(B-$B$D$-$N;MJU7A$rI=<($9$k!#(B 
            call autogl_draw_line_contour_quadrangle(
     c           min_range, max_range, n_grades,
     c           x00, y00, 0.0d0, value00,
     c           x10, y10, 0.0d0, value10,
     c           x11, y11, 0.0d0, value11,
     c           x01, y01, 0.0d0, value01)
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
      real*8 min_range, max_range
      integer n_grades
      integer model_is_rendered
      common grid_values, min_range, max_range, n_grades, 
     c     model_is_rendered

c     $B$^$:!"0lEY$@$1%b%G%k$r%G%#%9%W%l%$%j%9%H$XIA2h$7$F$*$/!#(B 
      if (model_is_rendered .eq. 0) then

c     $B%G%#%9%W%l%$%j%9%H$r3+$-!"$3$l$r6u$K$9$k!#(B 
         call autogl_open_display_list()

         call plot_line_contour()

c     $B%G%#%9%W%l%$%j%9%H$rJD$8$k!#(B 
         call autogl_close_display_list()

         model_is_rendered = 1
      endif

c     $B2hLL1&B&$K%3%s%?(B-$B$N%P!<$rIA2h$9$k!#(B 
      call autogl_draw_line_contour_map(
     c     80, min_range, max_range, n_grades)

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
