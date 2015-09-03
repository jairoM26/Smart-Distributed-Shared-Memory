/*
 * jSonReader.h
 *
 *  Created on: Aug 29, 2015
 *      Author: jairo-mm
 */

#ifndef DATAACCESS_JSONREADER_H_
#define DATAACCESS_JSONREADER_H_

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "string.h"
#include <iostream>

using namespace rapidjson;
using namespace std;

class jSonReader {
public:
	jSonReader(const char* pjson);
	virtual ~jSonReader();
	Document doc;
	Value& host_client = doc["Ip"];
	Value& coordx = doc["coordx"];
	Value& coordy = doc["coordy"];
	int getcoordx();
	int getcoordy();
	string gethost_client();


};

#endif /* DATAACCESS_JSONREADER_H_ */
