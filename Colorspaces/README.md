- [Understanding different color spaces and their histogram](#understanding-different-color-spaces-and-their-histogram)
  - [Color spaces](#color-spaces)
  - [Histogram](#histogram)
    - [1. RGB model](#1-rgb-model)
  - [2. CMYK color model](#2-cmyk-color-model)
  - [3. HSV color model](#3-hsv-color-model)
  - [4. LAB color space](#4-lab-color-space)
  - [Gamut](#gamut)
  - [Problem encountered](#problem-encountered)


## Understanding different color spaces and their histogram
---
In this task, i have learned about the different color spaces and their histograms and why these are needed.

### Color spaces

First of all color is the visual perception based electromagnetic spectrum and color space is a range of colors in a fixed spectrum of colors assigned by the number values that can be interpreted and displayed on the visual plane. Mainly there are two types of colorspace: linear and non linear colorspace.In linear color space numerical values used to represent colors are directly proportional to the actual physical intensity of light. eg RGB,CMYK,YUV,etc and non linear color space are those whose numerical values that are used to represent the color are not proportional to the physical intensity of light instead they are transformed using non linear function to map to uniform scale. eg HSV, LAB
When working in 8-bit mode a system can display 256 colors out of total 16 millions colors.

### Histogram

Color histogram is the graphical representation of distribution of colors within a image. The data contained in the histogram is obtained by counting the occurence of each posssible color of the respective color model within the image.
Histograms of colorspaces provide a way to analyze the distribution of color information in an image. By examining the histogram, we can gain insight into the color characteristics of the image,like the dominant colors, the color balance, and the contrast. This information can be useful for tasks such as image segmentation, object detection, and image enhancement.


#### 1. RGB model

It is widely used color space and stands for RED,GREEN and BLUE. It is additive color model, which means it adds different amounts of red, green and blue light to create a wide range of colors. The main difference between RGB and BGR is the way that the subpixels are arranged for the colors blue, green, and red. RGB are arranged in blue, green, and red order. However, BGR is arranged in the opposite layout with red, green, and blue being in this order. OpneCV reads the image in BGR format by default.


<img src="https://cdn.britannica.com/88/234588-050-05463E9D/colour-wheel-mixing.jpg" width = 300, height = 300>

It can also be understood with the following table:

![table](https://clauswilke.com/art/images/post/colors-color-spaces_files/figure-gfm/RGB-table-1.svg)

When all three primary colors are zeros which gives black color similary for red, white,etc

### 2. CMYK color model

It is just opposite of RGB color model. This color model is based in the light observing quality of inks printed on the paper.Combining three primary colors pigments Cyan, magnenta and yellow should absorb all the light thus resulting in black. It is subtractive model. The value of each primary color is assigned a percentage from the lighest(0%) to the brightest(100%).Because all inks contains some impurities, three inks actually produce the muddy brown, a black color is added in printing process thus it is CMYK color model. Here k represents black sinc B is used to represent blue color.

![cmyk](https://media.geeksforgeeks.org/wp-content/uploads/20200604222111/CMYK.PNG)


### 3. HSV color model

This color is based on human perception of colors.

<img src="https://htmlcolors.com/img/colorhsvprincipal.png" width=300, height=300>


Three fundamental characteristics of colors are:

* Hue - It is the wavelength of light. Hue is often identified by the name of the color.It is measured as a location on a standard color wheel as a degree between 0 to 360.
  
<img src="https://previews.123rf.com/images/myndouwe/myndouwe1609/myndouwe160900008/65990122-color-colors-wheel-names-degrees-rgb-hsb-hsv-hue.jpg" width=300, height=300>

* Saturation - It is the strength or purity of color. It represents the amount of gray in proportion to the hue as is measured as percentage from 0%(gray) to 100%(fully saturated).
* Value - It is the relative brightness or darkness of color.
  

### 4. LAB color space  
Lab color space is more accurate color space. It uses three values L for perpectual lightness, a and b for the four unique colors of human vision: magenta, green, bluw and yellow.

### Gamut
The gamut of color system is the range of colors that can be displayed or printed.

<img src="https://qph.cf2.quoracdn.net/main-qimg-2f2434fc7556ec1a0688ebec6b5baf3c.webp" width = 300, height= 300>

These are just the theory behind the color spaces. Still there are lots of color spaces with respective characteristics. I have mentioned what i learned about them.
I also learned to perform to implement the Opencv functions related to color spaces and histogram like:

* `imread()`--to read the image
* `imshow()`--to show the image
* `cvtColor()`-- to convert the image to various format like bgr to gray, hsv vice versa, etc

And mainly to calculate the histogram. Histogram is calculated because it helps to get better view of photographs that are over or under exposed by histogram equalization.

In the code i simply created the histogram function(with the help of https://docs.opencv.org/3.4/d8/dbc/tutorial_histogram_calculation.html) which basically calculates the histogram of the input image.

steps:


1. In main function it reads the image and convert to gray and then to other formats. And displayed after calling the histogram fucntion.
2. Histogram function first checks whether the read image is present or empty.
3. It then separates the image into three planes b,g,r with `split()`.
4. It then sets up some parameters so that range does not exceeds.
5. `calcHist()` calculates the histogram for each channel b,g,r.
6. to visualize the histogram width and height is adjusted and then normalized so that the values fall in the given range indicated by the parameters entered.
7. And draw the histogram for each channel and finally display our histogram and wait for the user to exit.

### Problem encountered

what i could not undersatnd is that grayscale image requires 1 channel(black and white) but hsv, lab color spaces requires 3 channel( red,green,blue) while my code it only reads and displays bgr2hsv,bgr2gray.