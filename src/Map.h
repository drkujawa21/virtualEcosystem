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
    public:
    int numRows, numCols;

    std::vector<std::string> mapRows;//the map stored into a vector of strings
    std::vector<std::string> listSpecies;//the list of species stored in string vector

    public:

    //Default constructor for map. Creates empty 5x5 map.
    Map(){
        for(int i = 0; i < 5; i++){
            numRows, numCols = 5;
            mapRows.push_back("     ");
        }
    }

    //Constructor for map, control rows and columns. Creates empty map.
    Map(int numRows, int numCols){
        std::string temp; //temp holder for how many columns.
        for(int i = 0; i < numCols; i++){ //this builds the number of columns.
            temp += " ";
        }
        for(int i = 0; i < numRows; i++){
            mapRows.push_back(temp);
        }
    }

    //Constructor for map, takes in a .txt file. Creates a full map and list of species
    Map(std::vector<std::string> mapFile, std::vector<std::string> speciesFile){
        //First two for loops handle creating mapfile. (second for loop tracks # of cols)
        for(int i = 0; i < mapFile.size(); i++){
            numRows++;
            mapRows.push_back(mapFile[i]);
        }
        for(int i = 0; i < mapFile[0].size(); i++){
            numCols++;
        }

        //Creates species list.
        for(int i = 0; i < speciesFile.size(); i++){
            listSpecies.push_back(speciesFile[i]);
        }
    }

    //Prints the current state of the ecosystem
    void printMap();

    //Prints the current list of species
    void printSpecies();

};

class Consume : public Movement{
    public:
    
};
#endif