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
	<�����������>
	@param T data
	@return NULL
	*/
	List(T data);
	/*
	<����������� �� ���������>
	@param List* this
	@return NULL
	*/
	List();
	/*
	<����������>
	@param List* this
	@return NULL
	*/
	~List();
	class iterator {
	public:
		Node<T>* tmp;
	/*
	<����������� �� ���������>
	@param List* this
	@return NULL
	*/
		iterator();
	/*
	<�����������>
	@param Node <T>* tmp
	@return NULL
	*/
		iterator(Node <T>* tmp);
	/*
	<����������� �����������>
	@param iterator* this
	@param const iterator& it - ������ ������, ������� ������������ ��� �������� �����
	@return NULL
	*/
		iterator(const iterator& it);
	/*
	<������������� �������� �������������>
	@param iterator* this 
	@return T 
	*/
		T operator*();
	/*
	<������������� �������� ������������>
	@param iterator* this
	@param const Node <T>* tmp 
	@return iterator&
	*/
		iterator& operator=(const Node <T>* tmp);
	/*
	<������������� ���������� ���������>
	@param iterator* this
	@return iterator&
	*/
		iterator& operator++();
	/*
	<������������� ����������� ���������>
	@param iterator* this
	@return iterator&
	*/
		iterator& operator++(T);
	/*
	<������������� ���������� ���������>
	@param iterator* this
	@return iterator&
	*/
		iterator& operator--();
	/*
	<������������� ����������� ���������>
	@param iterator* this
	@return iterator&
	*/
		iterator& operator--(T);
	/*
	<������������� �������� ���������>
	@param iterator* this
	@param iterator i
	@return bool 
	*/
		bool operator==(iterator i);
	/*
	<������������� �������� �����������>
	@param iterator* this
	@param iterator i
	@return bool
	*/
		bool operator!=(iterator i);
	};
	/*
	<����������� ��������� ������>
	@param List* this
	@return iterator
	*/
	iterator begin();
	/*
	<����������� ��������� �����>
	@param List* this
	@return iterator
	*/
	iterator end();
	/*
	<����� ���������� � ����� �������� ���� T>
	@param List* this
	@param T data
	@return NULL
	*/
	void push_back(T data);
	/*
	<����� ���������� � ����� ���������>
	@param List* this
	@param iterator it
	@return NULL
	*/
	void push_back(iterator it);
	/*
	<����� ���������� � ����� ������������������ ����������>
	@param List* this
	@param iterator it1 ������ ������������������
	@param iterator it2 ����� ������������������
	@return NULL
	*/
	void push_back(iterator it1, iterator it2);
	/*
	<����� ���������� ��������� ����� ������������ ��������� >
	@param List* this
	@param iterator it1 ����� ����� ���������
	@param iterator it2 ����������� ����
	@return NULL
	*/
	void push(iterator it1, iterator it2);
	/*
	<����� ���������� ������������������ ���������� ����� ������������ ��������� >
	@param List* this
	@param iterator it1 ����� ����� ��������� ����������� ������������������
	@param iterator it2 ������ ������������������
	@param iterator it3 ����� ������������������
	@return NULL
	*/
	void push(iterator it1, iterator it2, iterator it3);
	/*
	<�������� ���������� ��������>
	@param List* this
	@return NULL
	*/
	void pop_back();
	/*
	<�������� ������������ ���������>
	@param List* this
	@param iterator& it
	@return NULL
	*/
	void erase(iterator& it);
	/*
	<�������� ������������������ ����������� ����������>
	@param List* this
	@param iterator& it1 ������ ������������������
	@param iterator it2 ����� ������������������
	@return NULL
	*/
	void erase(iterator& it1, iterator it2);
	/*
	<������ ������������ ���������>
	@param List* this
	@param iterator& it1 ���������� ��������
	@param iterator it2 ���������� ��������
	@return NULL
	*/
	void replacement(iterator& it1, iterator it2);
	/*
	<������ ����� ������������������ ���������� �� ������ ����������� ������������������ ����������>
	@param List* this
	@param iterator& it1 ������ ������������������ ���������� ����������
	@param iterator it2 ������ ���������� ������������������
	@param iterator it3 ����� ���������� ������������������
	@return NULL
	*/
	void replacement(iterator& it1, iterator it2, iterator it3);
	/*
	<����� ��������� �� �������� ��������>
	@param List* this
	@param iterator it1 �������� ��� ������
	@return NULL
	*/
	iterator search(iterator it);
	/*
	<����� ������������������ ���������� �� �������� ��������>
	@param List* this
	@param iterator it1  ������ ��������� ��� ������
	@param iterator it2  ����� ��������� ��� ������
	@return NULL
	*/
	iterator search(iterator it1, iterator it2);
};

#include "List.cpp"

#endif