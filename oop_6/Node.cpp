#ifndef _NODE_CPP_
#define _NODE_CPP_


#include "Node.h"
template<typename T>
Node<T>::Node() {
	data = NULL;
	next = prev = nullptr;
}
template<typename T>
Node<T>::Node(T data) {
	this->data = data;
	next = prev = nullptr;
}
template<typename T>
Node<T>::~Node() {
	next = prev = nullptr;
	delete next;
	delete prev;
}

#endif