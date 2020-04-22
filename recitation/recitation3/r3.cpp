

int main(int argc, char* argv[]){
    
    int * dynamicArray = NULL;
    
    int sizeOfDynamicArray = stoi(argv[1]);
    
    dynamicArray = new int[sizeOfDynamicArray];

    for(int i=0; i < sizeOfDynamicArray; i++){
        dynamicArray[i] =i;
    }

    for(int i=0; i< sizeOfDynamicArray; i++){
        cout << dynamicArray[i] << endl;
    }

    delete [] dynamicArray; //deallocates the memory
    
    dynamicArray = NULL; //pointer loses address of the first element in array

    //cout << dynamicArray; //would print address; address is still stored but the memory is no longer accessible
}

// ./a.out 10