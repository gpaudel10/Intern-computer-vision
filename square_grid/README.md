
**I also have attached the practiced files along with the main file. Only `square_grid_main.py` can be checked.**

## Given an arbitrary number of images, write code in vanilla numpy to form a square grid of images.

The goal of this task is to make the square image grid where number of images should be pasted inside the grid.
Brief explanation of the code is:

**Steps**:

* Step 1: First of all images are loaded (jpg and png) using `listdir()` and joining images path and file path to get the images using `Image.open()`from PIL library and opened images are append into the empty list only after converted to numpy array.
* Step 2: Now image grid is created by calculating the the number of images to be stored in corresponding rows by calculating the square root of total number of images and using ceiling function to get accurate numbers. And images to be stored in column also calculated.
*  Step 3: Max width and height is calculated from the list of images in the list which has largest width and largest height.
*  Step 4: empty grid is created using max width and height.
*  Step 5: to paste the images inside the grid row and col value is calculated these values determine the position where the image will be placed in the grid.
*  Step 6: get the height, width, and number of channels of the current image using the shape attribute of the image array.
*  Step 7: *x_start* and *y_start* is calculated to align the image to the center of current image.
*  Step 8: create *new_image* with dimensions (max_height, max_width, 3) and data type uint8. This array will create black background for pasting the current image.
*  Step 9 : then indexing to copy the pixel values of the current image into the appropriate region of *new_image*. The region is defined by the *y_start, y_start + height, x_start, and x_start + width* values.
*  Step 10: now assign the *new_image* array to the corresponding position in the grid array using the *row* and *col* indices. This places the pasted image in the correct location within the grid.
*  Step 11: then concatente the images using `hstack()` in rows and using `vstack()` to concatenate the hstacked images.
*  Step 11: repeat the steps 5 to 11 to fill the entire grid.

In this way square grid of images is created.