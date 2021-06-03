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
	enum outputStyle;

	// ���������, ��������������� ������������ ���������� �������
	struct diagonalMtx
	{
		type key;
		long sideSize; // ������ ������� �������
		outputStyle style; // ������ ������
		int* currentMtx; // ������������ ���������� ������ ��� �������� �������� ���� int
		int sum = 0; // ����� ��������� �������
		bool sumMarker = false; // ����, �����������, ��� ����� ��� ���� ����������
	};

	int DiagonalSum(struct diagonalMtx* mtx); // ��������� ����� ��������� � ���������� �������
	bool DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst); // ����� ������������ ������� � �����
	diagonalMtx* DiagonalInput(ifstream& ifst); // ���� ������������ ������� �� ��������� ������ �� ������
	void DiagonalClear(struct diagonalMtx* mtx); // ������� ������
} // end namesapce simple_matrix
#endif // !diagonalMtx_definition