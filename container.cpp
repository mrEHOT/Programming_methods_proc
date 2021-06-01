#include "container.h"
#include "node.h"

namespace simple_matrix
{
	// Сортировка контейнера
	void Sort(struct container* cont)
	{
		NodeCompare(cont->head, cont->size); // Вызов функции сравнения узлов
	}

	// Инициализация контейнера
	void Init(struct container* cont)
	{
		cont->size = 0; // При инициализации контейнера его размер равен нулю
		cont->head = NULL; // При инициализации контейнер пуст => "головы" нет
	}

	// Очистка контейнера и его установка в начальное состояние
	void Clear(struct container* cont)
	{
		if (cont->head == NULL)
		{
			return;
		} // При пустом контейнере очистка не требуется
		else
		{
			for (int i = cont->size - 1; i >= 0; i--)
			{
				NodeRemove(cont->head, i); // Выполняем удаление каждого узла списка (каждого элемента контейнера)
			}
			cont->head = NULL; // После полной очистки контейнера указатель устанавливается на NULL
		}

		cont->size = 0; // После очистки в контейнере не останется элементов
	}

	// Ввод содержимого контейнера из указанного потока
	bool Input(struct container* cont, ifstream& ifst)
	{
		while (!ifst.eof())
		{
			if (NodeAdd(cont, ifst))
			{
				(cont->size)++; // Увеличиваем количество элементов в контейнере
			} // Если операция добавления в список выполнена корректно => возврашается TRUE и увеличивается размер контейнера
			else
			{
				return false;
			} // Операция добавления в список не выполнена
		} // Пока не достикнут конец потока

		return true;
	}

	//Вывод содержимого контейнера в указанный поток
	void Output(struct container* cont, ofstream& ofst)
	{
		ofst << "Container contains " << cont->size << " elements." << endl; // Выводим общее количество элементов в контейнере
		for (int i = 0; i < cont->size; i++)
		{
			if (!NodeOutput(cont->head, i, ofst))
			{
				cout << "Node is broken!" << endl; // Вывод сообщения о невозможности вывода элемента
			} // Если элементы вывелся корректно => вернется TRUE => !TRUE = FALSE => сообщение об ошибке не появится на экране
		} // Поочередный вывод элементов контейнера в поток
	}

	//Выборочный вывод в указанный поток.
	void FilteredOutput(struct container* cont, ofstream& ofst)
	{
		ofst << endl << "Filtered Output - Square matrix:" << endl << endl;
		for (int i = 0; i < cont->size; i++)
		{
			FilteredNodeOutput(cont->head, i, ofst);
		} // Поочередный вывод стандартных квадратных матриц из контейнера в поток
	}
} //end namespace simple_matrix