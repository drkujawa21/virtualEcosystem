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

int main(){
    vector<vector<string>> coords;
    vector<string> speciesTxt;
    string mapFilePath;
    string speciesFilePath;
    ifstream speciesFile;
    ifstream mapFile;

    cout << "Hello! Welcome to my virtual ecosystem." << endl;

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
        for(long unsigned int i = 0; i < temp.size(); i++){
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
    //map.printSpecies();

    int numIterate;
    int choice = 0;
    while(choice != 3){
        cout << "\n1. Run one iteration. " << endl;
        cout << "2. Run multiple iterations. " << endl;
        cout << "3. Exit simulation. " << endl;
        cin >> choice;
        if(choice == 1){
            map.iterateEcosystem();
            map.printMap();
        }
        else if(choice == 2){
            cout << "How many iterations would you like to run?: ";
            cin >> numIterate;
            for(int i = 0; i < numIterate; i++){
                map.iterateEcosystem();
            }
            map.printMap();
        }
    }
    cout << "Goodbye." << endl;
    
    return 0;
}