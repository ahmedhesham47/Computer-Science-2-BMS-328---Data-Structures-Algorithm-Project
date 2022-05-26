#pragma once
#include <iostream>
#include "MatrixGraph.h"
#include <fstream>
#include "../Linked List/LinkedList.h"
template<typename T>
MatrixGraph<T>::MatrixGraph()
{
	
}

template<typename T>
bool MatrixGraph<T>::IsEmpty() const
{
	return proteinNetwork.size() == 0;
}

template<typename T>
bool MatrixGraph<T>::AddProtein(const T & v)
{
	if (findKey(protein, v) < 0) { // vertex does not already exist in graph
		// Add it to the list of vertices
		protein.push_back(v);

		// Adjust the adjacency matrix accordingly
		// First, add a new column to existing rows
		for (auto row = proteinNetwork.begin(); row != proteinNetwork.end(); row++)
			row->push_back(0);
		// Second, add a new row
		vector<int> newRow;
		for (int i = 0; i < protein.size(); i++)
			newRow.push_back(0);
		proteinNetwork.push_back(newRow);

		proteinCount++;

		return true;
	}
	return false;
}

template<typename T>
bool MatrixGraph<T>::RemoveProtein(const T & v)
{
	int index = findKey(protein, v);
	if (index >= 0) { // vertex exists
		// First, delete it from list of vertices
		removeKey(protein, v);

		// Second, adjust adjacency matrix accordingly
		removeColumn(proteinNetwork, index);
		removeRow(proteinNetwork, index);

		proteinCount--;
		
		return true;
	}

	return false;
}

template<typename T>
bool MatrixGraph<T>::AddInteraction(const T & fromV, const T & toV, int weight)
{
	int fromIndex = findKey(protein, fromV);
	int toIndex = findKey(protein, toV);

	if (fromIndex >= 0 && toIndex >= 0) {
		proteinNetwork[fromIndex][toIndex] = weight;
		proteinNetwork[toIndex][fromIndex] = weight;

		interactionsCount++;
		
		return true;
	}

	return false;
}

