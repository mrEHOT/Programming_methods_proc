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

	// ���������, ��������������� ������������ ���������� �������
	struct squareMtx
	{
		type key;
		long sideSize; // ������ ������� �������
		int** currentMtx; // ������������ ��������� ������ ��� �������� �������� ���� int
	};

	void SquareOutput(struct squareMtx* mtx, ofstream& ofst); // ����� ����������� ������� � �����
	squareMtx* SquareInput(ifstream& ifst); // ���� ����������� ������� �� ��������� ������ �� ������
	void SquareClear(struct squareMtx* mtx); // ������� ������
} // end namesapce simple_matrix
#endif // !squareMtx_definition