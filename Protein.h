#pragma once
#include <iostream>
#include <string>
using namespace std;

enum proteinType {
	Activator, 
	Deactivator, 
	Neutral
};

enum proteinLocation {
	Cytosolic,
	Membraneous
};

enum proteinFunction {
	Antibody,
	Enzyme,
	Messenger,
	Structural,
	Transport,
	Storage,
	Regulator
};

enum EnzymeType {
	Hydrolase,
	Isomerase,
	Lyase,
	Oxidoreductase,
	Synthetase,
	Transferase,
	Ligase,
	NUL
};

enum proteinColor {
	BLACK,
	WHITE,
	RED,
	YELLOW,
	GREEN,
	BLUE
};

class Protein
{
private:
	string name;
	int ID;
	int aaCount;
	proteinType type;
	proteinLocation location;
	proteinFunction function;
	EnzymeType enzyme;
	proteinColor color;
public:
	Protein();
	Protein(string n, int id, int aa, proteinType t, proteinLocation l, proteinFunction f, proteinColor c = WHITE, EnzymeType et = NUL);
	Protein(string n);

	bool operator==(const Protein& rhs) const;

	friend ostream& operator<<(ostream& os, Protein const& m);

	string getName() const;

	int getID() const;

	int getAACount() const;
	
	string getType() const;

	string getLocation() const;

	string getFunction() const;

	string getColor() const;

	string getEnzymeType() const;

	void setName(string n);

	void setID(int id);
	
	void setAACount(int aa);

	void setType(proteinType t);

	void setLocation(proteinLocation l);

	void setFunction(proteinFunction f);

	void setColor(proteinColor c);

	void setEnzymeType(EnzymeType et);

	void printProteinInfo() const;
};
