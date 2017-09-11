// resim gösterme işlemleri
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat image = imread("C://Users//ceecece//Desktop//Adsz.png");   // Read the file

	if (!image.data)                              // Check for invalid input
	{
		cout << "Could not open or find the image" << endl;
		waitKey(5000);
		return -1;
	}

	namedWindow("Display window", CV_WINDOW_AUTOSIZE);// Create a window for display.
	imshow("Display window", image);
	
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}
