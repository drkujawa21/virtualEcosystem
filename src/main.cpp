#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
The main function to run the ecosystem.
*/

//call this function to run one iteration on the ecosystem, (all animals take one turn)
void nextIteration(Map m){
    //m.moveAnimal(Species s);
}

int main(){
    vector<vector<string>> coords;
    vector<string> speciesTxt;
    string mapFilePath;
    string speciesFilePath;
    ifstream speciesFile;
    ifstream mapFile;

    cout << "What is the path for the map file you would like to use?: ";
    cin >> mapFilePath;
    cout << "What is the path for the species file you would ike to use?: ";
    cin >> speciesFilePath;

    mapFile.open(mapFilePath);//moved txt files out of input because I could not access them
    speciesFile.open(speciesFilePath);

    //These ifs check if the file is opened or not
    if(!speciesFile){
        cerr << "Couldn't open 'species.txt' for reading.\n";
        return 1;
    }
    if(!mapFile){
        cerr << "Couldn't open 'map.txt' for reading.\n";
        return 1;
    }

    //This while loop iterates through each line of the map.txt file and copies them
    //into a local variable.
    string temp;
    while(getline(mapFile, temp)){
        vector<string> line(temp.size(), " ");
        for(int i = 0; i < temp.size(); i++){
            line.at(i) = temp[i];
        }
        coords.push_back(line);
    }

    string newTemp;
    while(getline(speciesFile, newTemp)){
        //cout << temp << endl;
        speciesTxt.push_back(newTemp);
    }

    //Testing
    /*cout << "\nChecking coords..." << endl;
    cout << "Size of coords: " << coords.size() << endl;
    for( vector<string> test : coords){
        for(string c : test){
            cout << "Text: " << c;
        }
        cout << endl;
    }
    cout << endl;*/

    Map map(coords, speciesTxt);

    map.printMap();
    map.printSpecies();

    return 0;
}