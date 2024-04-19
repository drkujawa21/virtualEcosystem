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

    Plant(std::string str, int regrow, int energy){
        name = str;
        regrowth = regrow;
        maxEnergy = energy;
    }

    void createPlant(std::string plantLine);
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

class Movement : public Omnivore , public Herbivore{
    public:
    enum Direction{
        up,
        down,
        left,
        right,
        stay
    };
    //not sure if this is the best way to control movement, but it will work for now.
    Movement::Direction move;

    void moveUp(){
        move = up;
    }

    void moveDown(){
        move = down;
    }

    void moveLeft(){
        move = left;
    }

    void moveRight(){
        move = right;
    }

    void moveNull(){
        move = stay;
    }

};