/*
 * dHeap.h
 *
 *  Created on: 7 de set. de 2015
 *      Author: isaac
 */

#ifndef LOGIC_DHEAP_H_
#define LOGIC_DHEAP_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;
class dHeap {
private:
	dHeap(string pPath);
	static bool instanceFlag;
	static dHeap* _DHeap;
public:
	static dHeap* getInstance();
	int dMalloc(int, string);
	virtual ~dHeap();
};
#endif /* LOGIC_DHEAP_H_ */




