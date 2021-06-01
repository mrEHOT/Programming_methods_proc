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
	enum type { SQUARE, DIAGONAL  TRIANGULAR }; // Тип квадратной матрицы: 1. Обычный двумерный массив размером n x n; 2. Диагональная матрица (на основе одномерного массива)
	enum outputStyle { LINEBYLINE, BYCOLUMNS, ONEDIMENARR }; // Выбор способа вывода матрицы: 1)Построчно; 2)По столбцам; 3)В виде одномерного массива

	struct matrix
	{
		type key;
		long sideSize;
		outputStyle style;
	};

	matrix* MtxInput(ifstream& ifst);
	bool MtxOutput(matrix* mtx, ofstream& ofst);
	void MtxClear(matrix* mtx);
	bool MtxStyleSet(matrix* mtx, int style);
}// end namesapce simple_matrix
#endif // !matrix_definition