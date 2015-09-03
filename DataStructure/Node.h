/*
 * Node.h
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#ifndef DATASTRUCTURE_NODE_H_
#define DATASTRUCTURE_NODE_H_


template<class T>

class Node {
public:
	Node(T pdata);
	virtual ~Node();
	int getId();
	void setId(int pid);
	T getData();
	void setData(T pdata);
	Node<T>* getNext();
	void setNext(Node<T>* pnext);

private:
	Node<T>* _next;
	T _data;
	int _id;
};

template<class T>
Node<T>::Node(T pdata)
{
	_next = 0;
	_data = pdata;
	_id = 0;
}

template<class T>
Node<T>::~Node()
{
	delete(_next);
}

template<class T>
void Node<T>::setId(int pid)
{
	_id = pid;
}

template<class T>
int Node<T>::getId()
{
	return _id;
}

template<class T>
void Node<T>::setData(T pdata)
{
	_data = pdata;
}

template<class T>
T Node<T>::getData()
{
	return _data;
}

template<class T>
void Node<T>::setNext(Node<T>* pnext)
{
	_next = pnext;
}

template<class T>
Node<T>* Node<T>::getNext()
{
	return _next;
}


#endif /* DATASTRUCTURE_NODE_H_ */
