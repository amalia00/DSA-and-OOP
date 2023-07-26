#include "Console.h"
#include <iostream>

int main() {
    Console console;
    bool run = true;
    while (run) {
        try {
            console.handleMenu(run);
        }
        catch (const char* err) {
            cerr << err << endl;
        }
    }
    return 0;
}