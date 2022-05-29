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
		interactionsCount -= NodeDegree(v);
		
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
	AddInteraction(fromV, toV, 0);
	interactionsCount--;
}

template<typename T>
LinkedList<Protein>* MatrixGraph<T>::FindInteracting(const T & fromV) const
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
bool MatrixGraph<T>::AreInteracting(const T & v1, const T & v2) const
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
void MatrixGraph<T>::BFS(int startVertex) const
{

}


template<typename T>
int MatrixGraph<T>::NumberOfInteractions(const T& v) const
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
LinkedList<Protein>* MatrixGraph<T>::ProteinsWithInteractionOfCountAtLeastK(int k) const
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
LinkedList<Protein>* MatrixGraph<T>::ProteinsWithInteractionOfCountAtMostK(int k) const
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
LinkedList<Protein>* MatrixGraph<T>::ProteinsWithInteractionOfStrengthAtLeastK(int k) const
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
LinkedList<Protein>* MatrixGraph<T>::ProteinsWithInteractionOfStrengthAtMostK(int k) const
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

	// Definitions to be used in looping

	LinkedList<Protein>* mostInteractingN = FindMostInteracting();
	Node<Protein>* mostInteractingN_temp = mostInteractingN->Head;

	LinkedList<Protein>* leastInteractingN = FindLeastInteracting();
	Node<Protein>* leastInteractingN_temp = leastInteractingN->Head;

	LinkedList<Protein>* mostInteractingS = FindProteinsWithStrongestTotalInteraction();
	Node<Protein>* mostInteractingS_temp = mostInteractingS->Head;

	LinkedList<Protein>* leastInteractingS = FindProteinsWithWeakestTotalInteraction();
	Node<Protein>* leastInteractingS_temp = leastInteractingS->Head;

	LinkedList<Protein>* StrongestIndividualInteraction = FindProteinsWithStrongestInteraction();
	Node<Protein>* StrongestIndividual_temp = StrongestIndividualInteraction->Head;

	Protein* sortedStrength	= sortProteinsAccordingToStrengthOfInteractions();

	Protein* sortedCount = sortProteinsAccordingToCountOfInteractions();

	LinkedList<Protein>* interactingProteins = FindInteractingProteins();
	Node<Protein>* interactingProteins_temp = interactingProteins->Head;

	LinkedList<Protein>* uninteractingProteins = FindUninteractingProteins();
	Node<Protein>* unInteractingProteins_temp = uninteractingProteins->Head;

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
	
	saveFile << endl;

	saveFile << "Total Protein Count: " << "\t" << getProteinCount() << endl;
	saveFile << "Total Interactive Proteins Count: " << "\t" << numOfInteractingProteins() << endl;
	saveFile << "Total Non-Interactive Proteins Count: " << "\t" << numOfUninteractingProteins() << endl;
	saveFile << "Total Interactions Count: " << "\t" << getInteractionsCount() << endl;
	saveFile << "Total Interactions Strength: " << "\t" << getTotalNetworkStrength() << endl;
	saveFile << "Is every protein interacting? " << "\t" << areAllInteracting() << endl;
	
	saveFile << "Most interacting proteins in terms of interactions count: " << "\t";
	while (mostInteractingN_temp) {
		saveFile << mostInteractingN_temp->getItem() << " ";
		mostInteractingN_temp = mostInteractingN_temp->getNext();
	}

	saveFile << endl;

	saveFile << "Least interacting proteins in terms of interactions count: " << "\t";
	while (leastInteractingN_temp) {
		saveFile << leastInteractingN_temp->getItem() << " ";
		leastInteractingN_temp = leastInteractingN_temp->getNext();
	}

	saveFile << endl;

	saveFile << "Proteins with strongest individual interaction: " << "\t";
	while (StrongestIndividual_temp) {
		saveFile << StrongestIndividual_temp->getItem() << " ";
		StrongestIndividual_temp = StrongestIndividual_temp->getNext();
	}

	saveFile << endl;

	saveFile << "Proteins with strongest total interactions strength: " << "\t";
	while (mostInteractingS_temp) {
		saveFile << mostInteractingS_temp->getItem() << " ";
		mostInteractingS_temp = mostInteractingS_temp->getNext();
	}

	saveFile << endl;

	saveFile << "Proteins with weakest total interactions strength: " << "\t";
	while (leastInteractingS_temp) {
		saveFile << leastInteractingS_temp->getItem() << " ";
		leastInteractingS_temp = leastInteractingS_temp->getNext();
	}

	saveFile << endl;

	saveFile << "All interacting proteins: " << "\t";
	while (interactingProteins_temp) {
		saveFile << interactingProteins_temp->getItem() << " ";
		interactingProteins_temp = interactingProteins_temp->getNext();
	}

	saveFile << endl;

	saveFile << "All Non-interacting proteins: " << "\t";
	while (unInteractingProteins_temp) {
		saveFile << unInteractingProteins_temp->getItem() << " ";
		unInteractingProteins_temp = unInteractingProteins_temp->getNext();
	}

	saveFile << endl;

	saveFile << "Proteins Sorted in Interactions Count (lowest to highest): " << "\t";
	for (int i = 0; i < getProteinCount(); i++) {
		saveFile << sortedCount[i] << " ";
	}

	saveFile << endl;
	saveFile << "Proteins Sorted in Interactions Strength (weakest to strongest): " << "\t";
	for (int i = 0; i < getProteinCount(); i++) {
		saveFile << sortedStrength[i] << " ";
	}

	saveFile.close();
}

