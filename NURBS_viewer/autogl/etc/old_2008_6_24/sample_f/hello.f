c     
c     $B%a%$%s%k!<%A%s(B
c     
      implicit none

c     $B%5%$%:$d;k@~J}8~$J$I$r@_Dj$9$k!#(B

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

c     $B:BI8<4$rGr$GIA2h$9$k!#(B

c     $BGr(B (r=1, g=1, b=1)
      call autogl_set_color(1.0d0, 1.0d0, 1.0d0) 

c     $B86E@$K86E@%i%Y%k$NJ8;zNs(B 
      call autogl_draw_string(0.0d0, 0.0d0, 0.0d0, 'O')

c     $B86E@$+$i(B(50, 0, 0)$B$X$N@~J,(B
      call autogl_draw_line(
     c     0.0d0, 0.0d0, 0.0d0,
     c     50.0d0, 0.0d0, 0.0d0)

c     X$B<4(B 
      call autogl_draw_string(50.0d0, 0.0d0, 0.0d0, 'X')

c     $B86E@$+$i(B(0, 50, 0)$B$X$N@~J,(B 
      call autogl_draw_line(
     c     0.0d0, 0.0d0, 0.0d0,
     c     0.0d0, 50.0d0, 0.0d0)

c     Y$B<4(B 
      call autogl_draw_string(0.0d0, 50.0d0, 0.0d0, 'Y')

c     $B86E@$+$i(B(0, 0, 50)$B$X$N@~J,(B 
      call autogl_draw_line(
     c     0.0d0, 0.0d0, 0.0d0,
     c     0.0d0, 0.0d0, 50.0d0)

c     Z$B<4(B 
      call autogl_draw_string(0.0d0, 0.0d0, 50.0d0, 'Z')

c     $B;03Q7A$r@V$GIA2h$9$k!#(B 

c     $B@V(B (r=1, g=0, b=0)
      call autogl_set_color(1.0d0, 0.0d0, 0.0d0) 

c     $B;0E@$r;XDj$7$F;03Q7A(B 
      call autogl_draw_triangle(
     c     -20.0d0, 0.0d0, 0.0d0, 
     c     0.0d0, -20.0d0, 0.0d0, 
     c     0.0d0, 0.0d0, -20.0d0)

c     $BD>J}BN(B(0, 0, 0) -$B!J(B10, 20, 30)$B$r%7%"%s$GIA2h$9$k!#(B 

c     $B%7%"%s(B (r=0, g=1, b=1)
      call autogl_set_color(0.0d0, 1.0d0, 1.0d0) 

c     $B;ME@$r;XDj$7$F;MJU7A(B 
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

c     $B$$$o$f$k$*7h$^$j$N%;%j%U(B 

c     $B2+?'(B (r=1, g=1, b=0)
      call autogl_set_color(1.0d0, 1.0d0, 0.0d0) 

c     $BJ8;zNs(BHello, world ! $B$NI=<((B
      call autogl_draw_string(
     c     10.0d0, 20.0d0, 30.0d0, 
     c     'Hello, world !')

      end



      subroutine autogl_handle_event
      end

      subroutine autogl_idle
      end

      subroutine autogl_callback(id)
      implicit none
      integer id
      end
