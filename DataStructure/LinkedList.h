/*
 * LinkedList.h
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#ifndef DATASTRUCTURE_LINKEDLIST_H_
#define DATASTRUCTURE_LINKEDLIST_H_

#include <iostream>

#include "Node.h"

template<class T>

class LinkedList
{
public:
	LinkedList();
	virtual ~LinkedList();
	bool deleteData(T to_delete);
	void insertData(T pdata);
	T getDatabyIndex(int index);
	Node<T>* getNodebyIndex(int index);
	int getLen();
	void showList();
	void deleteAll();
	Node<T>* getHead();

private:
	int _len;
	Node<T>* _head;
	Node<T>* _tail;
};


template<class T>
LinkedList<T>::LinkedList()
{
	_head = 0;
	_tail = 0;
	_len = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	free(_head);
	free(_tail);
}

template<class T>
bool LinkedList<T>::deleteData(T to_delete)
{
	Node<T>* tmp1, *tmp2;
	tmp1 = tmp2 = 0;
	if(_head->getData() == to_delete)
	{
		tmp1 = _head;
		_head = _head->getNext();
		free(tmp1);
		_len--;
		return true;
	}
	else
	{
		tmp1 = _head;
		while(tmp1 != NULL)
		{
			//(tmp1->obtenerSiguiente()->obtenerSiguiente() == NULL) && (tmp1->obtenerSiguiente()->obtenerDato() == pdato_borrar)
			if((tmp1->getNext() == _tail) && (tmp1->getNext()->getData() == to_delete))
			{
				std::cout << "ultimo" << std::endl;
				_tail = tmp1;
				tmp1 = tmp1->getNext();
				free(tmp1);
				_len--;
				return true;
			}
			else if (tmp1->getNext()->getData() == to_delete)
			{
				std::cout << "no ultimo" << std::endl;
				tmp2 = tmp1->getNext();
				tmp1->setNext(tmp1->getNext()->getNext());
				free(tmp2);
				_len--;
				return true;
			}
			tmp1 = tmp1->getNext();
		}
	}
	return false;
}

template<class T>
void LinkedList<T>::insertData(T pdata)
{
	Node<T>* nodo_to_insert = new Node<T>(pdata);
	if(_len == 0)
	{
		_head = nodo_to_insert;
		_tail = _head;
	}
	else
	{
		_tail->setNext(nodo_to_insert);
		_tail = nodo_to_insert;
	}
	nodo_to_insert->setId(_len);
	_len++;
}

template<class T>
void LinkedList<T>::showList()
{
	std::cout<< "mostrando lista" << std::endl;
	Node<T>* nodo_tmp = _head;
	while(nodo_tmp != _tail)
	{
		//std::cout << "Dato " << nodo_tmp->obtenerDato() << " id " << nodo_tmp->obtenerId() << std::endl;
		std::cout << nodo_tmp->getData() << std::endl;
		nodo_tmp = nodo_tmp->getNext();
	}
	//std::cout << "Dato " << nodo_tmp->obtenerDato() << " id " << nodo_tmp->obtenerId() << std::endl;
	std::cout << nodo_tmp->getData() << std::endl;
}

template<class T>
int LinkedList<T>::getLen()
{
	return _len;
}

template<class T>
T LinkedList<T>::getDatabyIndex(int index)
{
	Node<T>* tmp = _head;
	if(index < _len)
	{	for(int i = 0; i < index; i++)
		{
			tmp = tmp->getNext();
		}
		return tmp->getData();
	}
}

template<class T>
Node<T>* LinkedList<T>::getNodebyIndex(int index)
{
	Node<T>* tmp = _head;
	if(index < _len)
	{	for(int i = 0; i < index; i++)
		{
			tmp = tmp->getNext();
		}
		return tmp;
	}
}

template<class T>
Node<T>* LinkedList<T>::getHead()
{
	return _head;
}

template<class T>
void LinkedList<T>::deleteAll()
{
	Node<T>* tmp_node;
	for(int i = 0; i < _len; i++)
	{
		tmp_node = this->getNodebyIndex(i);
		this->deleteData(tmp_node->getData());
	}
	free(tmp_node);
}

#endif /* DATASTRUCTURE_LINKEDLIST_H_ */
