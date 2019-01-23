#include "Entity.h"
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;

namespace ScoreCore
{
	Entity::Entity(const char* name, float xPos, float yPos)
		: m_Name(name), m_XPos(xPos), m_YPos(yPos)
	{
		data = new char[1000];
		data[0] = 0;
		std::cout << "Created the Entity object!" << std::endl;
	}
	void Entity::Move(float deltaX, float deltaY)
	{
		m_XPos += deltaX;
		m_YPos += deltaY;
		std::cout << "Moved " << m_Name << " to (" << m_XPos << ", " << m_YPos << ")." << std::endl;
	}
	void Entity::DisplayImage(const char* path) {
		std::cout << "call DisplayImage:" << m_Name << std::endl;
		namedWindow("Image", WINDOW_NORMAL);
		namedWindow("CannyImage", WINDOW_NORMAL);
		//Mat image = imread("D:\\mia¤¤¤å\\Mia201711261136.jpg");
		Mat image = imread(path);
		imshow("Image", image);
		Mat edges;
		Canny(image, edges, 10, 100);
		imshow("CannyImage", edges);
		waitKey();
	}
	char* Entity::GetData() {
		strcpy_s(data,1000, "Hello ");
		strcat_s(data, 1000,m_Name);
		return data;
	}
}