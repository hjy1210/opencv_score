// Test application for the Visual Studio Image Watch Debugger extension
#include <iostream>                        // std::cout
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/imgcodecs/imgcodecs.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>     // cv::Canny()
using namespace std;
using namespace cv;
void help()
{
	cout
		<< "----------------------------------------------------" << endl
		<< "This is a test program for the Image Watch Debugger " << endl
		<< "plug-in for Visual Studio. The program loads an     " << endl
		<< "image from a file and runs the Canny edge detector. " << endl
		<< "No output is displayed or written to disk."
		<< endl
		<< "Usage:" << endl
		<< "image-watch-demo inputimage" << endl
		<< "----------------------------------------------------" << endl
		<< endl;
}
int main(int argc, char *argv[])
{
	String imageName("d:\\mia\\IMG_1902.JPG");
	help();
	if (argc > 1)
	{
		imageName = argv[1];
	}
	cout << "Loading input image: " << imageName << endl;
	Mat input;
	input = imread(imageName, IMREAD_COLOR);
	cout << "Detecting edges in input image" << endl;
	Mat edges;
	Canny(input, edges, 10, 100);
	return 0;
}
