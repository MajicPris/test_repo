#include "LinkedList.h"


LinkedList::LinkedList() : count(0), head(nullptr)
{

}

LinkedList::LinkedList(const LinkedList& a_ref)
{
	Copy(a_ref);
}

LinkedList& LinkedList::operator=(const LinkedList& a_ref)
{
	Copy(a_ref);
	return *this;
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Copy(const LinkedList& a_ref)
{
	Clear();

	Node* tmp = a_ref.head;
	for (int i = 0; i < a_ref.count; ++i)
	{
		addItem(tmp->data);
		tmp = tmp->next;
	}
	count = a_ref.count;
}

Node* LinkedList::Move(int a_index)
{
	if (count > 0)
	{
		Node* tmp = head;
		for (int i = 0; i < a_index; ++i)
			tmp = tmp->next;
		return tmp;
	}

	return nullptr;
}

void LinkedList::addItem(int a_value)
{
	Node* tmp = new Node;
	tmp->data = a_value;
	tmp->next = head;
	head = tmp;
	count++;
}

void LinkedList::delItem(int a_index)
{
	if (count == 0 || a_index >= count || a_index < 0)
	{
		return;
	}

	if (a_index == 0)
	{
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	else
	{
		Node* tmp = Move(a_index - 1);
		Node* tmp2 = tmp;
		tmp = tmp->next;
		delete tmp2;
	}
	count--;
}

void LinkedList::delItem()
{
	delItem(0);
}

void LinkedList::Clear()
{
	while (head != nullptr)
	{
		delItem();
	}
}

void LinkedList::Insert(int a_value, int a_index)
{
	if (count != 0 && (a_index >= count || a_index < 0))
	{
		return;
	}

	Node* newNode = new Node;
	newNode->data = a_value;

	if (a_index == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		Node* tmp = Move(a_index - 1);
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	count++;
}

int LinkedList::getCount()
{
	return count;
}

void LinkedList::Print()
{
	if (count == 0)
		return;

	Node* tmp = head;

	while (tmp != nullptr)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void LinkedList::Reverse(LinkedList& a_ref)
{
	Node* current = a_ref.head;
	Node* prev = nullptr, *next = nullptr;
	
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev; //reverse
		prev = current;
		current = next;
	}
	a_ref.head = prev;
}

void testLinkedListFunc()
{
	std::cout << "\ntestLinkedListFunc" << std::endl;

	LinkedList obj;
	obj.addItem(5);
	obj.Print();
	obj.addItem(15);
	obj.Print();
	obj.Insert(4,1);
	obj.Print();

	obj.Reverse(obj);
	obj.Print();

}
