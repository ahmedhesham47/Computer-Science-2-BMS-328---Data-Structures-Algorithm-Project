#pragma once
#define QUEUE_ADT_
using namespace std;
#include<iostream>
#include"QueueADT.h"
#pragma once
using namespace std;
template <typename T>
class ArrayQueue :public QueueADT<T>
{
private:
	int rear, front;
	T* items;		// Array of queue items
	const int Queue_SIZE;
public:
	ArrayQueue() :Queue_SIZE(30)	//default constructor
	{
		items = new T[Queue_SIZE];
		rear = front = 0;
	}

	ArrayQueue(int MaxSize) : Queue_SIZE(MaxSize)
	{
		items = new T[Queue_SIZE];
		rear = front = 0;
	}
	bool isEmpty() const
	{
	}
	bool enqueue(const T& newEntry)
	{

	}
	bool dequeue(T& frntEntry)
	{


	}

	bool peek(T& frntEntry) const
	{
	}

};