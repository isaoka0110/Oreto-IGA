c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

      integer CELLS
      parameter (CELLS = 40)
      real*8 grid_values(CELLS + 1, CELLS + 1, CELLS + 1)
      real*8 min_range, max_range, level_value, level_width
      integer model_is_rendered
      common grid_values, min_range, max_range, 
     c     level_value, level_width, model_is_rendered

      integer i, j, k
      real*8 scale, x, y, z

      do i = 1, CELLS + 1
         do j = 1, CELLS + 1
            do k = 1, CELLS + 1
               scale = 4.0d0 / CELLS
               x = (i - 1 - CELLS / 2) * scale
               y = (j - 1 - CELLS / 2) * scale
               z = (k - 1 - CELLS / 2) * scale
               grid_values(i, j, k) = sin(x * 3.1415) + y * y + z * z
            enddo
         enddo
      enddo

      min_range = -1.0d0
      max_range = 5.0d0
      level_value = 2.0d0
      level_width = 2.0d0
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



      subroutine plot_isosurface_of_level(value)
      implicit none

      real*8 value

      integer CELLS
      parameter (CELLS = 40)
      real*8 grid_values(CELLS + 1, CELLS + 1, CELLS + 1)
      real*8 min_range, max_range, level_value, level_width
      integer model_is_rendered
      common grid_values, min_range, max_range, 
     c     level_value, level_width, model_is_rendered

      real*8 cell_size
      real*8 grade
      real*8 red, green, blue
      integer gx, gy, gz
      real*8 x000, y000, z000, value000
      real*8 x100, y100, z100, value100
      real*8 x110, y110, z110, value110
      real*8 x010, y010, z010, value010
      real*8 x001, y001, z001, value001
      real*8 x101, y101, z101, value101
      real*8 x111, y111, z111, value111
      real*8 x011, y011, z011, value011

      cell_size = 60.0d0 / CELLS
      grade = (value - min_range) / (max_range - min_range)
      call autogl_get_contour_color(red, green, blue,
     c     grade)
      call autogl_set_color(red, green, blue)

      do gx = 1, CELLS
         do gy = 1, CELLS
            do gz = 1, CELLS
               x000 = (gx - 1 - CELLS / 2) * cell_size
               y000 = (gy - 1 - CELLS / 2) * cell_size
               z000 = (gz - 1 - CELLS / 2) * cell_size
               value000 = grid_values(gx, gy, gz)

               x100 = x000 + cell_size
               y100 = y000
               z100 = z000
               value100 = grid_values(gx + 1, gy, gz)

               x110 = x000 + cell_size
               y110 = y000 + cell_size
               z110 = z000
               value110 = grid_values(gx + 1, gy + 1, gz)

               x010 = x000
               y010 = y000 + cell_size
               z010 = z000
               value010 = grid_values(gx, gy + 1, gz)

               x001 = x000
               y001 = y000
               z001 = z000 + cell_size
               value001 = grid_values(gx, gy, gz + 1)

               x101 = x000 + cell_size
               y101 = y000
               z101 = z000 + cell_size
               value101 = grid_values(gx + 1, gy, gz + 1)

               x111 = x000 + cell_size
               y111 = y000 + cell_size
               z111 = z000 + cell_size
               value111 = grid_values(gx + 1, gy + 1, gz + 1)

               x011 = x000
               y011 = y000 + cell_size
               z011 = z000 + cell_size
               value011 = grid_values(gx, gy + 1, gz + 1)

c     $BO;LLBN$NEyCMLL$rIA2h$9$k!#(B 
               call autogl_draw_isosurface_hexahedron(
     c              value, value, 0,
     c              x000, y000, z000, value000,
     c              x100, y100, z100, value100,
     c              x110, y110, z110, value110,
     c              x010, y010, z010, value010,
     c              x001, y001, z001, value001,
     c              x101, y101, z101, value101,
     c              x111, y111, z111, value111,
     c              x011, y011, z011, value011)
            enddo
         enddo
      enddo

      end



      subroutine plot_isosurface
      implicit none

      integer CELLS
      parameter (CELLS = 40)
      real*8 grid_values(CELLS + 1, CELLS + 1, CELLS + 1)
      real*8 min_range, max_range, level_value, level_width
      integer model_is_rendered
      common grid_values, min_range, max_range, 
     c     level_value, level_width, model_is_rendered

      call plot_isosurface_of_level(level_value - level_width)
      call plot_isosurface_of_level(level_value)
      call plot_isosurface_of_level(level_value + level_width)

      end



c     $B%5%V%k!<%A%s(Bautogl_redraw
c     $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B */
c     $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B */
      subroutine autogl_redraw
      implicit none

      integer CELLS
      parameter (CELLS = 40)
      real*8 grid_values(CELLS + 1, CELLS + 1, CELLS + 1)
      real*8 min_range, max_range, level_value, level_width
      integer model_is_rendered
      common grid_values, min_range, max_range, 
     c     level_value, level_width, model_is_rendered

      real*8 size

c     $B2hLL:82<$K;0<!85:BI87O$rIA2h$9$k!#(B 
      call autogl_draw_coordinate_system3d(20)

c     $B3J;R$NOH$rIA2h$9$k!#(B 
      size = 30.0d0
      call autogl_set_color(1.0d0, 1.0d0, 1.0d0)
      call autogl_draw_box3d(-size, -size, -size, size, size, size)

c     $BH>F)L@I=<($rM-8z$K$9$k!#(B 
      call autogl_turn_on_transparency()

c     $B$^$:!"0lEY$@$1%b%G%k$r%G%#%9%W%l%$%j%9%H$XIA2h$7$F$*$/!#(B 
      if (model_is_rendered .eq. 0) then

c     $B%G%#%9%W%l%$%j%9%H$r3+$-!"$3$l$r6u$K$9$k!#(B 
         call autogl_open_display_list()

         call plot_isosurface()

c     $B%G%#%9%W%l%$%j%9%H$rJD$8$k!#(B 
         call autogl_close_display_list()

         model_is_rendered = 1
      endif

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
