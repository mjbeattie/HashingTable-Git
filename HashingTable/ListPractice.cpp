/* HashingTable.cpp : Demonstrates the use of vectors, linked lists, and hash tables
*  Author:  Matthew J. Beattie
*  Date:    July 18, 2017
*  Course:  CS 5005, Summer 2017
*/


#include <iostream>
#include <vector>
#include <array>
#include <list>
#include "Exception.h"
#include "Enumeration.h"
#include "HashTable.h"

using namespace std;


int main()
{

	//Sample list of names from Project 2 problem statement
	char* Names[25] = { "Andy B", "Amy Dean", "Antonio G", "Andy Roberts",
		"Brian W","Bob Macy", "Brent James", "Buck Muck",
		"Cannon James", "Cart Wright", "Catherine Zeta", "Carl Lewis",
		"David Johnson", "Dowd Peter", "Daniel Fauchier", "Dawn Smith",
		"Yarda Varda", "Yami Jacob", "Yester Louis", "Yukon Oklahoma",
		"Zandi Rich", "Zea John", "Zelby Leon", "Ziert Paul", "Zanola Helen" };

	//Procedures to manipulate the list of names
	cout << "The value of Names[1] is " << Names[1] << endl;			//Prints out an entire name char array
	cout << "The location of Names[1] is " << &Names[1] << endl;		//Prints the address

	for (char* c = Names[1]; *c; ++c) {									//Prints out a name character by character
		cout << c[0] << endl;
	}

	//Add all names to a single linked list and manipulate the list
	list<char*> namesList;												//Define a linked list
	cout << "Adding the names to a list..." << endl;					
	for (int i = 0; i < 25; ++i) {
		namesList.push_back(Names[i]);									//Add names to the list
	}
	
	cout << "The size of the linked list is " << namesList.size() << endl;

	list<char*>::iterator tempIter;										//Check beginning and end
	tempIter = namesList.begin();						
	cout << "Printing first name: " << *tempIter << endl;
	tempIter = namesList.end();
	tempIter--;
	cout << "Printing last name: " << *tempIter << endl;

	cout << "Printing the names in original order..." << endl;			//Iterate through list and print
	for (list<char*>::iterator namesListIter = namesList.begin(); namesListIter != namesList.end(); ++namesListIter) {
		cout << "Name is " << *namesListIter << endl;
	}
	cout << "Names list print complete" << endl;
	
    /***********************************/
	//Create a vector that is a set of linked lists and manipulate it
	vector<list<char*>> llVector;
	vector<list<char*>>::iterator llvIterator;

	//Create three linked lists and add to the vector
	list<char*> firstList;												//Define a linked list
	for (int i = 0; i < 3; ++i) {
		firstList.push_back(Names[i]);									//Add names to the list
	}

	list<char*> secondList;												//Define a linked list
	for (int i = 3; i < 6; ++i) {
		secondList.push_back(Names[i]);									//Add names to the list
	}
	list<char*> thirdList;												//Define a linked list
	for (int i = 6; i < 9; ++i) {
		thirdList.push_back(Names[i]);									//Add names to the list
	}

	//Add the linked lists to the vector
	llVector.push_back(firstList);
	llVector.push_back(secondList);
	llVector.push_back(thirdList);


	//Create a list iterator for printing
	list<char*>::iterator listIterator;
	cout << "Printing the names in 1th position of vector" << endl;			//Iterate through list and print
	for (listIterator = llVector[1].begin(); listIterator != llVector[1].end(); ++listIterator) {
		cout << "Name is " << *listIterator << endl;
	}
	cout << "1th vector list complete" << endl;
	

	
	return 0;

} //end main()

