#include <iostream>
#include <filesystem>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
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
    //cv::Mat bruce= cv::imread(path.filename());
    //cv::Mat dst; //didnt work
    std::cout<<"Path is "<<path<<std::endl;
    //cv::resize(bruce, dst, Size(500,1000), 0, 0, INTER_CUBIC); //didnt work
                         
    if(!bruce.empty())
    {       cv::namedWindow(path.filename(),cv::WINDOW_NORMAL); 
        cv::imshow(path.filename(),bruce);
        cv::resizeWindow(path.filename(),800,600);
    }
}
