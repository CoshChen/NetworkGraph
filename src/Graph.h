/*
 * Graph.h
 *
 *  Created on: Oct 31, 2017
 *      Author: Ko-Shin Chen
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "Node.h"

#include <set>
#include <unordered_map>

class Graph {
private:
	set<int> vertices;
	unordered_map<int, set<int> > in_adjList;
	unordered_map<int, Node*> id_dict;

public:
	Graph(){}

	void addVertex(Node* vertex);
	void addEdge(Node* from, Node* to);

	set<int> getVertices(){return vertices;}
	unordered_map<int, set<int> > get_in_adjList(){return in_adjList;}

	void exportGraph();
};

#endif /* GRAPH_H_ */
