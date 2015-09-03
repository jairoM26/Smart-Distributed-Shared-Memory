/*
 * jSonReader.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: jairo-mm
 */

#include "jSonReader.h"

jSonReader::jSonReader(const char* json) {
	// TODO Auto-generated constructor stub
	doc.Parse(json);
}

jSonReader::~jSonReader() {
	// TODO Auto-generated destructor stub
}

int jSonReader::getcoordx()
{
	return coordx.GetInt();
}

int jSonReader::getcoordy()
{
	return coordy.GetInt();
}

string jSonReader::gethost_client()
{
	return host_client.GetString();
}
