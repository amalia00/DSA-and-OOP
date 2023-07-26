#pragma once
#include "Node.h"

class BST {
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    Node* insertNode(Node*, string, string);
    Node* searchNode(Node*, string);
    Node* minValue(Node*);
    Node* deleteNode(Node*, string);
public:
    Node* root;
    BST() : root(nullptr) {}
    void preorder();
    void inorder();;
    void postorder();
    Node* insertNode(string, string);
    Node* searchNode(string);
    Node* deleteNode(string);
    friend class Map;
};