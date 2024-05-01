#ifndef SPECIES_H
#define SPECIES_H
#include <iostream>
#include <string>
#include <unordered_map>


class Species{
    private:
    std::string name{};
    int maxEnergy{};
    std::pair<int, int> coord{};//These will represent the species location on the map (x,y)
    bool carnivore{};

    public:
    Species(std::string n, int energy, std::pair<int, int> c, bool d)
        : name{n}, maxEnergy{energy}, coord{c}, carnivore{d} {}

    Species()
        : name{}, maxEnergy{}, coord{}, carnivore{} {}

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

    void print(){
        std::cout << "Specimen. Name: " << name << " Max Energy: " << maxEnergy
            << " Coordinates: " << coord.first << ", " << coord.second
            << " Carnivorous: " << carnivore << std::endl;
    }
};

class Plant : public Species{
    private:
    int regrowth{};

    public:
    Plant(int re, std::string n, int energy, std::pair<int,int> c, bool d)
        : regrowth{re}, Species{n, energy, c, d} {}

    Plant()
        : regrowth{}, Species{} {}
        
    int getRegrowth(){
        return regrowth;
    }

    void print(){
        Species::print();
        std::cout << "Regrowth Rate: " << regrowth << std::endl;
    }
};
#endif

