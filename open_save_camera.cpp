//Kodların kullanımı için projenize opencv yi dahil etmeniz yeterlidir.
//opencv ile kamera açılıyor ayrıca kameradan aynı anda görüntü kayit işlemide yapılıyor.

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2\imgproc.hpp"
#include "opencv2\video\background_segm.hpp"
#include "opencv2\video\tracking.hpp"
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	namedWindow("Deneme", CV_WINDOW_AUTOSIZE);
	VideoCapture cap(0);
	Mat image;
//	cap.open(0); 
	int satir = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	int sutun = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	cout << "satir : " << satir << endl << "sutun : " << sutun << endl;
	Size boyut(sutun, satir);
	VideoWriter vd("c:\\Users\\ceecece\\Desktop\\mm.avi", CV_FOURCC_DEFAULT, 20, boyut, true);
	if (!vd.isOpened()) {
		cout << "kayit yapilamıyor..";	return -1;
	}
	while (true) { //kameradan alacağı görüntüyü kesintisiz bir şekilde alması için sonsuz döngü oluşturduk.
		cap >> image; 	cap.read(image);
		imshow("Deneme", image); //imshow metodunun birinci parametresi yukarıda namedWindow metoduyla oluşturduğumuz pencerenin adını alır.İkinci parametre Mat türünden değişken alır.
		vd.write(image);
		if (waitKey(30) == 27)
		{
			imshow("Deneme1", image); 	
			cout << "cikis yapildi.." << endl; 	
			break;
		}
	}
	cvDestroyWindow("Deneme");//Bu metod  kullandığımız pencereyi hafızadan siler.
	waitKey(0); // Wait for a keystroke in the window
	return 0;
  }
