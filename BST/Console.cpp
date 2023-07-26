#include "Console.h"
#include <stdio.h>
#include <iostream>
#include <regex>

using namespace std;

void Console::printMenu() {
    cout << "1. add a person\n";
    cout << "2. print all\n";
    cout << "3. search a name in the list\n";
    cout << "4. delete a name from the list\n";
    cout << "5. exit\n\n";
}

void Console::add() {
    string name, phone;
    cout << "enter the name: ";
    cin >> name;
    cout << "enter phone number: ";
    cin >> phone;
    if (!regex_match(phone, regex("^\\d+$")))
        throw "invalid phone number";
    map.add(name, phone);
}

void Console::printAll() {
    map.printAll();
    cout << endl;
}

void Console::searchName() {
    string name;
    cout << "enter the name: ";
    cin >> name;
    if (map[name])
        printf("name: %s\nphone: %s\n\n", name.c_str(), map[name]->phone.c_str());
    else
        cout << "it doesn't exist\n\n";
}

void Console::deleteName() {
    string name;
    cout << "enter the name: ";
    cin >> name;
    if (map[name])
        map.deleteNode(name);
    else
        cout << "it doesn't exist\n\n";
}

void Console::handleMenu(bool& run) {
    this->printMenu();
    int option;
    cout << "your option: [ ]\b\b";
    cin >> option;
    switch (option) {
    case 1:
        add();
        break;
    case 2:
        printAll();
        break;
    case 3:
        searchName();
        break;
    case 4:
        deleteName();
        break;
    case 5:
        run = false;
        break;
    default:
        cout << "invalid option\n";
        break;
    }
}