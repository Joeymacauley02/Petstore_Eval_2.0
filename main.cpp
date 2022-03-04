/*
Name: Joey Macauley
Date: November 17, 2021
*/

#include "header.h"

int main(void)
{
	PetStoreList storeList;
	ifstream infile;
	ofstream outfile;
	string inputFileName = "petstoredata.csv";
	string outputFileName = "petreport.txt";
	vector<string> header;
	stringstream ss;

	bool isOpen = false;
	int numPets = 0, totaldays = 0, avgDays = 0;
	isOpen = openFiles(infile, outfile, inputFileName, outputFileName);

	if (isOpen == true)
	{
		cout << "Success! Both files are open.\n"
			 << endl;
	}
	else
	{
		cout << "Error! File(s) failed to open." << endl;
		exit(-1);
	}

	processingData(infile, storeList, header, ss, numPets);
	storeList.calculatePetSummary();
	storeList.writePetSummary(outfile);
	storeList.displayPetSummary();
	storeList.displayPetList();
	storeList.writePetList(outfile);

	infile.close();
	outfile.close();
	return 0;
}