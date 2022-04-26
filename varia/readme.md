For more information on the MiniLibX library, see:
* <harm-smits.github.io/42docs/libs/minilibx>;
* <aurelienbrabant.fr/blog/getting-started-with-the-minilibx>;
* <github.com/S-LucasSerrano/miniLibX_sample>;
* <tronche.com/gui/x/xlib>.

To  use  MiniLibX  functions,  you  may  need  to  link  your  software with several libraries, including the MiniLibX library itself. On MacOs, you will need to type the following line:

    cc -I /usr/local/include FILE.c -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit

Because the miniLibX uses Appkit and MX11 you need to link them adding -lmlx -framework OpenGL -framework AppKit when you compile.

On Unix/Linux, simply add the following arguments at linking time:

-lmlx -lXext -lX11

You may also need to specify the path to these libraries, using the -L flag.

I used <www.pixilart.com> to create my pixel images and used <onlinepngtools.com/crop-png> and <onlinepngtools.com/resize-png> respectively to crop amnd resize my png images before converting them to the xpm format.