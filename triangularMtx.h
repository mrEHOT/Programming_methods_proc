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

	// ���������, ��������������� ������ ����������� �������
	struct triangularMtx
	{
		type key;
		long sideSize; // ������ ������� �������
		int* currentMtx; // ������������ ��������� ������ ��� �������� �������� ���� int
	};

	void TriangularOutput(struct triangularMtx* mtx, ofstream& ofst); // ����� ������ ����������� ������� � �����
	triangularMtx* TriangularInput(ifstream& ifst); // ���� ������ ����������� ������� �� ��������� ������ �� ������
	void TriangularClear(struct triangularMtx* mtx); // ������� ������
} // end namesapce simple_matrix
#endif // !triangularMtx_definition