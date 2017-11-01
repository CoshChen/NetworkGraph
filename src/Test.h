/*
 * Test.h
 *
 *  Created on: Oct 31, 2017
 *      Author: Ko-Shin Chen
 */

#ifndef TEST_H_
#define TEST_H_

#include "Graph.h"

void printAdjMatrix(const unordered_map<int, set<int>>& adjList){
	for(auto v : adjList){
		cout << v.first << ": ";

		for(auto nb: v.second){
			cout << nb << " ";
		}
		cout << endl;
	}
}

void test_1(){
	Graph test;
	Node a = Node(1);
	Node b = Node(2);
	Node c = Node(3);

	a.setLabel(5.0);
	a.add_out_neighbor(b);
	a.add_out_neighbor(c);

	b.setLabel(2.0);
	b.add_out_neighbor(c);

	test.addVertex(&a);
	test.addVertex(&b);
	test.addVertex(&c);

	test.addEdge(&c,&a);

	cout << "---Node Info Extraction and Setting---" << endl;
	Node* aGet = test.getNode(1);
	aGet -> setFeature("Name", "a");
	cout << "Label: " << aGet -> getLabel() << endl;
	cout << "Name: " << a.getFeature("Name") << endl;
	cout << endl;

	cout << "---In_adjList---" << endl;
	printAdjMatrix(test.exportGraph());
	cout << endl;

	cout << "---Out Degrees---" << endl;
	cout << a.getId() << ": " << a.get_out_neighbors().size() << endl;
	cout << b.getId() << ": " << b.get_out_neighbors().size() << endl;
	cout << c.getId() << ": " << c.get_out_neighbors().size() << endl;
}

#endif /* TEST_H_ */
