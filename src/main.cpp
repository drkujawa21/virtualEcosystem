#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
The main function to run the ecosystem.
*/

int main(){
    vector<string> speciesTxt;
    vector<string> mapTxt;
    ifstream speciesFile;
    ifstream mapFile;
    mapFile.open("map.txt");//moved txt files out of input because I could not access them
    speciesFile.open("species.txt");

    //These ifs check if the file is opened or not
    if(!speciesFile){
        cerr << "Couldn't open 'species.txt' for reading.\n";
        return 1;
    }
    if(!mapFile){
        cerr << "Couldn't open 'map.txt' for reading.\n";
        return 1;
    }

    string temp;
    while(getline(mapFile, temp)){
        mapTxt.push_back(temp);
    }

    while(getline(speciesFile, temp)){
        speciesTxt.push_back(temp);
    }

    Map map(mapTxt,speciesTxt);

    map.printMap();
    map.printSpecies();
    cout << "\nwhat the sigma" << endl;

    return 0;
}