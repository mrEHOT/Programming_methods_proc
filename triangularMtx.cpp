#include "triangularMtx.h"
namespace simple_matrix
{
	int TriangularSum(struct triangularMtx* mtx)
	{
		if (!mtx->sumMarker)
		{
			for (int row = 0; row < mtx->numberOfElements; row++)
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

	bool TriangularOutput(struct triangularMtx* mtx, ofstream& ofst)
	{
		int count = 0;

		ofst << "It is Triangular matrix. Matrix side size: " << mtx->sideSize << ". The sum of the elements of the matrix: " << mtx->sum << endl;

		switch (mtx->style)
		{
		case 0:
			ofst << "Matrix output style - \"Line by line\" " << endl;
			for (int row = 0; row < mtx->sideSize; row++)
			{
				for (int col = 0; col < mtx->sideSize; col++)
				{
					if (col < row + 1)
					{
						ofst << mtx->currentMtx[count] << "\t";
						count++;
					}
					else
					{
						ofst << "0" << "\t";
					}
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
					if (row >= col)
					{
						ofst << mtx->currentMtx[count] << "\t";
						count++;
					}
					else
					{
						ofst << "0" << "\t";
					}
				}
				ofst << endl;
			}
			break;
		case 2:
			ofst << "Matrix output style - \"Output to a one-dimensional array\" " << endl;
			ofst << "[ ";
			for (int col = 0; col < mtx->numberOfElements; col++)
			{
				ofst << mtx->currentMtx[col] << " ";
			}
			ofst << "]" << endl;
			break;
		default:
			cout << "Triangular matrix output error! Incorrect output style!" << endl;
			return false;
		}

		ofst << endl;
		return true;
	}

	triangularMtx* TriangularInput(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = "";
		size_t pos = 0;
		int col = 0;
		int check = 0;

		triangularMtx* mtx = new triangularMtx;

		ifst >> content;
		mtx->numberOfElements = 1;
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				mtx->numberOfElements++;
			}
		}

		mtx->sideSize = (long)sqrt(mtx->numberOfElements) + 1;
		check = (1 + mtx->sideSize) * mtx->sideSize / 2;

		if (mtx->numberOfElements == check)
		{
			if ((mtx->numberOfElements <= 1) || (mtx->numberOfElements > 55))
			{
				cout << "Incorrect number of elements in triangular matrix! Re-enter items! Recommended amount: 2 to 55." << endl;
				return NULL;
			}
			else
			{
				mtx->currentMtx = new int[mtx->numberOfElements];

				while ((pos = content.find(delimiter)) != string::npos)
				{
					part = content.substr(0, pos);
					mtx->currentMtx[col] = atoi(part.c_str());
					string str = to_string(mtx->currentMtx[col]);
					if (part != str)
					{
						cout << "Trinagular matrix cast error, number cannot be cast to int!" << endl;
						TriangularClear(mtx);
						return NULL;
					}
					col++;
					content.erase(0, pos + delimiter.length());
				}

				mtx->currentMtx[col] = atoi(content.c_str());

				return mtx;
			}
		}
		else
		{
			cout << "Triangular matrix input error! The entered elements are not enough to enter the lower triangular matrix!" << endl;
			return NULL;
		}
	}

	void TriangularClear(struct triangularMtx* mtx)
	{
		delete[] mtx->currentMtx;
	}
} // end namesapce simple_matrix