
- [Understand Camera Matrix and 3D Transformations](#understand-camera-matrix-and-3d-transformations)
  - [Goal](#goal)
  - [Camera matrix](#camera-matrix)
  - [3D rigid transformation](#3d-rigid-transformation)
  - [3D rotation](#3d-rotation)
  - [3D to 2D projections](#3d-to-2d-projections)


## Understand Camera Matrix and 3D Transformations
---
### Goal

To be familiar with camera matrix and its components like intrinsic matrix, extrinsic matrix and 3D rigid transformations involving 3D to 2D projections, 3D rotations.

### Camera matrix

Camera matrix also know as projection matrix that describes the mapping of a pinhole camera from 3D points in the real world to 2D points in an image. Here pinhole camera is the simple camera that does not have a lens instead uses small tiny hole to focus all light rays within the smalllest possible area to obtained an image more clearly as possible and the image formed using a pinhole camera is always inverted. 

<img src = "https://www.schoolphysics.co.uk/age11-14/Light/text/Pinhole_camera/images/2.png" width=400, height=300>

Four things to remember:
1. when we reduce the distance between the screen and pinhole, then the size of tha image will decrease.
2. but when we increase the distance between the screen and pinhole the the size of the image will increase.
3. when we increase the distance of the object from the pinhole, then the size of the image will be decreased.
4. and when we decrease the idstance of the object from the pinhole the the size of the image will be increased.

So the camera plays a very important role in cpaturing 3D images and storing them in 2D images. The followi equation can represent the camera:
`x=PX` here x denotes the 2d image point, P denotes camera matrix and X denotes 3d world point.


<img src = "https://editor.analyticsvidhya.com/uploads/887441.png" width=400, height=200>

Camera matrix is composed of two components: intrinsic and extrinsic matrices.

1. Intrinsic matrix
The intrinsic matrix describes the internal parameters of the camera, such as the focal length, the image sensor size, and the lens distortion. It is denoted by K and is a 3x3 matrix. In opencv represented as: `Mat K = (Mat_<double>(3, 3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);`


2. Extrinsic matrix
The extrinsic matrix describes the position and orientation of the camera in 3D space. It is denoted by [R|t] and is a 3x4 matrix, where R is a 3x3 rotation matrix that describes the orientation of the camera, and t is a 3x1 translation vector that describes the position of the camera in 3D space. In opencv represented as: for rotation
`Mat R = (Mat_<double>(3, 3) << r11, r12, r13,   r21, r22, r23, r31, r32, r33);`, for translation
`Mat t = (Mat_<double>(3, 1) << tx, ty, tz);`
and concatenate both as:
```
Mat Rt;
hconcat(R, t, Rt)
```

We can put the camera intrinsics and extrinsics together to obtain a single 3 × 4 camera matrix
`P = K [R t]`.

<img src = "https://i.stack.imgur.com/AGwu9.jpg" width=400, height=200>

### 3D rigid transformation

In 3D space, rigid body transforms are composed of tranlations along 3D vectors and rotations around coordinate axes. A transformation is said to be rigid if it preserves relatives distance as well as angle between the points. It can be represented by a combination of a 3d rotation matrix R and a 3d translation matrix t. the transformation matrix for a rigid transformation is denoted by [R t] and is 4*4 matrix of the form mentioned above.

This transformation can be applied to a 3d point P by representing it in homogenous coordinates as [X,Y,Z,1] and multiplying it by the transformation matrix to get the transformed in homogeneous coordinates as [X',Y',Z',1] and can be convert back to cartesian coordinates by dividing by fourth coordinate as [X/w',Y/w',Z/w'].

### 3D rotation
In 3D rotation we need angle of roatation as well as axis of roatation. The axis can be either x or y or z and also can be roatated in clockwise as well as anticlockwise direction.

* rotation matrix about x-axis is:

<img src = "https://static.javatpoint.com/tutorial/computer-graphics/images/computer-graphics-3d-rotation-about-arbitrary-axis3.png" width=300, height=200>


* rotation matrix about y-axis is:

<img src = "https://static.javatpoint.com/tutorial/computer-graphics/images/computer-graphics-3d-rotation-about-arbitrary-axis4.png" width=300, height=200>


* rotation matrix about z-axis is:

<img src = "https://static.javatpoint.com/tutorial/computer-graphics/images/computer-graphics-3d-rotation-about-arbitrary-axis2.png" width=300, height=200>

### 3D to 2D projections

Projections is a way to transform a world from one dimensionality to another. Here is the types projections in a tree structure:

<img src = "https://image.slidesharecdn.com/sanu-120330032303-phpapp01/75/projection-in-computer-graphics-5-2048.jpg?cb=1666751232" width=400, height=400>

In parallel projection, coordinate positions are transformed to the view plane along the parallel lines.

<img src = "https://image.slidesharecdn.com/sanu-120330032303-phpapp01/75/projection-in-computer-graphics-4-2048.jpg?cb=1666751232" width=300, height=200>

In perspective projection, object position are transformed to the view plane along lines that converge to a point called center od projection.

<img src = "https://image.slidesharecdn.com/sanu-120330032303-phpapp01/75/projection-in-computer-graphics-3-2048.jpg?cb=1666751232" width=300, height=200>


So to implement the camera matrix as well as 3D to 2D projection, 3D rotation is important in computer vision field and we can do these with the help of opencv built in functions and classes.like `template<typename _Tp>
class cv::Point3_< _Tp >` and I have just collected some formula of and commented in .cpp file.