template<typename T>
LinkedList<Protein>* MatrixGraph<T>::FindMostInteracting() const
{
	// Check the degree of each node, and sort based on the degree.
	LinkedList<T>* maxList = new LinkedList<T>;
	int max = NumberOfInteractions(protein[0]);

	for (int i = 1; i < protein.size(); i++) {
			if (NumberOfInteractions(protein[i]) >= max) {
				max = NumberOfInteractions(protein[i]);
			}
		}

	for (int i = 0; i < protein.size(); i++) {
		if (NumberOfInteractions(protein[i]) == max) {
			maxList->InsertEnd(protein[i]);
		}
	}

	return maxList;
}

template<typename T>
LinkedList<Protein>* MatrixGraph<T>::FindLeastInteracting() const
{
	// Check the degree of each node, and sort based on the degree.

	LinkedList<T>* leastList = new LinkedList<T>;
	int least = NumberOfInteractions(protein[0]);
	for (int i = 1; i < protein.size(); i++) {
			if (NumberOfInteractions(protein[i]) <= least) {
				least = NumberOfInteractions(protein[i]);
			}
		}

	for (int i = 0; i < protein.size(); i++) {
		if (NumberOfInteractions(protein[i]) == least) {
			leastList->InsertEnd(protein[i]);
		}
	}

	return leastList;
}

template<typename T>
LinkedList<Protein>* MatrixGraph<T>::FindProteinsWithStrongestInteraction() const
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
LinkedList<Protein>* MatrixGraph<T>::FindProteinsWithWeakestTotalInteraction() const
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
LinkedList<Protein>* MatrixGraph<T>::FindProteinsWithStrongestTotalInteraction() const
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
Protein* MatrixGraph<T>::sortProteinsAccordingToStrengthOfInteractions() const
{
	int* arr = new int[protein.size()];
	Protein* tempHolder = new Protein[protein.size()];
	for (int i = 0; i < protein.size(); i++) {
		arr[i] = InteractionsValue(protein[i]);
		tempHolder[i] = protein[i];
	}

	bubbleSort(arr, tempHolder, protein.size());
	//removeDuplicates(arr, protein.size());
	return tempHolder;
}

