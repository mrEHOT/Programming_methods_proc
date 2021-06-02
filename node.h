#pragma once
#ifndef node_definition
#define node_definition
#include <string>
#include <iostream>
#include <fstream>
#include "matrix.h"
#include "container.h"
using namespace std;
namespace simple_matrix
{
	struct node
	{
		matrix* mtx;
		node* next;
		node* prev;
	};

	void NodeCompare(struct node* head, int size);
	node* GetNode(struct node* head, int pos);
	void NodeSwap(struct node* head, int first, int second);
	bool FilteredNodeOutput(struct node* head, int pos, ofstream& ofst);
	bool NodeAdd(struct container* cont, ifstream& ifst);
	void NodeRemove(struct node* head, int pos);
	bool NodeOutput(struct node* head, int pos, ofstream& ofst);
} // end namespace simple_matrix
#endif // !node_definition