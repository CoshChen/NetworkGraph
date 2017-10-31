/*
 * Test.h
 *
 *  Created on: Oct 31, 2017
 *      Author: Ko-Shin Chen
 */

#ifndef TEST_H_
#define TEST_H_

#include "Graph.h"
#include "Node.h"
#include <iostream>

void test_1(){
	Graph test;
	Node a = Node(1);
	Node b = Node(2);
	Node c = Node(3);

	a.setLabel(5);
	a.add_out_neighbor(b);
	a.add_out_neighbor(c);

	b.setLabel(5);
	b.add_out_neighbor(c);

	test.addVertex(&a);
	test.addVertex(&b);
	test.addVertex(&c);

	test.addEdge(&c,&a);

	cout << "---In_adjList---" << endl;
	test.exportGraph();

	cout << "---Out Degrees---" << endl;
	cout << a.getId() << ": " << a.get_out_neighbors().size() << endl;
	cout << b.getId() << ": " << b.get_out_neighbors().size() << endl;
	cout << c.getId() << ": " << c.get_out_neighbors().size() << endl;
}

#endif /* TEST_H_ */
