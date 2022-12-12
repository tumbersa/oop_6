#ifndef _LIST_CPP_
#define _LIST_CPP_

#include "List.h"
template<typename T>
List<T>::List() {
	head = NULL;
}

template<typename T>
List<T>::List(T data) {
	head = new Node <T>(data);
}

template<typename T>
List<T>::~List() {
	if (head)
		while (head->next) {
			Node<T>* rubbish = head;
			head = head->next;
			delete rubbish;
		}
	delete head;
}
template<typename T>
List<T>::iterator::iterator() {
	tmp = new Node<T>();
}

template<typename T>
List<T>::iterator::iterator(Node <T>* tmp) {
	this->tmp = tmp;
}

template<typename T>
List<T>::iterator::iterator(const iterator& it) {
	this->tmp = it.tmp;
}

template<typename T>
T List<T>::iterator::operator*() {
	if (tmp)
		return tmp->data;
}

template<typename T>
List<T>::template iterator& List<T>::iterator:: operator=(const Node <T>* tmp) {
	if (&tmp != this) this->tmp = tmp;
	return *this;
}

template<typename T>
List<T>::template iterator&  List<T>::iterator::operator++() {
	if (tmp)
		tmp = tmp->next;
	return *this;
}

template<typename T>
List<T>::template iterator& List<T>::iterator::operator++(T) {
	iterator tmpi = *this;
	++* this;
	return tmpi;
}

template<typename T>
List<T>::template iterator& List<T>::iterator::operator--() {
	if (tmp)
		tmp = tmp->prev;
	return *this;
}


template<typename T>
List<T>::template iterator& List<T>::iterator::operator--(T) {
	iterator tmpi = *this;
	--* this;
	return tmpi;
}

template<typename T>
bool List<T>::iterator:: operator==(iterator i) {
	return (tmp == i.tmp);
}


template<typename T>
bool List<T>::iterator::operator!=(iterator i) {
	return (tmp != i.tmp);
}

template<typename T>
List<T>::template iterator List<T>::begin() {
	return iterator(head);
}

template<typename T>
List<T>::template iterator List<T>::end() {
	return iterator(NULL);
}

template<typename T>
void List<T>::push_back(iterator it) {
	Node<T>* newNode = new Node<T>(it.tmp->data);
	if (!head) {
		head = newNode;
	}
	else {
		Node<T>* temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
	}
}

template<typename T>
void List<T>::push_back(iterator it1, iterator it2) {
	while (it1.tmp != it2.tmp) {
		push_back(it1);
		it1.tmp = it1.tmp->next;
	}
	if (it2.tmp) push_back(it2);
}

template<typename T>
void List<T>::push(iterator it1, iterator it2) {
	Node<T>* newNode = new Node<T>(it2.tmp->data);
	if (!it1.tmp)
		head = newNode;
	else {
		if (it1.tmp->next) it1.tmp->next->prev = newNode;
		newNode->next = it1.tmp->next;
		it1.tmp->next = newNode;
		newNode->prev = it1.tmp;
	}
}

template<typename T>
void List<T>::push(iterator it1, iterator it2, iterator it3) {
	while (it2 != it3) {
		push(it1, it2);
		it1++;
		it2++;
		if (!it1.tmp)it1.tmp = head;
	}
	if (it3.tmp) {
		push(it1, it2);
		it1++;
		it2++;
		if (!it1.tmp)it1.tmp = head;
	}
}

template<typename T>
void List<T>::pop_back() {
	if (!head) return;
	Node<T>* temp = head;
	while (temp->next) temp = temp->next;
	if (temp->prev) temp->prev->next = nullptr;
	delete temp;
}

template<typename T>
void List<T>::erase(iterator& it) {
	Node<T>* temp = it.tmp;
	if (!temp->prev) head = temp->next;
	it.tmp = it.tmp->next;
	if (temp->prev) temp->prev->next = temp->next;
	if (temp->next) temp->next->prev = temp->prev;
	delete temp;
}

template<typename T>
void List<T>::erase(iterator& it1, iterator it2) {
	while (it1.tmp != it2.tmp)
		erase(it1);
	if (it2.tmp) erase(it1);
}

template<typename T>
void List<T>::replacement(iterator& it1, iterator it2) {
	Node<T>* newNode = new Node<T>(it2.tmp->data);
	if (it1.tmp->prev) it1.tmp->prev->next = newNode;
	if (it1.tmp->next) it1.tmp->next->prev = newNode;
	newNode->next = it1.tmp->next;
	newNode->prev = it1.tmp->prev;
	if (head == it1.tmp) {
		it1.tmp = newNode;
		head = newNode;
	}
	else it1.tmp = newNode;
}

template<typename T>
void List<T>::replacement(iterator& it1, iterator it2, iterator it3) {
	Node<T>* temp = it1.tmp, * newNode = NULL;
	int f = 0, f1 = 1;
	while (it2.tmp != it3.tmp) {
		if (f1) replacement(it1, it2);
		else {
			push(it1, it2);
			if (it1.tmp->next)it1++;
		}
		f++;
		if (f == 1) Node<T>* newNode = it1.tmp;
		if (it1.tmp->next)
			it1++;
		else f1 = 0;
		it2++;
	}
	if (it3.tmp) {
		if (f1) replacement(it1, it2);
		else {
			push(it1, it2);
			if (it1.tmp->next)it1++;
		}
		if (it1.tmp->next)
			it1++;
		else f1 = 0;
		it2++;
	}
	if (head == temp) {
		it1.tmp = newNode;
		head = newNode;
	}
	else it1.tmp = newNode;
}

template<typename T>
List<T>::template iterator List<T>::search(iterator it) {
	iterator it3; it3.tmp = NULL;
	Node<T>* temp = head;
	while (temp) {
		if (it.tmp->data == temp->data) it3.tmp = temp;
		temp = temp->next;
	}
	return it3;
}

template<typename T>
List<T>::template iterator List<T>::search(iterator it1, iterator it2) {
	iterator it3 = search(it1);
	if (!it3.tmp) return it3;
	bool f = true;
	iterator it = it3;
	while (it1 != it2 && f) {
		if (it.tmp && it1.tmp) {
			if (it.tmp->data != it1.tmp->data) f = false;
		}
		else f = false;
		it1++;
		it++;
	}
	if (it.tmp && it1.tmp)
		if (it.tmp->data != it1.tmp->data) f = false;
	if (!f) it3.tmp = NULL;
	return it3;
}



template<typename T>
void List<T>::push_back(T data) {
	Node<T>* newNode = new Node<T>(data);
	if (!head) {
		head = newNode;
	}
	else {
		Node<T>* temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
	}
}
#endif