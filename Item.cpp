#include "Item.h"


 Item::Item(string N, string T) {
        name = N;
        type = T;
 }
        string Item::getName() {
            return name;
        }
        string Item::getType() {
            return type;
        }

        bool Item::isBundleItem() { 
            return type == "bundle";
        }
        