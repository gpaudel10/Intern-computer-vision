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

    GaussianBlur(gray, blured, Size(11, 11), BORDER_DEFAULT); //kernel having width and height 11/11

    // frame = imread("input frame of video", IMREAD_GRAYSCALE);
     

    Canny(blured, edge, 100, 200,5,false); 
//  Canny('/path/to/img', minVal, maxVal, apertureSize, L2gradient) 
    imshow("canny edge", edge);

    char ch = (char)waitKey(1);
    if(ch == 's'){
        break;
    }
}
capt.release();
return 0;
}
