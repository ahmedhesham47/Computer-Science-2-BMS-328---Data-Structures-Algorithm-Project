#pragma once

#ifndef MATRIX_GRAPH_
#define MATRIX_GRAPH_


#include <vector>
#include "\UST\Year 2\Spring\Computer Science 2\Project\Project\Project\Util.h"
#include "../Linked List/LinkedList.h"
using namespace std;


template<typename T>
class MatrixGraph
{
private:
	vector<T> protein;
	vector<vector<int>> proteinNetwork;
	int proteinCount;
	int interactionsCount;

public:
	MatrixGraph();

	bool IsEmpty() const; // Checks if graph is empty

	bool AddProtein(const T& v); // Adds a protein

	bool RemoveProtein(const T& v); // Removes a protein
	
	bool AddInteraction(const T& fromV, const T& toV, int weight = 1); // Adds an interaction bet. 2 proteins with default weighted interaction of 1.
	
	void RemoveInteraction(const T& fromV, const T& toV); // Removes interaction
	
	LinkedList<T>* FindInteracting(const T& fromV) const; // Shows all interacting protein with a certain protein
	
	bool EdgeExists(const T& fromV, const T& toV) const; // Checks if interaction exists
	
	bool IsInteracting(const T& v1, const T& v2) const; // Utilizes the above function
	
	void PrintNetwork(); // Displays the network in a readable fashion
	
	void DFS(const T& startV) const; // Depth-first search algorithm
	
	void BFS(const T& startV) const; // Breadth-first search algorithm
	
	int NodeDegree(const T& v) const; // Calculates the degree of a certain node
	
	int getProteinCount() const; // Captures the count of proteins in the network
	
	int getInteractionsCount() const; // Captures the count of interactions in the network
	
	LinkedList<T>* ProteinsWithInteractionOfCountAtLeastK(int k) const; // Shows all proteins that interact with weighted interaction of k or more
	
	LinkedList<T>* ProteinsWithInteractionOfCountAtMostK(int k) const; // Shows all proteins that interact with weighted interaction of k or less
	
	LinkedList<T>* ProteinsWithInteractionOfStrengthAtLeastK(int k) const;
	
	LinkedList<T>* ProteinsWithInteractionOfStrengthAtMostK(int k) const;
	
	void saveFile(string file_name) const; // Saves to an exertnal file
	
	LinkedList<T>* FindMostInteracting() const; // Finds the most interacting protein in terms of number of interactions
	
	LinkedList<T>* FindLeastInteracting() const; // Finds the least interacting protein in terms of number of interactions
	
	LinkedList<T>* FindProteinsWithStrongestInteraction() const; // Finds the strongest interacting protein
	
	LinkedList<T>* FindProteinsWithWeakestTotalInteraction() const; // Finds the weakest interacting protein
	
	LinkedList<T>* FindProteinsWithStrongestTotalInteraction() const;
	
	T* sortProteinsAccordingToStrengthOfInteractions();
	
	T* sortProteinsAccordingToCountOfInteractions();
	
	int InteractionsValue(const T& v) const;
	
	void SaveProtein(string file_name, T& p) const;
	
	T* FindProteinsWithInteractionOfStrengthK(int k) const;

	template <typename T>
	void bubbleSort(int array[], T arrayP[], int size) {

		// loop to access each array element
		for (int step = 0; step < (size - 1); ++step) {

			// check if swapping occurs
			int swapped = 0;

			// loop to compare two elements
			for (int i = 0; i < (size - step - 1); ++i) {

				// compare two array elements
				// change > to < to sort in descending order
				if (array[i] > array[i + 1]) {

					// swapping occurs if elements
					// are not in intended order 
					int temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;

					T tempProtein = arrayP[i];
					arrayP[i] = arrayP[i + 1];
					arrayP[i + 1] = tempProtein;

					swapped = 1;
				}
			}

			// no swapping means the array is already sorted
			// so no need of further comparison
			if (swapped == 0)
				break;
		}
	}
	
	int removeDuplicates(int arr[], int n)
	{
		if (n == 0 || n == 1)
			return n;

		// To store index of next unique element
		int j = 0;

		// Doing same as done in Method 1
		// Just maintaining another updated index i.e. j
		for (int i = 0; i < n - 1; i++)
			if (arr[i] != arr[i + 1])
				arr[j++] = arr[i];

		arr[j++] = arr[n - 1];

		return j;
	}

	~MatrixGraph();
};

#endif