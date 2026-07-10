#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class Item {
    private:
        string name;
        string type;
    public:
        Item(string name, string type);
        string getName();
        string getType();

        bool isBundleItem();
        void displayItem();
}; //updated 7/9

#endif