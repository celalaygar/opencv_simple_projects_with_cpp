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
	VideoCapture kamera(0);
	Mat frame, frame_gri;
	int ToplamPixel = 0, pixel = 0, cnt = 0,c;
	while (true) {
		kamera >> frame;
		c = 0;
		ToplamPixel = frame.rows*frame.cols;
		pixel = (frame.rows - 100)*(frame.cols - 100); cnt = 0;

		cvtColor(frame, frame_gri, CV_BGR2GRAY);
		//resmin ilk 200 x 200 lük bölümünü tek renk haline getirdik
		for (int x = 50; x < frame.rows - 50; x++) {
			for (int y = 50; y < frame.cols - 50; y++) {
				int b = 0, c = 0, a = 0;
				a = frame.at<cv::Vec3b>(x, y)[0];  //blue
				b = frame.at<cv::Vec3b>(x, y)[1];  //green
				c = frame.at<cv::Vec3b>(x, y)[2];  //red
				if (a < 25 && b < 25 && c < 25) {
					cnt++;
				}
			}
		}
		cout << " tp : " << ToplamPixel << "     p : " << pixel << "       cnt : " << cnt << endl;
		if (cnt > pixel - 15000)
			cout << " kamera önünde engel var " << endl;
		imshow("Görüntü", frame);
		if (waitKey(33) == 27) break;
	}
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}
