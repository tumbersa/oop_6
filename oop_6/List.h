#pragma once
#ifndef LIST_H
#define LIST_H

#include "Node.h"


template<typename T>
class List 
{
	Node<T>* head;
public:
	/*
	<Конструктор>
	@param T data
	@return NULL
	*/
	List(T data);
	/*
	<Конструктор по умолчанию>
	@param List* this
	@return NULL
	*/
	List();
	/*
	<Деструктор>
	@param List* this
	@return NULL
	*/
	~List();
	class iterator {
	public:
		Node<T>* tmp;
	/*
	<Конструктор по умолчанию>
	@param List* this
	@return NULL
	*/
		iterator();
	/*
	<Конструктор>
	@param Node <T>* tmp
	@return NULL
	*/
		iterator(Node <T>* tmp);
	/*
	<Конструктор копирования>
	@param iterator* this
	@param const iterator& it - объект класса, который используется для создания копии
	@return NULL
	*/
		iterator(const iterator& it);
	/*
	<Перегруженный оператор разыменования>
	@param iterator* this 
	@return T 
	*/
		T operator*();
	/*
	<Перегруженный оператор присваивания>
	@param iterator* this
	@param const Node <T>* tmp 
	@return iterator&
	*/
		iterator& operator=(const Node <T>* tmp);
	/*
	<Перегруженный префиксный инкремент>
	@param iterator* this
	@return iterator&
	*/
		iterator& operator++();
	/*
	<Перегруженный постфиксный инкремент>
	@param iterator* this
	@return iterator&
	*/
		iterator& operator++(T);
	/*
	<Перегруженный префиксный декремент>
	@param iterator* this
	@return iterator&
	*/
		iterator& operator--();
	/*
	<Перегруженный постфиксный декремент>
	@param iterator* this
	@return iterator&
	*/
		iterator& operator--(T);
	/*
	<Перегруженный оператор равенства>
	@param iterator* this
	@param iterator i
	@return bool 
	*/
		bool operator==(iterator i);
	/*
	<Перегруженный оператор неравенства>
	@param iterator* this
	@param iterator i
	@return bool
	*/
		bool operator!=(iterator i);
	};
	/*
	<Возвращение итератора начала>
	@param List* this
	@return iterator
	*/
	iterator begin();
	/*
	<Возвращение итератора конца>
	@param List* this
	@return iterator
	*/
	iterator end();
	/*
	<Метод добавления в конец элемента типа T>
	@param List* this
	@param T data
	@return NULL
	*/
	void push_back(T data);
	/*
	<Метод добавления в конец итератора>
	@param List* this
	@param iterator it
	@return NULL
	*/
	void push_back(iterator it);
	/*
	<Метод добавления в конец последовательности итераторов>
	@param List* this
	@param iterator it1 начало последовательности
	@param iterator it2 конец последовательности
	@return NULL
	*/
	void push_back(iterator it1, iterator it2);
	/*
	<Метод добавления итератора после определённого итератора >
	@param List* this
	@param iterator it1 после этого итератора
	@param iterator it2 добавляется этот
	@return NULL
	*/
	void push(iterator it1, iterator it2);
	/*
	<Метод добавления последовательности итераторов после определённого итератора >
	@param List* this
	@param iterator it1 после этого итератора добавляется последовательность
	@param iterator it2 начало последовательности
	@param iterator it3 конец последовательности
	@return NULL
	*/
	void push(iterator it1, iterator it2, iterator it3);
	/*
	<Удаление последнего элемента>
	@param List* this
	@return NULL
	*/
	void pop_back();
	/*
	<Удаление определённого итератора>
	@param List* this
	@param iterator& it
	@return NULL
	*/
	void erase(iterator& it);
	/*
	<Удаление последовательности определённых итераторов>
	@param List* this
	@param iterator& it1 начало последовательности
	@param iterator it2 конец последовательности
	@return NULL
	*/
	void erase(iterator& it1, iterator it2);
	/*
	<Замена определённого итератора>
	@param List* this
	@param iterator& it1 заменяемый итератор
	@param iterator it2 заменяющий итератор
	@return NULL
	*/
	void replacement(iterator& it1, iterator it2);
	/*
	<Замена одной последовательности итераторов на другую определённую последовательность итераторов>
	@param List* this
	@param iterator& it1 начало последовательности заменяемых итераторов
	@param iterator it2 начало заменяющей последовательности
	@param iterator it3 конец заменяющей последовательности
	@return NULL
	*/
	void replacement(iterator& it1, iterator it2, iterator it3);
	/*
	<Поиск итератора по сходному значению>
	@param List* this
	@param iterator it1 прототип для поиска
	@return NULL
	*/
	iterator search(iterator it);
	/*
	<Поиск последовательности итераторов по сходному значению>
	@param List* this
	@param iterator it1  начало прототипа для поиска
	@param iterator it2  конец прототипа для поиска
	@return NULL
	*/
	iterator search(iterator it1, iterator it2);
};

#include "List.cpp"

#endif