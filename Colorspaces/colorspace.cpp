#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

void histogram(const Mat& img)
{
    if (img.empty()) {
        cout << "image not found" << std::endl;
        return;
    }

    // split the source image in its three r,g and b plane

    vector<Mat> bgr_planes;
    split(img, bgr_planes);

    // Sets the histogram parameters as

    int histSize = 256;
    float range[] = { 0, 256 }; 
    const float* histRange[] = { range };
    bool uniform = true, accumulate = false;


    Mat b_hist, g_hist, r_hist;
    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, histRange, uniform, accumulate);

    // for histogram visualization
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat img_hist(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

    //normalize so that the histograms will fit to the image size(0-256)

    normalize(b_hist, b_hist, 0, img_hist.rows, cv::NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, img_hist.rows, cv::NORM_MINMAX, -1, Mat());
    normalize(r_hist, r_hist, 0, img_hist.rows, cv::NORM_MINMAX, -1, Mat());

    //to draw the histograms for each channel

    for (int i = 1; i < histSize; i++)
    {
        line(img_hist, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
        line(img_hist, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
            Scalar(0, 255, 0), 2, 8, 0);
        line(img_hist, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
            Scalar(0, 0, 255), 2, 8, 0);
    }

    
    imshow("Input image", img);
    imshow("Histogram", img_hist);
    waitKey();
}
int main() {
   
    Mat image = imread("dog.png");
    
    
    Mat rgb, hsv, gray, lab, hsv2;
    cvtColor(image, rgb, COLOR_BGR2RGB);
    cvtColor(image, hsv, COLOR_BGR2HSV);
    cvtColor(image, gray, COLOR_BGR2GRAY);
    cvtColor(image, lab, COLOR_BGR2Lab);
    cvtColor(image, hsv2, COLOR_RGB2HSV);
   

    imshow("RGB", rgb);
    histogram(rgb);
    imshow("HSV", hsv);
    histogram(hsv);
    imshow("Grayscale", gray);
    histogram(gray);
    imshow("lab", lab);
    histogram(lab);

    waitKey(0);
    destroyAllWindows();
    return 0;
}