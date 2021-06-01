#pragma once
#ifndef triangularMtx_definition
#define triangularMtx_definition
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
namespace simple_matrix
{
	enum type;
	enum outputStyle;

	struct triangularMtx
	{
		type key;
		long sideSize;
		outputStyle style;
		int* currentMtx;
		int currentMtxSize;
		int sum = 0;
		bool sumMarker = false;
	};

	int TriangularSum(struct triangularMtx* mtx);
	void TriangularOutput(struct triangularMtx* mtx, ofstream& ofst);
	triangularMtx* TriangularInput(ifstream& ifst);
	void TriangularClear(struct triangularMtx* mtx);
} // end namesapce simple_matrix
#endif // !triangularMtx_definition