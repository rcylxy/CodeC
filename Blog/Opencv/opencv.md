# 基于人工智能的图像处理技术(PBLF)
## 1. Opencv3.4.8+Opencv_contrib3.4.8在Ubuntu的配置
## 2. Takephotos使用Opencv处理照片
### 2.1 对ORL_Faces图集的介绍
### 2.2 调用摄像头实现拍照功能与预处理
```cpp
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include<stdio.h>
//#include <stdio.h>
//#include <cv.h>  
using namespace std;
using namespace cv;
int main() 
{
	CascadeClassifier cascada;
	cascada.load("/home/lxy/opencv-3.4.8/data/haarcascades/haarcascade_frontalface_alt2.xml");
	VideoCapture cap(0);
	Mat frame, myFace;
	int pic_num = 1;
	while (1) {
		//摄像头读图像
		cap >> frame;
		vector<Rect> faces;//vector容器存检测到的faces
		Mat frame_gray;
		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);//转灰度化，减少运算
		cascada.detectMultiScale(frame_gray, faces, 1.1, 4, CV_HAAR_DO_ROUGH_SEARCH, Size(70, 70), Size(1000, 1000));
		printf("检测到人脸个数：%d\n", faces.size());
		//1.frame_gray表示的是要检测的输入图像 2.faces表示检测到的人脸目标序列,3. 1.1表示每次图像尺寸减小的比例
		//4. 4表示每一个目标至少要被检测到3次才算是真的目标(因为周围的像素和不同的窗口大小都可以检测到人脸表示每一个目标至少要被检测到3次才算是真的目标(因为周围的像素和不同的窗口大小都可以检测到人脸
		/*5.flags–要么使用默认值，要么使用CV_HAAR_DO_CANNY_PRUNING，
			函数将会使用Canny边缘检测来排除边缘过多或过少的区域，
			因为这些区域通常不会是人脸所在区域；opencv3 以后都不用这个参数了*/
		//6. Size(100, 100)为目标的最小尺寸 一般为30*30 是最小的了 也够了
		//7. Size(500, 500)为目标的最大尺寸 其实可以不用这个，opencv会自动去找这个最大尺寸
		//适当调整5,6,7两个参数可以用来排除检测结果中的干扰项。
		//识别到的脸用矩形圈出
		for (int i = 0; i < faces.size(); i++) 
		{
			rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
		}
		//当只有一个人脸时，开始拍照
		if (faces.size() == 1) 
		{
			Mat faceROI = frame_gray(faces[0]);//在灰度图中将圈出的脸所在区域裁剪出
			//cout << faces[0].x << endl;//测试下face[0].x
			resize(faceROI, myFace, Size(92, 112));//将兴趣域size为92*112
			putText(frame, to_string(pic_num), faces[0].tl(), 3, 1.2, (0, 0, 225), 2, 0);//在 faces[0].tl()的左上角上面写序号
			string filename = format("%d.jpg", pic_num); //存放在当前项目文件夹以1-10.jpg 命名，format就是转为字符串
			imwrite(filename, myFace);//存在当前目录下
			imshow(filename, myFace);//显示下size后的脸
			waitKey(500);//等待500us
			destroyWindow(filename);//:销毁指定的窗口
			pic_num++;//序号加1
			if (pic_num == 11) 
			{
				return 0;//当序号为11时退出循环
			}
		}
		int c = waitKey(10);
		if ((char)c == 27) { break; } //10us内输入esc则退出循环
		imshow("frame", frame);//显示视频流
		waitKey(100);//等待100us
	}
	return 0;
}
```
### 2.3 利用create_csv.py实现at.txt文档的生成
```py
#!/usr/bin/env python
 
import sys
import os.path
 
# This is a tiny script to help you creating a CSV file from a face
# database with a similar hierarchie:
#
#  philipp@mango:~/facerec/data/at$ tree
#  .
#  |-- README
#  |-- s1
#  |   |-- 1.pgm
#  |   |-- ...
#  |   |-- 10.pgm
#  |-- s2
#  |   |-- 1.pgm
#  |   |-- ...
#  |   |-- 10.pgm
#  ...
#  |-- s40
#  |   |-- 1.pgm
#  |   |-- ...
#  |   |-- 10.pgm
#
 
if __name__ == "__main__":
 
    if len(sys.argv) != 2:
        print ("usage: create_csv <base_path>")
        sys.exit(1)
 
    BASE_PATH=sys.argv[1]
    SEPARATOR=";"
 
    label = 0
    for dirname, dirnames, filenames in os.walk(BASE_PATH):
        for subdirname in dirnames:
            subject_path = os.path.join(dirname, subdirname)
            for filename in os.listdir(subject_path):
                abs_path = "%s/%s" % (subject_path, filename)
                print ("%s%s%d" % (abs_path, SEPARATOR, label))
            label = label + 1
```
## 3. Train训练生成自身的.xml人脸模型
```cpp
#include "/home/lxy/opencv-3.4.8/opencv_contrib-3.4.8/modules/face/include/opencv2/face/facerec.hpp"
#include "/usr/local/include/opencv2/core.hpp"
#include "/usr/local/include/opencv2/face.hpp"
#include "/usr/local/include/opencv2/highgui/highgui.hpp"
 #include "/usr/local/include/opencv2/imgproc/imgproc.hpp"
#include <math.h>
#include <iostream>  
#include <fstream>  
#include <sstream>  
using namespace cv;
using namespace cv::face;
using namespace std;
 
static Mat norm_0_255(InputArray _src) {
	Mat src = _src.getMat();
	// 创建和返回一个归一化后的图像矩阵:  
	Mat dst;
	switch (src.channels()) {
	case 1:
		cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
		break;
	case 3:
		cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
		break;
	default:
		src.copyTo(dst);
		break;
	}
	return dst;
}
 
//使用CSV文件去读图像和标签，主要使用stringstream和getline方法  
static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
	std::ifstream file(filename.c_str(), ifstream::in);//c_str()函数可用可不用，无需返回一个标准C类型的字符串
	if (!file) 
	{
		string error_message = "No valid input file was given, please check the given filename.";
		CV_Error(CV_StsBadArg, error_message);
	}
	string line, path, classlabel;
	while (getline(file, line)) //从文本文件中读取一行字符，未指定限定符默认限定符为“/n”
	{
		stringstream liness(line);//这里采用stringstream主要作用是做字符串的分割
		getline(liness, path, separator);//读入图片文件路径以分好作为限定符
		getline(liness, classlabel);//读入图片标签，默认限定符
		if (!path.empty() && !classlabel.empty()) //如果读取成功，则将图片和对应标签压入对应容器中
		{
			images.push_back(imread(path, 0));
			labels.push_back(atoi(classlabel.c_str()));
		}
	}
}
 
int main()
{
	//读取你的CSV文件路径.  
	//string fn_csv = string(argv[1]);  
	string fn_csv = "/home/lxy/test/test1/at.txt";
 
	// 2个容器来存放图像数据和对应的标签  
	vector<Mat> images;
	vector<int> labels;
	// 读取数据. 如果文件不合法就会出错  
	// 输入的文件名已经有了.  
	try
	{
		read_csv(fn_csv, images, labels); //从csv文件中批量读取训练数据
	}
	catch (cv::Exception& e)
	{
		cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
		// 文件有问题，我们啥也做不了了，退出了  
		exit(1);
	}
	// 如果没有读取到足够图片，也退出.  
	if (images.size() <= 1) {
		string error_message = "This demo needs at least 2 images to work. Please add more images to your data set!";
		CV_Error(CV_StsError, error_message);
	}
 
	for (int i = 0; i < images.size(); i++)
	{
		if (images[i].size() != Size(92, 112))
		{
			cout << i << endl;
			cout << images[i].size() << endl;
		}
	}
 
 
	// 下面的几行代码仅仅是从你的数据集中移除最后一张图片，作为测试图片  
	//[gm:自然这里需要根据自己的需要修改，他这里简化了很多问题]  
	Mat testSample = images[images.size() - 1];
	int testLabel = labels[labels.size() - 1];
	images.pop_back();//删除最后一张照片，此照片作为测试图片
	labels.pop_back();//删除最有一张照片的labels
	// 下面几行创建了一个特征脸模型用于人脸识别，  
	// 通过CSV文件读取的图像和标签训练它。  
	// T这里是一个完整的PCA变换  
	//如果你只想保留10个主成分，使用如下代码  
	//      cv::createEigenFaceRecognizer(10);  
	//  
	// 如果你还希望使用置信度阈值来初始化，使用以下语句：  
	//      cv::createEigenFaceRecognizer(10, 123.0);  
	//  
	// 如果你使用所有特征并且使用一个阈值，使用以下语句：  
	//      cv::createEigenFaceRecognizer(0, 123.0);  
 
	//创建一个PCA人脸分类器，暂时命名为model吧，创建完成后
	//调用其中的成员函数train()来完成分类器的训练
	Ptr<BasicFaceRecognizer> model = EigenFaceRecognizer::create();
	model->train(images, labels);
	model->save("MyFacePCAModel.xml");//保存路径可自己设置，但注意用“\\”
 
	Ptr<BasicFaceRecognizer> model1 = FisherFaceRecognizer::create();
	model1->train(images, labels);
	model1->save("MyFaceFisherModel.xml");
 
	Ptr<LBPHFaceRecognizer> model2 = LBPHFaceRecognizer::create();
	model2->train(images, labels);
	model2->save("MyFaceLBPHModel.xml");
 
	// 下面对测试图像进行预测，predictedLabel是预测标签结果  
	//注意predict()入口参数必须为单通道灰度图像，如果图像类型不符，需要先进行转换
	//predict()函数返回一个整形变量作为识别标签
	int predictedLabel = model->predict(testSample);//加载分类器
	int predictedLabel1 = model1->predict(testSample);
	int predictedLabel2 = model2->predict(testSample);
 
	// 还有一种调用方式，可以获取结果同时得到阈值:  
	// int predictedLabel = -1;  
	// double confidence = 0.0;  
	//  model->predict(testSample, predictedLabel, confidence);  
 
	string result_message = format("Predicted class = %d / Actual class = %d.", predictedLabel, testLabel);
	string result_message1 = format("Predicted class = %d / Actual class = %d.", predictedLabel1, testLabel);
	string result_message2 = format("Predicted class = %d / Actual class = %d.", predictedLabel2, testLabel);
	cout << result_message << endl;
	cout << result_message1 << endl;
	cout << result_message2 << endl;
 
	getchar();
	//waitKey(0);
	return 0;
}
```
## 4. Facere 实现人脸识别
```cpp
#include<opencv2/opencv.hpp>  
#include"/usr/local/include/opencv2/core/core.hpp"
#include "/home/lxy/opencv-3.4.8/opencv_contrib-3.4.8/modules/face/include/opencv2/face/facerec.hpp"
#include "/usr/local/include/opencv2/core.hpp"
#include "/usr/local/include/opencv2/face.hpp"
#include "/usr/local/include/opencv2/highgui/highgui.hpp"
 #include "/usr/local/include/opencv2/imgproc/imgproc.hpp"
#include <math.h>  
//使用void read_csv()这个函数必须的三个头文件
#include <iostream>  
#include <fstream>  
#include <sstream> 
 
using namespace std;
using namespace cv;
using namespace cv::face;
 
RNG g_rng(12345);
Ptr<FaceRecognizer> model;
 
int Predict(Mat src_image)  //识别图片
{
	Mat face_test;
	int predict = 0;
	//截取的ROI人脸尺寸调整
	if (src_image.rows >= 120)
	{
		//改变图像大小，使用双线性差值
		resize(src_image, face_test, Size(92, 112));
 
	}
	//判断是否正确检测ROI
	if (!face_test.empty())
	{
		//测试图像应该是灰度图  
		predict = model->predict(face_test);
	}
	cout << predict << endl;
	return predict;
}
int main()
{
	VideoCapture cap(0);    //打开默认摄像头  
	if (!cap.isOpened())
	{
		return -1;
	}
	Mat frame;
	Mat gray;
	//这个分类器是人脸检测所用
	CascadeClassifier cascade;
	bool stop = false;
	//训练好的文件名称，放置在可执行文件同目录下  
	cascade.load("/home/lxy/opencv-3.4.8/data/haarcascades/haarcascade_frontalface_alt2.xml");//感觉用lbpcascade_frontalface效果没有它好，注意哈！要是正脸
 
	model = FisherFaceRecognizer::create();
	//1.加载训练好的分类器
	model->read("/home/lxy/test/test1/MyFaceFisherModel.xml");// opencv2用load
										 //3.利用摄像头采集人脸并识别
	while (1)
	{
		cap >> frame;
  
		vector<Rect> faces(0);//建立用于存放人脸的向量容器
		
		cvtColor(frame, gray, CV_RGB2GRAY);//测试图像必须为灰度图
		
		equalizeHist(gray, gray); //变换后的图像进行直方图均值化处理  
		//检测人脸
		cascade.detectMultiScale(gray, faces,
			1.1, 4, 0
			//|CV_HAAR_FIND_BIGGEST_OBJECT  
			| CV_HAAR_DO_ROUGH_SEARCH,
			//| CV_HAAR_SCALE_IMAGE,
			Size(30, 30), Size(500, 500));
		Mat* pImage_roi = new Mat[faces.size()];    //定以数组
		Mat face;
		Point text_lb;//文本写在的位置
		//框出人脸
		string str;
		for (int i = 0; i < faces.size(); i++)
		{
			pImage_roi[i] = gray(faces[i]); //将所有的脸部保存起来
			text_lb = Point(faces[i].x, faces[i].y);
			if (pImage_roi[i].empty())
				continue;
			switch (Predict(pImage_roi[i])) //对每张脸都识别
			{

			case 24:str ="2021091203006 LiXiaoyang";break;
			default: str = "error"; break;
			}
			Scalar color = Scalar(g_rng.uniform(100, 255), g_rng.uniform(10, 255), g_rng.uniform(20, 255));//所取的颜色任意值
			rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), color, 1, 8);//放入缓存
			putText(frame, str, text_lb, FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255));//添加文字
		}
 
		delete[]pImage_roi;
		imshow("face", frame);
		waitKey(200);	
	}
 
	return 0;
}
 ```
 ## 4.1 CMakeLists.txt
 ```txt
 cmake_minimum_required(VERSION 2.8)
project( train )
find_package( OpenCV REQUIRED )
add_executable( train train.cpp )
target_link_libraries( train ${OpenCV_LIBS} )
```