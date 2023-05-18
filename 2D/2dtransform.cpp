#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

Mat rotation(const Mat& img){

    Point2f centre((img.cols-1)/2.0,(img.rows-1)/2.0);

    double angle = 45;
    double scale = 1.0;
    double radians = angle * CV_PI / 180.0;
    double cosine = cos(radians);
    double sine = sin(radians);
    Mat rotation_matrix = (Mat_<double>(2,3)<< cosine*scale, -sine*scale, centre.x*(1-cosine)+centre.y*sine,

                                              sine*scale,   cosine*scale, centre.y*(1-cosine)-centre.x*sine);                                                        

    
    Mat rotated_image = Mat::zeros(img.rows, img.cols, img.type());

    for(int i=0;i<img.rows;i++){

        for(int j=0;j<img.cols;j++){

            Mat pixel = (Mat_<double>(3,1) << j, i, 1);
            Mat newpixel = rotation_matrix * pixel;

            int x = round(newpixel.at<double>(0,0));
            int y = round(newpixel.at<double>(1,0));
            if(x >= 0 && x < img.cols && y >= 0 && y < img.rows){
                rotated_image.at<Vec3b>(y, x) = img.at<Vec3b>(i, j);
               }
       }
    }

    return rotated_image;
}

Mat translation(const Mat& img){

    int height = img.cols;
    int width = img.rows;

    float tx = float(width) / 4;
    float ty = float(height) / 4;

    float values[] = { 1.0, 0.0, tx, 
                       0.0, 1.0, ty };

    Mat translation_matrix = Mat(2, 3, CV_32F, values);

    
    Mat translated_image = Mat::zeros(img.rows, img.cols, img.type());

    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){

            Mat pixel = (Mat_<float>(3,1) << j, i, 1);

            Mat newpixel = translation_matrix * pixel;
            int x = round(newpixel.at<float>(0,0));
            int y = round(newpixel.at<float>(1,0));
            if(x >= 0 && x < img.cols && y >= 0 && y < img.rows){
                translated_image.at<Vec3b>(y, x) = img.at<Vec3b>(i, j);
         }
        }
    }

    return translated_image;
}    

// Mat rotation(const Mat& img){

//     Point2f centre((img.cols-1)/2.0,(img.rows-1)/2.0);
//     Mat rotation_matrix = getRotationMatrix2D(centre, 45, 1.0 );
//     Mat rotated_image;

//     warpAffine(img, rotated_image, rotation_matrix, img.size());
//     return rotated_image;
// }

// Mat translation(const Mat& img){

//     int height = img.cols;
//     int width = img.rows;

//     float tx = float(width) / 4;
//     float ty = float(height) / 4;
    
//     float values[] = { 1.0, 0.0, tx, 0.0, 1.0, ty };
//     Mat translation_matrix = Mat(2, 3, CV_32F, values);
    
//     Mat translated_image;

//     warpAffine(img, translated_image, translation_matrix, img.size());
//     return translated_image;
// }

Mat affine( const Mat& img){

    Mat affine_image = Mat::zeros(Size ( img.cols, img.rows),img.type());


    Point2f inpMat[3];
    Point2f outMat[3];

    inpMat[0] = Point2f(0.0,0.0);
    inpMat[1] = Point2f(img.cols,0.0);
    inpMat[2] = Point2f(0.0,img.rows);

    outMat[0] = Point2f(0,200);
    outMat[1] = Point2f(500,100);
    outMat[2] = Point2f(170,520);

    Mat M = getAffineTransform(inpMat,outMat);
    warpAffine(img,affine_image,M, affine_image.size());

    return affine_image;


}

int main(){

    Mat img = imread("coke.jpg");
    if (img.empty()) {
        cout << "image not found" << std::endl;
        return 0;
    }
    
    Mat rotated_image = rotation(img);
    imshow("rotated image", rotated_image);

    Mat translated_image = translation(img);
    imshow("translated image", translated_image);

    Mat affine_image = affine(img);
    imshow("input image", img);
    imshow("affine image", affine_image);

    waitKey(100000);
    destroyAllWindows();
    return 0;


}