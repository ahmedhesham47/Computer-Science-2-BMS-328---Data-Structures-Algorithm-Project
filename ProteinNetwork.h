#pragma once

#ifndef MATRIX_GRAPH_
#define MATRIX_GRAPH_


#include <vector>
#include "\UST\Year 2\Spring\Computer Science 2\Project\Project\Project\Util.h"
#include "../Linked List/LinkedList.h"
#include "../../Protein/Protein.h"
using namespace std;


template<typename T>
class ProteinNetwork
{
private:
	vector<T> protein;
	vector<vector<int>> proteinNetwork;
	int proteinCount;
	int interactionsCount;

public:
	ProteinNetwork();

	bool IsEmpty() const; // Checks if graph is empty

	bool AddProtein(const T& v); // Adds a protein

	bool RemoveProtein(const T& v); // Removes a protein
	
	bool AddInteraction(const T& fromV, const T& toV, int weight = 1); // Adds an interaction bet. 2 proteins with default weighted interaction of 1.
	
	void RemoveInteraction(const T& fromV, const T& toV); // Removes interaction
	
	LinkedList<Protein>* FindInteracting(const T& fromV) const; // Shows all interacting proteins with a certain protein
	
	bool EdgeExists(const T& fromV, const T& toV) const; // Checks if interaction exists
	
	bool AreInteracting(const T& v1, const T& v2) const; // Utilizes the above function
	
	void PrintNetwork(); // Displays the network in a readable fashion
	
	int NumberOfInteractions(const T& v) const; // Calculates the number of interactions for a given protein
	
	int getProteinCount() const; // Captures the count of proteins in the network
	
	int getInteractionsCount() const; // Captures the count of interactions in the network
	
	LinkedList<Protein>* ProteinsWithInteractionOfCountAtLeastK(int k) const; // Shows all proteins that have interaction count of at least k
	
	LinkedList<Protein>* ProteinsWithInteractionOfCountAtMostK(int k) const; // Shows all proteins that have interaction count of at most k
	
	LinkedList<Protein>* ProteinsWithInteractionOfStrengthAtLeastK(int k) const;  // Shows all proteins that have interaction strength of at least k
	
	LinkedList<Protein>* ProteinsWithInteractionOfStrengthAtMostK(int k) const;  // Shows all proteins that have interaction strength of at most k
	
	void saveFile(string file_name); // Saves to an exertnal file
	
	LinkedList<Protein>* FindMostInteracting() const; // Finds the most interacting protein in terms of number of interactions
	
	LinkedList<Protein>* FindLeastInteracting() const; // Finds the least interacting protein in terms of number of interactions
	
	LinkedList<Protein>* FindProteinsWithStrongestInteraction() const; // Finds the proteins with the strongest individual interaction
	
	LinkedList<Protein>* FindProteinsWithWeakestTotalInteraction() const; // Finds the weakest interacting protein
	
	LinkedList<Protein>* FindProteinsWithStrongestTotalInteraction() const; // Finds the proteins with the strongest total interaction.
	
	Protein* sortProteinsAccordingToStrengthOfInteractions() const; // Sorts proteins based on strength of interactions
	
	Protein* sortProteinsAccordingToCountOfInteractions() const; // Sorts proteins based on number of interactions.
	
	int InteractionsValue(const T& v) const; // Calculates the total interaction strength of a given protein
	
	void SaveProtein(string file_name, Protein& p); // Saves protein info to an external .txt file
	
	Protein* FindProteinsWithInteractionOfStrengthK(int k) const; // Finds all proteins with interaction strength of exactly k.

	LinkedList<Protein>* FindUninteractingProteins() const; // Finds all un-interacting protein and adds them to a list.
	 
	LinkedList<Protein>* FindInteractingProteins() const; // Finds all interacting proteins and adds them to a list.

	int numOfInteractingProteins() const; // Finds how many proteins are interactive

	int numOfUninteractingProteins() const; // Finds how many proteins are not reactive.

	ProteinNetwork<Protein>* cloneNetwork(ProteinNetwork<T>* network); // Copies the network.

	bool isInteracting(const T& v) const; // Checks if a given protein is interactive or not (has at least 1 interaction).
	
	// Not yet implemented, finds the degree of proximity bet. proteins
	int FindOrderBetweenProteins(const T& v1, const T& v2) const;
	
	// Not yet implemented, articulation "cut" points
	LinkedList<Protein>* FindCriticalPoints() const;
	
	// Not yet implemented, basically this should be Dijkstra
	LinkedList<Protein>* FindMinPathBetweenProteins(const T& v1, const T& v2) const;

	// Not yet implemented. Uses a graphics library and draws circles and lines.
	void DrawNetwork();

	int FindInteractionStrength(const T& v1, const T& v2) const; // Finds interaction strength between two proteins.

	bool isInteractionCritical(T& v1, T& v2); // Checks if a given interaction is critical: it is critical if the interaction is removed the network becomes not all connected.
	// In other words, is that interaction between two proteins where any of them is only engaged in THIS interaction?
	
	int getTotalNetworkStrength() const; // Calculates the total interaction strength of the entire network.

	bool areAllInteracting() const; // Checks if every protein has at least 1 interaction in the network.
	
	double fractionOfTotalInteractionsCount(Protein& p) const;

	double fractionOfTotalInteractionsStrength(Protein& p) const;

	double ConnectivityPercent() const;

	double ClusteringCoefficient(Protein& p) const;

	double AverageClusteringCoefficient();
	
	template <typename T>
	void bubbleSort(int array[], T arrayP[], int size) const {

		// loop to access each array element
		for (int step = 0; step < (size - 1); ++step) {

			// check if swapping occurs
			int swapped = 0;

			// loop to compare two elements
			for (int i = 0; i < (size - step - 1); ++i) {

				// compare two array elements
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

	~ProteinNetwork();
};

#endif