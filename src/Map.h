#ifndef MAP_H
#define MAP_H
#include "Species.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

/*
Library for the map. Uses a vectors to build the map.
*/

class Map{
    private:
    std::vector<std::vector<std::string>> map{};
    std::vector<std::string> possibleSpecies{};
    std::vector<Plant> currentPlants{};
    std::vector<Species> currentAnimals{};

    public:
    Map() : map{}, possibleSpecies{}, currentPlants{}, currentAnimals{} {}

    Map(std::vector<std::vector<std::string>> m, std::vector<std::string> s){
        map = m;
        possibleSpecies = s;
        currentPlants = initializePlants();
        currentAnimals = initializeAnimals();
    }
        

    /*
    Looking at the current map, INITIALIZE a list of species in the ecosystem.
    We first loop through currentSpecies. Once we find the name, we loop through the map and 
    find each plant that is the same as the current plant we are looking at in currentSpecies.
    After we find a species with the same name, we will create a new species of the current specimen we are on
    while looping through currentSpecies.
    */
    std::vector<Plant> initializePlants();
    
    //Same as initialize plants
    std::vector<Species> initializeAnimals();

    //Getter for vector of current plants
    std::vector<Plant> getCurrentPlants(){
        return currentPlants;
    }

    //Getter for vectro of current animals
    std::vector<Species> getCurrentAnimals(){
        return currentAnimals;
    }

    //Prints the current state of the ecosystem at initialization
    void printMap();

    //Prints the current list of all species
    void printSpecies();

    //A function that will iterate through all species and find the specimen in a given location.
    //Will break if the animal doesn't exist
    Species findAnimal(std::pair<int,int> location);

    //Similar to findAnimal, however looks for plants
    Plant findPlant(std::pair<int,int> location);

    //When given a predator and prey, has the predator eat the prey.
    //If it can, take prey location and remove prey from list of current species.
    //Also updates the map
    void eatAnimal(Species prey, Species predator);

    //The same as eatAnimal, however is used on plants
    void eatPlant(Plant prey, Species predator);

    //Checks a spot on the map. Returns 0 if empty, 1 if plant, 2 if herbivore, 3 if omnivore, 4 if not possible
    int checkLocation(std::pair<int,int> location);


    //new move for an animal. Given an animal, determines it's possible moves and
    //returns a vector with options. 
    //The vector will be size = 4
    //INDEX VALUES: 0 = UP, 1 = RIGHT, 2 = DOWN, 3 = LEFT
    std::vector<bool> lookAnimal(Species anim);

    //Given a vector of choices, the animal will make one move. Works hand in hand with lookAnimal.
    //The move will also update the map
    void moveAnimal(Species a, std::vector<bool> m);

    //After an animal has done something, goes into the currentSpecies vector and updates them
    void updateAnimal(Species a);

    //Same as updateAnimal, but for plants
    void updatePlant(Plant p);
    
    //Removes the animal from the list of current Plants
    void killAnimal(Species a);

    //One iteration of the ecosystem. Every animal takes one move.
    //Every plant IF DEAD will try and regrow.
    void iterateEcosystem();
};
#endif