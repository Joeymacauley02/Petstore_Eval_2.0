/*
Name: Joey Macauley
Date: November 17, 2021
*/

#include "header.h"

/*************************************************************
 * Function: PetStoreList()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Constructor
 * Input parameters: void
 * Returns: void
 **************************************************************/
PetStoreList::PetStoreList()
{
	headPtr = nullptr;
}

/*************************************************************
 * Function: ~PetStoreList()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Deconstructor
 * Input parameters: void
 * Returns: void
 **************************************************************/
PetStoreList::~PetStoreList()
{
	PetStoreData *storePtr = headPtr;
	PetStoreData *nextStore = nullptr;

	while (storePtr != nullptr)
	{
		nextStore = storePtr->nextStore;
		delete storePtr;
		storePtr = nextStore;
	}
}

/*************************************************************
 * Function: createNode()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: creates a new link list node
 * Input parameters: string storeName
 * Returns: void
 **************************************************************/
PetStoreList::PetStoreData *PetStoreList::createNode(string storeName)
{
	PetStoreData *newStore = new PetStoreData;

	newStore->petStoreName = storeName;
	newStore->nextStore = nullptr;

	return newStore;
}

/*************************************************************
 * Function: insertAtEnd()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: insert node at the end of a link list
 * Input parameters: PetStoreData* newStoreData
 * Returns: void
 **************************************************************/
void PetStoreList::insertAtEnd(PetStoreData *newStoreData)
{
	PetStoreData *storePtr = nullptr;

	if (headPtr == nullptr)
	{
		headPtr = newStoreData;
	}
	else
	{
		storePtr = headPtr;
		while (storePtr->nextStore != nullptr)
		{
			storePtr = storePtr->nextStore;
		}
		storePtr->nextStore = newStoreData;
	}
}

/*************************************************************
 * Function: addPetData()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Adding data to a vector for pet data
 * Input parameters: string storeName, string pName, string pType, int numDays
 * Returns: void
 **************************************************************/
void PetStoreList::addPetData(string storeName, string pName, string pType, int numDays)
{
	PetStoreData *storePtr = headPtr;
	PetData temp;

	while (storePtr->petStoreName != storeName)
	{
		storePtr = storePtr->nextStore;
	}

	temp.petName = pName;
	temp.petType = pType;
	temp.numDaysAtStore = numDays;

	storePtr->petData.push_back(temp);
}

/*************************************************************
 * Function: displayPetList()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Print pet list to the consol
 * Input parameters: void
 * Returns: void
 **************************************************************/
void PetStoreList::displayPetList() const
{
	PetStoreData *storePtr = headPtr;
	while (storePtr != nullptr)
	{
		cout << "__________________________________" << endl;
		cout << "Pet Store Name: " << storePtr->petStoreName << endl;
		cout << "**********************************" << endl;
		cout << "| Number of Pets: " << storePtr->petData.size() << endl;
		cout << "| Pet Information: " << endl;
		for (int i = 0; i < storePtr->petData.size(); i++)
		{
			cout << "> Pet " << i + 1 << " Name: " << storePtr->petData.at(i).petName << endl;
			cout << "> Pet Type: " << storePtr->petData.at(i).petType << endl;
			cout << "> Number of days at store: " << storePtr->petData.at(i).numDaysAtStore << endl;
			cout << "----------------------------" << endl;
		}
		storePtr = storePtr->nextStore;
	}
}

/*************************************************************
 * Function: writePetList()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Output pet list to an outfile
 * Input parameters: ofstream& outfile
 * Returns: void
 **************************************************************/
void PetStoreList::writePetList(ofstream &outfile)
{
	PetStoreData *storePtr = headPtr;
	while (storePtr != nullptr)
	{
		outfile << "__________________________________" << endl;
		outfile << "Pet Store Name: " << storePtr->petStoreName << endl;
		outfile << "**********************************" << endl;
		outfile << "| Number of Pets: " << storePtr->petData.size() << endl;
		outfile << "| Pet Information: " << endl;
		for (int i = 0; i < storePtr->petData.size(); i++)
		{
			outfile << "> Pet " << i + 1 << " Name: " << storePtr->petData.at(i).petName << endl;
			outfile << "> Pet Type: " << storePtr->petData.at(i).petType << endl;
			outfile << "> Number of days at store: " << storePtr->petData.at(i).numDaysAtStore << endl;
			outfile << "----------------------------" << endl;
		}
		storePtr = storePtr->nextStore;
	}
}

/*************************************************************
 * Function: storeInList()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Check to see if a store is already in link list
 * Input parameters: string name
 * Returns: void
 **************************************************************/
bool PetStoreList::storeInList(string name)
{
	PetStoreData *storePtr = headPtr;

	while (storePtr != nullptr)
	{
		if (storePtr->petStoreName == name)
		{
			return true;
		}
		else
		{
			storePtr = storePtr->nextStore;
		}
	}
	return false;
}

/*************************************************************
 * Function: calculatePetSummary()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Make/update calculations for pet store data
 * Input parameters: void
 * Returns: void
 **************************************************************/
