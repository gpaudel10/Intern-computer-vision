## 2D transformation of Images using Matrix Multiplication.

----

In this task I have learned about the 2D transformation of images like translation, rotation, perspective, euclidean and affine using matrix multiplication for translation and rotation as well as using `warpAffin` function of opencv. The function warpAffine transforms the source image as `warpAffine(src, M, dsize, dst, flags, borderMode, borderValue)` where the parameters used are:



* src - input image.
* dst - output image that has the size dsize and the same type as src .
* M	- 2×3 transformation matrix.
dsize	size of the output image.
* flags - combination of interpolation methods and the optional flag WARP_INVERSE_MAP that means that M is the inverse transformation ( dst→src ).
* borderMode - pixel extrapolation method when borderMode=BORDER_TRANSPARENT, it means that the pixels in the destination image corresponding to the "outliers" in the source image are not modified by the function.
* borderValue - value used in case of a constant border; by default, it is 0.

So basically transformation of image means changing the  shape, size, oreintation, color and other appearence of images without changing its content. when the transformation takes places in 2D planes it is then called as 2D transformation.There are various transformation techniques to transform the images such as:

### 1. Translation
It is a type of image transformation in which an image is moved or shifted from one position to another. The process involves moving every pixel of an image a certain distance in a given direction while preserving the size and shape of the image. It preserves the distance between each pair of points of the objects and thus overall shape and size of the object.

<img src = "https://www.tutorialspoint.com/computer_graphics/images/translation.jpg " width=300, height=200>

In 2D translation, the image is described by its x and y coordinates, and the translation operation is applied to these coordinates.If the translation distance is (tx, ty), then the new coordinates of a pixel at position (x,y) are given as (x + tx, y + ty) and the new coordinates is (x',y') as shown in the figure mentioned above.

### 2. Rotation
In rotation, we rotate the object at particular angle θ (theta) from its origin. From the following figure, we can see that the point P(x',y') is located at angle φ from the horizontal X coordinate with distance r from the origin. it preserves the oreintation of the object.

<img src = "https://www.tutorialspoint.com/computer_graphics/images/rotation.jpg" width = 300, height = 200>

<img src = "https://www.101computing.net/wp/wp-content/uploads/2D-Rotation-Matrix-1.png" width = 400, height = 200>

The above rotation matrix will change depending on positive or negative rotational angle.

### 3. Euclidean transformation

In this transformation it is either a translation, a rotation, or a reflection. Also the shape of a geometric object will not change. That means, lines transform to lines, planes transform to planes, circles transform to circles, and ellipsoids transform to ellipsoids. Only the position and orientation of the object will change.


### 3. Affine transformation

Affine transformations are generalizations of Euclidean transformations. Under affine transformations, lines transforms to lines; but, circles become ellipses. Length and angle are not preserved.
About this transformation what i learned from opencv documentation was, it is the trasformation that can be expressed in the form of matrix multiplication (linear transformation) followed by the vector addition ie translation. it preserves the lines and parallelism.

<img src = "https://static.packt-cdn.com/products/9781838646301/graphics/assets/67389115-e14a-41d2-a378-eac1f4135b75.png" width = 400, height = 200>

The usual way to represent an Affine Transformation is by using a 2×3 matrix as T = M.X where M is affine 2*3 matrix and X is the coordinate that we want to transform. I nabove figure affine transformation is apllied to the 1st image to obtained the 2nd image.


### 4. Projective transformation

Projective transformations are the most general linear transformations and require the use of homogeneous coordinates. Homogeneous coordinate means any point in the projective plane represented by (x, y, z), also called  projective coordinates of the point, where x, y and z are not all 0. Given a point in space in homogeneous coordinate (x,y,z,w) and its image under a projective transform (x',y',z',w'), a projective transform has the following form :

<img src = "https://pages.mtu.edu/~shene/COURSES/cs3621/NOTES/geometry/pr-tran-1.jpg" width = 400, height = 100>

The projective transformation does not preserve parallelism, length, and angle. But preserves collinearity and incidence (lines and points).

### 4. Similarity transformation

This transformation are called similarity transformations because they transform shapes into similar shapes by preserving the angles but not distances.

What i actually found out and learned is that there are  classes of transformation as:

• Rigid transformation (distance preserving)-
Translation + Rotation

• Similarity transformation (angle preserving)-
Translation + Rotation + Uniform Scale

• Affine transformation (parallelism preserving)-
Translation + Rotation + Scale + Shear


These transformation other than rotation translation was very new to me. So while coding i have used the opencv functions like `warAffine()`,`getRotationMatrix2D`,`getAffineTransform`,etc 

**To perform rotation** i had tried transformation using matrix multiplication. Where input image whose pixel value is stored in the form of matrix and i have calculated the center point with `Point2f center()`. And the parameters requires like tha value of theta in radian was used 45(could be any angle) and rotation matrix is defined with knowing that translating before rotation so that the origin remains at(0,0). And finally matrix multiplication with no. of rows and no.columns is done as`rotation_matrix*pixel`to obatined new pixel of the input image and new pixel value obtained is stored in matrix of newpixel.

**To perform translation** similarly for translation same procedure is done instead of translation matrix `{ 1.0, 0.0, tx, 0.0, 1.0, ty };`.As before a matrix with zeros is initialized and after performing the multipplication it is filled with new pixel values. 

**To perform affine, similarity and eulidean transformation**,the same code for rotation and translation can be modified with by keeping constant scaling values for euclidean and similarity transformation scaling with different values as well as shearing components also needed for affine transformation.And i had given random pixel value as (0,200),(500, 100),(170,520) as input of the image. Also i have tried affine transformation using affine function of opencv by looking in opencv documentation but commented it.









