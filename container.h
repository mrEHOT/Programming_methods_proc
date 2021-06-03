#pragma once
#ifndef container_definition
#define container_definition
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

namespace simple_matrix
{
	struct container
	{
		long size;
		struct node* head;
	};

	void Sort(struct container* cont);
	void FilteredOutput(struct container* cont, ofstream& ofst);
	void Init(struct container* cont);
	void Clear(struct container* cont);
	bool Input(struct container* cont, ifstream& ifst);
	void Output(struct container* cont, ofstream& ofst);
} // end namespace simple_matrix
#endif // !container_definition