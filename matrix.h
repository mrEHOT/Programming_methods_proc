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
	enum type { SQUARE, DIAGONAL, TRIANGULAR }; // ��� ���������� �������: 1. ������� ��������� ������ �������� n x n; 2. ������������ ������� (�� ������ ����������� �������)

// ��������� ���������� ��� ���� ���������� ������
	struct matrix
	{
		type key;
		long sideSize; // ������ �������
	};

	matrix* MtxInput(ifstream& ifst); // ���������� ����� ���������� ������� �� ��������� ������ �� ������
	bool MtxOutput(matrix* mtx, ofstream& ofst); // ����� ���������� � ���������� ������� � �����
	void MtxClear(matrix* mtx); // ������� ������, ���������� ��� �������� �������
}// end namesapce simple_matrix
#endif // !matrix_definition