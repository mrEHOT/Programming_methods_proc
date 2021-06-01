#include "squareMtx.h"
namespace simple_matrix
{
	// ����� ����������� ������� � �����
	void SquareOutput(struct squareMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Square matrix. Matrix side size: " << mtx->sideSize << endl;

		switch (mtx->style)
		{
		case 0:
			for (int row = 0; row < mtx->sideSize; row++)
			{
				for (int col = 0; col < mtx->sideSize; col++)
				{
					ofst << mtx->currentMtx[row][col] << "\t";
				}
				ofst << endl;
			}
			ofst << endl;
			break;
		case 1:
			for (int col = 0; col < mtx->sideSize; col++)
			{
				for (int row = 0; row < mtx->sideSize; row++)
				{
					ofst << mtx->currentMtx[row][col] << "\t";
				}
				ofst << endl;
			}
			ofst << endl;
			break;
		case 2:
			ofst << "[ ";
			for (int row = 0; row < mtx->sideSize; row++)
			{
				for (int col = 0; col < mtx->sideSize; col++)
				{
					ofst << mtx->currentMtx[row][col] << " ";
				}
			}
			ofst << "]" << endl;
			break;
		default:
			break;
		}
	}

	// ���� ����������� ������� �� ��������� ������ �� ������
	squareMtx* SquareInput(ifstream& ifst)
	{
		string content = ""; // ������� ������ ������ ��� ���������� ��������� ������
		string delimiter = ","; // �����������
		string part = ""; // ������ ��� ������ ��������� ��������� �������
		size_t pos = 0;
		int col = 0;

		squareMtx* mtx = new squareMtx;

		ifst >> mtx->sideSize; // ��������� ������ ���������� ������� 
		mtx->currentMtx = new int* [mtx->sideSize]; // ������� ������ ���������� �� ���������
		for (int row = 0; row < mtx->sideSize; row++)
		{
			mtx->currentMtx[row] = new int[mtx->sideSize]; //������� ��������� �� ���������� ������
		} // �������� ���������� �������

		for (int row = 0; row < mtx->sideSize; row++)
		{
			ifst >> content;

			while ((pos = content.find(delimiter)) != string::npos)
			{
				part = content.substr(0, pos);
				mtx->currentMtx[row][col] = atoi(part.c_str()); // ��������� col ������� ������� � ������ row
				col++;
				content.erase(0, pos + delimiter.length());
			} // ��������� ������� ������ �� ����������� ","

			mtx->currentMtx[row][col] = atoi(content.c_str()); // ������ ��������� ������� ������ � ������� row
			content = ""; //�������� ������ content
			col = 0; //�������� ������� �������� �� ��������
		}

		return mtx;
	}

	// ������� ������
	void SquareClear(struct squareMtx* mtx)
	{
		for (int row = 0; row < mtx->sideSize; row++)
		{
			delete mtx->currentMtx[row];
		} // ������� ��������� �� ���������� �������

		delete[] mtx->currentMtx; // ����� ������ ������� ������� ������, ���������� ��� ������ 
	}
} // end namesapce simple_matrix