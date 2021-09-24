c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

c     $B3J;R$NJ,3d?t(B 
      integer CELLS
      parameter (CELLS = 40)

c     $B3J;R>e$N%9%+%i!<CM(B 
      real*8 grid_values(CELLS + 1, CELLS + 1, CELLS + 1)
      common/value/ grid_values

      real*8 min_range, max_range
      real*8 level_value, level_width
      real*8 a, b, c, d
      common/parameter/ min_range, max_range, level_value, level_width, 
     c     a, b, c, d

      integer section_is_shown, isosurface_is_shown
      common/flag/ section_is_shown, isosurface_is_shown

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

c     $B%3%s%?(B-$B$N:GBg!&:G>.CM(B 
      min_range = -1.0d0
      max_range = 5.0d0

c     $B??$sCf$NEyCMLL$NCM(B 
      level_value = 2.0d0

c     $BI}!JB>$NFsKg$NEyCMLL$O!"(Blevel_value +- level_width $B$H$J$k!#!K(B 
      level_width = 2.0d0

c     $BCGLL$NJ}Dx<0(B Ax+By+Cz+D=0 $B$N78?t(B
      a = 1.0d0
      b = 1.0d0
      c = 1.0d0
      d = 0.0d0

c     $BCGLL$rI=<($9$k$+(B 
      section_is_shown = 0

c     $BEyCMLL$rI=<($9$k$+(B 
      isosurface_is_shown = 0
   


c     $B%S%e!<$r=`Hw$9$k!#(B 

c     $B%S%e!<$NBg$-$5(B 
      call autogl_set_view_size(60.0d0)

c     $B$*$^$8$J$$(B 
      call autogl_set_default_callback_in_mode3d()
      call autogl_enable_drag_in_mode3d()

c     $B%Q%M%k$r=`Hw$9$k!#(B 
c     $B%\%?%sMQ%5%V%k!<%A%sHV9f$d%3%s%H%m!<%kMQJQ?t$rEPO?$9$k!#(B
      call autogl_add_group('model')
      call autogl_set_panel_in_mode3d()
      call autogl_add_comment()
      call autogl_set_label('Model Parameters')

c     $BCGLL%3%s%?(B- 
      call autogl_add_boolean(section_is_shown, 'section_is_shown')
      call autogl_set_label('section')
      call autogl_add_comment()
      call autogl_set_label('equation Ax+By+Cz+D=0')
      call autogl_add_real(a, 'a')
      call autogl_add_real(b, 'b')
      call autogl_add_real(c, 'c')
      call autogl_add_real(d, 'd')
      call autogl_add_real(min_range, 'min_range')
      call autogl_add_real(max_range, 'max_range')

c     $BEyCMLL(B 
      call autogl_add_boolean(isosurface_is_shown, 
     c     'isosurface_is_shown')
      call autogl_set_label('iso-surface')
      call autogl_add_real(level_value, 'level_value')
      call autogl_add_real(level_width, 'level_width')

      call autogl_set_button(0, 'UpdateModel')

c     AutoGL$B$N%a%$%s%k!<%W(B
c     $BFsEY$HLa$i$J$$(B
      call autogl_main()

      end



c     $B3J;R$NCGLL%3%s%?(B-$B$rIA2h$9$k!#(B
      subroutine plot_section
      implicit none

      integer CELLS
      parameter (CELLS = 40)

      real*8 grid_values(CELLS + 1, CELLS + 1, CELLS + 1)
      common/value/ grid_values

      real*8 min_range, max_range
      real*8 level_value, level_width
      real*8 a, b, c, d
      common/parameter/ min_range, max_range, level_value, level_width, 
     c     a, b, c, d

      real*8 cell_size
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

c     $BO;LLBN$NCGLL%3%s%?!<$rIA2h$9$k!#(B 
               call autogl_draw_section_smooth_contour_hexahedron(
     c              a, b, c, d, min_range, max_range,
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



c     $B3J;R$NEyCMLL$rIA2h$9$k!#(B 
      subroutine plot_isosurface_of_level(value)
      implicit none

      real*8 value

      integer CELLS
      parameter (CELLS = 40)

      real*8 grid_values(CELLS + 1, CELLS + 1, CELLS + 1)
      common/value/ grid_values

      real*8 min_range, max_range
      real*8 level_value, level_width
      real*8 a, b, c, d
      common/parameter/ min_range, max_range, level_value, level_width, 
     c     a, b, c, d

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



c     $BEyCMLL$rIA2h$9$k!#(B 
      subroutine plot_isosurface
      implicit none

      real*8 min_range, max_range
      real*8 level_value, level_width
      real*8 a, b, c, d
      common/parameter/ min_range, max_range, level_value, level_width, 
     c     a, b, c, d

      call plot_isosurface_of_level(level_value - level_width)
      call plot_isosurface_of_level(level_value)
      call plot_isosurface_of_level(level_value + level_width)

      end



c     $B%5%V%k!<%A%s(Bautogl_redraw
c     $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B 
c     $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B 
      subroutine autogl_redraw
      implicit none

      real*8 min_range, max_range
      real*8 level_value, level_width
      real*8 a, b, c, d
      common/parameter/ min_range, max_range, level_value, level_width, 
     c     a, b, c, d

      integer section_is_shown, isosurface_is_shown
      common/flag/ section_is_shown, isosurface_is_shown

      real*8 size

c     $B2hLL:82<$K;0<!85:BI87O$rIA2h$9$k!#(B 
      call autogl_draw_coordinate_system3d(20)

      if (section_is_shown .eq. 1) then
c     $B2hLL1&B&$K%3%s%?(B-$B$N%P!<$rIA2h$9$k!#(B 
         call autogl_draw_contour_map(80, min_range, max_range)
      endif
            
c     $B3J;R$NOH$rIA2h$9$k!#(B 
      size = 30.0d0
      call autogl_set_color(1.0d0, 1.0d0, 1.0d0)
      call autogl_draw_box3d(-size, -size, -size, size, size, size)

c     $BH>F)L@I=<($rM-8z$K$9$k!#(B 
      call autogl_turn_on_transparency()

c     $B%G%#%9%W%l%$%j%9%H$KF~$l$?IA2hL?Na$r<B:]$KIA2h$9$k!#(B 
      call autogl_draw_display_list()

      end



c     $BIA2h%"%C%W%G!<%H%3%^%s%I$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B
c     "UpdateModel"$B%\%?%s$rA*$V$H8F$P$l$k!#(B 
      subroutine update_model_button
      implicit none

      integer section_is_shown, isosurface_is_shown
      common/flag/ section_is_shown, isosurface_is_shown

c     $B%G%#%9%W%l%$%j%9%H$r3+$-!"$3$l$r6u$K$9$k!#(B 
      call autogl_open_display_list()

c     $B0J2<$NIA2hL?Na$r%G%#%9%W%l%$%j%9%H$K=g<!F~$l$F$$$/!#(B 
c     $B<B:]$NIA2h$O$3$3$G$O$^$@9T$o$l$J$$!#(B 

      if (section_is_shown .eq. 1) then
         call plot_section()
      endif

      if (isosurface_is_shown .eq. 1) then
         call plot_isosurface()
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

