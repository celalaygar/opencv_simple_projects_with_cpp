#include <opencv2/highgui/highgui.hpp>
#include <iostream>                        // std::cout
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/imgcodecs/imgcodecs.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>     // cv::Canny()
using namespace cv;
using namespace std;
const char m[] = "M";
const char p[] = "P";
const char d[] = "4";
const char i[] = "2";
int main(int argc, char** argv)
{
	int cv = CV_FOURCC(m[0], p[0], d[0], i[0]);
	VideoCapture vid("C:\\Users\\ceecece\\Desktop\\soz_rap.mp4"); //"C:\\Users\\ceecece\\Desktop\\soz_rap.mp4"
	int satir, sutun;
	Mat frame,acikframe,koyuframe;

	if (!vid.isOpened()) {
		cout << "video acılamadı...";
		system("Pause");
		return -1;
	}
	
	cout << "video acıldı...";
	namedWindow("acik", CV_WINDOW_AUTOSIZE);
	namedWindow("kapali", CV_WINDOW_AUTOSIZE);
	namedWindow("kendi", CV_WINDOW_AUTOSIZE);
	
	sutun = vid.get(CV_CAP_PROP_FRAME_WIDTH);
	satir = vid.get(CV_CAP_PROP_FRAME_HEIGHT);
	Size boyut(sutun,satir);
	
	VideoWriter vid2("C:\\Users\\ceecece\\Desktop\\soz_1.mp4", cv, 23, boyut, true);
	VideoWriter vid3("C:\\Users\\ceecece\\Desktop\\soz_2.mp4", cv, 23, boyut, true);

	while (1) {
		vid.read(frame);
		
		if (waitKey(30) == 27)
		{
			imshow("Deneme1", frame);
			cout << "cikis yapildi.." << endl;
			break;
		}
		imshow("kendi", frame);
		acikframe = frame + Scalar(75, 75, 75);  imshow("acik", acikframe);             
		koyuframe = frame - Scalar(75, 75, 75);  imshow("kapali", koyuframe);
		vid2.write(acikframe);
		vid3.write(koyuframe);
	}



}
