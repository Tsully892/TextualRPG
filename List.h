#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include "Pair.h"
#include "Chain.h"

/*
 A templated class representing lists. A List<T> manages pointers to objects of type T.
 */
template <typename T>
class List : public Chain<T> {

protected:

    /*
     Creates a list consisting of the specified node.
     */
    List(Node<T>* existingNode) {
        if (existingNode == nullptr) {
            this->startNode = nullptr;
            this->endNode = nullptr;
            this->numNodes = 0;

        }
        else {
            this->numNodes = 1;
            Node<T>* currentNode = existingNode;

            while (currentNode->getNextNode() != nullptr) {
                currentNode = currentNode->getNextNode();
                this->numNodes++;
            }

            this->endNode = currentNode;
            currentNode = existingNode;

            while (currentNode->getPreviousNode() != nullptr) {
                currentNode = currentNode->getPreviousNode();
                this->numNodes++;
            }
            this->startNode = currentNode;
        }
    }

public:

    /*
     Creates an empty list.
     */
    List() : Chain<T>() {}

    /*
     Returns the index of the first occurance of the specified
     data in this chain, or, if the specified data is not in
     this chain, returns a negative number.

     Note: the specified data is considered to be in this chain
     iff its pointer has the same value as one of the pointers
     managed by this list.
     */
    int getIndex(T* data) {
        int result = -1;
        int sz = this->getSize();

        for (int k = 0; k < sz; k++) {
            T* peekResult = this->peek(k);

            if (peekResult == data) {
                result = k;
                break;
            }
        }
        return result;
    }

    /*
     Removes the node at the specified position, and returns the
     data from that node. If there is no node in the specified
     position, this method leaves the list unaltered and returns
     the null pointer.
     */



    T* removeFromPosition(int position) {
        T* result;
        Node<T>* currentNode = this->startNode;

        for (int k = 0; k < position; k++) {
            currentNode = currentNode->getNextNode();
        }

        List<T>* lastHalf = this->splitAfter(position);
        result = this->removeFromEnd();
        this->append(lastHalf);
        return result;
    }

    /*
     Inserts the specified data into the list as a new node in
     the specified position.
     */
    void insertAtPosition(int position, T* data) {
        if (this->isEmpty()) {
            this->startNode = new Node<T>(data);
            this->endNode = this->startNode;
            this->numNodes = 1;

        }
        else if (position == 0) {
            Node<T>* newStart = new Node<T>(data);
            this->startNode->setPreviousNode(newStart);
            newStart->setNextNode(this->startNode);
            this->startNode = newStart;
            this->numNodes++;

        }
        else {
            List<T>* lastHalf = this->splitAfter(position - 1);
            this->insertAtEnd(data);
            this->append(lastHalf);
            this->numNodes++;
        }
    }

    /*
     Splits this list after the specified position, removing all
     nodes after that position from this list, and returning these
     nodes as another list.
     */
    List<T>* splitAfter(int position) {
        List<T>* result;

        if (this->numNodes < 2) {
            result = new List<T>();

        }
        else {
            Node<T>* currentNode = this->startNode;

            for (int k = 0; k < position; k++) {
                currentNode = currentNode->getNextNode();
            }

            if (currentNode == this->endNode) {
                result = new List<T>();

            }
            else {
                Node<T>* newRoot = currentNode->getNextNode();
                newRoot->setPreviousNode(nullptr);
                currentNode->setNextNode(nullptr);
                this->endNode = currentNode;
                this->numNodes = position + 1;
                result = new List<T>(newRoot);
            }
        }
        return result;
    }

    /*
     Appends the specified list to this one.
     */
    void append(List<T>* suffix) {
        if (!suffix->isEmpty()) {

            if (this->isEmpty()) {
                this->startNode = suffix->startNode;
                this->endNode = suffix->endNode;
                this->numNodes = suffix->numNodes;

            }
            else {
                this->endNode->setNextNode(suffix->startNode);
                suffix->startNode->setPreviousNode(this->endNode);
                this->endNode = suffix->endNode;
                this->numNodes += suffix->getSize();
            }
        }
    }

    /*
     Prepends the specified list to this one.
     */
    void prepend(List<T>* prefix) {
        if (!prefix->isEmpty()) {

            if (this->isEmpty()) {
                this->startNode = prefix->startNode;
                this->endNode = prefix->endNode;
                this->numNodes = prefix->getSize();

            }
            else {
                this->startNode->setPreviousNode(prefix->endNode);
                prefix->endNode->setNextNode(this->startNode);
                this->startNode = prefix->startNode;
                this->numNodes += prefix->getSize();
            }
        }
    }

    /*
     Returns a string representation of this list.
     */
    std::string toString();

};