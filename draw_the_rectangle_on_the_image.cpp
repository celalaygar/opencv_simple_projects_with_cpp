
#include <opencv2/highgui/highgui.hpp>
#include <opencv/highgui.h>
#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>                        // std::cout
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/imgcodecs/imgcodecs.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>     // cv::Canny()
#include <math.h>
#include <vector>
#include <opencv/cv.h>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2\video\background_segm.hpp> //for MOG, GMG
#include <iostream>

using namespace cv;
using namespace std;
Mat resim;

Point firstPoint,lastPoint;

void fareTakip(int event, int x, int y, int flags, void *kullanici)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		//firstPoint.x = x;   firstPoint.y = y;
		firstPoint = Point(x, y);
	}

	//farenin sol tuşana basarak sürükleyince
	if (flags == EVENT_FLAG_LBUTTON && event == EVENT_MOUSEMOVE)
	{
		lastPoint = Point(x, y);
		Mat arkaPlan = Mat::zeros(resim.size(), CV_8UC3); //0 matrisi olusturuldu
		rectangle(arkaPlan, firstPoint, lastPoint, Scalar(0, 0, 255), 4, 8, 0);
		arkaPlan = arkaPlan + resim;
		imshow("dörtgen Çizme", arkaPlan);
	}

	if (event == EVENT_LBUTTONUP)
	{
	
		//aynı noktaya tıklayıp bırakınca Dikdörtgen çizmiyor
		if (!(firstPoint == lastPoint))
		{
			rectangle(resim, firstPoint, lastPoint, Scalar(0, 255, 0), 4, 8, 0);
			imshow("dörtgen Çizme", resim);
		}

	}
}

int main(int argc, char** argv)
{
	resim = imread("C:\\Users\\ceecece\\Desktop\\12.jpg", CV_LOAD_IMAGE_COLOR);
	if (resim.empty())
	{
		cout << "Resim acilamadi" << endl; return -1;
	}
	imshow("dörtgen Çizme", resim);

	setMouseCallback("dörtgen Çizme", fareTakip, NULL);

	waitKey(0); // Wait for a keystroke in the window
	destroyAllWindows();
	return 0;
}
