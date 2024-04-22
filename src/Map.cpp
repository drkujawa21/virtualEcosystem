#include "Map.h"
#include <iostream>
#include <string>
#include <vector>

void Map::printMap(){
    for(int i = 0; i < mapRows.size(); i++){
        std::cout << mapRows[i] << std::endl;
    }
}

void Map::printSpecies(){
    for(int i = 0; i < listSpecies.size(); i++){
        std::cout << listSpecies[i] << std::endl;
    }
}

void Map::moveAnimal(Species specie){
    //move an animal once
}

std::vector<Species> Map::createSpecies(){
    for(int i = 0; i < mapRows.size(); i++){
        if(mapRows[i] != " "){
            
        }
    }
}