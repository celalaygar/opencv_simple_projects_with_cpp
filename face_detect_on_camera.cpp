// kamera üzerinde face detect işlemi 
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

	CascadeClassifier dedektor;
	bool yuklendi = dedektor.load("C:\\haar\\haarcascade_frontalface_alt.xml");
	
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

		if (bulunanlar.size() > 0)
			for (int i = 0; i <= bulunanlar.size() - 1; i++){
				
				//kutu cızer
				rectangle(frame, bulunanlar[i].br(), bulunanlar[i].tl(), Scalar(0, 0, 0));
				/*
				Point pt1(bulunanlar[i].x + bulunanlar[i].width, bulunanlar[i].y + bulunanlar[i].height);
				Point pt2(bulunanlar[i].x, bulunanlar[i].y);
				rectangle(frame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
				*/
				
				// Draw the circle - daire cizer 
				/*
				int radius = cvRound((bulunanlar[i].width + bulunanlar[i].height)*0.25);
				Point center(bulunanlar[i].x + bulunanlar[i].width*0.5, bulunanlar[i].y + bulunanlar[i].height*0.5);
				circle(frame, center, radius, Scalar(255, 0, 0), 2, 8, 0);
				*/
			}
		imshow("Yuz Bulucu", frame);

		if (waitKey(3) == 27) break;
	}


	waitKey(0); // Wait for a keystroke in the window
	return 0;
}




