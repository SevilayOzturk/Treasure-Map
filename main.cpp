#include <iostream>
#include <string>
#include <fstream>

#include "TreasureMap.h"
#include "FileReadException.h"
#include "Location.h"

using namespace std;

//overload operator << of Location class, no changes needed
ostream& operator<<(ostream& os, Location& pt) {
    return os << pt.getName();
}

//overload operator >> of Location class, no changes needed
istream& operator >> (istream& os, Location& pt) {
    string name;
    float x,y;
    os >> name >> x >> y;
    pt.setName(name);
    pt.setX(x);
    pt.setY(y);
    
    return os;
}


//FIX ME: Implement readmap function that reads from a file and return a proper TreasureMap object
template<class T>
TreasureMap<T> readMap(string file_name, int maxstep){
    TreasureMap<T> Tmap(maxstep);
    ifstream infile;
    infile.open(file_name);
    if(!infile.is_open()){
        FileReadException ex("Error reading map: " + file_name +"does not exists!");
        throw ex;
    }
    string filetype;
    int x = 0;
    T step;
    
    
    while(infile >> step){
        if(x == maxstep){
            FileReadException ex("Error reading map: " + file_name + " contains more than " + to_string(maxstep)+" steps!");
            throw ex;
        }
        Tmap.addStep(step);
        x++;
    }
    infile.close();
    return Tmap;
    
}


int main()
{
    string file_name, file_type;
    int max_steps;
    cin >> file_name >> file_type >> max_steps;
    
    
    try{
        if (file_type == "string"){
            TreasureMap<string> Tmap = readMap<string>(file_name, max_steps);
            for (int i = 0; i < Tmap.getTotalSteps()-1; i ++){
                Tmap.nextStep();
            }
        } else if (file_type == "int"){
            //FIX ME: Create a TreasureMap of type int, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
            TreasureMap<int>Tmap = readMap<int>(file_name, max_steps);
            for(int x =0; x< Tmap.getTotalSteps()-1; x++){
                Tmap.nextStep();
            }
        } else if (file_type == "char"){
            //FIX ME: Create a TreasureMap of type char, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
            TreasureMap<char> Tmap= readMap<char>(file_name, max_steps);
            for(int y =0; y < Tmap.getTotalSteps()-1; y++){
                Tmap.nextStep();
            }
        } else if (file_type == "location"){
            //FIX ME: Create a TreasureMap of type Location, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
            TreasureMap<Location> Tmap= readMap<Location>(file_name, max_steps);
            for(int z =0; z < Tmap.getTotalSteps()-1; z++){
                Tmap.nextStep();
            }        }
    }catch(const FileReadException &ex){
        std::cout << ex.getMessage() << std::endl;
        //FIX ME: prints out the exception message using getMessage() here
    }
    return 0;
}
