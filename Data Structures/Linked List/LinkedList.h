#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <map>
#include <string>

#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
public:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
	int count;	//Number of nodes in the list
public:

	LinkedList()
	{
		count = 0;
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		//DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList() const
	{
		cout << "\nList has " << count << " nodes";
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
		count++;

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head->getNext() != nullptr)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		count = 0;
	}



	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions

	// [0] Is Empty
	// Checks if the Linked List is empty (extra, not in the lab but did it anyways since it's easy :D)

	bool isEmpty() {
		if (Head == nullptr || count == 0) return true;
		return false;
	}

	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data) {
		Node<T>* R = new Node<T>(data);
		Node<T>* current = Head;
		if (count == 0) {
			InsertBeg(data);
		}
		else {
			while (current->getNext() != nullptr) {
				current = current->getNext();
			}
			current->setNext(R);
			R->setNext(nullptr);
			count++;
		}
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(int Key) {
		if (count == 0) {
			return false;
		}
		else {
			Node<T>* current = Head;
			while (current->getNext() != nullptr) {
				if (current->getItem() == Key) { return true; }
				current = current->getNext();
			}
			return false;
		}
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value) {
		Node<T>* current = Head;
		int repeats = 0;
		if (count == 0) return repeats;
		else {
			while (current) {
				if (current->getItem() == value) { repeats++; }
				current = current->getNext();
			}
		}
		return repeats;

	}

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst() {
		if (count == 0) {
			cout << "Nothing to delete!" << endl;
		}
		else {
			Node<T>* current = Head;
			Head = Head->getNext();
			delete current;
			count--;
		}
	}


	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast() {
		Node<T>* current = Head;
		Node<T>* previous;
		if (count == 0) {
			cout << "Nothing to delete! " << endl;
		}
		else {
			while (current->getNext() != nullptr) {
				previous = current;
				current = current->getNext();
			}
			delete current;
			previous->setNext(nullptr);
			count--;
		}
	}

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value) {

		Node<T>* current = Head;
		Node<T>* previous;
		Node<T>* after;

		if (count == 0) {
			cout << "Nothing to delete!" << endl;
			return false;
		}

		if (Head->getItem() == value) {
			Head = Head->getNext();
			delete current;
			count--;
			return true;
		}

		while (current) {
			if (current->getNext()->getItem() == value) {
				previous = current;
				after = current->getNext()->getNext();
				delete current->getNext();
				previous->setNext(after);
				count--;
				return true;
			}
			current = current->getNext();
		}
		return false;
	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value)
	{
		Node<T>* current = Head;
		Node<T>* previous = nullptr;
		Node<T>* temp;

		if (count == 0) {
			cout << "Nothing to delete!" << endl;
			return false;
		}

		while (current) {
			temp = current->getNext();
			if (current->getItem() == value) {
				if (previous) {
					previous->setNext(current->getNext());
				}
				else {
					Head = current->getNext();
				}
				//delete current;
				count--;
			}
			else {
				previous = current;
			}
			current = temp;
		}
	}

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(LinkedList& L) {
		Node<T>* current = this->Head;
		if (this->Head && L.Head)
		{
			while (current->getNext() != nullptr)

			{
				current = current->getNext();
			}

			current->setNext(L.Head);
			count = count + L.count;
		}
		else cout << "Cannot merge empty lists! " << endl;
	}

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse() {
		Node<T>* previous = nullptr;
		Node<T>* current = Head;
		Node<T>* after = nullptr;
		while (current)
		{
			after = current->getNext();
			current->setNext(previous);
			previous = current;
			current = after;
		}
		Head = previous;
	}

	template<typename Map>
	void PrintMap(Map& m)
	{
		cout << "[ ";
		for (auto& item : m) {
			cout << item.first << ":" << item.second << " ";
		}
		cout << "]\n";
	}

	// Q1 Lab 5

	void MakeDictionary() {
		map<char, int> nMap = { {'A', CountOccurance('A')}, {'C', CountOccurance('C')}, {'G', CountOccurance('G')}, {'T', CountOccurance('T')} };
		PrintMap(nMap);
	}

	// Q4 Lab 5
	void EditLinkedList() {
		T firstVal = 0;
		T secondVal = 0;
		T thirdVal = 0;
		T fourthVal = 0;

		if (Head) {
			firstVal = Head->getItem();
			DeleteNodes(firstVal);
		}
		if (Head) {
			secondVal = Head->getItem();
			DeleteNodes(secondVal);
		}
		if (Head) {
			thirdVal = Head->getItem();
			DeleteNodes(thirdVal);
		}
		if (Head) {
			fourthVal = Head->getItem();
			DeleteNodes(fourthVal);
		}

		if (firstVal) InsertEnd(firstVal);
		if (secondVal) InsertEnd(secondVal);
		if (thirdVal) InsertEnd(thirdVal);
		if (fourthVal) InsertEnd(fourthVal);

	}

	// ===================================================================================

	// Assignment 2

	// Q1
	T SumElements() {
		int total = 0;
		Node <T>* current = Head;
		while (current) {
			total += current->getItem();

			current = current->getNext();
		}

		return total;
	}

	// Q2
	LinkedList<T> CloneList(LinkedList<T> L) {
		LinkedList<T> clonedList;
		if (!L.Head) {
			cout << "Nothing to clone from the given linked list! " << endl;
		}
		else {
			Node<T>* current = L.Head;
			while (current) {
				clonedList.InsertEnd(current->getItem());
				current = current->getNext();
			}
		}

		return clonedList;
	}

	// Q3

	Node<T>* FindMin() {
		Node<T>* current = Head;
		Node<T>* minNode;
		T min = Head->getItem();

		while (current) {
			if (min > current->getItem()) {
				min = current->getItem();
				minNode = current;
			}
			current = current->getNext();
		}

		return minNode;
	}

	Node<T>* RemoveMin() {
		Node<T>* toBeDeleted;
		Node<T>* returnedNode = nullptr;
		if (count == 0) {
			cout << "Nothing to delete!" << endl;
		}
		else if (count == 1) {
			toBeDeleted = Head;
			returnedNode = toBeDeleted;
			DeleteNode(toBeDeleted->getItem());
		}
		else {
			toBeDeleted = FindMin();
			returnedNode = toBeDeleted;
			DeleteNode(toBeDeleted->getItem());
		}

		return returnedNode;
	}

	// Q4

	void SplitSign(LinkedList<T>& L, LinkedList<T>& pos, LinkedList<T>& neg) {
		//LinkedList<T> posList; 
		//LinkedList<T> negList;
		Node<T>* current = L.Head;
		if (!L.Head) {
			cout << "Nothing to split! " << endl;
		}
		else {
			for (int i = 0; i < L.count; i++) {
				if (current->getItem() > 0) {
					pos.InsertEnd(current->getItem());
				}
				else if (current->getItem() < 0) {
					neg.InsertEnd(current->getItem());
				}

				current = current->getNext();
			}
		}
	}

	// Bonus

	void OrderedList(LinkedList<string>& process, LinkedList<int>& order) {
		Node<int>* cur1 = order.Head;
		Node<string>* cur1String = process.Head;
		Node<int>* cur2 = nullptr;
		Node<string>* cur2String = nullptr;

		while (cur1 && cur1String) {
			cur2 = cur1->getNext();
			cur2String = cur1String->getNext();
			while (cur2 && cur2String) {
				if (cur1->getItem() > cur2->getItem()) {
					int temp = cur1->getItem();
					string tmp = cur1String->getItem();
					cur1->setItem(cur2->getItem());
					cur1String->setItem(cur2String->getItem());
					cur2->setItem(temp);
					cur2String->setItem(tmp);

				}
				cur2 = cur2->getNext();
				cur2String = cur2String->getNext();
			}
			cur1 = cur1->getNext();
			cur1String = cur1String->getNext();
		}
	}

	LinkedList<int>* Reorder_x(int x) {
		Node<int>* current = this->Head;
		LinkedList<int> newList;
		while (current) {
			if (current->getItem() <= x) {
				newList.InsertBeg(current->getItem());
			}
			else {
				newList.InsertEnd(current->getItem());
			}
			current = current->getNext();
		}
		return &newList;
	}

	/*
	void ShiftLargest(LinkedList<int>& L) {
		Node<int>* current = L.Head;
		Node<int>* temp = nullptr;
		Node<int>* tempBefore = nullptr;
		while (current->getNext()) {
			temp = current->getNext();
			if (current->getItem() > temp->getItem()) {
				current->setNext(temp->getNext());
				temp->setNext(current);
				//tempAfter->setNext(current);
				//current->setNext(tempAfter->getNext());
				//current->setNext(current->getNext());
			}
			current = current->getNext();
		}

		//current->setNext(nullptr);
	}

	*/

	void RemoveD() {
		Node<T>* current = this->Head;
		LinkedList<int> templist;

		while (current) {
			if (CountOccurance(current->getItem()) > 1 && !(templist.Find(current->getItem()))) {
				templist.InsertEnd(current->getItem());
				DeleteNodes(current->getItem());
			}

			current = current->getNext();
		}

		//this->DeleteAll();

		Node<T>* newCurrent = templist.Head;

		while (newCurrent) {
			this->InsertEnd(newCurrent->getItem());
			newCurrent = newCurrent->getNext();
		}
	}
	

	bool ShiftLargest() {
		Node<T>* prev = this->Head;
		Node<T>* curr = prev->getNext();
		Node<T>* next = curr->getNext();

		//checking at the head
		if (prev->getItem() > curr->getItem()) {
			this->Head = curr;
			this->Head->setNext(prev);
			prev->setNext(next);
		}

		prev = this->Head;
		curr = prev->getNext();
		next = curr->getNext();


		Node<T>* nextOfNext = next->getNext();
		while (nextOfNext) {

			if (curr->getItem() > next->getItem()) {
				prev->setNext(next);
				next->setNext(curr);
				curr->setNext(nextOfNext);
			}

			prev = prev->getNext();
			curr = prev->getNext();
			next = curr->getNext();
			nextOfNext = next->getNext();

		}
		//checking at the end of the linkedlist
		if (curr->getItem() > next->getItem()) {
			prev->setNext(next);
			next->setNext(curr);
			curr->setNext(nullptr);

		}

		return true;
	}
};

#endif	