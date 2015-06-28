#include "stdafx.h"
#include "BST.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>


using namespace std;

void bst_test();
void bst_correctness_test();

vector<int> insertValues = {};
vector<int> deleteValues = {};
vector<int> searchValues = {};


int _tmain(int argc, _TCHAR* argv[])
{
	//Generation of small int vectors used for testing
	for (int a = 0; a < 100; a++)
	{
		insertValues.push_back(a);
		searchValues.push_back(a);
	}

	for (int a = 25; a < 75; a++)
	{
		deleteValues.push_back(a);
	}

	random_shuffle(insertValues.begin(), insertValues.end());
	random_shuffle(deleteValues.begin(), deleteValues.end());
	random_shuffle(searchValues.begin(), searchValues.end());

	insertValues.clear();
	deleteValues.clear();
	searchValues.clear();

	//Generation of large int vectors used for testing
	for (int a = 0; a < 10000; a++)
	{
		insertValues.push_back(a);
		searchValues.push_back(a);
	}

	for (int a = 2500; a < 7500; a++)
	{
		deleteValues.push_back(a);
	}

	random_shuffle(insertValues.begin(), insertValues.end());
	random_shuffle(deleteValues.begin(), deleteValues.end());
	random_shuffle(searchValues.begin(), searchValues.end());

	bst_test();
	bst_correctness_test();

	cin.ignore();

	return 0;
}


void bst_correctness_test()
{
	cout << "####################" << endl << endl;;
	cout << "BST correctness test" << endl << endl;
	btree* myBtree = new btree;

	myBtree->print_insert(15);
	myBtree->print_insert(6);
	myBtree->print_insert(7);
	myBtree->print_insert(3);
	myBtree->print_insert(2);
	myBtree->print_insert(18);
	myBtree->print_insert(4);
	myBtree->print_insert(17);
	myBtree->print_insert(20);
	myBtree->print_insert(13);
	myBtree->print_insert(9);

	myBtree->print_inorder_tree_walk();

	myBtree->print_maximum();
	myBtree->print_minimum();

	myBtree->print_predecessor(15);
	myBtree->print_successor(15);

	myBtree->print_delete_node(17);
	myBtree->print_predecessor(15);
	myBtree->print_successor(15);

	myBtree->print_delete_node(15);
	myBtree->print_predecessor(18);
	myBtree->print_successor(13);
	myBtree->print_predecessor(13);
	myBtree->print_successor(9);
	myBtree->print_successor(7);
}

void bst_test()
{
	clock_t start_i, end_i, start_d, end_d, start_s, end_s;
	//Testing
	cout << "####################" << endl << endl;;
	cout << "Testing BST" << endl << endl;
	btree* myBtree = new btree;

	//Insert
	cout << "Inserting values into BST" << endl;
	start_i = clock();
	for (vector<int>::const_iterator i = insertValues.begin(); i != insertValues.end(); ++i)
	{
		myBtree->insert(*i);
	}
	end_i = clock();
	cout << "Time required for execution: "
		<< (double)(end_i - start_i) / CLOCKS_PER_SEC
		<< " seconds." << endl << endl;

	//Deletion
	cout << "Deleting values from BST" << endl;
	start_d = clock();
	for (vector<int>::const_iterator i = deleteValues.begin(); i != deleteValues.end(); ++i)
	{
		myBtree->delete_node(*i);
	}
	end_d = clock();
	cout << "Time required for execution: "
		<< (double)(end_d - start_d) / CLOCKS_PER_SEC
		<< " seconds." << endl << endl;

	//Searching
	cout << "Searching for values in BST" << endl;
	start_s = clock();
	for (vector<int>::const_iterator i = searchValues.begin(); i != searchValues.end(); ++i)
	{
		myBtree->search(*i);
	}
	end_s = clock();
	cout << "Time required for execution: "
		<< (double)(end_s - start_s) / CLOCKS_PER_SEC
		<< " seconds." << endl << endl;
}
