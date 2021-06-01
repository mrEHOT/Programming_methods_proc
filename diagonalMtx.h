#pragma once
#ifndef diagonalMtx_definition
#define diagonalMtx_definition
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
namespace simple_matrix
{
	enum type;

	// ���������, ��������������� ������������ ���������� �������
	struct diagonalMtx
	{
		type key;
		long sideSize; // ������ ������� �������
		int* currentMtx; // ������������ ���������� ������ ��� �������� �������� ���� int
	};

	void DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst); // ����� ������������ ������� � �����
	diagonalMtx* DiagonalInput(ifstream& ifst); // ���� ������������ ������� �� ��������� ������ �� ������
	void DiagonalClear(struct diagonalMtx* mtx); // ������� ������
} // end namesapce simple_matrix
#endif // !diagonalMtx_definition