#pragma once
#ifndef squareMtx_definition
#define squareMtx_definition
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace simple_matrix
{
	enum type;
	enum outputStyle;

	// ���������, ��������������� ������������ ���������� �������
	struct squareMtx
	{
		type key;
		long sideSize; // ������ ������� �������
		outputStyle style; // ������ ������
		int** currentMtx; // ������������ ��������� ������ ��� �������� �������� ���� int
		int sum = 0; // ����� ��������� �������
		bool sumMarker = false; // ����, �����������, ��� ����� ��� ���� ����������
	};

	int SquareSum(struct squareMtx* mtx); // ��������� ����� ��������� � ���������� �������
	bool SquareOutput(struct squareMtx* mtx, ofstream& ofst); // ����� ����������� ������� � �����
	squareMtx* SquareInput(ifstream& ifst); // ���� ����������� ������� �� ��������� ������ �� ������
	void SquareClear(struct squareMtx* mtx); // ������� ������
} // end namesapce simple_matrix
#endif // !squareMtx_definition