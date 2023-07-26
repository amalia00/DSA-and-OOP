#include "Map.h"

void Map::add(string name, string phone) {
    this->tree.insertNode(name, phone);
}

Node* Map::operator[] (string name) {
    return this->tree.searchNode(name);
}

void Map::printAll() {
    this->tree.inorder();
}

void Map::deleteNode(string name) {
    tree.deleteNode(name);
}