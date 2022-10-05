#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


//////  basic function ////////////

int main()
{
	string path = "Resource/mokoko_muscle.jpg";
	Mat img = imread(path);
	Mat imgResize;
	Mat imgGray;

	Mat Blue, Green, Red;
	vector<Mat> bgr(3);


	resize(img, imgResize, Size(), 0.25, 0.25);  //크기가 큰 이미지 파일 1/4로 재구성

	cvtColor(imgResize, imgGray, COLOR_BGR2GRAY); //cvtColor를 이요한 Grayscale

	//Split과 merge를 이용한 Grayscale image

	split(imgResize, bgr);

	vector<Mat> imgCh(3);

	imgCh[0] = bgr[2];
	imgCh[1] = bgr[1];
	imgCh[2] = bgr[0];

	Mat imgmer;

	merge(imgCh, imgmer);

	Mat mergedGray = 0.299 * bgr[2] + 0.587 * bgr[1] + 0.114 * bgr[0];

	imshow("Image", imgResize);
	imshow("image Gray", imgGray);

	imshow("blue", bgr[0]);
	imshow("green", bgr[1]);
	imshow("red", bgr[2]);

	imshow("merged merged", imgmer);

	imshow("merged Grayscale", mergedGray);


	waitKey(0);

	return 0;
}
