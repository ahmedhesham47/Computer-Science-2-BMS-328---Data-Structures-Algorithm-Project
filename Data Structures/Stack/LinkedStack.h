#pragma once
#include"StackADT.h"
#include<iostream>
#include"../3-Queues/Node.h"
using namespace std;
template<typename T>
class LinkedStack : public StackADT<T>
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public : 
	LinkedStack()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	
	
	bool isEmpty() const
	{
		return Head == NULL;
	}  // end isEmpty

	bool push(const T& newEntry)
	{
		Node<T>* ptr = new Node <T>(newEntry);
		ptr->setNext(Head);
		Head = ptr;
		return true;

	}  // end push

	bool pop(T& TopEntry)
	{
		TopEntry = Head->getItem();
		Head = Head->getNext();
		return true;
	}

	bool peek(T& TopEntry) const
	{
		TopEntry = Head->getItem();
		return true;
	}  // end peek
};