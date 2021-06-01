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
		long size; // ѕеременна€ дл€ контрол€ размера списка
		struct node* head; // ”казатель на узел, €вл€ющийс€ "головой" списка  
	};

	void FilteredOutput(struct container* cont, ofstream& ofst); //¬ыборочный вывод в указанный поток.
	void Init(struct container* cont); // »нициализаци€ контейнера
	void Clear(struct container* cont); // ќчистка контейнера и его установка в начальное состо€ние
	void Input(struct container* cont, ifstream& ifst); // ¬вод содержимого контейнера из указанного потока
	void Output(struct container* cont, ofstream& ofst); //¬ывод содержимого контейнера в указанный поток
} // end namespace simple_matrix
//—труктура, описывающа€ двунаправленный кольцевой список, состо€щий из узлов (node)
#endif // !container_definition