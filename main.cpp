#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//checking if there are 4 parameters
	if(argc != 5)
	{
		cout<<"Error: There should be 3 parameters!\n";
		return -1;
	}


	//defying variables
	Mat inputImage, outputImage, kern;
	stringstream s;
	unsigned char pe, se;	// primary and secondary enhancementFactor


	//loading input image
	inputImage = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	if(!inputImage.data)
	{
		cout<<"Error: Input file opening failure!\n";
		return -1;
	}


	//loading enhancement factors
	s << argv[3];
	s >> pe;
	s << argv[4];
	s >> se;


	//assigning mask to kern variable
	kern = (Mat_<char>(3,3) << 0, se, 0,
							   se, pe, se,
							   0, se, 0);

	//applying mask to input image
	filter2D(inputImage, outputImage, inputImage.depth(), kern);

	//saving output image
	imwrite(argv[2], outputImage);

	//defying windows and siplaying images
	namedWindow("Input image", CV_WINDOW_AUTOSIZE);
	namedWindow("Output image", CV_WINDOW_AUTOSIZE);
	imshow("Input image", inputImage);
	imshow("Output image", outputImage);

	//waiting for signal to close
	waitKey(0);

	return 0;
}