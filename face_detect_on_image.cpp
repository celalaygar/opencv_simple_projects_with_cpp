// resim üzerinde basit yüz tespiti opencv ile 

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

void tespitEt() {
	CascadeClassifier dedektor;
	bool yuklendi = dedektor.load("C:\\haar\\haarcascade_frontalface_alt.xml");
	Mat frame_gri;

	Mat frame2 = imread("C:\\Users\\ceecece\\Desktop\\123.jpg", CV_LOAD_IMAGE_COLOR);
	int groundThreshold = 2;
	double scaleStep = 1.1;
	Size minimumNesneBoyutu(5, 5);
	Size maksimumNesneBoyutu(250, 250);

	vector<Rect> bulunanlar;

	cvtColor(frame2, frame_gri, CV_BGR2GRAY);

	// Yüzleri algılayalım/bulalım/detect edelim :)
	dedektor.detectMultiScale(frame_gri, bulunanlar, scaleStep, groundThreshold, CV_HAAR_SCALE_IMAGE, minimumNesneBoyutu, maksimumNesneBoyutu);
	
	//yüzü tespit ederken cizim rengini belirleme
	Scalar renk = Scalar(0, 0, 110);
	
	
	if (bulunanlar.size() > 0)
		for (int i = 0; i <= bulunanlar.size() - 1; i++)
			rectangle(frame2, bulunanlar[i].br(), bulunanlar[i].tl(), renk);

	imshow("resim", frame2);
}

int main(int argc, char** argv)
{

	tespitEt();

	waitKey(0); // Wait for a keystroke in the window
	return 0;

 }
