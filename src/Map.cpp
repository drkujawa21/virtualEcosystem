#include "Map.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<Plant> Map::initializePlants(){
    std::vector<Plant> initialPlants; //the return value
    for(long unsigned int line = 0; line < possibleSpecies.size(); line++){
        std::string animalID; //this is used to determine what the current species in currentSpecies is 
        animalID = possibleSpecies.at(line).at(0);
        if(animalID.compare("p") == 0){
            std::string leftChar;
            std::string rightChar;
            std::string nameChar;
            for(long unsigned int character = 1; character < possibleSpecies.at(line).size()-1; character++){
                leftChar = possibleSpecies.at(line).at(character-1);
                rightChar = possibleSpecies.at(line).at(character+1);
                nameChar = possibleSpecies.at(line).at(character);
                //make sure to break character for loop once done finding all species
                if(leftChar.compare(" ") == 0 && rightChar.compare(" ") == 0){
                    int uniqueID = 1;
                    //search the map for a species with the same name
                    for(long unsigned int row = 0; row < map.size(); row++){
                        for(long unsigned int column = 0; column < map.at(row).size(); column++){
                            std::string c;
                            c = map.at(row).at(column);
                            if(c.compare(nameChar) == 0){ //once we find a species, create a unique one
                                std::string nameSpecies;
                                //std::string nameSpeciesID;
                                std::pair<int,int> location;
                                std::string num1;
                                std::string num2;
                                std::string numCombine; //combination of num1 and num2. used in 2 digit energy species.
                                std::string numRegrowth;
                                int speciesEnergy;
                                
                                //REGROWTH MUST BE ONE DIGIT
                                int regrowthPlant;

                                //location
                                location.first = row;
                                location.second = column;

                                //name
                                //nameSpeciesID = std::to_string(speciesID.at(line));
                                //speciesID.at(line)++;
                                nameSpecies.append(c);
                                //nameSpecies.append(nameSpeciesID);

                                //energy and regrowth
                                //second to last digit in possibleSpecies.at(line)
                                std::string digitChecker;
                                digitChecker = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-2);
                                if(digitChecker.compare(" ") == 0){//if 1 digit energy
                                    num1 = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-1);
                                    speciesEnergy = stoi(num1);
                                    numRegrowth = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-3);
                                    regrowthPlant = stoi(numRegrowth);
                                }
                                else{//if 2 digit energy
                                    num1 = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-2);
                                    num2 = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-1);
                                    numCombine.append(num1);
                                    numCombine.append(num2);
                                    speciesEnergy = stoi(numCombine);
                                    numRegrowth = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-4);
                                    regrowthPlant = stoi(numRegrowth);
                                }
                                Plant newP(regrowthPlant, nameSpecies, speciesEnergy, location, false, uniqueID);
                                initialPlants.push_back(newP);
                                uniqueID++;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    return initialPlants;
}

