/*
Name: Joey Macauley
Date: November 17, 2021
*/

#ifndef PETSTORE_2 .0
#define PETSTORE_2 .0

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class PetStoreList
{
private:
	// programmer-defined data type
	// stores data related to a single pet
	struct PetData
	{
		string petName;
		string petType;
		int numDaysAtStore;
	};
	// programmer-defined data type
	// stores data related to a single
	// PetStoreList
	struct PetSummary
	{
		int numPets;
		int averageDaysAtStore;
		int minDaysAtStore;
		int maxDaysAtStore;
	};
	// programmer-defined data type
	// stores data related to a single store
	// includes the store name, a vector of all
	// pet data associated with that store, and
	// a pointer to the next store in the list
	struct PetStoreData
	{
		string petStoreName;
		vector<PetData> petData;
		PetStoreData *nextStore;
	};
	// a private member of the PetStoreList class
	// storing this class object's summary data
	// for all pet stores and pets
	PetSummary summaryData = {};

	// pointer to the start of this class object's
	// list of pet store and pet data
	PetStoreData *headPtr;

public:
	PetStoreList();	 // class constructor
	~PetStoreList(); // class destructor
	/* createNode
	 * creates a new PetStoreData variable and initializes the store name,
	 * returns a pointer to the dynamically allocated memory. */
	PetStoreData *createNode(string storeName); // Note: extra step attention required to handle this return type
	/* insertAtEnd
	 * accepts a pointer to PetStoreData variable
	 * inserts the PetStoreData "node" at the end of the list */
	void insertAtEnd(PetStoreData *newStoredata);
	/* addPetData
	 * adds pet name, pet type, and number of days that pet has been at the store
	 * to the vector of pet data for the matching store name. */
	void addPetData(string storeName, string pName, string pType, int numDays);
	/* displayPetList
	 * prints the contents of the PetStoreList in forward order
	 * see example output */
	void displayPetList() const;
	/* writePetList
	 * writes the contents of the PetStoreList in forward order to an output file
	 * see example output */
	void writePetList(ofstream &outfile);
	/* storeInList
	 * accepts a string store name
	 * returns true if the store name is in this object's list of stores */
	bool storeInList(string name);
	/* calculatePetSummary
	 * calculates/updates this object's PetSummary values
	 * see PetSummary programmer-defined data type */
	void calculatePetSummary();
	/* displayPetSummary
	 * prints this object's PetSummary values of the PetStoreList
	 * see example output */
	void displayPetSummary() const;
	/* writePetSummary
	 * writes this object's PetSummary values of the PetStoreList to an output file
	 * see example output */
	void writePetSummary(ofstream &outfile); // bonus class member functions
};

bool openFiles(ifstream &infile, ofstream &outfile, string infileName, string outfileName);
void processingData(ifstream &inputFile, PetStoreList &storeList, vector<string> &header, stringstream &ss, int &numPets);

#endif
