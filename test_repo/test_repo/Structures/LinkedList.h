#include <iostream>

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
	int count;
	Node* Move(int a_index);
	void Copy(const LinkedList& a_ref);
public:
	LinkedList();
	LinkedList(const LinkedList& a_ref);
	LinkedList& operator=(const LinkedList& a_ref);
	~LinkedList();
	void addItem(int a_value);
	void delItem();
	void delItem(int a_index);
	void Clear();
	int getCount();
	void Insert(int a_value, int a_index);
	void Print();
	void Reverse(LinkedList& a_ref);
};

void testLinkedListFunc();