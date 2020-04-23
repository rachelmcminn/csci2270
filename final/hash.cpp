#include "hash.hpp"
#include <iostream>
using namespace std;


//constructor
HashTable::HashTable(int bsize){
    tableSize = bsize;
    table = new node*[tableSize];

}

//create node
//for inserting items into table
node* HashTable::createNode(int key, node* next){
    node* newNode = new node;
    newNode->key = key;
    newNode->next = next;
    return newNode;
}

//insert
//returns true if item was successfully inserted
bool HashTable::insertItem(int key){
    if(!searchItem(key)){ //if key is not found in search, insert into index
        int idx = hashFunction(key); //get index for key
        node* temp = createNode(key, NULL); //create a node with that key
        table[idx] = temp;  //insert the node at that index in the table
        return true;
    }
    //otherwise, key already exists in table
    else{
        cout<<"duplicate entry: "<< key <<endl;
        numOfcolision++;
        return false;
    }

}


unsigned int HashTable::hashFunction(int key){
    return key % tableSize;
}

void HashTable::printTable(){
    for(int i = 0; i < tableSize; i++){
        cout << i << "-> ";
        node* temp = table[i];
        while (temp != NULL) {
          cout << temp->key << "  ";
          temp = temp->next;
        }
    }
}


int HashTable::getNumOfCollision(){
    cout << "total number of collisions: " << numOfcolision << endl;
   return numOfcolision;
}


//search hash table
node* HashTable::searchItem(int key){
    node* temp = new node; //points to node in hash table with corresponding key
    
    int idx = hashFunction(key); //calculates index (idx)
    if(table[idx] != NULL){ //if array is not null at that index
        temp = table[idx];
        
        while(temp!=NULL){ //traverse the chain to find the key 
            if(temp->key == key){ // if key matches search key - found!
                return temp; //return found value
            }
            else{ //otherwise, update temp to keep searching
                temp = temp->next; 
            }
        }
    }
    //returns null if the table at that index is null
    return NULL;
}


// while(temp->key != key && temp->next != NULL){
//         temp = temp->next;
// }
//     return temp;
// } 
// else{
//       return NULL;
// }