template<typename T>
Protein* MatrixGraph<T>::sortProteinsAccordingToCountOfInteractions() const
{
	int* arr = new int[protein.size()];
	Protein* tempHolder = new Protein[protein.size()];
	for (int i = 0; i < protein.size(); i++) {
		arr[i] = NumberOfInteractions(protein[i]);
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
void MatrixGraph<T>::SaveProtein(string file_name, Protein& p) const
{
	ofstream saveFile;
	LinkedList<T>* intrPtr = FindInteracting(p);
	Node<T>* current = intrPtr->Head;
	saveFile.open(file_name + ".txt");

	saveFile << "Protein Name: " << "\t" << p.getName() << endl;
	saveFile << "Protein ID: " << "\t" << p.getID() << endl;
	saveFile << "Protein Amino Acid Count: " << p.getAACount() << endl;
	saveFile << "Protein Type: " << "\t" << p.getType() << endl;
	saveFile << "Protein Location: " << "\t" << p.getLocation() << endl;
	saveFile << "Protein Function: " << "\t" << p.getFunction() << endl;
	saveFile << "Protein Color: " << "\t" << p.getColor() << endl;

	if (p.getFunction() == "Enzyme") {
		saveFile << "Protein Enzymatic Role: " << "\t" << p.getEnzymeType() << endl;
	}

	saveFile << "Protein Interaction Count: " << "\t" << NumberOfInteractions(p) << endl;
	saveFile << "Protein Interaction Strength: " << "\t" << InteractionsValue(p) << endl;
	saveFile << "Protein Interactions: " << "\t";
	while (current) {
		saveFile << current->getItem() << " ";
		current = current->getNext();
	}
	saveFile.close();
}

template<typename T>
Protein* MatrixGraph<T>::FindProteinsWithInteractionOfStrengthK(int k) const
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
LinkedList<Protein>* MatrixGraph<T>::FindUninteractingProteins() const
{
	LinkedList<T>* stored = new LinkedList<T>;

	for (int i = 0; i < protein.size(); i++) {
		if (NumberOfInteractions(protein[i]) == 0) {
			stored->InsertEnd(protein[i]);
		}
	}
	return stored;
}

template<typename T>
LinkedList<Protein>* MatrixGraph<T>::FindInteractingProteins() const
{
	LinkedList<T>* stored = new LinkedList<T>;

	for (int i = 0; i < protein.size(); i++) {
		if (NumberOfInteractions(protein[i]) > 0) {
			stored->InsertEnd(protein[i]);
		}
	}
	return stored;
}

template<typename T>
int MatrixGraph<T>::numOfInteractingProteins() const
{
	int counter = 0;
	for (int i = 0; i < protein.size(); i++) {
		if (NumberOfInteractions(protein[i]) > 0) {
			counter++;
		}
	}
	return counter;
}

template<typename T>
int MatrixGraph<T>::numOfUninteractingProteins() const
{
	return proteinCount - numOfInteractingProteins();
}

template<typename T>
MatrixGraph<Protein>* MatrixGraph<T>::cloneNetwork(MatrixGraph* network)
{
	MatrixGraph<T>* ClonedGraph = new MatrixGraph<T>;
	ClonedGraph = network;
	return ClonedGraph;
}

template<typename T>
bool MatrixGraph<T>::isInteracting(const T& v) const
{
	return NumberOfInteractions(v);
}

template<typename T>
int MatrixGraph<T>::FindOrderBetweenProteins(const T& v1, const T& v2) const
{
	return 0;
}

template<typename T>
LinkedList<Protein>* MatrixGraph<T>::FindCriticalPoints() const
{
	return nullptr;
}

template<typename T>
LinkedList<Protein>* MatrixGraph<T>::FindMinPathBetweenProteins(const T& v1, const T& v2) const
{
	return nullptr;
}

template<typename T>
int MatrixGraph<T>::FindInteractionStrength(const T& v1, const T& v2) const
{
	int interactionStrength = 0;
	int i = findKey(protein, v1);
	int j = findKey(protein, v2);
	if (proteinNetwork[i][j] > 0) {
			interactionStrength += proteinNetwork[i][j];
			return interactionStrength;
	}
	else {
		cout << v1 << "& " << v2 << "are not interacting! " << endl;
		return 0;
	}
}

template<typename T>
bool MatrixGraph<T>::isInteractionCritical(T& v1, T& v2)
{
	int interactionVal = FindInteractionStrength(v1, v2);
	if (AreInteracting(v1, v2)) {
		RemoveInteraction(v1, v2);
		if (!areAllInteracting()) {
			AddInteraction(v1, v2, interactionVal);
			return true;
		}
		else {
			AddInteraction(v1, v2, interactionVal);
		}
	}
	return false;
}

template<typename T>
int MatrixGraph<T>::getTotalNetworkStrength() const
{
	int strength = 0;
	for (int i = 0; i < protein.size(); i++) {
		strength+= InteractionsValue(protein[i]);
	}
	return strength;
}

template<typename T>
bool MatrixGraph<T>::areAllInteracting() const
{
	return (numOfInteractingProteins() == getProteinCount());
}

template<typename T>
void MatrixGraph<T>::DrawNetwork()
{
	return;
}

template<typename T>
MatrixGraph<T>::~MatrixGraph()
{
	
}