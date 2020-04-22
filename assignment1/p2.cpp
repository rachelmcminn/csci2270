#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
using namespace std;

/*
write a program that reads a .csv file with up to 100 lines and columns containing info,
stores the info in an array of structs, 
write the lines into the output .csv file with bounds
print contents of entire array
*/

// length: Number of items currently stored in the array
//void addPark(Park parks[], string parkname, string state, int area, int length);

// length: Number of items in the array
//void printList(const Park parks[], int length);

struct Park{
    string parkname;
    string state;
    int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length){
    Park park;
    park.parkname = parkname;
    park.state = state;
    park.area = area;
    parks[length] = park;
    length++;
}

void printList(const Park parks[], int length){
    for(int i=0; i<length; i++){
        cout << parks[i].parkname << " [" << parks[i].state << "] " << "area: "<< parks[i].area << endl;
    }
}

int main(int argc, char *argv[]){
    Park parks[100];
    ifstream inFile;
    inFile.open(argv[1]);

    string line, parkname, state, _area;
    int area;
    int j=0;
    while(getline(inFile, line)){
        stringstream s(line);
        getline(s, parkname, ',');
        getline(s, state, ',');
        getline(s, _area, ',');
        area = stoi(_area);
        addPark(parks, parkname, state, area, j);
        j++;
    }

    printList(parks, j);
    
    int lower_bound = stoi(argv[3]);
    int upper_bound = stoi(argv[4]);
    
    ofstream out;
    out.open(argv[2]);
    for(int i=0; i<j; i++){
        if(parks[i].area >= lower_bound && parks[i].area <= upper_bound){
            out <<parks[i].parkname<< ","<< parks[i].state << "," <<parks[i].area<<endl;
        }
    }
    out.close();
    return 0;

}