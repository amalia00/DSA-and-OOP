#include <iostream>
#include <vector>
#include<string>
#include<string.h>
using namespace std;
#include "MyFlower.h"

int main()
{
    std::vector<string> v = { "f1","f2","f3","f4","f5","f6" };
    std::vector<MyFlower> flowers;
    std::vector<MyFlower> flower;
    char name;
    unsigned int age;
    int i = 0;
    int ok = 1;
    MyFlower f;
    while (ok == 1)
    {
        char name[30];
        cin >> name;
        cin >> age;
        f.setName(name);
        f.setAge(age);
        flowers.push_back(f);
        cout << "if you want to continue press 1";
        cin >> ok;

    }
    for(i=0;i<flowers.size()-1;i++)
    {
        flower.push_back(flowers[i] + flowers[i + 1]);
    }

    for (auto i:flower)
        std::cout << i << ' ';

    cout << endl;
    cout << "living: " << MyFlower::getLivingCount() << endl;
    cout << "created: " << MyFlower::getCreatedCount() << endl;
    return 0;

	}

