//#ifndef StackLinkedList.h
//#include "StackLinkedList.h"
//#endif // !StackLinkedList.h
//#include <iostream>
//
//using namespace std;
//
//// head & top
//Node* top = nullptr;
//Node* head = nullptr;
//
//// Push
//Node* Push(Node* _head, int data)
//{
//	// the stack is empty
//	if (_head == nullptr)
//	{
//		_head = new Node;
//		_head->prev = nullptr;
//		_head->next = nullptr;
//		_head->number = data;
//		top = _head;
//		return _head;
//	}
//	// the stack is have one node
//	else if (_head->next == nullptr)
//	{
//		Node* newNode = new Node;
//		newNode->prev = _head;
//		_head->next = newNode;
//		newNode->next = nullptr;
//		newNode->number = data;
//		top = newNode;
//
//		return _head;
//	}
//	// if there is more than one node in the stack
//
//	Node* iter = _head;
//
//	while (iter->next != nullptr) { iter = iter->next; }
//
//	Node* newNode = new Node;
//	newNode->prev = iter;
//	iter->next = newNode;
//	newNode->next = nullptr;
//	newNode->number = data;
//	top = newNode;
//
//	return _head;
//}
//
////Pop
//Node* Pop(Node* _head)
//{
//	// the stack is empty
//	if (_head == nullptr) { cout << "the stack is empty(Pop function)" << endl; return _head; }
//	// the stack is have one node
//	else if (_head->next == nullptr)
//	{
//		Node* temp = new Node;
//		temp = _head; // or temp =_head
//		_head = nullptr;
//		delete temp;
//
//		return _head;
//	}
//
//	Node* temp = new Node;
//	temp = top;
//	top = top->prev;
//	delete temp;
//	top->next = nullptr;
//
//	return _head;
//}
//
//// Show stack
//Node* Show(Node* _head)
//{
//	if (_head == nullptr) { cout << "the stack is empty !(show function)" << endl; return _head; }
//
//	Node* iter = _head;
//
//	while (iter != nullptr)
//	{
//		cout << iter->number << " ";
//		iter = iter->next;
//	}
//	cout << endl;
//	top != nullptr ? cout << "Top node:" << top->number << endl : cout << "the stack is empty" << endl;
//
//	return iter;
//}
//
//
//int main()
//{
//	Pop(head);
//	Show(head);
//	head = Push(head, 10);
//	Show(head);
//	head = Pop(head);
//	Show(head);
//	head = Push(head, 20);
//	Show(head);
//	head = Push(head, 30);
//	Show(head);
//	head = Push(head, 40);
//	Show(head);
//	head = Pop(head);
//	Show(head);
//	head = Pop(head);
//	Show(head);
//	head = Pop(head);
//	Show(head);
//
//
//
//
//
//	return 0;
//}