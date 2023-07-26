#pragma once
#include "Map.h"

class Console {
    Map map;
public:
    void printMenu();
    void add();
    void printAll();
    void searchName();
    void deleteName();
    void handleMenu(bool&);
};