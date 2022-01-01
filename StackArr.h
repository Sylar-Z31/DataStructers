#include <iostream>

using namespace std;

constexpr int SIZE = 100;

class StackClass
{
public:
	int myArr[SIZE];
	int top;

	StackClass()
	{
		myArr[SIZE] = { NULL };
		top = -1;
	}
};


