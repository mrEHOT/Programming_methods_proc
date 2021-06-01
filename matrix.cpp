#include "matrix.h"
namespace simple_matrix
{
	// ?��������� ����� ���������� ������� �� ��������� ������ �� ������
	matrix* MtxInput(ifstream& ifst)
	{
		matrix* newMatrix;
		int currKey;
		ifst >> currKey;

		switch (currKey)
		{
		case 0:
			newMatrix = (matrix*)SquareInput(ifst);
			newMatrix->key = SQUARE;
			break;
		case 1:
			newMatrix = (matrix*)DiagonalInput(ifst);
			newMatrix->key = DIAGONAL;
			break;
		default:
			return NULL; // ���������� NULL, �.�. �� ������� ���������������� � ������ ���� ����������� �������
		}

		return newMatrix; // ���������� ��������� �� ��������� �������
	}

	// ����� ���������� � ���������� ������� � �����
	bool MtxOutput(matrix* mtx, ofstream& ofst)
	{
		bool check = false;

		if (!check)
		{
			if (mtx->key == SQUARE)
			{
				SquareOutput((squareMtx*)mtx, ofst);
				return true;
			} // ?��� �������� � ����� ������� ������ ������������ ��������� �������� => ����� � ����� + TRUE

			if (mtx->key == DIAGONAL)
			{
				DiagonalOutput((diagonalMtx*)mtx, ofst);
				return true;
			} // ?��� �������� � ����� ������� ������ ������������ ��������, ���������� �� ��������� ����������� ������� => ����� � ����� + TRUE

			check = true; // ?��� ������� �� ����������� �� ������ �� ����� => ��������� TRUE
		}

		if (check)
		{
			ofst << "Incorrect matrix!" << endl;
			return false;
		} // ����� �������� �� ������ � ��� ������, ����� ������� �� ����������� �� � ������ �� ��������������� �����

	}

	// ������� �����, ���������� ��� �������� �������
	void MtxClear(matrix* mtx)
	{
		if (mtx->key == SQUARE)
		{
			SquareClear((squareMtx*)mtx);
		} //������� ����� �� ������� ���������� �������

		if (mtx->key == DIAGONAL)
		{
			DiagonalClear((diagonalMtx*)mtx);
		} //������� ����� �� ������������ ������� �������

	}
} // end namesapce simple_matrix