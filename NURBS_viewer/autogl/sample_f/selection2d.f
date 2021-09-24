c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

      real*8 vertexs(6, 2)
      integer selected_edge_id
      common vertexs, selected_edge_id

c     $BD:E@$N:BI8(B 
      vertexs(1, 1) = 10.0d0
      vertexs(1, 2) = 0.0d0

      vertexs(2, 1) = 10.0d0
      vertexs(2, 2) = 20.0d0

      vertexs(3, 1) = 0.0d0
      vertexs(3, 2) = 20.0d0

      vertexs(4, 1) = -10.0d0
      vertexs(4, 2) = 0.0d0

      vertexs(5, 1) = 0.0d0
      vertexs(5, 2) = -20.0d0

      vertexs(6, 1) = 30.0d0
      vertexs(6, 2) = -20.0d0

c     $B8=:_A*Br$5$l$F$$$kNG@~$NHV9f(B 
      selected_edge_id = -1



      call autogl_set_view_size(70.0d0)

c     $B%$%Y%s%H=hM}%3!<%k%P%C%/4X?t$H$7$F(Bautogl_handle_event$B$r;XDj!#(B 
      call autogl_set_default_callback_in_mode2d()

c     $B=i4|>uBV$G$O!"%f!<%6!<Dj5A%$%Y%s%H=hM}$r9T$&!#(B 
      call autogl_set_mode2d(0)

c     $B%$%Y%s%H=hM}Cf(B, $B%I%i%C%0$rM-8z$K$9$k!#(B
      call autogl_enable_drag_in_mode2d()

c     $B%Q%M%k>e$KFs<!85%"%W%jMQ%$%Y%s%H=hM}5!G=$r=`Hw$9$k!#(B 
      call autogl_set_panel_in_mode2d()

c     AutoGL$B$N%a%$%s%k!<%W(B
c     $BFsEY$HLa$i$J$$(B
      call autogl_main()

      end



c     $B%5%V%k!<%A%s(Bautoglredraw
c     $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B 
c     $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B 
      subroutine autogl_redraw
      implicit none

      real*8 vertexs(6, 2)
      integer selected_edge_id
      common vertexs, selected_edge_id

      integer i

      call autogl_set_color(0.0d0, 1.0d0, 0.0d0) 

      call autogl_draw_line(
     c     -50.0d0, 0.0d0, 0.0d0,
     c     50.0d0, 0.0d0, 0.0d0)
      call autogl_draw_string(50.0d0, 0.0d0, 0.0d0, "X = 50") 
      call autogl_draw_string(-50.0d0, 0.0d0, 0.0d0, "X = -50") 
         
      call autogl_draw_line(
     c     0.0d0, -50.0d0, 0.0d0,
     c     0.0d0, 50.0d0, 0.0d0)
      call autogl_draw_string(0.0d0, 50.0d0, 0.0d0, "Y = 50") 
      call autogl_draw_string(0.0d0, -50.0d0, 0.0d0, "Y = -50") 

      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
      call autogl_draw_string(0.0d0, 0.0d0, 0.0d0, "O")

      do i = 1, 6 - 1
         if (i .eq. selected_edge_id) then
            call autogl_set_color(1.0d0, 0.0d0, 0.0d0) 
         else
            call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
         endif
         call autogl_draw_line(
     c        vertexs(i, 1), vertexs(i, 2), 0.0d0,
     c        vertexs(i + 1, 1), vertexs(i + 1, 2), 0.0d0)
      enddo

      end



      subroutine autogl_handle_event
      implicit none

      real*8 vertexs(6, 2)
      integer selected_edge_id
      common vertexs, selected_edge_id

      integer event
      integer dc_x, dc_y, dc_z
      integer tolerance_dc
      integer i
      integer key_char
      
      call autogl_get_view_event(event)

c     $B$b$7!"%^%&%9%/%j%C%/$,$"$l$P(B 
      if (event .eq. 2) then 
         
         tolerance_dc = 10

         call autogl_get_pointing_device_position_dc(
     c        dc_x, dc_y, dc_z)
         
         call autogl_start_selection(dc_x, dc_y, tolerance_dc)

         do i = 1, 6 - 1
            call autogl_set_selection_id(i)
            call autogl_draw_line(
     c           vertexs(i, 1), vertexs(i, 2), 0.0d0,
     c           vertexs(i + 1, 1), vertexs(i + 1, 2), 0.0d0)
         enddo
         
         call autogl_end_selection()
         call autogl_get_selected_id(
     c        selected_edge_id)
         
         write(*,*) ' selected edge ID is ', selected_edge_id

c     $B%S%e!<$r:FIA2h$9$k!#(B 
         call autogl_draw_view()

c     $B$b$7!"%-!<%\!<%IF~NO$,$"$l$P(B 
      elseif (event .eq. 3) then
         call autogl_get_key_char(key_char)
         if (key_char .eq. ichar(' ')) then
            write(*,*) ' hit space '
         else
            call autogl_handle_default_key_event_in_mode2d()
         endif
      endif
      end



      subroutine autogl_idle
      end

      subroutine autogl_callback(id)
      implicit none
      integer id
      end