void PetStoreList::calculatePetSummary()
{
	PetStoreData *storePtr = headPtr;
	int totalDays = 0;
	summaryData.numPets = 0;
	summaryData.averageDaysAtStore = 0;
	summaryData.minDaysAtStore = 999;
	summaryData.maxDaysAtStore = 0;

	while (storePtr != nullptr)
	{
		for (int i = 0; i < storePtr->petData.size(); i++)
		{
			if (storePtr->petData.at(i).numDaysAtStore > summaryData.maxDaysAtStore)
			{
				summaryData.maxDaysAtStore = storePtr->petData.at(i).numDaysAtStore;
			}
			if (storePtr->petData.at(i).numDaysAtStore < summaryData.minDaysAtStore)
			{
				summaryData.minDaysAtStore = storePtr->petData.at(i).numDaysAtStore;
			}
			totalDays = totalDays + storePtr->petData.at(i).numDaysAtStore;
			(summaryData.numPets)++;
		}
		storePtr = storePtr->nextStore;
	}

	summaryData.averageDaysAtStore = totalDays / summaryData.numPets;
}

/*************************************************************
 * Function: displayPetSummary()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Display calculations to the consol
 * Input parameters: void
 * Returns: void
 **************************************************************/
void PetStoreList::displayPetSummary() const
{
	cout << "__________________________________" << endl;
	cout << "Total Number of pets: " << summaryData.numPets << endl;
	cout << "Average Number of days at pet store: " << summaryData.averageDaysAtStore << endl;
	cout << "Shortest stay at pet store: " << summaryData.minDaysAtStore << endl;
	cout << "Longest stay at pet store: " << summaryData.maxDaysAtStore << endl;
}

/*************************************************************
 * Function: writePetSummary()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Display calculations in an output file
 * Input parameters: ofstream& outfile
 * Returns: void
 **************************************************************/
void PetStoreList::writePetSummary(ofstream &outfile)
{
	outfile << "Pet Store CSV Summary Report" << endl;
	outfile << "__________________________________" << endl;
	outfile << "Total Number of pets: " << summaryData.numPets << endl;
	outfile << "Average Number of days at pet store: " << summaryData.averageDaysAtStore << endl;
	outfile << "Shortest stay at pet store: " << summaryData.minDaysAtStore << endl;
	outfile << "Longest stay at pet store: " << summaryData.maxDaysAtStore << endl;
}

/*************************************************************
 * Function: openFiles()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Open input and output file
 * Input parameters: ifstream& infile, ofstream& outfile, string infileName, string outfileName
 * Returns: bool
 **************************************************************/
bool openFiles(ifstream &infile, ofstream &outfile, string infileName, string outfileName)
{
	infile.open(infileName);
	outfile.open(outfileName);

	if (!infile.is_open() || !outfile.is_open())
	{
		return false;
	}
	else if (infile.fail() || outfile.fail())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*************************************************************
 * Function: processingData()
 * Date Created: November 8, 2021
 * Date Last Modified: November 11, 2021
 * Description: Read input file and output processing data to the consol
 * Input parameters: ifstream& inputFile, PetStoreList& storeList, vector<string>& header, stringstream& ss, int& numPets
 * Returns: void
 **************************************************************/
void processingData(ifstream &inputFile, PetStoreList &storeList, vector<string> &header, stringstream &ss, int &numPets)
{
	string lineToParse;
	string line = "", sName = "", pName = "", pType = "";
	int numDays = 0, avgDays = 0, totalDays = 0;
	bool alreadyIn = false;

	getline(inputFile, lineToParse);
	ss.clear();
	ss.str(lineToParse);
	getline(ss, line, ',');
	header.push_back(line);
	getline(ss, line, ',');
	header.push_back(line);
	getline(ss, line, ',');
	header.push_back(line);
	getline(ss, line, ',');
	header.push_back(line);

	cout << "Processed " << header.size() << " header columns: ";
	for (int i = 0; i < header.size(); i++)
	{
		cout << header.at(i);
		if (i < header.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl
		 << endl;
	while (!inputFile.eof())
	{
		if (inputFile.good())
		{
			getline(inputFile, lineToParse);
			ss.clear();
			ss.str(lineToParse);
			getline(ss, sName, ',');

			if (sName != "")
			{
				alreadyIn = storeList.storeInList(sName);
				if (alreadyIn == false)
				{
					storeList.insertAtEnd(storeList.createNode(sName));
				}
				getline(ss, pName, ',');
				getline(ss, pType, ',');
				ss >> numDays;
				storeList.addPetData(sName, pName, pType, numDays);
				if (sName != "")
				{
					cout << "Processed a " << pType << ", \"" << pName << "\" ... " << numDays << " days(s) on site at store \"" << sName << "\"" << endl;
					numPets++;
					totalDays = totalDays + numDays;
				}
			}
		}
		else
		{
			return;
		}
	}
	cout << "\nAll pet store data processed!\n\nGenerating summary report...\n\nDone!\n"
		 << endl;
	return;
}
