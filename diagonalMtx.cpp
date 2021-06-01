#include "diagonalMtx.h"
namespace simple_matrix
{
	// ����� ������������ ������� � �����
	void DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Diagonal matrix. Matrix side size: " << mtx->sideSize << endl;

		switch (mtx->style)
		{
		case 0:
			ofst << "Matrix output style - \"Line by line\" " << endl;
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
			break;
		case 1:
			ofst << "Matrix output style - \"Output by columns\" " << endl;
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
			break;
		case 2:
			ofst << "Matrix output style - \"Output to a one-dimensional array\" " << endl;
			ofst << "[ ";
			for (int col = 0; col < mtx->sideSize; col++)
			{
				ofst << mtx->currentMtx[col] << " ";
			}
			ofst << "]" << endl << endl;
			break;
		default:
			break;
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