template<typename T>
void MatrixGraph<T>::RemoveInteraction(const T & fromV, const T & toV)
{
	AddEdge(fromV, toV, 0);
	interactionsCount--;
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::FindInteracting(const T & fromV) const
{
	LinkedList<T>* interactingPr = new LinkedList<T>;
	int i = findKey(protein, fromV);
	if (i >= 0) {
		for (int j = 0; j < protein.size(); j++) {
			if (proteinNetwork[i][j] > 0)
				interactingPr->InsertEnd(protein[j]);
		}
	}
	return interactingPr;
}

template<typename T>
bool MatrixGraph<T>::EdgeExists(const T & fromV, const T & toV) const
{
	int fromIndex = findKey(protein, fromV);
	int toIndex = findKey(protein, toV);

	return (fromIndex >= 0
		&& toIndex >= 0
		&& proteinNetwork[fromIndex][toIndex] > 0);
}

template<typename T>
bool MatrixGraph<T>::IsInteracting(const T & v1, const T & v2) const
{
	return (EdgeExists(v1, v2)
		|| EdgeExists(v2, v1));
}

template<typename T>
void MatrixGraph<T>::PrintNetwork()
{
	int numVertices = protein.size();

	cout << "\t\t";
	for (int i = 0; i  < numVertices; i++)
		cout << protein[i] << "\t";

	cout << endl;

	for (int i = 0; i < numVertices; i++)
		cout << "--------------";
	cout << endl;
	for (int i = 0; i < numVertices; i++) {
		cout << protein[i] << "\t|\t";
		for (int j = 0; j < numVertices; j++) {
			cout << proteinNetwork[i][j] << "\t";
		}
		cout << endl;
	}

}

template<typename T>
void MatrixGraph<T>::DFS(const T & startV) const
{
}

template<typename T>
void MatrixGraph<T>::BFS(const T & startV) const
{
}


template<typename T>
int MatrixGraph<T>::NodeDegree(const T& v) const
{
	int degree = 0;
	int i = findKey(protein, v);
	if (i >= 0) {
		for (int j = 0; j < protein.size(); j++) {
			if (proteinNetwork[i][j] > 0)
				degree++;
		}
	}
	return degree;
}

template<typename T>
int MatrixGraph<T>::getProteinCount() const
{
	return proteinCount;
}

template<typename T>
int MatrixGraph<T>::getInteractionsCount() const
{
	return interactionsCount;
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::ProteinsWithInteractionOfCountAtLeastK(int k) const
{
	LinkedList<T>* L = new LinkedList<T>;
	for (int i = 0; i < protein.size(); i++) {
			if (NodeDegree(protein[i]) >= k) {
				L->InsertEnd(protein[i]);
			}
		}

	return L;
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::ProteinsWithInteractionOfCountAtMostK(int k) const
{
		LinkedList<T>* Z = new LinkedList<T>;
		for (int i = 0; i < protein.size(); i++) {
				if (NodeDegree(protein[i]) <= k) {
					Z->InsertEnd(protein[i]);
				}
			}

		return Z;
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::ProteinsWithInteractionOfStrengthAtLeastK(int k) const
{
	LinkedList<T>* Z = new LinkedList<T>;
	for (int i = 0; i < protein.size(); i++) {
		if (InteractionsValue(protein[i]) >= k) {
			Z->InsertEnd(protein[i]);
		}
	}

	return Z;
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::ProteinsWithInteractionOfStrengthAtMostK(int k) const
{
	LinkedList<T>* Z = new LinkedList<T>;
	for (int i = 0; i < protein.size(); i++) {
		if (InteractionsValue(protein[i]) <= k) {
			Z->InsertEnd(protein[i]);
		}
	}

	return Z;
}

template<typename T>
void MatrixGraph<T>::saveFile(string file_name) const
{
	ofstream saveFile;

	saveFile.open(file_name + ".txt");

	saveFile << "\t\t";
	
	for (int i = 0; i < protein.size(); ++i)
		saveFile << protein[i] << "\t";

	saveFile << endl;

	for (int i = 0; i < protein.size(); i++)
		saveFile << "---------";
	saveFile << endl;
	
	for (int i = 0; i < protein.size(); i++) {
		saveFile << protein[i] << "\t|\t";
		for (int j = 0; j < protein.size(); j++) {
			if (proteinNetwork[i][j] > 0) {
				saveFile << proteinNetwork[i][j] << "\t";
			}
			else saveFile << proteinNetwork[i][j] << "\t";
			
		}
		saveFile << endl;
	}
	
	saveFile.close();
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::FindMostInteracting() const
{
	// Check the degree of each node, and sort based on the degree.
	LinkedList<T>* maxList = new LinkedList<T>;
	int max = NodeDegree(protein[0]);

	for (int i = 1; i < protein.size(); i++) {
			if (NodeDegree(protein[i]) >= max) {
				max = NodeDegree(protein[i]);
			}
		}

	for (int i = 0; i < protein.size(); i++) {
		if (NodeDegree(protein[i]) == max) {
			maxList->InsertEnd(protein[i]);
		}
	}

	return maxList;
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::FindLeastInteracting() const
{
	// Check the degree of each node, and sort based on the degree.

	LinkedList<T>* leastList = new LinkedList<T>;
	int least = NodeDegree(protein[0]);
	for (int i = 1; i < protein.size(); i++) {
			if (NodeDegree(protein[i]) <= least) {
				least = NodeDegree(protein[i]);
			}
		}

	for (int i = 0; i < protein.size(); i++) {
		if (NodeDegree(protein[i]) == least) {
			leastList->InsertEnd(protein[i]);
		}
	}

	return leastList;
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::FindProteinsWithStrongestInteraction() const
{
	// Loop over the weighted interactions, and sort based on that.
	LinkedList<T>* maxList = new LinkedList<T>;
	int max = proteinNetwork[0][0];

	for (int i = 0; i < protein.size(); i++) {
		for (int j = 1; j < protein.size(); j++) {
			if (proteinNetwork[i][j] >= max) {
				max = proteinNetwork[i][j];
			}
		}
	}

	for (int i = 0; i < protein.size(); i++) {
		for (int j = 0; j < protein.size(); j++) {
			if (proteinNetwork[i][j] == max) {
				maxList->InsertEnd(protein[i]);
			}
		}
	}
	return maxList;
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::FindProteinsWithWeakestTotalInteraction() const
{
	// Loop over the weighted interactions, and sort based on that.
	LinkedList<T>* leastList = new LinkedList<T>;
	int least = 100000;

	for (int i = 0; i < protein.size(); i++) {
		if (InteractionsValue(protein[i]) < least) {
			least = InteractionsValue(protein[i]);
		}
	}

	for (int i = 0; i < protein.size(); i++) {
		if (InteractionsValue(protein[i]) == least) {
			leastList->InsertEnd(protein[i]);
		}
	}
	return leastList;
}

template<typename T>
LinkedList<T>* MatrixGraph<T>::FindProteinsWithStrongestTotalInteraction() const
{
	LinkedList<T>* StrongestList = new LinkedList<T>;
	int strongest = 0;

	for (int i = 0; i < protein.size(); i++) {
		if (InteractionsValue(protein[i]) > strongest) {
			strongest = InteractionsValue(protein[i]);
		}
	}

	for (int i = 0; i < protein.size(); i++) {
		if (InteractionsValue(protein[i]) == strongest) {
			StrongestList->InsertEnd(protein[i]);
		}
	}

	return StrongestList;
}

template<typename T>
T* MatrixGraph<T>::sortProteinsAccordingToStrengthOfInteractions()
{
	int* arr = new int[protein.size()];
	T* tempHolder = new T[protein.size()];
	for (int i = 0; i < protein.size(); i++) {
		arr[i] = InteractionsValue(protein[i]);
		tempHolder[i] = protein[i];
	}

	bubbleSort(arr, tempHolder, protein.size());
	//removeDuplicates(arr, protein.size());
	return tempHolder;
}

template<typename T>
T* MatrixGraph<T>::sortProteinsAccordingToCountOfInteractions()
{
	int* arr = new int[protein.size()];
	T* tempHolder = new T[protein.size()];
	for (int i = 0; i < protein.size(); i++) {
		arr[i] = NodeDegree(protein[i]);
		tempHolder[i] = protein[i];
	}

	bubbleSort(arr, tempHolder, protein.size());
	//removeDuplicates(arr, protein.size());
	return tempHolder;
}

template<typename T>
int MatrixGraph<T>::InteractionsValue(const T& v) const
{
	int sum = 0;
	int i = findKey(protein, v);
	for (int j = 0; j < protein.size(); j++) {
		if (proteinNetwork[i][j] > 0) {
			sum += proteinNetwork[i][j];
		}
	}
	return sum;
}

template<typename T>
void MatrixGraph<T>::SaveProtein(string file_name, T& p) const
{
	ofstream saveFile;
	LinkedList<T>* intrPtr = FindInteracting(p);
	Node<T>* current = intrPtr->Head;
	saveFile.open(file_name + ".txt");

	saveFile << "Protein Name: " << "\t" << p << endl;
	
	saveFile << "Protein Interaction Count: " << "\t" << NodeDegree(p) << endl;
	saveFile << "Protein Interaction Strength: " << "\t" << InteractionsValue(p) << endl;
	saveFile << "Protein Interactions: " << "\t";
	while (current) {
		saveFile << current->getItem() << " ";
		current = current->getNext();
	}
	saveFile.close();
}

template<typename T>
T* MatrixGraph<T>::FindProteinsWithInteractionOfStrengthK(int k) const
{
	int tracingCounter = 0;
	T* arrProtein = new T[protein.size()];
	for (int i = 0; i < protein.size(); i++) {
		if (InteractionsValue(protein[i]) == k) {
			arrProtein[i] = protein[i];
		}
		else {
			tracingCounter++;
		}
	}

	if (tracingCounter) return NULL;
	return arrProtein;
}


template<typename T>
MatrixGraph<T>::~MatrixGraph()
{
	
}
