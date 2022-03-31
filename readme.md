For more information on the MiniLibX library, see:
* <https://harm-smits.github.io/42docs/libs/minilibx>;
* <https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx>;
* <https://github.com/S-LucasSerrano/miniLibX_sample>;
* <https://tronche.com/gui/x/xlib>.

To  use  MiniLibX  functions,  you  may  need  to  link  your  software with several libraries, including the MiniLibX library itself. On MacOs, you will need to type the following line:

    cc -I /usr/local/include FILE.c -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit

Because the miniLibX uses Appkit and MX11 you need to link them adding -lmlx -framework OpenGL -framework AppKit when you compile.

On Unix/Linux, simply add the following arguments at linking time:

-lmlx -lXext -lX11

You may also need to specify the path to these libraries, using the -L flag.

algorithme pour faire du bruit perlin perlin noise