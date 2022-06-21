#pragma once
#include <iostream>
#include "Protein/Protein.h"
using namespace std;

Protein::Protein() {
	name = "Default Protein";
	ID = 0;
	aaCount = 100;
	type = Neutral;
	location = Cytosolic;
	function = Regulator;
	color = BLUE;
	enzyme = NUL;
}

Protein::Protein(string n, int id, int aa, proteinType t, proteinLocation l, proteinFunction f, proteinColor c, EnzymeType et) {
	name = n;
	ID = id;
	aaCount = aa;
	type = t;
	location = l;
	function = f;
	color = c;
	enzyme = et;
}

Protein::Protein(string n) {
	name = n;
	ID = 0;
	aaCount = 100;
	type = Neutral;
	location = Cytosolic;
	function = Regulator;
	color = BLUE;
	enzyme = NUL;
}

string Protein::getName() const {
	return name;
}

int Protein::getID() const {
	return ID;
}

int Protein::getAACount() const {
	return aaCount;
}

string Protein::getType() const {
	switch (type) {
	case Activator:
		return "Activator";
		break;
	case Deactivator:
		return "Deactivator";
		break;
	case Neutral:
		return "Neutral";
		break;
	}
}

string Protein::getLocation() const {
	switch (location) {
	case Cytosolic:
		return "Cytosolic";
		break;
	case Membraneous:
		return "Membraneous";
		break;
	}
}

string Protein::getFunction() const {
	switch (function) {
	case Antibody:
		return "Antibody";
		break;
	case Enzyme:
		return "Enzyme";
		break;
	case Messenger:
		return "Messenger";
		break;
	case Structural:
		return "Structural";
		break;
	case Transport:
		return "Transport";
		break;
	case Storage:
		return "Storage";
		break;
	case Regulator:
		return "Regulator";
		break;
	}
}

string Protein::getEnzymeType() const {
	switch (enzyme) {
	case Hydrolase:
		return "Hydrolase";
		break;
	case Ligase:
		return "Ligase";
		break;
	case Lyase:
		return "Lyase";
		break;
	case Transferase:
		return "Transferase";
		break;
	case Oxidoreductase:
		return "Oxidoreductase";
		break;
	case Isomerase:
		return "Isomerase";
		break;
	case Synthetase:
		return "Synthetase";
		break;
	case NUL:
		return "Not yet defined";
		break;
	}
}

string Protein::getColor() const {
	switch (color) {
	case BLACK:
		return "Black";
		break;
	case WHITE:
		return "White";
		break;
	case RED:
		return "Red";
		break;
	case YELLOW:
		return "Yellow";
		break;
	case GREEN:
		return "Green";
		break;
	case BLUE:
		return "Blue";
		break;
	}
}

void Protein::setName(string n) {
	name = n;
}

void Protein::setID(int id) {
	ID = id;
}

void Protein::setAACount(int aa) {
	aaCount = aa;
}

void Protein::setLocation(proteinLocation l) {
	location = l;
}

void Protein::setFunction(proteinFunction f)
{
	function = f;
}

void Protein::setColor(proteinColor c)
{
	color = c;
}

void Protein::setEnzymeType(EnzymeType et)
{
	enzyme = et;
}

void Protein::setType(proteinType t) {
	type = t;
}

void Protein::printProteinInfo() const
{
	cout << "Protein's name: " << getName() << endl;
	cout << "Protein's ID: " << getID() << endl;
	cout << "Protein's amino acid count: " << getAACount() << endl;
	cout << "Protein's type: " << getType() << endl;
	cout << "Protein's location: " << getLocation() << endl;
	cout << "Protein's Function: " << getFunction() << endl;
	cout << "Protein's color: " << getColor() << endl;
	if (getFunction() == "Enzyme") {
		cout << "Protein's Enzymatic Role: " << getEnzymeType() << endl;
	}
}

bool Protein::operator==(const Protein& rhs) const {
	return this->getName() == rhs.name;
}