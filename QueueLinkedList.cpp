//#ifndef QueueLinkedList.h
//#include "QueueLinkedList.h"
//#endif // !QueueLinkedList.h
//#include <iostream>
//
//using namespace std;
//
//Node* head = nullptr, * front = nullptr, * rear = nullptr;
//
//// Enqueue
//Node* Enqueue(Node* _head, int _data)
//{
//	// The Queue is empty
//	if (_head == nullptr)
//	{
//		_head = new Node;
//		front = _head;
//		rear = _head;
//		_head->next = nullptr;
//		_head->data = _data;
//
//		return _head;
//	}
//	// if there is 1 node in the queue
//	else if (_head->next == nullptr)
//	{
//		Node* newNode = new Node;
//		_head->next = newNode;
//		rear = newNode;
//		newNode->next = nullptr;
//		newNode->data = _data;
//
//		return _head;
//	}
//
//	Node* iter = _head;
//
//	while (iter->next != nullptr) { iter = iter->next; }
//
//	Node* newNode = new Node;
//	iter->next = newNode;
//	newNode->next = nullptr;
//	rear = newNode;
//	newNode->data = _data;
//
//	return _head;
//
//}
//
//// Dequeue
//Node* Dequeue(Node* _head)
//{
//	// the queue is empty
//	if (front == nullptr) { cout << "The Queue is empty(pop funtions)" << endl; return front; }
//	// if queue has one node
//	else if (front->next == nullptr)
//	{
//		Node* temp = new Node;
//		temp = front;
//		front = nullptr;
//		rear = nullptr;
//
//		delete temp;
//
//		return front;
//	}
//
//	Node* temp = new Node;
//	temp = front;
//	front = front->next;
//
//	delete temp;
//
//	return front;
//}
//
//
//
//// Display
//Node* Display(Node* _head)
//{
//	if (front == nullptr) { cout << "The Queue is empty(dislplay funciton)" << endl; return front; }
//
//	while (_head != nullptr)
//	{
//		cout << _head->data << " ";
//		_head = _head->next;
//	}
//	cout << endl;
//	cout << "front: " << front->data << " <-> " << "rear: " << rear->data << endl;
//	return front;
//}
//
//// Main
//int main()
//{
//	head = Dequeue(head);
//	Display(head);
//	head = Enqueue(head, 10);
//	Display(head);
//	head = Dequeue(head);
//	Display(head);
//	head = Enqueue(head, 20);
//	Display(head);
//	head = Enqueue(head, 30);
//	Display(head);
//	head = Enqueue(head, 40);
//	Display(head);
//	head = Dequeue(head);
//	Display(head);
//
//	return 0;
//}