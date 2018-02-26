
//zoom the image by using bilinear interpolation

#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;

int main()
{
	//Reading an image
	Mat image = imread("C:\\Users\\HP\\Pictures\\Download\\p3.png");

	Mat grey_image(image.rows, image.cols, CV_8UC1);

	Mat zoom_image1(image.rows, ((image.cols * 2) - 1), CV_8UC1);

	Mat zoom_image2(((image.rows * 2) - 1), ((image.cols * 2) - 1), CV_8UC1);
	Mat zoom_image3(((image.rows * 2) - 1), ((image.cols * 2) - 1), CV_8UC1);
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols;j++)
		{
			grey_image.at<uchar>(i, j) = (image.at<Vec3b>(i, j)[0] + image.at<Vec3b>(i, j)[1] + image.at<Vec3b>(i, j)[2]) / 3;
		}
	}

	int l = 0, m = 0;
	for (int i = 0; i < image.rows; i++)
	{
		m = 0;
		for (int j = 0; j < image.cols; j++)
		{
			zoom_image1.at<uchar>(l, m) = grey_image.at<uchar>(i, j);
			m++;
			if (j < (image.cols - 1))
			{
				zoom_image1.at<uchar>(l, m) = (int)((grey_image.at<uchar>(i, j)) + (grey_image.at<uchar>(i, (j + 1)))) / 2;
				m++;
			}
		}
		l++;
	}
	l = 0, m = 0;
	for (int i = 0; i <zoom_image1.rows; i++)
	{
		m = 0;
		for (int j = 0; j < zoom_image1.cols; j++)
		{
			zoom_image2.at<uchar>(l, m) = zoom_image1.at<uchar>(i, j);
			if (i < (int)(zoom_image1.rows - 1))
			{
				zoom_image2.at<uchar>((l + 1), m) = (int)((zoom_image1.at<uchar>(i, j)) + (zoom_image1.at<uchar>((i + 1), j))) / 2;

			}
			m++;
		}
		l = l + 2;
	}


	//Displaying an image
	imshow("1", image);

	//displaying gray image
	//imshow("2", grey_image);

	//Displaying zoom_image
	imshow("2", zoom_image1);
	imshow("3", zoom_image2);
	waitKey(0);

	return 1;
}