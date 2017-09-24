
#include <opencv2/highgui/highgui.hpp>
#include <opencv/highgui.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>                        // std::cout
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/imgcodecs/imgcodecs.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>     // cv::Canny()
#include <math.h>
#include "deneme.h"
#include <vector>
#include <opencv/cv.h>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat res = imread("C:\\Users\\ceecece\\Desktop\\12.jpg");
	if (res.empty()) {
		cout << "resim bulunamadı..";
		return -1;
	}
	Mat rr, cannyImage,grayimage;
	cvtColor(res, grayimage, CV_BGR2GRAY);
	imshow("ORJINAL-1", res);
  
	//3. deger min_threshold
	//4. deger max_threshold
	Canny(grayimage, cannyImage, 50, 150, 3);
	imshow("Canny Image",cannyImage);

	waitKey(0); // Wait for a keystroke in the window
	return 0;


}
