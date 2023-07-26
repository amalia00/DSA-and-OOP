#pragma once
#include "BST.h"
#include <string>

using namespace std;

class Map {
    int size;
    BST tree;
public:
    Map() {}
    ~Map() = default;
    void add(string, string);
    void printAll();
    void deleteNode(string);
    Node* operator[] (string);
};