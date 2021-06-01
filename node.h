#pragma once
#ifndef node_definition
#define node_definition
#include <string>
#include <iostream>
#include <fstream>
#include "matrix.h"
#include "container.h"
using namespace std;
namespace simple_matrix
{
	// Структура, описывающая узел списка
	struct node
	{
		matrix* mtx; // Указатель на объект типа "матрица"
		node* next; // Указатель на следующий элемент списка
		node* prev; // Указатель на предыдущий элемент списка
	};

	bool NodeAdd(struct container* cont, ifstream& ifst); // Добавление нового узла на основании данных из потока
	void NodeRemove(struct node* head, int pos); // Удаление узла с номером (pos - 1) из списка
	bool NodeOutput(struct node* head, int pos, ofstream& ofst); // Вывод узла в поток
} // end namespace simple_matrix
#endif // !node_definition