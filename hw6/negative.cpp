#include <iostream>
#include <filesystem>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace std;

int main()
{
    cv::Mat boring = cv::imread("./boring.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat boringneg = boring;

    if(!boring.empty())
    {
        cv::imwrite("./boring_bw.jpg", boring);
        cv::imshow("Boring", boring);
        cv::imshow("negBoring", boringneg);
        cv::waitKey(100);
    }
    else
    {
        cout << "Image not found " << endl;
    }

    for(int i = 0; i < boringneg.rows; i++)
    {
        cv::imshow("negBoring", boringneg);
        cv::waitKey(5);
        for(int j = 0; j < boringneg.cols; j++)
        {
            boringneg.at<unsigned char>(i,j) = 255 - boringneg.at<unsigned char>(i,j);
        }
    }
    
    if(!boringneg.empty())
    {
        cv::imwrite("./boring_bw_neg.jpg", boringneg);
    }
    else
    {
        cout << "Did not write and empty file" << endl;
    }
    cv::waitKey(0);
}
