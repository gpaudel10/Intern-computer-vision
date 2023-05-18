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