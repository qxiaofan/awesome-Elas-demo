#include "StereoEfficientLargeScale.h"

int main(int argc, char **argv)
{
        std::string left_image_path = argv[1];
        std::string right_image_path = argv[2];
        cv::Mat leftim = cv::imread(left_image_path);
        cv::Mat rightim = cv::imread(right_image_path);

        cv::namedWindow("left_image",1);
        cv::namedWindow("right_image",1);
        cv::imshow("left_image",leftim);
        cv::imshow("right_image",rightim);
        cv::waitKey(600);
	
	Mat dest;
	StereoEfficientLargeScale elas(0,128);
	
	elas(leftim,rightim,dest,100);

	Mat disp;
	dest.convertTo(disp,CV_8U,1.0/8);
	
	cv::Mat disp_color;//伪彩色
	applyColorMap(disp,disp_color,cv::COLORMAP_JET);

        cv::namedWindow("disp",1);
	imshow("disp",disp);

	cv::namedWindow("disp_color",1);
	cv::imshow("disp_color",disp_color);
	
	std::string disp_map_path = argv[2]; 	disp_map_path += ".d.bmp";
        std::string disp_color_map_path = argv[2]; disp_color_map_path += ".c.bmp";
	cv::imwrite(disp_map_path,disp);
	cv::imwrite(disp_color_map_path,disp_color);
	waitKey();
	return 0;
}
