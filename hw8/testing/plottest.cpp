#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

#include <filesystem>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "opencv2/imgproc/imgproc.hpp"

#define CVPLOT_HEADER_ONLY 1
#include <CvPlot/cvplot.h>


using namespace std;
using namespace cv;



int main() {

	int cols, x, y;
	string line;
	ifstream inputcsv;
	vector<pair<string,vector<double>>> read_csv;

	inputcsv.open("hw8.csv");
	if(!inputcsv.is_open()){ cout<<"Failed to open" <<endl;exit(1);}
	cols = read_csvfile(inputcsv, read_csv);

	cout<<"Sanity CHECK" <<read_csv[0].first << endl;

}
