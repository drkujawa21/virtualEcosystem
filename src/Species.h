
#include <iostream>
#include <string>
#include <vector>


class Species{
    public:
    std::string name;
    int maxEnergy;


};

class Plant : public Species{
    public:
    int regrowth;

    Plant(){
        name = "none";
        maxEnergy = 10;
        regrowth = 3;
    }

    Plant(std::string str){
        
    }

    void printPlant();
};


class Omnivore : public Species{
    public:

    Omnivore(std::string str, int energy){
        name = str;
        maxEnergy = energy;
    }

    void printOmnivore();
};

class Herbivore : public Species{
    public:
    Herbivore(std::string str, int energy){
        name = str;
        maxEnergy = energy;
    }

    void printHerbivore();
};


