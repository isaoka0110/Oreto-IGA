c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

      real*8 vertexs(8, 3)
      integer selected_vertex_id
      common vertexs, selected_vertex_id

c     $BD:E@$N:BI8(B 
      vertexs(1, 1) = 0.0d0
      vertexs(1, 2) = 0.0d0
      vertexs(1, 3) = 0.0d0

      vertexs(2, 1) = 10.0d0
      vertexs(2, 2) = 0.0d0
      vertexs(2, 3) = 0.0d0

      vertexs(3, 1) = 10.0d0
      vertexs(3, 2) = 20.0d0
      vertexs(3, 3) = 0.0d0

      vertexs(4, 1) = 0.0d0
      vertexs(4, 2) = 20.0d0
      vertexs(4, 3) = 0.0d0

      vertexs(5, 1) = 0.0d0
      vertexs(5, 2) = 0.0d0
      vertexs(5, 3) = 30.0d0

      vertexs(6, 1) = 10.0d0
      vertexs(6, 2) = 0.0d0
      vertexs(6, 3) = 30.0d0

      vertexs(7, 1) = 10.0d0
      vertexs(7, 2) = 20.0d0
      vertexs(7, 3) = 30.0d0

      vertexs(8, 1) = 0.0d0
      vertexs(8, 2) = 20.0d0
      vertexs(8, 3) = 30.0d0

c     $B8=:_A*Br$5$l$F$$$kD:E@$NHV9f(B 
      selected_vertex_id = -1



      call autogl_set_view_size(70.0d0)

c     $B%$%Y%s%H=hM}%3!<%k%P%C%/4X?t$H$7$F(Bautogl_handle_event$B$r;XDj!#(B 
      call autogl_set_default_callback_in_mode3d()

c     $B=i4|>uBV$G$O!"%f!<%6!<Dj5A%$%Y%s%H=hM}$r9T$&!#(B 
      call autogl_set_mode3d(0)

c     $B%$%Y%s%H=hM}Cf(B, $B%I%i%C%0$rM-8z$K$9$k!#(B
      call autogl_enable_drag_in_mode3d()

c     $B%Q%M%k>e$K;0<!85%"%W%jMQ%$%Y%s%H=hM}5!G=$r=`Hw$9$k!#(B 
      call autogl_set_panel_in_mode3d()

c     AutoGL$B$N%a%$%s%k!<%W(B
c     $BFsEY$HLa$i$J$$(B
      call autogl_main()

      end



c     $B%5%V%k!<%A%s(Bautogl_redraw
c     $B%S%e!<$N:FIA2h$N$?$a$N%3!<%k%P%C%/%5%V%k!<%A%s(B 
c     $B%S%e!<$,:FI=<($5$l$k$4$H$K8F$P$l$k!#(B 
      subroutine autogl_redraw
      implicit none

      real*8 vertexs(8, 3)
      integer selected_vertex_id
      common vertexs, selected_vertex_id

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
      
      call autogl_draw_line(
     c     0.0d0, 0.0d0, -50.0d0,
     c     0.0d0, 0.0d0, 50.0d0)
      call autogl_draw_string(0.0d0, 0.0d0, 50.0d0, "Z = 50") 
      call autogl_draw_string(0.0d0, 0.0d0, -50.0d0, "Z = -50") 

      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
      call autogl_draw_string(0.0d0, 0.0d0, 0.0d0, "O")

      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 
      call autogl_draw_quadrangle(
     c     0.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 0.0d0, 
     c     0.0d0, 20.0d0, 0.0d0)
      call autogl_draw_quadrangle(
     c     0.0d0, 0.0d0, 30.0d0, 
     c     10.0d0, 0.0d0, 30.0d0, 
     c     10.0d0, 20.0d0, 30.0d0, 
     c     0.0d0, 20.0d0, 30.0d0)
      call autogl_draw_quadrangle(
     c     0.0d0, 0.0d0, 0.0d0, 
     c     0.0d0, 20.0d0, 0.0d0, 
     c     0.0d0, 20.0d0, 30.0d0, 
     c     0.0d0, 0.0d0, 30.0d0)
      call autogl_draw_quadrangle(
     c     10.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 30.0d0, 
     c     10.0d0, 0.0d0, 30.0d0)
      call autogl_draw_quadrangle(
     c     0.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 0.0d0, 0.0d0, 
     c     10.0d0, 0.0d0, 30.0d0, 
     c     0.0d0, 0.0d0, 30.0d0)
      call autogl_draw_quadrangle(
     c     0.0d0, 20.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 0.0d0, 
     c     10.0d0, 20.0d0, 30.0d0, 
     c     0.0d0, 20.0d0, 30.0d0)
      
c     $B3FD:E@$K$D$$$F!"$=$l$,A*Br$5$l$F$$$k$+$I$&$+$rIA2h$9$k!#(B 
      call autogl_set_color(1.0d0, 0.0d0, 0.0d0) 
      do i = 1, 8
         is_filled = 0
         if (i .eq. selected_vertex_id) then
            is_filled = 1
         endif
         mark_size_dc = 10
         
c     $B%@%$%"%b%s%I$N%^!<%/$rI=<($9$k!#(B 
         call autogl_draw_diamond_mark3d(
     c        vertexs(i, 1), vertexs(i, 2), vertexs(i, 3), 
     c        mark_size_dc, is_filled)
c     mark_size_dc$B$K$h$j!"(B10 pixel$B$0$i$$$NBg$-$5$H$J$k!#(B 
c     is_filled .eq. 1$B$J$i!"$3$ND:E@$OA*Br$5$l$F$$$k!#(B 
      enddo

      end



      subroutine autogl_handle_event
      implicit none

      real*8 vertexs(8, 3)
      integer selected_vertex_id
      common vertexs, selected_vertex_id

      integer event
      integer i
      integer tolerance_dc
      real*8 parameter
      integer flag
      
      call autogl_get_view_event(event)

c     $B$b$7!"%^%&%9%/%j%C%/$,$"$l$P(B 
      if (event .eq. 2) then 
         
c     $B3FD:E@$K$D$$$F!"%^%&%9%]%$%s%?$,%R%C%H$7$?$+$I$&$+D4$Y$k!#(B 
         selected_vertex_id = -1
         do i = 1, 8
            tolerance_dc = 10
            
c     $B$3$ND:E@$,%^%&%9%]%$%s%?$N$=$P$K$"$l$P(B 
            call autogl_pointing_device_is_hit3d(
     c           flag, parameter, 
     c           vertexs(i, 1), vertexs(i, 2), vertexs(i, 3),
     c           tolerance_dc)
c     $BE@$N:BI8$O@$3&:BI8!J;0<!85!K$GM?$($k!#(B 
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
         call autogl_handle_default_key_event_in_mode3d()
      endif

      end



      subroutine autogl_idle
      end

      subroutine autogl_callback(id)
      implicit none
      integer id
      end
