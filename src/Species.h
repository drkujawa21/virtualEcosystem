#ifndef SPECIES_H
#define SPECIES_H
#include <iostream>
#include <string>
#include <unordered_map>


class Species{
    private:
    std::string name{};
    int maxEnergy{};
    int currentEnergy{};
    std::pair<int, int> coord{};//These will represent the species location on the map (x,y)
    bool carnivore{};
    int id{};//this is ued to differentiate species

    public:
    Species(std::string n, int energy, std::pair<int, int> c, bool d, int i)
        : name{n}, maxEnergy{energy}, coord{c}, carnivore{d}, currentEnergy{energy}, id{i} {}

    Species()
        : name{}, maxEnergy{}, coord{}, carnivore{}, currentEnergy{}, id{} {}

    std::pair<int, int> getCoord() const{
        return coord;
    }

    std::string getName() const{
        return name;
    }

    int getMaxEnergy() const{
        return maxEnergy;
    }

    bool getDiet() const{
        return carnivore;
    }

    int getCurrentEnergy() const{
        return currentEnergy;
    }

    int getID() const{
        return id;
    }

    void setCoord(std::pair<int,int> newCoord){
        coord.first = newCoord.first;
        coord.second = newCoord.second;
    }

    void setCurrentEnergy(int newEnergy){
        currentEnergy = newEnergy;
    }

    void setName(std::string newName){
        name = newName;
    }

    //Returns true if predator can eat prey. False if not
    bool canEatAnimal(Species prey, Species predator);

    void print(){
        std::cout << "Specimen Name: " << name << " Max Energy: " << maxEnergy
            << " Current Energy: " << currentEnergy 
            << "\nCoordinates: " << coord.first << ", " << coord.second
            << " Carnivorous: " << carnivore
            << " Unique ID: " << id;
    }

};

class Plant : public Species{
    private:
    int regrowth{};
    int regrowthTime{};//this is used to track how many more turns the plant is dead for
    std::string realName{};//the plants real name. Used so that once the plant is dead, it can remember its name

    public:
    Plant(int re, std::string n, int energy, std::pair<int,int> c, bool d, int i)
        : regrowth{re}, realName{n}, Species{n, energy, c, d, i}, regrowthTime{re} {}

    Plant()
        : regrowth{}, regrowthTime{}, realName{}, Species{} {}
        
    int getRegrowth(){
        return regrowth;
    }

    int getRegrowthTime(){
        return regrowthTime;
    }

    std::string getRealName(){
        return realName;
    }

    //This is used to pass one turn
    void decrementRegrowth(){
        regrowthTime--;
    }

    //Used when the plant is born again, must reset the regrowth
    void resetRegrowth(){
        regrowthTime = regrowth;
    }

    //Returns true if predator can eat prey (plant). False if not
    bool canEatPlant(Plant prey, Species predator);

    void print(){
        Species::print();
        std::cout << " Regrowth Rate: " << regrowth;
    }
};
#endif

