#include "BST.hpp"
#include <iostream>
using namespace std;


//create a node with key as data
Node* BST::createNode(int data){
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//parameterized contructor - will create the root and put the data in 
BST::BST(int data){
    root = createNode(data);
    cout << "New tree created with " << data <<endl;
}


//destructor - ensures used memory is correctly deallocated
BST::~BST(){
    destroyNode(root); 
}

//will destroy the subtree rooted at currNode (postorder)
void BST:: destroyNode(Node *currNode){ 
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
}



//-------------------------insert node----------------------
//adds the data into the tree rooted at currNode
Node* BST::insertNodeHelper(Node* currNode, int data){
    //base case: empty tree
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){ //if data is larger than key, goes on right side of bst
        currNode->right = insertNodeHelper(currNode->right,data); //recursion
    }
    else if(currNode->key > data){ //if data is less than key, goes on left side of bst
        currNode->left = insertNodeHelper(currNode->left, data);
    }
    return currNode; //returns inserted node

}

void BST::insertNode(int id){
    root = insertNodeHelper(root, id);
    cout << id << "has been added." << endl;
}  



//---------------------------search------------------------
//searches the data in the tree to find specific key
Node* BST::searchHelper(Node* currNode, int data){
    //base case; currNode is null (empty)
    if(currNode == NULL){
        return NULL;
    }
    if(currNode->key == data){ //key is found
        return currNode; //return node associated with that key
    }
    //if the data is smaller than the key, it lies on the left side 
    if(currNode->key > data){ 
        return searchHelper(currNode->left,data); //recursion to search left subtree
    }
    //otherwise go right
    return searchHelper(currNode->right,data);

}

bool BST::search(int key){
    Node* found = searchHelper(root, key);
    if(found != NULL){
        return true;
    }
    cout << "key not found"<< endl;
    return false;

}

//---------------------------print tree----------------------
//performs an in-order traversal of the tree to print out node values

void BST::printTreeHelper(Node* currNode){
    if(currNode){ //if tree is not empty
        printTreeHelper(currNode->left); //recursion
        cout << " " << currNode->key << endl;
        printTreeHelper(currNode->right); //recursion
    }

}

void BST::printTree(){
    printTreeHelper(root);
    cout << endl;

}

int main(){

}