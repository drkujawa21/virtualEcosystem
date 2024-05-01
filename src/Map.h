#ifndef MAP_H
#define MAP_H
#include "Species.h"
#include <iostream>
#include <vector>
#include <string>

/*
Library for the map. Uses a vectors to build the map.
*/

class Map{
    private:
    std::vector<std::vector<std::string>> map{};
    std::vector<std::string> possibleSpecies{};
    std::vector<Species> currentSpecies{};

    public:
    Map() : map{}, possibleSpecies{}, currentSpecies{} {}

    Map(std::vector<std::vector<std::string>> m, std::vector<std::string> s){
        map = m;
        possibleSpecies = s;
        currentSpecies = initializeSpecies();
    }
        

    //Looking at the current map, INITIALIZE a list of species in the ecosystem.
    std::vector<Species> initializeSpecies();

    std::vector<Species> getCurrentSpecies(){
        return currentSpecies;
    }

    //Prints the current state of the ecosystem
    void printMap();

    //Prints the current list of currentSpecies
    void printSpecies();


    //The purpose of this function is to iterate through the map and find all current
    //existing species in the map. Once they are found, return a vector of species.
    //std::vector<Species> createSpecies();

};
#endif