#include "matrix.h"
namespace simple_matrix
{
	// ���������� ����� ���������� ������� �� ��������� ������ �� ������
	matrix* MtxInput(ifstream& ifst)
	{
		matrix* newMatrix;
		int currKey;
		ifst >> currKey;

		switch (currKey)
		{
		case 0:
			newMatrix = (matrix*)SquareInput(ifst);
			if (newMatrix != NULL)
			{
				newMatrix->key = SQUARE;
				break;
			}
			else
			{
				return NULL;
			}
		case 1:
			newMatrix = (matrix*)DiagonalInput(ifst);
			if (newMatrix != NULL)
			{
				newMatrix->key = DIAGONAL;
				break;
			}
			else
			{
				return NULL;
			}
		case 2:
			newMatrix = (matrix*)TriangularInput(ifst);
			if (newMatrix != NULL)
			{
				newMatrix->key = TRIANGULAR;
				break;
			}
			else
			{
				return NULL;
			}
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
			} // ���� ��������� � ����� ������� ������� ������������ ��������� �������� => ����� � ����� + TRUE

			if (mtx->key == DIAGONAL)
			{
				DiagonalOutput((diagonalMtx*)mtx, ofst);
				return true;
			} // ���� ��������� � ����� ������� ������� ������������ ��������, ���������� �� ��������� ����������� ������� => ����� � ����� + TRUE

			if (mtx->key == TRIANGULAR)
			{
				TriangularOutput((triangularMtx*)mtx, ofst);
				return true;
			} // ���� ��������� � ����� ������� �������  ������ ���������� ��������, ���������� �� ��������� ����������� ������� => ����� � ����� + TRUE

			check = true; // ���� ������� �� ����������� �� ������ �� ����� => ���������� TRUE
		}

		if (check)
		{
			ofst << "Incorrect matrix!" << endl;
			return false;
		} // ����� ��������� �� ������ � ��� ������, ����� ������� �� ����������� �� � ������ �� ��������������� �����

	}

	// ������� ������, ���������� ��� �������� �������
	void MtxClear(matrix* mtx)
	{
		if (mtx->key == SQUARE)
		{
			SquareClear((squareMtx*)mtx);
		} //������� ������ ��� ������� ���������� �������

		if (mtx->key == DIAGONAL)
		{
			DiagonalClear((diagonalMtx*)mtx);
		} //������� ������ ��� ������������ ������� �������

		if (mtx->key == TRIANGULAR)
		{
			TriangularClear((triangularMtx*)mtx);
		} //������� ������ ��� ������������ ������� ������

	}
} // end namesapce simple_matrix