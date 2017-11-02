#include <opencv2/highgui/highgui.hpp>
#include <opencv/highgui.h>
#include <iostream>                        // std::cout
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/imgcodecs/imgcodecs.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>     // cv::Canny()
#include <math.h>
#include <vector>
#include <opencv/cv.h>
#include <opencv2/objdetect/objdetect.hpp>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	namedWindow("kontrol", CV_WINDOW_AUTOSIZE);
	VideoCapture vid(0);
	int hmin = 170, hmax = 179, smin = 150, smax = 255, vmin = 60, vmax = 255;
	createTrackbar("minH", "kontrol", &hmin, 179);
	createTrackbar("maxH", "kontrol", &hmax, 179);
	createTrackbar("minS", "kontrol", &smin, 255);
	createTrackbar("maxS", "kontrol", &smax, 255);
	createTrackbar("minV", "kontrol", &vmin, 255);
	createTrackbar("maxV", "kontrol", &vmax, 255);
	
	int eskix = -1, eskiy = -1;
	Mat araframe;
	vid.read(araframe);
	Mat cizgiresim = Mat::zeros(araframe.size(), CV_8UC3);
	while (true) {

		Mat yeniframe, Hsvres, Isres;
		vid.read(yeniframe);
		
		cvtColor(yeniframe, Hsvres, COLOR_BGR2HSV);
		imshow("HSV Image", Hsvres);

		//hsv nın scalar degerler arasındakı degerlere 1 dıgerlerıne 0 veren thereshold formatıdır.
		inRange(Hsvres, Scalar(hmin, smin, vmin), Scalar(hmax, smax, vmax), Isres);
		
		//aşındırma genişletme açma işlemidir.
		erode(Isres, Isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(Isres, Isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		
		//genişletme aşındırma kapatma işlemidir.
		dilate(Isres, Isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(Isres, Isres, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		 
		Moments konum = moments(Isres);
		double xeksen = konum.m10, yeksen = konum.m01, alan = konum.m00;
		if (alan > 10000) {
			int yenix = xeksen / alan;
			int yeniy = yeksen / alan;
			if (eskix >= 0 && eskiy >= 0 && yenix >= 0 && yeniy >= 0) {
				cout << "cizgi ciziliyor --------------------\n";
				line(cizgiresim, Point(yenix, yeniy), Point(eskix, eskiy),Scalar(0,255,0), 2);
			}
			eskix = yenix;  eskiy = yeniy;
		}
		imshow("cizgi resim", Isres);
		yeniframe = yeniframe+ cizgiresim;
		//1. deger giriş frame 2. deger cıkış frame 
		//3. deger 1 0 ve -1 degerini alır.
		flip(yeniframe, yeniframe, 1);
		imshow("Orjinal resim", yeniframe);
		if (waitKey(30) == 27) {
			cout << "uygulama sonlandı.";
			break;
		}
	}
	waitKey(0); // Wait for a keystroke in the window
	destroyAllWindows();
	return 0;
}
