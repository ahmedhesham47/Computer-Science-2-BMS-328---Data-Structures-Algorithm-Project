// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include "Data Structures/Graph/MatrixGraph.cpp"
#include "../Project/Protein/Protein.h"
#include <iostream>
using namespace std;

int main()
{
	//std::cout << "test"; 
	Protein protein1 = Protein("Z", 30, Activator);
	Protein protein2 = Protein("A", 31, Activator);
	Protein protein3 = Protein("B", 32, Activator);
	Protein protein4 = Protein("C", 33, Activator);
	Protein protein5 = Protein("D", 34, Deactivator);
	Protein protein6 = Protein("E", 35, Activator);
	Protein protein7 = Protein("F", 36, Activator);
	Protein protein8 = Protein("G", 37, Neutral);
	Protein protein9 = Protein("H", 38, Neutral);
	Protein protein10 = Protein("I", 39, Activator);
	Protein protein11 = Protein("J", 40, Activator);
	Protein protein12 = Protein("K", 41, Activator);
	

	MatrixGraph<Protein> ProteinNetwork;
	ProteinNetwork.AddProtein(protein1);
	ProteinNetwork.AddProtein(protein2);
	ProteinNetwork.AddProtein(protein3);
	ProteinNetwork.AddProtein(protein4);
	ProteinNetwork.AddProtein(protein5);
	ProteinNetwork.AddProtein(protein6);
	ProteinNetwork.AddProtein(protein7);
	ProteinNetwork.AddProtein(protein8);
	ProteinNetwork.AddProtein(protein9);
	ProteinNetwork.AddProtein(protein10);
	ProteinNetwork.AddProtein(protein11);

	ProteinNetwork.AddInteraction(protein6, protein8, 7);
	ProteinNetwork.AddInteraction(protein8, protein6, 2);
	ProteinNetwork.AddInteraction(protein6, protein3, 5);
	ProteinNetwork.AddInteraction(protein6, protein1, 7);
	ProteinNetwork.AddInteraction(protein3, protein1, 5);
	ProteinNetwork.AddInteraction(protein3, protein2, 7);
	ProteinNetwork.AddInteraction(protein3, protein8, 5);
	ProteinNetwork.AddInteraction(protein2, protein7, 11);
	ProteinNetwork.AddInteraction(protein9, protein11, 11);
	ProteinNetwork.AddInteraction(protein11, protein4, 14);
	ProteinNetwork.saveFile("testt7");
	ProteinNetwork.SaveProtein("tst2", protein6);

	//ProteinNetwork.DisplayInteracting(protein6);
	ProteinNetwork.PrintNetwork();
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