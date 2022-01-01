//#ifndef Stack.h
//#include "Stack.h"
//#endif // !Stack.h
//#include <iostream>
//
//using namespace std;
//
//StackClass mystack;
//
//// Push
//int Push(int data)
//{
//	if (mystack.top == SIZE - 1) { cout << "The stack is full" << endl; return mystack.top; }
//	else if (mystack.myArr[++mystack.top] == NULL)
//	{
//		mystack.myArr[mystack.top] = data;
//		return mystack.top;
//	}
//}
//
//// Pop
//int Pop()
//{
//	if (mystack.top == -1) { cout << "The stack is empty" << endl; return mystack.top; }
//	else
//	{
//		mystack.myArr[mystack.top--] = NULL;
//	}
//
//}
//
//// Show
//int showStack()
//{
//	if (mystack.top == -1) { cout << "The Stack is empty !" << endl; return -1; }
//
//	for (int i = 0; i < mystack.top + 1; i++) { cout << mystack.myArr[i] << " "; }
//	cout << endl;
//
//	return mystack.top;
//}
//
//int main()
//{
//	showStack();
//	Push(10);
//	showStack();
//	Push(20);
//	showStack();
//	Push(30);
//	showStack();
//	Push(40);
//	showStack();
//	Pop();
//	showStack();
//	Pop();
//	showStack();
//	Pop();
//	showStack();
//	Pop();
//	showStack();
//
//}
