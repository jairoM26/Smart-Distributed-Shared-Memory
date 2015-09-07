/*
 * dHeap.h
 *
 *  Created on: 7 de set. de 2015
 *      Author: isaac
 */

#ifndef LOGIC_DHEAP_H_
#define LOGIC_DHEAP_H_

using namespace std;
class dHeap {
private:
	dHeap(){

	}
	static bool instanceFlag;
	static dHeap *_DHeap;
public:
	static dHeap* getInstance();
	~dHeap(){
		instanceFlag = false;
	}
};
#endif /* LOGIC_DHEAP_H_ */


bool dHeap::instanceFlag = false;
dHeap::_DHeap = NULL;
dHeap* dHeap::getInstance(){
	if (!instanceFlag)
	{
		_DHeap = new dHeap();
		instanceFlag = true;
		return _DHeap;
	}else{
		return _DHeap;
	}
}

