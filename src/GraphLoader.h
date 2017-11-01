/*
 * GraphLoader.h
 *
 *  Created on: Oct 31, 2017
 *      Author: Ko-Shin Chen
 */

#ifndef SRC_GRAPHLOADER_H_
#define SRC_GRAPHLOADER_H_

#include"Graph.h"

#include <fstream>

using namespace std;

class GraphLoader {
public:
	GraphLoader(){};

	Graph readFile(string path);
};

#endif /* SRC_GRAPHLOADER_H_ */
