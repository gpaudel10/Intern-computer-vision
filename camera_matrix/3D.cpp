// #include <iostream>
// #include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// using namespace std;
// using namespace cv;

// int main(){
    
//     // intrinsic matrix
//     Mat K = (Mat_<double>(3, 3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);

//     // extrinsic matrix with rotation and translation
//     Mat R = (Mat_<double>(3, 3) << r11, r12, r13, r21, r22, r23, r31, r32, r33);
//     Mat t = (Mat_<double>(3, 1) << tx, ty, tz);
//     Mat Rt;
//     hconcat(R, t, Rt);

//     // camera matrix
//     Mat P = K * Rt;

//     // 3d point
//     Mat point3D = (Mat_<double>(4, 1) << X, Y, Z, 1);

//     // 3d to 2d projection
//     Mat point2D = P * point3D;
//     point2D /= point2D.at<double>(2);
// }