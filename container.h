#pragma once
#ifndef container_definition
#define container_definition
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
namespace simple_matrix
{
	struct container
	{
		long size; // Переменная для контроля размера списка
		struct node* head; // Указатель на узел, являющийся "головой" списка  
	};

	void Sort(struct container* cont); // Сортировка контейнера
	void Init(struct container* cont); // Инициализация контейнера
	void Clear(struct container* cont); // Очистка контейнера и его установка в начальное состояние
	bool Input(struct container* cont, ifstream& ifst); // Ввод содержимого контейнера из указанного потока
	void Output(struct container* cont, ofstream& ofst); //Вывод содержимого контейнера в указанный поток
} // end namespace simple_matrix
//Структура, описывающая двунаправленный кольцевой список, состоящий из узлов (node)
#endif // !container_definition