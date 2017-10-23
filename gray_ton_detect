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
#include "car.h"



using namespace cv;
using namespace std;

Mat src, src_gray, fakesrc; Scalar fake;
void fareTakip(int event, int x, int y, int flags, void *kullanici)
{
	//farenin sol tuşuna basarak sürüklendiğinde çizim yapıyor veya
	//farenin sol tuşuna tıklandığında çizim yapıyor
	if ((event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON) || event == EVENT_LBUTTONDOWN)
	{

		try {
			system("cls");
			cout << "<-------Gri Resim - Piksel Bilgi ------>" << endl;
			Scalar yogunluk = src_gray.at<uchar>(y, x);
			cout << endl;
			cout << "     " << "Gri Ton Degeri = " << yogunluk.val[0] << endl;
			cout << "     " << "Koordinat  x   = " << x << endl;
			cout << "     " << "Koordinat  y   = " << y << endl << endl << endl;
			fake = yogunluk;
		}
		catch (...)
		{
			system("cls");
			cout << "<-----------------Hata olustu.----------------->" << endl;
		}
		Mat img(480, 640, CV_8UC1, fake);
		imshow("click point",img);
	}

}

int main(int argc, char** argv)
{

	src = imread("C:\\Users\\ceecece\\Desktop\\ttt.jpg", CV_LOAD_IMAGE_COLOR);
	cvtColor(src, src_gray, CV_BGR2GRAY);
	namedWindow("Gri Resim", CV_WINDOW_AUTOSIZE);
	imshow("Gri Resim", src_gray);

	//fare hareketleri burada takip ediliyor
	setMouseCallback("Gri Resim", fareTakip, NULL);
	waitKey(0); // Wait for a keystroke in the window
	destroyAllWindows();
	return 0;
}	

