#pragma once
#include "Vertex.h"
#include "Pair.h"


/*
A template representing an edge in a graph.
Typename T refers to the data type stored in vertices.
Typename U refers to the data type stored in edges.
*/
template <typename T, typename U>
class Edge
{
protected:

	// Stores an edge as a pair of vertices (initial vertex , terminal vertex) (from , to) 
	Pair<Vertex<T>, Vertex<T>>* theEdge;

	//edgeWeight parameter can store some sort of data in the edge
	double edgeWeight;

	//Pointer to the data stored in the edge
	U* data;

public:
	//Creates an edge with values given, the defualt edgeWeight is 1, and sine there is no data 
	//Data is initialized as nullptr
	Edge(Vertex<T>* initialVertex, Vertex<T>* terminalVertex) {
		this->theEdge = new Pair<Vertex<T>, Vertex<T>>(initialVertex, terminalVertex);
		this->edgeWeight = 1;
		this->data = nullptr;
	}

	//Gets the data from the vertex
	U* getData() {
		return this->data;
	}

	//Will set the data for the edge 
	void setData(U* data) {
		this->data = data;
	}

	//Getter for initial vertex from any pair 
	Vertex<T>* getInitialVertex() {
		return this->theEdge->first;
	}

	//Getter for terminal vertex from any pair 
	Vertex<T>* getTerminalVertex() {
		return this->theEdge->second;
	}

	//Getter for edgeWeight
	double getEdgeWeight() {
		return this->edgeWeight;
	}

	//Setter for edgeWeight
	void setEdgeWeight(double weight) {
		this->edgeWeight = weight;
	}

	//Will be able to tell if the edge is a loop 
	bool isLoop() {
		Vertex<T>* initVer = getInitialVertex();
		Vertex<T>* termVer = getTerminalVertex();
		if (initVer == termVer) {
			return true;
		}
		else {
			return false;
		}
	}

	//toString to represent the edge
	std::string toString() {
		std::ostringstream sout;
		sout << "Edge at " << this << "." << std::endl;
		sout << "Initial Edge: " << getInitialVertex() << "." << std::endl;
		sout << "Terminal Edge: " << getTerminalVertex() << "." << std::endl;
		sout << "EdgeWeight: " << this->edgeWeight << std::endl;

		//Add one for data W & w/O data
		return sout.str();
	}


};


template <typename T, typename U>
bool operator==(Edge<T, U>& lhs, Edge<T, U>& rhs) {
	bool sameInitVertex = lhs.getInitialVertex() == rhs.getInitialVertex();
	bool sameTermVertex = lhs.getTerminalVertex() == rhs.getTerminalVertex();
	bool sameEdgeWeight = lhs.getEdgeWeight() == rhs.getEdgeWeight();
	bool sameDataPointer = lhs.getData() == rhs.getData();
	return sameInitVertex && sameTermVertex && sameEdgeWeight && sameDataPointer;
}


template <typename T, typename U>
bool operator!=(Edge<T, U>& lhs, Edge<T, U>& rhs) {
	return !(lhs == rhs);
}

