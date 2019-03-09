#include<iostream>
#include<string>
#include<unistd.h>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
using namespace std;
using namespace cv;


class coder{
public:Mat image;
       string data;
public:coder(string path,Mat image);
       Mat& start();
       void initialize();
       ~coder();
};

class decoder{
public: Mat image;
        string data;
public:decoder(Mat &image);
       void start();
       void show();
       ~decoder();
};

