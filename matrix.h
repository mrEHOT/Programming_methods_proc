#pragma once
#ifndef matrix_definition
#define matrix_definition
#include <string>
#include <iostream>
#include <fstream>
#include "squareMtx.h"
#include "diagonalMtx.h"
#include "triangularMtx.h"

using namespace std;

namespace simple_matrix
{
	enum type { SQUARE, DIAGONAL, TRIANGULAR };
	enum outputStyle { LINEBYLINE, BYCOLUMNS, ONEDIMENARR };

	struct matrix
	{
		type key;
		long sideSize;
		outputStyle style;
	};

	bool FilteredMtxOutput(matrix* mtx, ofstream& ofst);
	bool MtxCompare(matrix* firstMtx, matrix* secondMtx);
	int MtxSum(matrix* mtx);
	matrix* MtxInput(ifstream& ifst);
	bool MtxOutput(matrix* mtx, ofstream& ofst);
	void MtxClear(matrix* mtx);
	bool MtxStyleSet(matrix* mtx, int style);
}// end namesapce simple_matrix
#endif // !matrix_definition