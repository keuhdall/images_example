# images_example
A simple example program made for the 42 students going into the graphic branch, Its purpose is to help them understanding the way images are working in the MLX (the graphcal lib we use).

# MLX Images
## 1) What is the point ?

If you thoroughly followed the explanatory video about the MLX (if you didn't check it first !) you saw that you could print a pixel on the screen thanks to the `mlx_put_pixel` function. Great, so why bother using anything else ?

Well simply for better performance. Think of it that way : why would you use hundreds of little printf functions when you could actually call it one time, with a bigger input. Printing pixels is quite the same.

The solution to this problem is to "print" all the pixels in the memory, and then on the screen all at once, and that's the purpose of the images : they will store your pixels in memory.

Their use is not mandatory on **FdF** (but you might be quite slow on maps such as mars), but they will become crucial on **Fract'ol** since you will have to perform real-time display, which require the use of the images.

## 2) How does it work ?

MLX images are actually just char pointers, it's as simple as that. 1 image = char pointer.

Each pixels of your image are placed one after the other in the char pointer, starting by the top-left pixel (`(0;0)` coordinates), then going to the right, then the next row of pixel. Each pixel is represented by 4 chars.

Here is an example for a 800x600 resolution : you have 480 000 pixels (800x600 = 480 000) represented by 1 920 000 chars (480 000x4 = 1 920 000).
You will get a char pointer that has a length of 1 920 000 chars.

How do you find the pixel you want then ? Simple ! Let's start from the first pixel, the one in the top-left corner which has the coordinates `(0;0)`, it is, as you would have guessed, the first pixel of your char pointer.

Now let's imagine that you want to change the color of the 6th pixel, which means the one that has the coordinates `(5;0)`, for that we need to move 5 pixels to the right.
> **NB** : By convention the coordinates will always be written `(x, y)` with x the abscissas et y the ordinates.

Your pixel is therefore described by the following position is the string : `0 + 4 * 5 = 20` and on 4 chars, so the very positions in string are `20, 21, 22, 23`.

Now how do we get down on the Y axis ? That's actually really simple : we just have to use the following formula : `X position + 4 * Line size * Y position`.
Let's take the pixel `(0;2)` for a window size of 800x600 as example :
This gives us `(0 + 4 * 800 * 2) = 6400`, so the pixel `(0;2)` will be described by the chars `6400, 6401, 6402, 6403` on our char pointer.

Another question : why 4 chars for one pixel ? Simple ! The 3 first chars are representing the color of the pixel through **RGB** values going from 0 to 255. The 4th pixel is the alpha, but we won't talk about it here, so just ignore it.
Time for another example : let's imagine we want to color the pixel from the previous example in green. We know that a pixel is represented by (**RED**, **GREEN**, **BLUE**, **ALPHA**), so in this very example, chars `6400, 6402, 6403` would be to `0` and char `6401` would be to `255`.

## How to use it ?

It's a bit annoying to setup, but once done you'll be able to reuse it easily in all your graphical projects.

### Step 1 : create an image :

Create an image with its dedicated function :

`image_pointer = mlx_new_image(mlx_pointer, width, height);`
Be sure to store the return value of this function you will need later.

### Step 2 : get the image's char pointer

``my_image_data =  mlx_get_data_addr(image_pointer, &bpp, &size_line, &endian);``

Just so you know, variables sent as address here (`&bpp`, `&size_line` and `&endian`) represents :
- `&bpp` : the number of bits per pixels.
- `&size_line` : the size of a line times 4.
- `&endian` : the [endian](https://en.wikipedia.org/wiki/Endianness).

Since you are passing the address of your variables here, **you don't need to initialize them, the function will do it for you**. If you have trouble understanding the use of these variables it's okay, you probably won't need them at all, but you still need to declare them as they are part of the `mlx_get_data_addr` function paramters.

Here is an example of return values you might have :

```c
int     bpp;
int     size_line;
int     endian;
void    *mlx_ptr = mlx_init();
void    *img_ptr = mlx_new_image(mlx_ptr, 800, 600); // 800 = width ; 600 = height
char    *img_data =  mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
```
In this very example we have :
 - `bpp` = 32 because a pixel is coded on 4 char, those chars worth 8 bits each, which gives us 32.
 - `size_line` = 3200 because the width of one line of pixel is 800, times 4, because a pixel is coded on 4 chars
 - `endian` = 0 or 1, depending of the architecture of the computer you use (more informations in the link above).

### Step 3 : Fill the image

All you have to do is using the formula given above (`X position * 4 + 4 * Line size * Y position`) to calculate the postition of the pixel you want on the char pointer, then change the 3 first chars according to the color you want to get.

### Step 4 : Display the image

Simply do : `mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);`

With :
- `mlx_ptr` being the pointer returned by the `mlx_init` function.
- `win_ptr` being the pointer to your MLX window.
- `img_ptr` being the pointer to your MLX image.
- The first `0` is the X position of your image on the window, the second `0` is the Y position.

---

## How to refresh the screen and have animated images ?

Thats really simple :

Simply create a render loop in which you will modify the color of the pixels of your image through the char pointer, and at the end of loop simply call `mlx_put_image_to_window`.
If you have troubles, try calling `mlx_destroy_image` before rendering you new image.

---

### Thats all for this little tutorial, I hope you enjoyed it, if you find any typo or unclear/inaccurate part don't hesitate to open an issue or a pull request ! :) .

> [Origanal post](https://forum.intra.42.fr/topics/16245/messages) by sfaure\
> Translation and example by keuhdall (lmarques)
