//#ifndef LinkedList.h
//#include "LinkedList.h"
//#endif // !"LinkedList.h"
//#include <iostream>
//
//using namespace std;
//
//// Head & Tail
//Node* head = NULL, * tail = NULL;
//
//// AddSort
//Node* AddSortedLinkedList(Node* _head, string _name, unsigned int _old)
//{
//	Node* iter = _head;
//
//	// Linked List is empty
//	if (_head == NULL)
//	{
//		_head = new Node;
//		tail = head = _head;
//		_head->name = _name; _head->old = _old;
//		_head->next = NULL;
//
//		return _head;
//	}
//
//	// SortAdd Linked List not is empty and one size
//	else if (_name <= _head->name)
//	{
//		Node* newNode = new Node;
//		newNode->name = _name; newNode->old = _old;
//		newNode->next = _head;
//		_head = newNode;
//		tail = _head->next;
//
//		return _head;
//	}
//
//	iter = _head;
//
//	// Last or intermittent SortAdd
//	while (iter->next != NULL && iter->next->name < _name) { iter = iter->next; }
//
//	Node* newNode = new Node;
//	tail = newNode;
//	newNode->next = iter->next;
//	iter->next = newNode;
//	newNode->name = _name; newNode->old = _old;
//
//	return _head;
//}
//
//// Delete
//Node* DeleteItems(Node* _head, string _name, unsigned int _old)
//{
//	Node* temp;
//
//	if (_head == NULL) { cout << "Linked List is empty !" << endl << endl; return _head; }
//	else if (_head->name == _name && _head->old == _old)
//	{
//		temp = _head;
//		_head = _head->next;
//		delete temp;
//
//		return _head;
//	}
//
//	Node* iter = _head;
//
//	while (iter->next != NULL && (iter->next->name != _name && iter->next->old != _old))
//	{
//		iter = iter->next;
//	}
//
//	if (iter->next == NULL) { cout << "Element not found !" << endl; return _head; }
//
//	temp = iter->next;
//	iter->next = iter->next->next;
//	delete temp;
//
//	return _head;
//}
//
//// Show 
//int ShowLinkedList(Node* _head)
//{
//	if (_head == NULL) { cout << "Linked List is empty Show !" << endl << endl; return -1; }
//
//	
//	while (_head != NULL)
//	{
//		cout << _head->name << " " << _head->old << endl;
//		_head = _head->next;
//	}
//
//	cout << "last data name:" << tail->name << " - last data old:" << tail->old << endl << endl;
//
//	return 0;
//}
//
//// Main
//int main()
//{
//
//
//	ShowLinkedList(head);
//	head = AddSortedLinkedList(head, "mert", 21);
//	ShowLinkedList(head);
//	head = AddSortedLinkedList(head, "mete", 33);
//	ShowLinkedList(head);
//	head = AddSortedLinkedList(head, "hulya", 55);
//	ShowLinkedList(head);
//	head = DeleteItems(head, "hulya", 55);
//	ShowLinkedList(head);
//	head = AddSortedLinkedList(head, "apo", 20);
//	ShowLinkedList(head);
//	head = AddSortedLinkedList(head, "burak", 23);
//	ShowLinkedList(head);
//
//	delete head, tail;
//
//	return 0;
//}