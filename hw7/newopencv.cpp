#include <iostream>
#include <filesystem>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "opencv2/imgproc/imgproc.hpp"
#include <cmath>

using namespace cv;
using namespace std;

int main()
{
    cv::Mat input = cv::imread("./bball.jpg");
    cv::Mat resiz;
    cv::resize(input, resiz, cv::Size(600,600), INTER_LINEAR);
    cv::imshow("resiz", resiz);

    waitKey(0);

    rectangle(resiz, Point(150,150), Point(450,450), Scalar(0, 0, 255), -1, LINE_8);
    imshow("resiz", resiz);

    waitKey(0);

    circle(resiz, Point(300,300), 150, Scalar(0, 255, 0), -1);
    imshow("resiz", resiz);

    waitKey(0);

    double topx = 300+(cos((3*M_PI)/4)*150);
    double topy = 300+(sin((3*M_PI)/4)*150);
    double botx = 300+(cos((-1*M_PI)/4)*150);
    double boty = 300+(sin((-1*M_PI)/4)*150);

    rectangle(resiz, Point(topx,topy), Point(botx,boty), Scalar(255, 0, 0), -1, LINE_8);
    imshow("resiz", resiz);

    waitKey(0);

    imwrite("./hw7_out.jpg", resiz);
    putText(resiz,"SAVED, Press any key to continue", Point(0,550), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0,255,0), 2, LINE_AA);

    imshow("resiz", resiz);

    waitKey(0);

    exit(0);

}
