/*
 * Node.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: Ko-Shin Chen
 */

#include "Node.h"

// constructor
Node::Node(int id){
	this -> id = id;
}


// member functions
void Node::add_out_neighbor(Node to){
	out_neighbors.insert(to.getId());
}

void Node::setFeature(string field, string value){
	if(features.count(field) != 0){
		cout << field << ": the value is changed from " << features[field] << " to " << value << endl;
	}
	else{
		featureFields.push_back(field);
	}
	features[field] = value;
}


string Node::getFeature(string field){
	if(features.count(field) == 0){
		cout << field << ": specified feature does not exist." << endl;
		return "";
	}
	return features[field];
}
