c     
c     $B%a%$%s%k!<%A%s(B
c     
      program idle2d
      implicit none

      real*8 vertexs(6, 2), center_x, center_y
      integer selected_vertex_id, idle_event_is_on
      common vertexs, center_x, center_y, 
     c     selected_vertex_id, idle_event_is_on

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

c     $B8=:_A*Br$5$l$F$$$kD:E@$NHV9f(B 
      selected_vertex_id = -1

      center_x = 0.0d0
      center_y = 0.0d0

      idle_event_is_on = 0



      call autogl_set_view_size(70.0d0)

c     $B%$%Y%s%H=hM}%3!<%k%P%C%/4X?t$H$7$F(Bautogl_handle_event$B$r;XDj!#(B 
      call autogl_set_default_callback_in_mode2d()

c     $B%"%$%I%k%$%Y%s%H=hM}$NM-8z2=(B
      call autogl_enable_idle_event()

c     $B=i4|>uBV$G$O!"%f!<%6!<Dj5A%$%Y%s%H=hM}$r9T$&!#(B 
      call autogl_set_mode2d(0)

c     $B%$%Y%s%H=hM}Cf(B, $B%I%i%C%0$rM-8z$K$9$k!#(B
      call autogl_enable_drag_in_mode2d()

c     $B%Q%M%k>e$KFs<!85%"%W%jMQ%$%Y%s%H=hM}5!G=$r=`Hw$9$k!#(B 
      call autogl_set_panel_in_mode2d()

c     $B%\%?%s(B Animate
      call autogl_set_button(0, 'Animate')

c     AutoGL$B$N%a%$%s%k!<%W(B
c     $BFsEY$HLa$i$J$$(B
      call autogl_main()

      end



c     $B%5%V%k!<%A%s(Bautogl_redraw
c     $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B 
c     $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B 
      subroutine autogl_redraw
      implicit none

      real*8 vertexs(6, 2), center_x, center_y
      integer selected_vertex_id, idle_event_is_on
      common vertexs, center_x, center_y, 
     c     selected_vertex_id, idle_event_is_on

      integer i
      integer mark_size_dc
      integer is_filled

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

      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
      do i = 1, 6 - 1
         call autogl_draw_line(
     c        vertexs(i, 1) + center_x, vertexs(i, 2) + center_y, 0.0d0,
     c        vertexs(i + 1, 1) + center_x, 
     c        vertexs(i + 1, 2) + center_y, 0.0d0)
      enddo
      
c     $B3FD:E@$K$D$$$F!"$=$l$,A*Br$5$l$F$$$k$+$I$&$+$rIA2h$9$k!#(B 
      call autogl_set_color(1.0d0, 0.0d0, 0.0d0) 
      do i = 1, 6
         is_filled = 0
         if (i .eq. selected_vertex_id) then
            is_filled = 1
         endif
         
         mark_size_dc = 10
c     $B%@%$%"%b%s%I$N%^!<%/$rI=<($9$k!#(B 
         call autogl_draw_diamond_mark2d(
     c        vertexs(i, 1) + center_x, vertexs(i, 2) + center_y, 0.0d0,
     c        mark_size_dc, is_filled)
c     mark_size_dc$B$K$h$j!"(B10 pixel$B$0$i$$$NBg$-$5$H$J$k!#(B 
c     is_filled .eq. 1$B$J$i!"$3$ND:E@$OA*Br$5$l$F$$$k!#(B 
      enddo

      end



      subroutine autogl_handle_event
      implicit none

      real*8 vertexs(6, 2), center_x, center_y
      integer selected_vertex_id, idle_event_is_on
      common vertexs, center_x, center_y, 
     c     selected_vertex_id, idle_event_is_on

      integer event
      integer i
      integer tolerance_dc
      integer flag
      integer key_char
      
      call autogl_get_view_event(event)

c     $B$b$7!"%^%&%9%/%j%C%/$,$"$l$P(B 
      if (event .eq. 2) then 
         
c     $B3FD:E@$K$D$$$F!"%^%&%9%]%$%s%?$,%R%C%H$7$?$+$I$&$+D4$Y$k!#(B 
         selected_vertex_id = -1
         do i = 1, 6
            tolerance_dc = 10
            
c     $B$3$ND:E@$,%^%&%9%]%$%s%?$N$=$P$K$"$l$P(B 
            call autogl_pointing_device_is_hit2d(
     c           flag, 
     c           vertexs(i, 1) + center_x, vertexs(i, 2) + center_y,
     c           tolerance_dc)
c     $BE@$N:BI8$O@$3&:BI8!J$?$@$7Fs<!85!K$GM?$($k!#(B 
            if (flag .eq. 1) then
               selected_vertex_id = i
            endif
         enddo
         
         if (selected_vertex_id .ne. -1) then
            write(*,*) ' vertex ', selected_vertex_id, ' is selected '
         endif

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
      implicit none

      real*8 vertexs(6, 2), center_x, center_y
      integer selected_vertex_id, idle_event_is_on
      common vertexs, center_x, center_y, 
     c     selected_vertex_id, idle_event_is_on

      if (50.0d0 .lt. center_x) then
         center_x = -49.0d0
         center_y = -49.0d0
      else 
         center_x = center_x + 0.1d0
         center_y = center_y + 0.1d0
      endif
         
      call autogl_draw_view()

      end



c     "Animate"$B%\%?%s$rA*$V$H8F$P$l$k!#(B 
      subroutine animate_button
      implicit none

      real*8 vertexs(6, 2), center_x, center_y
      integer selected_vertex_id, idle_event_is_on
      common vertexs, center_x, center_y, 
     c     selected_vertex_id, idle_event_is_on

      if (idle_event_is_on .eq. 1) then
         call autogl_set_idle_event_callback(0)
         idle_event_is_on = 0
      else
         call autogl_set_idle_event_callback(1)
         idle_event_is_on = 1
      endif

      end



c     $B%3!<%k%P%C%/%5%V%k!<%A%s(B
      subroutine autogl_callback(id)
      implicit none

      integer id

      if (id .eq. 0) then
         call animate_button()
      endif

      end



