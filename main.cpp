#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>
#include <iostream>
#include <vector>
#include "opencv2/core/cuda.hpp"
using namespace cv;
using namespace cv::ml;
using namespace std;


int main() {
	int counter_left=0;
	int counter_right = 0;
	Mat img, gray, draw;
	string filename = "D:\\campus4-c1.avi";
	VideoCapture capture(filename);
	HOGDescriptor hog;
	vector< Rect > locations;
	vector< Rect > prev_locations;
	hog.setSVMDetector(hog.getDefaultPeopleDetector());
	Point prev_center = Point(0, 0);
	for (;;) 
	{
		capture >> img;
		resize(img, img, Size(288, 224));
		cvtColor(img, gray, CV_BGR2GRAY);
		draw = img.clone();
		hog.detectMultiScale(gray, locations);
		line(draw, Point(90, 0), Point(90, 224), Scalar(255, 0, 0), 2);
		stringstream c_left;
		stringstream c_right;
		c_left << "W lewo: " << counter_left;
		c_right << "W prawo: " << counter_right;
		putText(draw, c_left.str(), Point(95, 15), FONT_HERSHEY_COMPLEX, 0.5, Scalar(123, 180, 0), 2);
		putText(draw, c_right.str(), Point(180, 15), FONT_HERSHEY_COMPLEX, 0.5, Scalar(123, 180, 0), 2);
		if (!locations.empty() && !prev_locations.empty())
		{
			for (size_t i = 0; i < locations.size(); i++)
			{
				if (locations.size() == prev_locations.size())
				{
					double prev_width = prev_locations[i].width / 2;
					double prev_height = prev_locations[i].height / 2;
					prev_center = Point(prev_locations[i].x + prev_width, prev_locations[i].y + prev_height);
				}
				double width = locations[i].width / 2;
				double height = locations[i].height / 2;
				Point center = Point(locations[i].x + width, locations[i].y + height);
				circle(draw, center , 2, Scalar(0, 255, 0));
				rectangle(draw, locations[i], Scalar(0, 255, 0), 2);
				if (center.x < 90 && prev_center.x >= 90 && prev_center.x < 93)
				{
					line(draw, Point(90, 0), Point(90, 224), Scalar(0, 0, 255), 2);
					counter_left++;
				}
				if (center.x > 90 && prev_center.x <= 90 && prev_center.x > 87)
				{
					line(draw, Point(90, 0), Point(90, 224), Scalar(0, 0, 255), 2);
					counter_right++;
				}
			}
		}
		prev_locations = locations;
		imshow("Video", draw);
		waitKey(1);
	}
}