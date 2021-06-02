#include "pch.h"
#include "CppUnitTest.h"

#include "..\container.h"
#include "..\container.cpp"
#include "..\matrix.h"
#include "..\matrix.cpp"
#include "..\node.h"
#include "..\node.cpp"
#include "..\squareMtx.h"
#include "..\squareMtx.cpp"
#include "..\diagonalMtx.h"
#include "..\diagonalMtx.cpp"
#include "..\triangularMtx.h"
#include "..\triangularMtx.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace simple_matrix;

namespace UnitTestProc
{
	TEST_CLASS(UnitTestProc)
	{
	public:
		string Read(const char* filename)
		{

			ifstream ifst(filename);
			string content = "";
			if (ifst.is_open())
			{
				while (!ifst.eof())
				{
					string tmp;
					ifst >> tmp;
					content += tmp;
				}
				ifst.close();
			}
			return content;
		}

		TEST_METHOD(TestOut)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\out_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			container* cont = new container;
			Init(cont);
			Input(cont, ifst);
			Output(cont, ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\out_cheсk.txt");

			Assert::AreEqual(s1, s2);

			Clear(cont);
			delete cont;
		}

		TEST_METHOD(TestInitContainer)
		{
			container* cont = new container;
			Init(cont);

			Assert::IsTrue((cont->head == NULL) && (cont->size == 0));

			Clear(cont);
			delete cont;
		}

		TEST_METHOD(TestSortContainer)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\sortcontainer_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			container* cont = new container;
			Init(cont);
			Input(cont, ifst);
			Sort(cont);
			Output(cont, ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\sortcontainer_cheсk.txt");

			Assert::AreEqual(s1, s2);

			Clear(cont);
			delete cont;
		}

		TEST_METHOD(TestClearContainer)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\clearcontainer_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			container* cont = new container;
			Init(cont);
			Input(cont, ifst);
			Sort(cont);
			Output(cont, ofst);
			Clear(cont);
			Output(cont, ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\clearcontainer_check.txt");

			Assert::AreEqual(s1, s2);

			delete cont;
		}

		TEST_METHOD(TestFilteredOutput)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\filteredoutput_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			container* cont = new container;
			Init(cont);
			Input(cont, ifst);
			FilteredOutput(cont, ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\filteredoutput_cheсk.txt");

			Assert::AreEqual(s1, s2);

			Clear(cont);
			delete cont;
		}

		TEST_METHOD(TestSumElements)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\sum_input.txt");

			matrix* mtx = MtxInput(ifst);
			int sum = MtxSum(mtx);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\sum_check.txt");

			Assert::IsTrue(sum == atoi(s1.c_str()));
		}

		TEST_METHOD(TestMatrixCompare)
		{
			ifstream ifst1("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\matrixcompare_first.txt");
			ifstream ifst2("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\matrixcompare_second.txt");

			matrix* mtx1 = MtxInput(ifst1);
			int sum1 = MtxSum(mtx1);

			matrix* mtx2 = MtxInput(ifst2);
			int sum2 = MtxSum(mtx2);

			Assert::IsTrue(sum1 > sum2);
		}

		TEST_METHOD(TestNodeSwap)
		{
			int pos1, pos2;
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\nodeswap_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			ifst >> pos1;
			ifst >> pos2;
			container* cont = new container;
			Init(cont);
			Input(cont, ifst);

			if (pos1 < cont->size && pos2 < cont->size)
			{
				NodeSwap(cont->head, pos1, pos2);
			}

			Output(cont, ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\nodeswap_cheсk.txt");

			Assert::AreEqual(s1, s2);

			Clear(cont);
			delete cont;
		}

		TEST_METHOD(TestInputSquare)
		{
			bool check = false;

			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\squareinput_input.txt");

			squareMtx* newMatrix = SquareInput(ifst);

			ifstream checkst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\squareinput_check.txt");

			for (int row = 0; row < newMatrix->sideSize; row++)
			{
				if (check)
				{
					break;
				}

				for (int col = 0; col < newMatrix->sideSize; col++)
				{
					int currNumber;
					checkst >> currNumber;
					if (newMatrix->currentMtx[row][col] != currNumber)
					{
						check = true;
						break;
					}
				}
			}
			Assert::IsFalse(check);
		}

		TEST_METHOD(TestInputDiagonal)
		{
			bool check = false;

			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\diagonalinput_input.txt");

			diagonalMtx* newMatrix = DiagonalInput(ifst);

			ifstream checkst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\diagonalinput_check.txt");

			for (int row = 0; row < newMatrix->sideSize; row++)
			{
				int currNumber;
				checkst >> currNumber;
				if (newMatrix->currentMtx[row] != currNumber)
				{
					check = true;
					break;
				}
			}
			Assert::IsFalse(check);
		}

		TEST_METHOD(TestInputTriangular)
		{
			bool check = false;

			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\triangularinput_input.txt");

			triangularMtx* newMatrix = TriangularInput(ifst);

			ifstream checkst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_proc\\UnitTest_Proc\\Tests\\triangularinput_check.txt");

			for (int row = 0; row < newMatrix->sideSize; row++)
			{
				int currNumber;
				checkst >> currNumber;
				if (newMatrix->currentMtx[row] != currNumber)
				{
					check = true;
					break;
				}
			}
			Assert::IsFalse(check);
		}
	};
}