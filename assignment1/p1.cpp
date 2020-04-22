//CSCI 2270
//

using namespace std;
#include <fstream>
#include <string>

//write a program that reads up to 100 numbers from a file. as the file is read, store the values
//into array in a descending order

int insertIntoSortedArray(float myArray[100], int numEntries, float newValue){ //sorts collected numbers from file into an array
    int count = numEntries;

    while(myArray[count-1] > newValue && count >= 0){
        myArray[count] = myArray[count-1];
        count--; 
    }
    myArray[count] = newValue;
    
    for(int i=0; i<= numEntries; i++){
        if(i==0){
            cout<<myArray[i];
        }
        else{
            cout << ",";
            cout << myArray[i];
        }  
    }
    cout << endl;
    numEntries++;
    return numEntries; 
}

int main(int argc, char const *argv[]){
    float temp[100]; //array of numbers, size 100
    fstream file; //initialize input file
    file.open(argv[1]); //opens the file

    if(file.fail()){ //if file fails to open for any reason
        cout << "Failed to open the file." << endl;
    }

    string line, num;
    int i=0;
    int entries;


    if(file.is_open()){ //if file opens successfulyy
        while(getline(file, line)){ //read file line by line
            line = stof(line);
            insertIntoSortedArray(temp[100], entries, line); //stoi?
            entries++;
        }

    }
    file.close();
}

/*

while(myfile >> number){
    i++;
    for(int j=0;j<i;j++)
        cout << numbersArr[j] << ",";
            cout<< "\n";

}


*/

/*
int insertIntoSortedArray(float myArray[100], int numEntries, float newValue){ //sorts collected numbers from file into an array
    int count = numEntries;
    float temp;
    
    while(myArray[count+1] > newValue && count >= 0){
        myArray[count+1] = myArray[count];
        count++; 
    }
    myArray[count+1] = newValue;
    
    numEntries++;
    return numEntries;
}

*/

/* inserts into ascending order
int insertIntoSortedArray(float myArray[100], int numEntries, float newValue){ //sorts collected numbers from file into an array
    int i;
    for(i=0; i < numEntries; i++){
        if(myArray[i] > newValue){
            for(int j = numEntries; j > i; j--){
                myArray[j] = myArray[j-1];
            }
            break;
        }
    }
    myArray[i] = newValue;
    return numEntries+1;
}

*/

/*
int insertIntoSortedArray(float myArray[100], int numEntries, float newValue){
    int count; // number at certain index
    for(i = 1; i < numEntries; i++){
        count = myArray[i];
        
        for(j = i - 1; (j >= 0) && (myArray[j] < count); j--){
            num[j+1] = num[j]; // traverse through array
        }
        num[j+1] = count;
    }
    numEntries++;
    return numEntries;
}