std::vector<Species> Map::initializeAnimals(){
    std::vector<Species> initialAnimals; //the return value
    for(long unsigned int line = 0; line < possibleSpecies.size(); line++){
        std::string animalID; //this is used to determine what the current species in currentSpecies is 
        animalID = possibleSpecies.at(line).at(0);
        if(animalID.compare("p") != 0){
            std::string leftChar;
            std::string rightChar;
            std::string nameChar;
            for(long unsigned int character = 1; character < possibleSpecies.at(line).size()-1; character++){
                leftChar = possibleSpecies.at(line).at(character-1);
                rightChar = possibleSpecies.at(line).at(character+1);
                nameChar = possibleSpecies.at(line).at(character);
                //make sure to break character for loop once done finding all species
                if(leftChar.compare(" ") == 0 && rightChar.compare(" ") == 0){
                    int uniqueID = 1;//this will be used to differentiate each animal
                    //search the map for a species with the same name
                    for(long unsigned int row = 0; row < map.size(); row++){
                        for(long unsigned int column = 0; column < map.at(row).size(); column++){
                            std::string c;
                            c = map.at(row).at(column);
                            if(c.compare(nameChar) == 0){ //once we find a species, create a unique one
                                std::string nameSpecies;
                                //std::string nameSpeciesID;
                                std::pair<int,int> location;
                                std::string num1;
                                std::string num2;
                                std::string numCombine; //combination of num1 and num2. used in 2 digit energy species.
                                int speciesEnergy;
                                bool dietAnimal;

                                if(animalID.compare("h") == 0){
                                    dietAnimal = false;
                                }
                                else{
                                    dietAnimal = true;
                                }
                                

                                //location
                                location.first = row;
                                location.second = column;

                                //name
                                //nameSpeciesID = std::to_string(speciesID.at(line));
                                //speciesID.at(line)++;
                                nameSpecies.append(c);
                                //nameSpecies.append(nameSpeciesID);

                                //energy
                                //second to last digit in possibleSpecies.at(line)
                                std::string digitChecker;
                                digitChecker = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-2);
                                if(digitChecker.compare(" ") == 0){//if 1 digit energy
                                    num1 = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-1);
                                    speciesEnergy = stoi(num1);
                                }
                                else{//if 2 digit energy
                                    num1 = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-2);
                                    num2 = possibleSpecies.at(line).at(possibleSpecies.at(line).size()-1);
                                    numCombine.append(num1);
                                    numCombine.append(num2);
                                    speciesEnergy = stoi(numCombine);
                                }
                                Species newA(nameSpecies, speciesEnergy, location, dietAnimal, uniqueID);
                                initialAnimals.push_back(newA);
                                uniqueID++;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    return initialAnimals;
}

Species Map::findAnimal(std::pair<int,int> location){
    for(long unsigned int c = 0; c < currentAnimals.size(); c++){
        if((currentAnimals.at(c).getCoord().first == location.first) && 
            (currentAnimals.at(c).getCoord().second == location.second)){
            return currentAnimals.at(c);
        }
    }
}

Plant Map::findPlant(std::pair<int,int> location){
    for(Plant p : currentPlants){
        //p.print();
        if(p.getCoord().first == location.first){
            //std::cout << "Row location matches. ";

            //THIS IS WHERE THE ERROR IS WHEN TRYING TO EAT A PLANT. NOT SURE WHY.
            //VECTOR OUT OF RANGE ERROR
            if(p.getCoord().second == location.second){
                //std::cout << "\nThis is the plant at the location. ";
                return p;
            }
        }
    }
}


int Map::checkLocation(std::pair<int,int> location){
    try{
        std::string temp;
        temp = map.at(location.first).at(location.second);
        //std::cout << "The location we are checking: " << temp << ". ";
        if(temp.compare(" ") == 0){
            //std::cout << "The location is empty. ";
            return 0;
        }
        else{
            //std::cout << "Checking if location is plant. ";
            for(Plant p : currentPlants){
                if((p.getCoord().first == location.first) && (p.getCoord().second == location.second)){
                    //std::cout << "The location is plant. ";
                    return 1;
                }
            }
            //std::cout << "Checking if location is animal. \n";
            for(Species a : currentAnimals){
                if((a.getCoord().first == location.first) && (a.getCoord().second == location.second 
                    && a.getDiet() == false)){
                        //std::cout << "The location is an animal. ";
                        return 2;
                }
                else if(a.getCoord().first == location.first && a.getCoord().second == location.second
                    && a.getDiet() == true){
                        //std::cout << "The location is an APEX PREDATOR. ";
                        return 3;
                }
            }
            throw 4;
        }
    }
    catch(...){
        return 4;
    }
}

void Map::eatAnimal(Species prey, Species predator){
    //Change old location of predator on map to " "
    map.at(predator.getCoord().first).at(predator.getCoord().second) = " ";

    //Predator take prey location
    std::pair<int,int> newL;
    newL.first = prey.getCoord().first;
    newL.second = prey.getCoord().second;
    predator.setCoord(newL);
    predator.setCurrentEnergy(predator.getCurrentEnergy() + prey.getCurrentEnergy());
    updateAnimal(predator);

    //Change new location of predator on map
    map.at(predator.getCoord().first).at(predator.getCoord().second) = predator.getName();
    
    //Prey removed from current animals in ecosystem
    killAnimal(prey);
}

void Map::eatPlant(Plant prey, Species predator){
    std::pair<int,int> preyL;
    std::pair<int,int> predL;
    preyL.first = prey.getCoord().first;
    preyL.second = prey.getCoord().second;
    predL.first = predator.getCoord().first;
    predL.second = predator.getCoord().second;

    prey.setName(" ");
    map.at(preyL.first).at(preyL.second) = predator.getName(); //move pred into prey
    updatePlant(prey);

    predator.setCoord(preyL);
    map.at(predL.first).at(predL.second) = " "; //set old pred as empty
    predator.setCurrentEnergy(predator.getCurrentEnergy() + prey.getCurrentEnergy());
    updateAnimal(predator);
}

void Map::updateAnimal(Species a){
    std::string aName;
    aName = a.getName();
    for(long unsigned int i = 0; i < currentAnimals.size(); i++){
        std::string iName;
        iName = currentAnimals.at(i).getName();
        if(iName.compare(aName) == 0){
            if(currentAnimals.at(i).getID() == a.getID()){
                currentAnimals.at(i) = a;
            }    
        }
    }
}

void Map::updatePlant(Plant p){
    std::string pName;
    pName = p.getName();
    for(long unsigned int i = 0; i < currentPlants.size(); i++){
        std::string iName;
        iName = currentAnimals.at(i).getName();
        if(iName.compare(pName) == 0){
            if(currentPlants.at(i).getID() == p.getID()){
                currentAnimals.at(i) = p;
            } 
        }
    }
}

std::vector<bool> Map::lookAnimal(Species a){
    std::pair<int,int> currentL;
    std::pair<int,int> tempL;
    std::vector<bool> moves(4,false);//INDEX VALUES: 0 = UP, 1 = RIGHT, 2 = DOWN, 3 = LEFT
    currentL.first = a.getCoord().first;
    currentL.second = a.getCoord().second;

    if(a.getCurrentEnergy() > 0){
        int checkSpace;
        if(a.getCoord().first != 0){
            //UP MOVE
            tempL.first = currentL.first-1;
            tempL.second = currentL.second;
            //std::cout << "Checking up move... ";
            checkSpace = checkLocation(tempL);
            if(checkSpace == 0){
                //empty space
                moves.at(0) = true;
                //std::cout << "Up move is possible. Empty space. ";
            }
            else if(checkSpace == 1){
                //plant
                //if it can eat it
                if(findPlant(tempL).canEatPlant(findPlant(tempL), a)){
                    moves.at(0) = true;
                    //std::cout << "Up move is possible. Can eat plant. ";
                }  
            }
            else if(checkSpace == 2){
                //herbivore at space
                //check if the predator can eat the other animal
                if(findAnimal(tempL).canEatAnimal(findAnimal(tempL), a)){
                    moves.at(0) = true;
                    //std::cout << "Up move is possible. Can eat animal. ";
                }  
            }
        }

        //right move
        if(a.getCoord().second != map.at(0).size() - 1){
            tempL.first = currentL.first;
            tempL.second = currentL.second + 1;
            //std::cout << "Checking right move... ";
            checkSpace = checkLocation(tempL);
            if(checkSpace == 0){
                //nothing
                moves.at(1) = true;
                //std::cout << "Right move is possible. Empty space. ";
            }
            else if(checkSpace == 1){
                //plant
                //if animal can eat plant
                if(findPlant(tempL).canEatPlant(findPlant(tempL), a)){
                    moves.at(1) = true;
                    //std::cout << "Right move is possible. Can eat plant. ";
                }
            }
            else if(checkSpace == 2){
                //animal
                //if current animal is predator
                if(findAnimal(tempL).canEatAnimal(findAnimal(tempL),a)){
                    moves.at(1) = true;
                    //std::cout << "Right move is possible. Can eat animal. ";
                }
            }
        }
        
        //down move
        if(a.getCoord().first != map.at(0).size()-1){
            tempL.first = currentL.first + 1;
            tempL.second = currentL.second;
            //std::cout << "Checking down move... ";
            checkSpace = checkLocation(tempL);
            if(checkSpace == 0){
                //nothing
                moves.at(2) = true;
                //std::cout << "Down move is possible. Empty space. ";
            }
            else if(checkSpace == 1){
                //plant, then checks if it is eatable
                if(findPlant(tempL).canEatPlant(findPlant(tempL), a)){
                    moves.at(2) = true;
                    //std::cout << "Down move is possible. Can eat plant. ";
                }
            }
            else if(checkSpace == 2){
                //animal, checks if it is consumable
                if(findAnimal(tempL).canEatAnimal(findAnimal(tempL), a)){
                    moves.at(2) = true;
                    //std::cout << "Down move is possible. Can eat animal. ";
                }
            }
        }

        //left move
        if(a.getCoord().second != 0){
            tempL.first = currentL.first;
            tempL.second = currentL.second - 1;
            //std::cout << "Checking left move... ";
            checkSpace = checkLocation(tempL);
            if(checkSpace == 0){
                //nothing
                moves.at(3) = true;
                //std::cout << "Left move is possible. Empty space. ";
            }
            else if(checkSpace == 1){
                //plant, then checks if it is eatable
                if(findPlant(tempL).canEatPlant(findPlant(tempL), a)){
                    moves.at(3) = true;
                    //std::cout << "Left move is possible. Can eat plant. ";
                }
            }
            else if(checkSpace == 2){
                //animal, checks if it is consumable
                if(findAnimal(tempL).canEatAnimal(findAnimal(tempL), a)){
                    moves.at(3) = true;
                    //std::cout << "Left move is possible. Can eat animal. ";
                }
            }
        }
    }
    //std::cout << "Finished looking for moves." << std::endl;
    return moves;
}

void Map::moveAnimal(Species animalC, std::vector<bool> moves){
    std::pair<int,int> tempL;
    //std::cout << "\nStarting the move process. ";
    bool hasMoved = false;
    while(hasMoved == false){
        int rand = std::rand()%4;
        //this if statement basically looks for a move, and checks if it is possible
        if(moves.at(rand) == true){
            //Change old location on map to " "
            map.at(animalC.getCoord().first).at(animalC.getCoord().second) = " ";
            //std::cout << "Set old location to empty. Starting search for move. ";
            //Using rand to determine which move it was
            if(rand == 0){
                //UP MOVE
                tempL.first = animalC.getCoord().first - 1;
                tempL.second = animalC.getCoord().second;
                //std::cout << "The move is up. Checking location. \n";
                int checkSpace = checkLocation(tempL);
                if(checkSpace == 0){
                    animalC.setCoord(tempL);
                    //Change new location of predator on map
                    map.at(animalC.getCoord().first).at(animalC.getCoord().second) = animalC.getName();
                    animalC.setCurrentEnergy(animalC.getCurrentEnergy() - 1);
                    updateAnimal(animalC);
                    //std::cout << "The animal moved up. Empty space. ";
                }
                else if(checkSpace == 1){
                    eatPlant(findPlant(tempL), animalC);
                    //std::cout << "The animal moved up. Ate plant. ";
                }
                else if(checkSpace == 2){
                    eatAnimal(findAnimal(tempL), animalC);
                    //std::cout << "The animal moved up. Ate animal";
                }
            }
            else if(rand == 1){
                //RIGHT MOVE
                tempL.first = animalC.getCoord().first;
                tempL.second = animalC.getCoord().second + 1;
                //std::cout << "The move is right. Checking location. \n";
                int checkSpace = checkLocation(tempL);
                if(checkSpace == 0){
                    animalC.setCoord(tempL);
                    //Change new location of predator on map
                    map.at(animalC.getCoord().first).at(animalC.getCoord().second) = animalC.getName();
                    animalC.setCurrentEnergy(animalC.getCurrentEnergy() - 1);
                    updateAnimal(animalC);
                    //std::cout << "The animal moved right. Empty space. ";
                }
                else if(checkSpace == 1){
                    eatPlant(findPlant(tempL), animalC);
                    //std::cout << "The animal moved right. Ate plant. ";
                }
                else if(checkSpace == 2){
                    eatAnimal(findAnimal(tempL), animalC);
                    //std::cout << "The animal moved right. Ate animal. ";
                }
            }
            else if(rand == 2){
                //DOWN MOVE
                tempL.first = animalC.getCoord().first + 1;
                tempL.second = animalC.getCoord().second;
                //std::cout << "The move is down. Checking location. \n";
                int checkSpace = checkLocation(tempL);
                if(checkSpace == 0){
                    animalC.setCoord(tempL);
                    //Change new location of predator on map
                    map.at(animalC.getCoord().first).at(animalC.getCoord().second) = animalC.getName();
                    animalC.setCurrentEnergy(animalC.getCurrentEnergy() - 1);
                    updateAnimal(animalC);
                    //std::cout << "The animal moved down. Empty space. ";
                }
                else if(checkSpace == 1){
                    eatPlant(findPlant(tempL), animalC);
                    //std::cout << "The animal moved down. Ate plant. ";
                }
                else if(checkSpace == 2){
                    eatAnimal(findAnimal(tempL), animalC);
                    //std::cout << "The animal moved down. Ate animal. ";
                }
            }
            else if(rand == 3){
                //LEFT MOVE
                tempL.first = animalC.getCoord().first;
                tempL.second = animalC.getCoord().second - 1;
                int checkSpace = checkLocation(tempL);
                //std::cout << "tempL: " << tempL.first << ", " << tempL.second;
                //std::cout << "The move is left. Checking location. \n";
                //std::cout << "\n\n" << checkSpace << std::endl;
                //std::cout << " Animal location: " << a.getCoord().first << ", " << a.getCoord().second; 
                
                if(checkSpace == 0){
                    animalC.setCoord(tempL);
                    //std::cout << "Animal coords: " << animalC.getCoord().first << ", " << animalC.getCoord().second;
                    //Change new location of predator on map
                    map.at(animalC.getCoord().first).at(animalC.getCoord().second) = animalC.getName();
                    animalC.setCurrentEnergy(animalC.getCurrentEnergy() - 1);
                    updateAnimal(animalC);
                    //std::cout << "The animal moved left. Empty space. ";
                }
                else if(checkSpace == 1){
                    eatPlant(findPlant(tempL), animalC);
                    //std::cout << "The animal moved left. Ate plant. ";
                }
                else if(checkSpace == 2 ){
                    eatAnimal(findAnimal(tempL), animalC);
                    //std::cout << "The animal moved left. Ate animal. ";
                }
            }
            hasMoved = true;
        }
    }
}


void Map::iterateEcosystem(){
    for(Plant plant : currentPlants){
        std::string pName;
        pName = plant.getName();
        if(pName.compare(" ") == 0){
            //if the plant is dead
            if(plant.getRegrowthTime() > 0){
                plant.decrementRegrowth();
            }
            //else its time to regrow
            else{
                std::string temp;
                temp = map.at(plant.getCoord().first).at(plant.getCoord().second);
                if(temp.compare(" ") == 0){
                    //if the space is empty, the plant can grow back
                    plant.resetRegrowth();
                    plant.setName(plant.getRealName());
                    map.at(plant.getCoord().first).at(plant.getCoord().second) = plant.getName();
                }
            }
        }
    }
    std::vector<bool> aMoves(4,false);
    for(Species a : currentAnimals){
        std::srand(std::time(nullptr));
        if(a.getCurrentEnergy() == 0){
            killAnimal(a);
        }
        else{
            //std::cout << "\n\nStarting animal turn. \n";
            //a.print();
            aMoves = lookAnimal(a);
            /*std::cout << "Animal moves: ";
            for(int x = 0; x < aMoves.size();x++){
                std::cout << aMoves.at(x) << " ";
            }*/
            moveAnimal(a, aMoves);
            //updateAnimal(a);
            //a.print();
        }
        //std::cout << "\nAnimal turn done. \n";
        aMoves.clear();
    }
}

void Map::killAnimal(Species a){
    int counter = 0;
    for(Species anim : currentAnimals){
        if(anim.getName().compare(a.getName()) == 0){
            if(anim.getID() == a.getID()){
                map.at(anim.getCoord().first).at(anim.getCoord().second) = " ";
                currentAnimals.erase(currentAnimals.begin() + counter);
                break;
            }
        }
        counter++;
    }
}

void Map::printSpecies(){
    std::cout << "These are the current plants on the map: " << std::endl;
    for(Plant plants : currentPlants){
        plants.print();
        std::cout << std::endl << std::endl;
    }
    std::cout << "These are the current animals on the map: " << std::endl;
    for(Species animals : currentAnimals){
        animals.print();
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl;
}

void Map::printMap(){
    std::cout << "This is the current map: " << std::endl;
    for(std::vector<std::string> line : map){
        for(std::string c : line){
            std::cout << c;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}  