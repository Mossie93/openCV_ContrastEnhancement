#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//checking if there are 4 parameters
	if(argc != 5)
	{
		cout<<"Error: There should be 4 parameters!\n";
		return -1;
	}


	//defying variables
	Mat inputImage, outputImage, kern;
	stringstream paramStream;
	short int pe;	// primary enhancementFactor
	short int se;	// primary enhancementFactor


	//loading input image
	inputImage = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	if(!inputImage.data)
	{
		cout<<"Error: Input file opening failure!\n";
		return -1;
	}


	//loading enhancement factors
	paramStream << argv[3];
	paramStream >> pe;
	paramStream.clear();
	paramStream << argv[4];
	paramStream >> se;
	cout << "primary enhancement factor: " << pe << endl;
	cout << "secondary enhancement factor: " << se << endl;
	if(pe > 255 || pe < -255 || se > 255 || se < -255)
	{
		cout<<"enhancement factors should be in range <-255, 255>\n";
		return -1;
	}

	//assigning mask to kern variable
	kern = (Mat_<char>(3,3) << 0,  se, 0,
							   se, pe, se,
							   0,  se, 0);

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