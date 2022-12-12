#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
template<typename T> class Node
{
public:
	T data;
	Node* next;
	Node* prev;
	/*
	<����������� �� ���������>
	@param Node* this
	@return NULL
	*/
	Node();
	/*
	<�����������>
	@param T data  
	@return NULL
	*/
	Node(T data);
	/*
	<����������>
	@param Node* this
	@return NULL
	*/
	~Node();
};
#include "Node.cpp"

#endif