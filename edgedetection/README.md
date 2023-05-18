- [Implement Edge Detection on a Video Feed.](#implement-edge-detection-on-a-video-feed)
  - [Canny Edge Detection](#canny-edge-detection)

## Implement Edge Detection on a Video Feed.
---
Edge detection is an image processing technique used for finding the boundaries or edges of the objects within the image. It is used for image segmantation and information extraction from the image that is useful for various application the field such as image processing, computer vision, etc. Basically sudden changes in pixel intensity defines the edge. Edges are those point where the image brightness varies sharply.

Real time edge detection can be implemented in an image or video usinf various edge detection algorithms. Some of them are:

* Prewitt edge detection
* Sobel edge detection
* Laplacian edge detection
* Canny edge detection
  
In this task I have used canny edge detection because it produces very clean edges by performing in number of processing steps as well as it is being widely used which is also implemented in OpenCV as `cv::canny()` function.

### Canny Edge Detection

It is multi-stage algorithm used to identify wide range of edges with the followings key steps:

* Converts the image into the grayscale.
* Reduce noise.
* Calculate the gradient(helps to identify the edge intensity and direction). 
* Non-maximum supression(to thin the image).
* Doubled threshold (to identify strong, weak, and irrelevant pixels in the image). 
* Hysteresis edge tracking(helps convert the weak pixels into strong ones only if they have a strong pixel around them).
  
These are the key steps used in canny edge detection. In opencv the syntax of canny edge detection is: `Canny('/path', minVal, maxVal, apertureSize, L2gradient) ` where:

```/path: file path of the image/video
minVal: Minimum intensity gradient
maxVal: Maximum intensity gradient
aperture: It is optional argument
L2gradient: Its default value is false, if value is true, Canny () uses a more computationally expensive equation to detect edges, which provides more accuracy at the cost of resources.
```

Steps involved during implementation of algorithms:

1.  At first the image is is converted to the grayscale so  that computation becomes simple.
2.  For noise reduction Gaussian kernel is used. Since the mathematics involved behind the scene are mainly based on derivatives edge detection results are highly sensitive to image noise.One way to get rid of the noise on the image, is by applying Gaussian blur to smooth it. For that, image convolution technique is applied with a Gaussian Kernel (3x3, 5x5, 7x7 etc…). The kernel size depends on the expected blurring effect. Basically, the smallest the kernel, the less visible is the blur. I have used a 11 by 11 Gaussian kernel with the syntax as `GaussianBlur(gray, blured, Size(11, 11), BORDER_DEFAULT);`.

In this way i had tested sample mp4 video.

I have used this algorithm to detect the edge of the mp4 file as :

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
        Mat gray, blured, edge; 

        cvtColor(frame, gray, COLOR_BGR2GRAY); 

        GaussianBlur(gray, blured, Size(11, 11), BORDER_DEFAULT);

        // frame = imread("input frame of video", IMREAD_GRAYSCALE);
        

        Canny(blured, edge, 100, 200,5,false); 
        imshow("canny edge", edge);

        char ch = (char)waitKey(1);
        if(ch == 's'){
            break;
        }
    }
    capt.release();
    return 0;
    }
```

In above code various Opencv function is used like capturing video, reading each frame and applying canny edge and showing the final result.