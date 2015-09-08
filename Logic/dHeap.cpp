#include "dHeap.h"

dHeap::dHeap(string path)
{

}
bool dHeap::instanceFlag = false;

dHeap* dHeap::_DHeap = NULL;

dHeap* dHeap::getInstance(){
	if (!instanceFlag)
	{
		_DHeap = new dHeap("XML.xml");
		instanceFlag = true;
		return _DHeap;
	}else{
		return _DHeap;
	}
}

dHeap::~dHeap()
{
	instanceFlag = false;
}
