#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;
//Make the parent class
class Character {
    private:
        string name;
        string location;
    public:
        Character(string name, string location);
        string getName(); 
        void setName(string newName);
        string getLocation();
        void setLocation(string newLocation);
        
       
};



#endif