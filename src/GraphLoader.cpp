/*
 * GraphLoader.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: Ko-Shin Chen
 */

#include "GraphLoader.h"

Graph GraphLoader::readFile(string path){
	Graph result;

	ifstream inFile;
	inFile.open(path);
	if(!inFile){
		cout << "File does not exist." << endl;
		return result;
	}
	
	// In the file, the order of information provided is: title, year, id, out_neighbors (reference paper ids).

	string line;
	string title;
	string year;
	int id = 0;
	Node* curr;

	bool hasTitle = false;
	bool hasYear = false;
	bool nodeConstructed = false;

	while(std::getline(inFile, line)){
		if(line.size() == 0 && nodeConstructed){
		// End of the block. Add current Node to the graph.
			result.addVertex(curr);
			hasTitle = false;
			hasYear = false;
			nodeConstructed = false;
			id = 0;
		}
		else if(line[1] == '*'){
			title = line.substr(2);
			hasTitle = true;
		}
		else if(line[1] == 't'){
			year = line.substr(2);
			hasYear = true;
		}
		else if(line[1] == 'i'){
			id = std::stoi(line.substr(6));

			Node paper(id);
			nodeConstructed = true;
			curr = &paper;

			if(hasTitle) paper.setFeature("Title", title);
			if(hasYear) paper.setFeature("Year", year);
		}
		else if(line[1] == '%' && nodeConstructed){
			int nb = std::stoi(line.substr(2));
			curr -> add_out_neighbor(nb);
		}

	}

	if(nodeConstructed){
	// Catch the last block if there is no blank line after it.
		result.addVertex(curr);
		nodeConstructed = false;
	}
	
	inFile.close();

	return result;
}

