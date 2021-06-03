#include "squareMtx.h"

namespace simple_matrix
{
	int SquareSum(struct squareMtx* mtx)
	{
		if (!mtx->sumMarker)
		{
			for (int row = 0; row < mtx->sideSize; row++)
			{
				for (int col = 0; col < mtx->sideSize; col++)
				{
					mtx->sum += mtx->currentMtx[row][col];
				}
			}
			mtx->sumMarker = true;
			return mtx->sum;
		}
		else
		{
			return mtx->sum;
		}
	}

	bool SquareOutput(struct squareMtx* mtx, ofstream& ofst)
	{
		ofst << "It is Square matrix. Matrix side size: " << mtx->sideSize << ". The sum of the elements of the matrix: " << mtx->sum << endl;

		switch (mtx->style)
		{
		case 0:
			ofst << "Matrix output style - \"Line by line\" " << endl;
			for (int row = 0; row < mtx->sideSize; row++)
			{
				for (int col = 0; col < mtx->sideSize; col++)
				{
					ofst << mtx->currentMtx[row][col] << "\t";
				}
				ofst << endl;
			}
			break;
		case 1:
			ofst << "Matrix output style - \"Output by columns\" " << endl;
			for (int col = 0; col < mtx->sideSize; col++)
			{
				for (int row = 0; row < mtx->sideSize; row++)
				{
					ofst << mtx->currentMtx[row][col] << "\t";
				}
				ofst << endl;
			}
			break;
		case 2:
			ofst << "Matrix output style - \"Output to a one-dimensional array\" " << endl;
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
			cout << "Square matrix output error! Incorrect output style!" << endl;
			return false;
		}

		ofst << endl;
		return true;
	}

	squareMtx* SquareInput(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = "";
		size_t pos = 0;
		int col = 0;

		squareMtx* mtx = new squareMtx;

		ifst >> content;
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				col++;
			}
		}
		if (col != 0)
		{
			cout << "Input Square matrix error! Side size must be one digit!" << endl;
			return NULL;
		}
		else
		{
			mtx->sideSize = atoi(content.c_str());
			content = "";
			col = 1;
		}

		if ((mtx->sideSize <= 1) || (mtx->sideSize > 10))
		{
			cout << "Incorrect Square matrix size!Re-enter the side size!Recommended size : 2 to 10." << endl;
			return NULL;
		} // Возвращани NULL в случае если размер стороны матрицы не попадает в диапазон
		else
		{
			mtx->currentMtx = new int* [mtx->sideSize];
			for (int row = 0; row < mtx->sideSize; row++)
			{
				mtx->currentMtx[row] = new int[mtx->sideSize];
			}

			for (int row = 0; row < mtx->sideSize; row++)
			{
				ifst >> content;
				for (int i = 0; i < content.size(); i++)
				{
					if (content[i] == ',')
					{
						col++;
					}
				}

				if (col == mtx->sideSize)
				{
					col = 0;

					while ((pos = content.find(delimiter)) != string::npos)
					{
						part = content.substr(0, pos);
						mtx->currentMtx[row][col] = atoi(part.c_str());
						string str = to_string(mtx->currentMtx[row][col]);
						if (part != str)
						{
							cout << "Square matrix cast error, number cannot be cast to int!" << endl;
							SquareClear(mtx);
							return NULL;
						}
						col++;
						content.erase(0, pos + delimiter.length());
					}

					mtx->currentMtx[row][col] = atoi(content.c_str());
					content = "";
					col = 1;
				}
				else
				{
					SquareClear(mtx);
					cout << "Input Square matrix error! The number of items does not match the side size that was received!" << endl;
					return NULL;
				}
			}
			return mtx;
		} // Выполняется, если желаемый размер попадает в диапазон
	}

	void SquareClear(struct squareMtx* mtx)
	{
		for (int row = 0; row < mtx->sideSize; row++)
		{
			delete mtx->currentMtx[row];
		}

		delete[] mtx->currentMtx;
	}
} // end namesapce simple_matrix