/* HashingTable.cpp : Demonstrates the use of vectors, linked lists, and hash tables
*  Author:  Matthew J. Beattie
*  Date:    July 18, 2017
*  Course:  CS 5005, Summer 2017
*/


#include "VectorHashTable.h"

using namespace std;

int main()
{
	try
	{
		/********************************************************************/
		/*********       MY TEST CODE FOLLOWS              ******************/
		/********************************************************************/
		cout << "TESTING VECTORHASHTABLE CLASS WITH MY CODE" << endl << endl;
		//Sample list of names from Project 2 problem statement
		char* myNames[25] = { "Andy B", "Amy Dean", "Antonio G", "Andy Roberts",
			"Brian W","Bob Macy", "Brent James", "Buck Muck",
			"Cannon James", "Cart Wright", "Catherine Zeta", "Carl Lewis",
			"David Johnson", "Dowd Peter", "Daniel Fauchier", "Dawn Smith",
			"Yarda Varda", "Yami Jacob", "Yester Louis", "Yukon Oklahoma",
			"Zandi Rich", "Zea John", "Zelby Leon", "Ziert Paul", "Zanola Helen" };


		//Initialize a vector hash table with size 0 -- the size of the table will increase as necessary
		cout << "Creating a hash table hashHT..." << endl;
		VectorHashTable<char*>* testHT;
		testHT = new VectorHashTable<char*>();

		//Load the list of names into the new hash table
		for (int i = 0; i < 25; ++i)
		{
			(*testHT).insert(myNames[i]);
		}

		//Print out the entire hash table using overloaded operator <<
		cout << *testHT;
		cout << endl;

		//Check for a char* in the hash table
		cout << "Searching for Bob Macy... " << endl;
		cout << "The hash location for Bob Macy was " << (*testHT).foundAt("Bob Macy") << endl;

		//Remove a char* in the hash table
		cout << "Removing Bob Macy..." << endl;
		(*testHT).remove("Bob Macy");
		cout << "Bob Macy found? " << (*testHT).find("Bob Macy") << endl;
		cout << *testHT;
		cout << endl;

		//Test overloaded operator []
		cout << endl << "Testing overloaded operator []" << endl;
		list<char*> newList = (*testHT)[0];
		for (list<char*>::iterator iter = newList.begin(); iter != newList.end(); ++iter)
		{
			cout << *iter << ", ";
		}
		cout << endl;

		//Perform split on table, reducing the length of the linked lists
		cout << endl << "Splitting the hash table..." << endl;
		unsigned int startSize = (*testHT).size();
		for (unsigned int i = 0; i < startSize; ++i)
		{
			(*testHT).split(i, 2);
		}
		cout << *testHT;

		//Deleting hash table using destructor method
		delete testHT;

		/****************************************************/
		/***       SAMPLE CODE FROM HOMEWORK FOLLOWS      ***/
		/****************************************************/
		cout << endl << endl << "TESTING VECTORHASHTABLE CLASS WITH ASSIGNED CODE" << endl << endl;
		VectorHashTable<char*>* myHashTable;
		char* Names[25] = { "Andy B", "Amy Dean", "Antonio G", "Andy Roberts",
			"Brian W","Bob Macy", "Brent James", "Buck Muck",
			"Cannon James", "Cart Wright", "Catherine Zeta", "Carl Lewis",
			"David Johnson", "Dowd Peter", "Daniel Fauchier", "Dawn Smith",
			"Yarda Varda", "Yami Jacob", "Yester Louis", "Yukon Oklahoma",
			"Zandi Rich", "Zea John", "Zelby Leon", "Ziert Paul", "Zanola Helen" };
		int i; 
		myHashTable = new VectorHashTable<char*>();					//Note: changed to show empty constructor
		for (int i = 0; i < 25; i++)
			(*myHashTable).insert(Names[i]);
		cout << "Printing the hash table after inserting...." << endl;
		cout << *myHashTable << endl;
		if ((*myHashTable).find("Zandi Rich"))
			cout << "Zandi Rich is in the list" << endl;
		else
			cout << "Zandi Rich is not in the list" << endl;
		(*myHashTable).remove("Zea John");
		if ((*myHashTable).find("Zea John"))
			cout << "Zea John is in the list" << endl;
		else
			cout << "Zea John is not in the list" << endl;
		for (i = 0; i < 26; i++)
			(*myHashTable).split(i, 2);
		cout << "Printing the hash table after splitting...." << endl;
		cout << *myHashTable << endl;
		if ((*myHashTable).find("Ziert Paul"))
			cout << "Ziert Paul is in the list" << endl;
		else
			cout << "Ziert Paul is not in the list" << endl;
			(*myHashTable).insert("Zea John");
		if ((*myHashTable).find("Zea John"))
			cout << "Zea John is in the list [up at 25 because the table isn't resplit]" << endl;
		else
			cout << "Zea John is not in the list" << endl;

		//Routine to test copy() method
		cout << endl << "TESTING COPY CONSTRUCTOR USING LAST MYHASHTABLE ABOVE" << endl;
		VectorHashTable<char*> destTable;
		destTable.copy(*myHashTable);
		cout << "Table created via copy(): " << endl;
		cout << destTable << endl;

		//Routine to test copy constructor
		VectorHashTable<char*>* anotherTable;
		anotherTable = new VectorHashTable<char*>(*myHashTable);
		cout << "Table created via copy constructor: " << endl;
		cout << *anotherTable << endl;

		//Routine to test copy constructor
		VectorHashTable<char*> oneMoreTable;
		oneMoreTable = destTable;
		cout << "Table created via overloaded = : " << endl;
		cout << oneMoreTable << endl;

		delete myHashTable;				//Explicit call to destructor due to the way we created the table
		delete anotherTable;			//Explicit call required
		//Don't need to call destructor for tables created without calls to "new"

		return 0;

	}
	catch (exception e)
	{
		cout << "Encountered Hash Table errors" << endl;
		return 0;
	}


} //end main()

