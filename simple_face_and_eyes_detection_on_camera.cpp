
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
const char m[] = "M";
const char p[] = "P";
const char d[] = "4";
const char i[] = "2";

int main(int argc, char** argv)
{

	CascadeClassifier face_cascade, eye_cascade;
	if (!face_cascade.load("C:\\haar\\haarcascade_frontalface_alt2.xml")) {
		cout << "error face_cascade load...........";
		return 1;
	}
	if (!eye_cascade.load("C:\\haar\\haarcascade_eye.xml")) {
		cout << "error eye_cascade load...........";
		return 1;
	}

	VideoCapture capture(0);
	if (!capture.isOpened()) {
		cout << "error video devices not load...........";
		return 1;
	}
	Mat cap_img, gray_img;
	vector<Rect> faces, eyes;
	while (1) {
		capture >> cap_img;
		waitKey(10);
		cvtColor(cap_img, gray_img, CV_BGR2GRAY);
		equalizeHist(gray_img, gray_img);
		face_cascade.detectMultiScale(gray_img, faces, 1.1, 10, CV_HAAR_SCALE_IMAGE | CV_HAAR_DO_CANNY_PRUNING, CvSize(0, 0), CvSize(300, 300));
		for (int i = 0; i < faces.size(); i++) {
			Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
			Point pt2(faces[i].x , faces[i].y );
			Mat faceROI = gray_img(faces[i]);
			eye_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
			for (size_t j = 0; j < eyes.size(); j++) {

				Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
				int radius = cvRound((eyes[j].width+eyes[j].height)*0.25);
				circle(cap_img, center, radius, Scalar(255, 0, 0), 2, 8, 0);

			}
			rectangle(cap_img, pt1, pt2, CvScalar(0, 255, 0), 2, 8, 0);


		}
		imshow("RESULT", cap_img);
		waitKey(3);
		char c= waitKey(3);
		if(c == 27) {
			break;
		}

	}
	waitKey(0); // Wait for a keystroke in the window
	return 0;


}
