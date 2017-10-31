/*
 * Graph.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: Ko-Shin Chen
 */

#include "Graph.h"

//using namespace std;

// member functions
void Graph::addVertex(Node* vertex){
	if(id_dict.count(vertex -> getId()) != 0){
		cout << "Vertex exists!" << endl;
		return;
	}

	int id = vertex -> getId();
	set<int> out_neighbors = vertex -> get_out_neighbors();

	vertices.insert(id);
	id_dict[id] = vertex;

	for(auto to : out_neighbors){
		if(in_adjList.count(to) == 0){
			set<int> neighbor;
			in_adjList[to] = neighbor;
		}
		in_adjList[to].insert(id);
	}
}

void Graph::addEdge(Node* from, Node* to){
	int from_id = from -> getId();
	int to_id = to -> getId();

	if(id_dict.count(from_id) == 0){
		vertices.insert(from_id);
		id_dict[from_id] = from;
	}
	if(id_dict.count(to_id) == 0){
		vertices.insert(to_id);
		id_dict[to_id] = to;
	}

	if(in_adjList.count(to_id) == 0){
		set<int> neighbor;
		in_adjList[to_id] = neighbor;
	}

	in_adjList[to_id].insert(from_id);
	from -> add_out_neighbor(*to);
}

void Graph::exportGraph(){
	for(auto pair : in_adjList){
		cout << pair.first << ": ";

		for(auto nb : pair.second){
			cout << nb << ", ";
		}
		cout << endl;
	}
}
