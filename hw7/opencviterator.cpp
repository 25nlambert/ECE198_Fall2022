
#include <iostream>
#include <filesystem>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "opencv2/imgproc/imgproc.hpp"
//#include <math.h>
#include <cmath>
using namespace cv;
//This is my file firstopencv.cpp
//
// This program uses opencv
// This program is called firstopencv.cpp
// A good way to compile this program is with the command line
// g++ firstopencv.cpp `pkg-config --cflags --libs opencv4`
//
// (a better way is to use CMake, but that is a topic for another day)
//
// Note the backquotes (aka backpops) are not single quotes
//
// This particular program loops through the current directory looking for jpg (or JPG) files
// it opens every one it finds in its own window.
// It relies on a usable X11 "DISPLAY"
//

  //define some inline functions to make the code more readable
  //make_iterator(path)  and make_recursive_iterator(path)
      inline std::filesystem::directory_iterator make_iterator(std::filesystem::path x) { return std::filesystem::directory_iterator(x); };
      inline std::filesystem::recursive_directory_iterator make_recursive_iterator(std::filesystem::path x) { return std::filesystem::recursive_directory_iterator(x, std::filesystem::directory_options::skip_permission_denied); };
 //get_begin(iterator)
      inline const std::filesystem::directory_iterator get_begin(std::filesystem::directory_iterator x) {return std::filesystem::begin(x);};
      inline const std::filesystem::recursive_directory_iterator get_begin(std::filesystem::recursive_directory_iterator x) {return std::filesystem::begin(x);};
   //
  //get_end(iterator)
      inline const std::filesystem::directory_iterator get_end(std::filesystem::directory_iterator x) {return std::filesystem::end(x);};
      inline const std::filesystem::recursive_directory_iterator get_end(std::filesystem::recursive_directory_iterator x) {return std::filesystem::end(x);}  ;
      //
      inline bool check_file(const std::filesystem::directory_iterator fil){ return (fil->is_regular_file() && fil->path().has_extension()&& (fil->path().extension()==".JPG"||fil->path().extension()==".jpg"));};
      //
      //
      //

void display(std::filesystem::path );


int main()
{
  auto iteratorbruce=make_iterator("./");
  auto beginbruce=get_begin(iteratorbruce);
  auto endbruce=get_end(iteratorbruce);
  int endit;
   
  for(iteratorbruce=beginbruce;iteratorbruce != endbruce;iteratorbruce++)
  {
     if(check_file(iteratorbruce)) display(iteratorbruce->path());
  }
  std::cout<<"Enter q to close all windows and quit"<<std::endl;


  while( (endit=cv::waitKey(100))!='q') if(endit > 1) std::cout<<"got "<<int(endit)<<std::endl;
}
void display(std::filesystem::path path) 
{
    cv::Mat bruce= cv::imread(path.filename());
    std::cout<<"Path is "<<path<<std::endl;
    cv::Mat resiz;
    cv::resize(bruce, resiz, cv::Size(600,600), INTER_LINEAR);
    cv::imshow("resiz", resiz);

    waitKey(0);

    //rectangle(resiz,(125,250),(375,750),(255,0,0),-1)
   //resize(bruce, resiz, cv::Size(1000,500), INTER_LINEAR);
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
//    std::cout<<boty;
    rectangle(resiz, Point(topx,topy), Point(botx,boty), Scalar(255, 0, 0), -1, LINE_8);
    imshow("resiz", resiz);

    waitKey(0);

    imwrite("./hw7_out.jpg", resiz);
    putText(resiz,"SAVED, Press any key to continue", Point(0,550), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0,255,0), 2, LINE_AA);

    imshow("resiz", resiz);

    waitKey(0);

    exit(0);
   /* if(!bruce.empty())
    {       cv::namedWindow(path.filename(),cv::WINDOW_NORMAL); 
        cv::imshow(path.filename(),bruce);
        cv::resizeWindow(path.filename(),800,600);
    }*/

}
