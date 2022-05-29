// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include "Data Structures/Graph/MatrixGraph.cpp"
#include <iostream>
#include "Protein/Protein.h"
using namespace std;

ostream& operator<<(ostream& os, Protein const& m) {
	return os << m.getName();
}

int main()
{
	Protein protein1 = Protein("Z", 30, 200, Activator, Cytosolic, Enzyme);
	Protein protein2 = Protein("A", 31, 200, Activator, Cytosolic, Regulator);
	Protein protein3 = Protein("B", 32, 200, Activator, Cytosolic, Regulator);
	Protein protein4 = Protein("C", 33, 200, Activator, Cytosolic, Regulator);
	Protein protein5 = Protein("D", 34, 200, Deactivator, Cytosolic, Regulator);
	Protein protein6 = Protein("E", 35, 200, Activator, Cytosolic, Regulator);
	Protein protein7 = Protein("F", 36, 200, Activator, Cytosolic, Regulator);
	Protein protein8 = Protein("G", 37, 200, Neutral, Cytosolic, Regulator);
	Protein protein9 = Protein("H", 38, 200, Neutral, Cytosolic, Regulator);
	Protein protein10 = Protein("I", 39, 200, Activator, Cytosolic, Regulator);
	Protein protein11 = Protein("J", 40, 200, Activator, Cytosolic, Regulator);
	Protein protein12 = Protein("K", 41, 200, Activator, Cytosolic, Regulator);
	 
	 
	MatrixGraph<Protein> ProteinNetwork;
	ProteinNetwork.AddProtein(protein1);
	ProteinNetwork.AddProtein(protein2);
	ProteinNetwork.AddProtein(protein3);
	ProteinNetwork.AddProtein(protein4);
	ProteinNetwork.AddProtein(protein5); 
	ProteinNetwork.AddProtein(protein6);

	ProteinNetwork.AddInteraction(protein1, protein2, 7);
	ProteinNetwork.AddInteraction(protein2, protein3, 3);
	ProteinNetwork.AddInteraction(protein3, protein4, 10);
	ProteinNetwork.AddInteraction(protein4, protein5, 6);
	//ProteinNetwork.AddInteraction(protein5, protein6, 5);
	//ProteinNetwork.AddInteraction(protein6, protein1, 21);

	//ProteinNetwork.PrintNetwork(); 
	//cout << ProteinNetwork.sortProteinsAccordingToCountOfInteractions() << endl;
	//cout << ProteinNetwork.sortProteinsAccordingToCountOfInteractions()[2];
	ProteinNetwork.SaveProtein("protein1", protein1);  
	ProteinNetwork.saveFile("proteins"); 

	/*
	Protein* arrayI = new Protein[11];
	arrayI = ProteinNetwork.sortProteinsAccordingToCountOfInteractions();
	for (int i = 0; i < 11; i++) {
		cout << arrayI[i] << " "; 
	}
	 
	Protein* arrayI = new Protein[11];
	arrayI = ProteinNetwork.sortProteinsAccordingToStrengthOfInteractions;
	for (int i = 0; i < 11; i++) {
		cout << arrayI[i] << " ";
	}

	LinkedList<Protein>* uninteractingProteins = ProteinNetwork.FindUninteractingProteins();
	LinkedList<Protein>* interactingProteins = ProteinNetwork.FindInteractingProteins();

	cout << endl << "Number of un-interacting proteins: " << ProteinNetwork.numOfUninteractingProteins() << endl;
	cout << "Number of interacting proteins: " << ProteinNetwork.numOfInteractingProteins();
	uninteractingProteins->PrintList();
	interactingProteins->PrintList();

	MatrixGraph<Protein>* toCloneFrom = &ProteinNetwork;
	MatrixGraph<Protein>* cloned = ProteinNetwork.cloneNetwork(toCloneFrom);
	cloned->PrintNetwork();
	
	LinkedList<Protein>* leastInteracting = ProteinNetwork.FindLeastInteracting();
	LinkedList<Protein>* mostInteracting = ProteinNetwork.FindMostInteracting();
	LinkedList<Protein>* strongestTwoProteins = ProteinNetwork.FindProteinsWithStrongestInteraction();
	LinkedList<Protein>* weakestAvgProteins = ProteinNetwork.FindProteinsWithWeakestTotalInteraction();
	LinkedList<Protein>* strongestAvgProteins = ProteinNetwork.FindProteinsWithStrongestTotalInteraction();
	LinkedList<Protein>* atLeastKInteractions = ProteinNetwork.ProteinsWithInteractionOfCountAtLeastK(2);
	LinkedList<Protein>* atMostKInteractions = ProteinNetwork.ProteinsWithInteractionOfCountAtMostK(1);
	LinkedList<Protein>* strongProteins = ProteinNetwork.ProteinsWithInteractionOfStrengthAtLeastK(10);
	LinkedList<Protein>* weakProteins = ProteinNetwork.ProteinsWithInteractionOfStrengthAtMostK(10);
	leastInteracting->PrintList();
	mostInteracting->PrintList();
	strongestTwoProteins->PrintList();
	strongestAvgProteins->PrintList();
	weakestAvgProteins->PrintList();
	atLeastKInteractions->PrintList();
	atMostKInteractions->PrintList();
	strongProteins->PrintList();
	weakProteins->PrintList();
	*/
	return 0;
}