
- [Apply Line Detection in a video](#apply-line-detection-in-a-video)
  - [Overview](#overview)
  - [Hough transform algorithm](#hough-transform-algorithm)
  - [Summary of Line Detection Process in a video feed](#summary-of-line-detection-process-in-a-video-feed)
  - [Conclusion](#conclusion)
  - [Source code](#source-code)

## Apply Line Detection in a video
---

### Overview
Line detection is the technique that is used to identify and extract the straight lines from the image or video. Lines are the important features in an image used to represent boundaries of objects, edges, patterns,etc. In this task line detection is used in a video feed.Hough algorithm is used for the line detection with the help of OpenCV. This is the continuation the previous task of edge detection in a video feed.

### Hough transform algorithm
Hough transform is a feature extraction method to detect the lines, circles, and other geometrical shapes or curves. So basically all the lines can be represented in two ways:
* In cartesian coordinate system as:`y = mx+b`
* In polar coordinate system as: `ρ = xcosθ + ysinθ`
  
Hough transform works in polar coordinates system since in cartesian system algorithm won't be able to detect vertical lines because the slope m is will be infinity for vertical lines. In the polar system, there are two parameters, ρ, and θ, where ρ is the perpendicular distance of the line from the origin and θ is the angle made by the line from the x-axis. This overcomes the limitations of cartesian coordinates system. Any line can be represented in these two terms, (ρ,θ). So first it creates a 2D array or accumulator (to hold the values of the two parameters) and it is set to 0 initially. rows denote the ρ and columns denote the θ. Size of array depends on the accuracy needed. Suppose isf we want the accuracy of angles to be 1 degree, we will need 180 columns. For ρ, the maximum distance possible is the diagonal length of the image. So taking one pixel accuracy, the number of rows can be the diagonal length of the image. Incrementing the value of accumulator by in for each theta and taking corresponding ρ is called voting process. By continuing this maximum vote obtained will be the line.

<img src = "https://docs.opencv.org/3.4/Hough_Lines_Tutorial_Theory_0.jpg" width=300, height=200>

Hough transform converts the points in xy spaces to the c-m(intercept-slope) space. To perform the hough transform, first we have to perform the edge detection as in previous task and we have to take the edge detected image, and for every point that is non black, draw lines in the mc(parameter space)place. And lines will intersect. These intersections are the parameters of the line.

<img src = "https://sbme-tutorials.github.io/2021/cv/images/hough-mb_parameter_space.png" width=300, height=200>

### Summary of Line Detection Process in a video feed

As we know video is the sequence of images fist of all perform edge detection.

1. Convert to black and white for simplicity.

2. Determine edge pixels (i have used Canny edge detection algorithm)

3. For each pixel, convert to the parameter space and increment the appropriate spaces in the accumulator matrix. Here accumulator matrix is used to collect points of lines in descretized form so that the computer understands and this matrix is splits in defined bins.

4. Can be performed non-maximal suppression on the accumulator matrix to avoid near-duplicate lines caused by quantization.(I have used default hough line transfrom of opencv)

5. At last take the  intersection points in the parameter space and convert back to image space.


These are some background points related to how does the hough transform for line detection works. All these steps and mathematics has been implemented by opencv with `HoughLines()` function. Its syntax is : `HoughLines (image, lines, ρ, θ, threshold, srn = 0, stn = 0, min_theta = 0, max_theta = Math.PI)` where,

```
ρ - distance resolution of the accumulator in pixels
θ- angle resolution of the accumulator in radians
threshold - accumulator threshold parameter. Only thoselines are returned that get enough votes

srn and stn for multi-scale hough transform. equals to zero for normal method.

min_theta - minimum angle to check for lines between 0 and max_theta

max_theta - maximum angle to check for lines between min_theta and CV_PI.
```

These are the parameters used to change according to the desire of a problem. I have changed threshold parameter to see different results. Also there was another form know as probabilistic line transfrom, it is same as that of normal hough line transform but probabilistic line trasfrom minimises the computation needed to detect the lines by exploiting the difference on the fraction of votes needed to detect the lines with different numbers of supporting points.

Its syntax is: `HoughLinesP (image, lines, rho, theta, threshold, minLineLength = 0, maxLineGap = 0)` where,

```
minLineLength - minimum line length. Line segments shorter than that are rejected.
maxLineGap - maximum allowed gap between points on the same line to link them.
```

I have changed these two parameters to visualize different results.

### Conclusion

I was not much familiar with the usage of edge as well as line detection implemantation with c++. But learned about the working of these algorithms how we can modify the parameters. Also the `GaussianBlur();` function is used to reduce the noise by lowerig the size of image as well as to obtained more information. 

### Source code

```
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

int main(int argc, char** argv){

if(argc < 2){
    cout<<"path not found"<<endl;
    return -1;
}

VideoCapture capt(argv[1]);
if (!capt.isOpened()){
    cout<<"couldnot open the video"<<endl;
    return -1;
}

while(1){
    Mat frame; 
    capt >> frame;
    if(frame.empty()){
        cout<<"error reading!!"<<endl;
        break;
    }
    Mat gray, blured, edge, newdst, newdstp; 

    cvtColor(frame, gray, COLOR_BGR2GRAY); 
    newdst = gray.clone();
    newdstp = gray.clone();

    GaussianBlur(gray, blured, Size(11, 11), BORDER_DEFAULT);
    Canny(blured, edge, 100, 200,5,false); 
    // imshow("canny edge", edge);
    // newdst = edge.clone();

    // hough line transform
    vector<Vec2f> lines; // it holds the result of the detection
    HoughLines(edge, lines, 1, CV_PI/180, 250, 0, 0 ); // main func to detect line
    // drawing the lines with this formula
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 3000*(-b));
        pt1.y = cvRound(y0 + 3000*(a));
        pt2.x = cvRound(x0 - 3000*(-b));
        pt2.y = cvRound(y0 - 3000*(a));
        line( newdst, pt1, pt2, Scalar(0,0,255), 5, LINE_AA);
    }
      // probabilistic line transform
    vector<Vec4i> linesP; 
    HoughLinesP(edge, linesP, 1, CV_PI/180, 250, 50, 500 ); 
    
    for( size_t i = 0; i < linesP.size(); i++ )
    {
        Vec4i l = linesP[i];
        line( newdstp, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
    }
    imshow("Detected lines using standard hough line transform", newdst);
    imshow("detected lines using probabilistic hough line transform", newdstp);

    char ch = (char)waitKey(1);
    if(ch == 's'){
        break;
    }
}
capt.release();
return 0;
}

```