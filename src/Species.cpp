#include "Species.h"
#include <iostream>
#include <vector>
#include <string>

bool Species::canEatAnimal(Species prey, Species predator){
    if(predator.getDiet() == true){
        if(predator.getCurrentEnergy() + prey.getCurrentEnergy() <= predator.getMaxEnergy()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Plant::canEatPlant(Plant prey, Species predator){
    std::string pName;
    pName = prey.getName();
    if((predator.getCurrentEnergy() + prey.getCurrentEnergy() <= predator.getMaxEnergy()) && pName.compare(" ") != 0){
        return true;
    }
    else{
        return false;
    }
}
