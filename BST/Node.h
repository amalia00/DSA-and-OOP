#pragma once
#include <string>

using namespace std;

class Node {
public:
    string name;
    string phone;
    Node* left, * right;
    Node(string name, string phone) : name(name), phone(phone) {
        this->left = nullptr;
        this->right = nullptr;
    }
};