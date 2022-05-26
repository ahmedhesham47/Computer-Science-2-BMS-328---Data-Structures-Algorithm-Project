#pragma once
#include <iostream>
#include <string>
using namespace std;

enum proteinType {
	Activator, 
	Deactivator, 
	Neutral
};

class Protein
{
private:
	string name = "";
	int ID = 0;
	enum proteinType type = Neutral;
public:
	Protein() {
		name = "";
		ID = 0;
		type = Neutral;
	}
	Protein(string n, int id, proteinType t) {
		name = n;
		ID = id;
		type = t;
	}

	bool operator==(const Protein& rhs) const { 
		
		return this->getName() == rhs.name;
	}

	friend ostream& operator<<(ostream& os, Protein const& m);

	string getName() const{
		return name;
	}
	int getID() const {
		return ID;
	}
	string getType() const {
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

	void setName(string n) {
		name = n;
	}
	void setID(int id) {
		ID = id;
	}
	void setType(proteinType t) {
		type = t;
	}
	void printProteinInfo() const {
		cout << "Protein's name: " << getName() << endl;
		cout << "Protein's ID: " << getID() << endl;
		cout << "Protein's Type: " << getType() << endl;
	}
};

ostream& operator<<(ostream& os, Protein const& m) {
	return os << m.getName();
}
