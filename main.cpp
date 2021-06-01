#include <iostream>
#include <fstream>
#include "container.h"
using namespace std;
namespace simple_matrix
{
	// Сигнатуры требуемых внешних функций
	void Sort(struct container* cont);
	void FilteredOutput(struct container* cont, ofstream& ofst);
	void Init(struct container* cont);
	void Clear(struct container* cont);
	bool Input(struct container* cont, ifstream& ifst);
	void Output(struct container* cont, ofstream& ofst);
}
using namespace simple_matrix;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line!" << endl;
		cout << "Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	if (!ifst.is_open())
	{
		cout << "Input file is not open!" << endl;
		return 1;
	} // Проверка открытия файла Input

	ofstream ofst(argv[2]);
	if (!ofst.is_open())
	{
		cout << "Input file is not open!" << endl;
		return 1;
	} // Проверка открытия файла Output
	cout << "Start" << endl;

	container* cont = new container; // Создаем экземпляр контейнера
	Init(cont); // Инициализируем контейнер

	if (Input(cont, ifst))
	{
		Sort(cont);
		cout << "Filled container. " << endl;
		Output(cont, ofst); // Вывод заполненного контейнера

		cout << endl << "Output of square matrix." << endl;
		FilteredOutput(cont, ofst); // Процедура, реализующая выборочный вывод информации (только о первом виде объетов - стандартные квадратные матрицы)

		Clear(cont); //Очистка контейнера
		cout << "Empty container. " << endl;
		Output(cont, ofst); // Вывод пустого контейнера

		cout << "Stop" << endl;

		return 0;
	} // Если заполнение контейнера выполнено корректно, то программа выполняется до конца
	else
	{
		Clear(cont); //Очистка контейнера
		cout << "Input data error! Container filling stopped!" << endl;
		return 1;
	} // Экстренное завершение программы, ошибка при заполнении контейнера
}