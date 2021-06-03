#include "diagonalMtx.h"

namespace simple_matrix
{
	int DiagonalSum(struct diagonalMtx* mtx)
	{
		if (!mtx->sumMarker)
		{
			for (int row = 0; row < mtx->sideSize; row++)
			{
				mtx->sum += mtx->currentMtx[row];
			}
			mtx->sumMarker = true;
			return mtx->sum;
		}
		else
		{
			return mtx->sum;
		}
	}

	bool DiagonalOutput(struct diagonalMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Diagonal matrix. Matrix side size: " << mtx->sideSize << ". The sum of the elements of the matrix: " << mtx->sum << endl;

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
			ofst << "]" << endl;
			break;
		default:
			cout << "Diagonal matrix output error! Incorrect output style!" << endl;
			return false;
		}

		ofst << endl;
		return true;
	}

	diagonalMtx* DiagonalInput(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = "";
		size_t pos = 0;
		int col = 0;

		diagonalMtx* mtx = new diagonalMtx;

		ifst >> content;
		mtx->sideSize = 1;
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				mtx->sideSize++;
			}
		}

		if ((mtx->sideSize <= 1) || (mtx->sideSize > 10))
		{
			cout << "Incorrect diagonal matrix size! Re-enter items! Recommended amount: 2 to 10." << endl;
			return NULL;
		} // ¬озвращани NULL в случае если размер стороны матрицы не попадает в диапазон
		else
		{
			mtx->currentMtx = new int[mtx->sideSize];

			while ((pos = content.find(delimiter)) != string::npos)
			{
				part = content.substr(0, pos);
				mtx->currentMtx[col] = atoi(part.c_str());

				string str = to_string(mtx->currentMtx[col]);
				if (part != str)
				{
					cout << "Diagonal matrix cast error, number cannot be cast to int!" << endl;
					DiagonalClear(mtx);
					return NULL;
				}
				col++;
				content.erase(0, pos + delimiter.length());
			}

			mtx->currentMtx[col] = atoi(content.c_str());

			return mtx;
		} // ќсуществл€ем корректное заполнение матрицы

	}

	void DiagonalClear(struct diagonalMtx* mtx)
	{
		delete[] mtx->currentMtx;
	}
} // end namesapce simple_matrix