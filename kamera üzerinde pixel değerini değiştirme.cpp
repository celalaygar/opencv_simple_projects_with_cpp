#include <opencv2/highgui/highgui.hpp>
#include <opencv/highgui.h>
#include <opencv2/highgui/highgui.hpp>
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


	// detectMultiscale Cascade Classifier Parametreleri
	int groundThreshold = 2;
	double scaleStep = 1.1;
	Size minimumNesneBoyutu(5, 5);
	Size maksimumNesneBoyutu(250, 250);

	vector<Rect> bulunanlar;
	while (true) {
		kamera >> frame;

		cvtColor(frame, frame_gri, CV_BGR2GRAY);

		// Yüzleri algılayalım/bulalım/detect edelim :)
		dedektor.detectMultiScale(frame_gri, bulunanlar, scaleStep, groundThreshold, CV_HAAR_SCALE_IMAGE, minimumNesneBoyutu, maksimumNesneBoyutu);
		//resmin ilk 200 x 200 lük bölümünü tek renk haline getirdik
		for (int x = 0; x < 200;x++) {
			for (int y = 0; y < 200;y++) {
				frame.at<cv::Vec3b>(x, y)[0] = 255;    // mavi
				frame.at<cv::Vec3b>(x, y)[1] = 0;      // yeşil
				frame.at<cv::Vec3b>(x, y)[2] = 0;	   //kırmızı
			}
		}


		imshow("Yuz Bulucu", frame);

		if (waitKey(3) == 27) break;
	}


	waitKey(0); // Wait for a keystroke in the window
	return 0;
