#include "diagonalMtx.h"
namespace simple_matrix
{
	//��������� ����� ��������� � ������������ ������� �������
	int DiagonalSum(struct diagonalMtx* mtx)
	{
		if (!mtx->sumMarker)
		{
			for (int row = 0; row < mtx->sideSize; row++)
			{
				mtx->sum += mtx->currentMtx[row];
			}
			mtx->sumMarker = true; // ���������, ��� ����� ���� ���������
			return mtx->sum;
		} // ���� ����� ��� �� ���� ��������� => ������� � ����������
		else
		{
			return mtx->sum;
		} // ���������� ����� ��������������� �������� �����
	}

	// ����� ������������ ������� � �����
	void DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Diagonal matrix. Matrix side size: " << mtx->sideSize << ". Sum of matrix elements: " << mtx->sum << endl;
		for (int row = 0; row < mtx->sideSize; row++)
		{
			for (int col = 0; col < mtx->sideSize; col++)
			{
				if (row != col)
				{
					ofst << "0" << "\t";
				}
				else
				{
					ofst << mtx->currentMtx[row] << "\t";
				}
			}
			ofst << endl;
		}

		ofst << endl;
	}

	// ���� ������������ ������� �� ��������� ������ �� ������
	diagonalMtx* DiagonalInput(ifstream& ifst)
	{
		string content = ""; // ������� ������ ������ ��� ���������� ��������� ������
		string delimiter = ","; // �����������
		string part = ""; // ������ ��� ������ ��������� ��������� �������
		size_t pos = 0;
		int col = 0;

		diagonalMtx* mtx = new diagonalMtx;

		ifst >> mtx->sideSize >> content; // ��������� ������ ������� (���-�� ��������� � ���������� �������), ����� ��������� ���� ��������
		mtx->currentMtx = new int[mtx->sideSize]; // ������� ����� ������������ ������


		while ((pos = content.find(delimiter)) != string::npos)
		{
			part = content.substr(0, pos);
			mtx->currentMtx[col] = atoi(part.c_str()); // ��������� col ������� �������
			col++;
			content.erase(0, pos + delimiter.length());
		} // ��������� ������� ������ �� ����������� ","

		mtx->currentMtx[col] = atoi(content.c_str()); // ������ ��������� ������� �������

		return mtx;
	}

	// ������� ������
	void DiagonalClear(struct diagonalMtx* mtx)
	{
		delete[] mtx->currentMtx; // ����� ������ ������� ������� ������, ���������� ��� ������ 
	}
} // end namesapce simple_matrix