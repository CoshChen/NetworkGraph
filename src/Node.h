/*
 * Node.h
 *
 *  Created on: Oct 31, 2017
 *      Author: Ko-Shin Chen
 */

#ifndef NODE_H_
#define NODE_H_

#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
private:
	int id;
	int label = 0;
	set<int> out_neighbors;
	unordered_map<string, string> features;
	vector<string> featureFields;

public:
	Node(int id);

	void setLabel(int n){label = n;}
	void add_out_neighbor(Node to);
	void setFeature(string field, string value);

	int getId(){return id;}
	int getLabel(){return label;}
	set<int> get_out_neighbors(){return out_neighbors;}
	int getFeatureNum(){return features.size();}

	vector<string> getFeatureFields(){return featureFields;}

	string getFeature(string field);
};

#endif /* NODE_H_ */
