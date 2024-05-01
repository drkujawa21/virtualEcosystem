#include "Map.h"
#include <iostream>
#include <string>
#include <vector>

/*
We first loop through currentSpecies. Once we find the name, we loop through the map and 
find each species that is the same as the current species we are looking at in currentSpecies.
After we find a species with the same name, we will create a new species of the current specimen we are on
while looping through currentSpecies.
*/
std::vector<Species> Map::initializeSpecies(){
    std::vector<Species> initialSpecimens; //the return value
    //this vector serves to help identify each species. parallel to currentSpecies in that line 1 of 
    //speciesID is line 1 of currentSpecies.
    std::vector<int> speciesID(possibleSpecies.size(), 1);

    for(int line = 0; line < possibleSpecies.size(); line++){
        std::string animalID; //this is used to determine what the current species in currentSpecies is 
        std::string leftChar;
        std::string rightChar;
        std::string nameChar;
        animalID = possibleSpecies.at(line).at(0);
        for(int character = 1; character < possibleSpecies.at(line).size()-1; character++){
            leftChar = possibleSpecies.at(line).at(character-1);
            rightChar = possibleSpecies.at(line).at(character+1);
            nameChar = possibleSpecies.at(line).at(character);
            //make sure to break character for loop once done finding all species
            if(leftChar.compare(" ") == 0 && rightChar.compare(" ") == 0){
                //search the map for a species with the same name
                for(int row = 0; row < map.size(); row++){
                    for(int column = 0; column < map.at(row).size(); column++){
                        std::string c;
                        c = map.at(row).at(column);
                        if(c.compare(nameChar) == 0){ //once we find a species, create a unique one
                            std::string nameSpecies;
                            std::string nameSpeciesID;
                            std::pair<int,int> location;
                            std::string num1;
                            std::string num2;
                            std::string numCombine; //combination of num1 and num2. used in 2 digit energy species.
                            std::string numRegrowth;
                            int speciesEnergy;
                            /*Now that we have the species, we have to determine what it is.*/
                            if(animalID.compare("p") == 0){//if plant is the current species
                                //REGROWTH MUST BE ONE DIGIT
                                int regrowthPlant;

                                //location
                                location.first = row;
                                location.second = column;

                                //name
                                nameSpeciesID = std::to_string(speciesID.at(line));
                                speciesID.at(line)++;
                                nameSpecies.append(c);
                                nameSpecies.append(nameSpeciesID);

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
                                Plant newP(regrowthPlant, nameSpecies, speciesEnergy, location, false);
                                initialSpecimens.push_back(newP);
                            }
                            else if(animalID.compare("h") == 0){//if herbivore is the current species
                                //location
                                location.first = row;
                                location.second = column;

                                //name
                                nameSpeciesID = std::to_string(speciesID.at(line));
                                speciesID.at(line)++;
                                nameSpecies.append(c);
                                nameSpecies.append(nameSpeciesID);

                                //energy and regrowth
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
                                Species newH(nameSpecies, speciesEnergy, location, false);
                                initialSpecimens.push_back(newH);
                            }
                            else if(animalID.compare("o") == 0){//if omnivore is the current species
                                //location
                                location.first = row;
                                location.second = column;

                                //name
                                nameSpeciesID = std::to_string(speciesID.at(line));
                                speciesID.at(line)++;
                                nameSpecies.append(c);
                                nameSpecies.append(nameSpeciesID);

                                //energy and regrowth
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
                                Species newO(nameSpecies, speciesEnergy, location, true);
                                initialSpecimens.push_back(newO);
                            }
                            else{//if not the above 3
                                std::cerr << "Unknown species on the map. Check your map for foriegn species."
                                    << std::endl;
                            }

                        }
                    }
                }
                break;
            }
        }
    }
    return initialSpecimens;
}

void Map::printSpecies(){
    std::cout << "These are the current species on the map: " << std::endl;
    for(Species specimens : currentSpecies){
        specimens.print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Map::printMap(){
    std::cout << "This is the current map: " << std::endl;
    for(std::vector<std::string> line : map){
        std::cout << "Text: ";
        for(std::string c : line){
            std::cout << c;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}  