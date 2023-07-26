#include "BST.h"
#include <iostream>

Node* BST::insertNode(Node* node, string name, string phone) {
    if (node == nullptr)
        node = new Node(name, phone);
    else if (name < node->name)
        node->left = insertNode(node->left, name, phone);
    else
        node->right = insertNode(node->right, name, phone);
    return node;
}

void BST::preorder(Node* node) {
    if (node == nullptr)
        return;
    else {
        cout << node->name << " " << node->phone << endl;
        this->preorder(node->left);
        this->preorder(node->right);
    }
}

void BST::preorder() {
    preorder(root);
}

Node* BST::insertNode(string name, string phone) {
    if (root == nullptr) {
        root = this->insertNode(this->root, name, phone);
        return root;
    }
    else return this->insertNode(this->root, name, phone);
}

void BST::inorder(Node* node) {
    if (node == nullptr)
        return;
    else {
        inorder(node->left);
        cout << node->name << " " << node->phone << endl;
        inorder(node->right);
    }
}

void BST::inorder() {
    inorder(root);
}

void BST::postorder(Node* node) {
    if (node == nullptr)
        return;
    else {
        postorder(node->left);
        postorder(node->right);
        cout << node->name << " " << node->phone << endl;
    }
}

void BST::postorder() {
    postorder(root);
}

Node* BST::searchNode(Node* root, string name) {
    if (!root)
        return nullptr;
    if (name == root->name)
        return root;
    else if (name < root->name)
        return searchNode(root->left, name);
    else return searchNode(root->right, name);
}

Node* BST::searchNode(string name) {
    return searchNode(root, name);
}

Node* BST::minValue(Node* root) {
    Node* current = root;
    while (current && current->left)
        current = current->left;
    return current;
}

Node* BST::deleteNode(Node* root, string name) {
    if (root == nullptr)
        return root;
    if (name < root->name)
        root->left = deleteNode(root->left, name);
    else if (name > root->name)
        root->right = deleteNode(root->right, name);
    else {
        if (root->left == nullptr) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == nullptr) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        Node* tmp = minValue(root->right);
        root->name = tmp->name;
        root->right = deleteNode(root->right, tmp->name);
    }
    return root;
}

Node* BST::deleteNode(string name) {
    root = this->deleteNode(root, name);
    return root;
}