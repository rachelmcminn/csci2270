#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

// Constructor: Initialize any member variables of the class to default
MovieTree::MovieTree() {
  //write your code
  root = NULL; //initialize variable to default
}

void deleteNodeHelper(MovieNode* currNode){
    if(currNode!=NULL){
      deleteNodeHelper(currNode->left);
      deleteNodeHelper(currNode->right);

      delete currNode;
      currNode = NULL;
    }

}

//Destructor: Free all memory that was allocated
MovieTree::~MovieTree() {
  //write your code
  deleteNodeHelper(root);
}

//print every node in the tree in alphabetical order of titles
//helper implemented
void printHelper(MovieNode* node){
  if(node!= NULL){ //if tree is not empty
    
    if(node->left != NULL){ //if parent has a left child
      printHelper(node->left); //recursion
    }
    
    // for every Movie node in the tree
    cout << "Movie: " << node->title << " " << node->rating << endl;

    if(node->right != NULL){ //if parent has a right child
      printHelper(node->right); //recursion
    }
  }
}

void MovieTree::printMovieInventory() { 
  //if there is no movie in the tree
  if(root == NULL){
    cout << "Tree is Empty. Cannot print" << endl;
    return;
  }
  else
  //call the printHelper function to actually print the values
    printHelper(root);

}

MovieNode* addNodeHelper(MovieNode* currentNode, MovieNode* newNode){
  if(currentNode == NULL){
    return newNode;
  }
  //if not empty, check if node will be right or left child
  else if(currentNode->title < newNode->title){
    currentNode->right = addNodeHelper(currentNode->right, newNode);
  }
  else if(currentNode->title > newNode->title){
    currentNode->left = addNodeHelper(currentNode->left, newNode);
  }
  return currentNode;
  
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  MovieNode* newNode = new MovieNode(ranking,title,year,rating); //allocating memory for the node
  
  if(root == NULL){
    root = newNode;
  }
  else{
    MovieNode* node = addNodeHelper(root, newNode);
    newNode = node;
  }

}

MovieNode* searchHelper(MovieNode* currNode, string title){
  if(currNode == NULL){ //list is empty
    return NULL;
  }
  if(currNode->title == title){
    return currNode;
  }
  if(currNode->title > title){ //go left
    return searchHelper(currNode->left, title);
  }
  //otherwise go right
  return searchHelper(currNode->right, title); 
}

void MovieTree::findMovie(string title) {
   //call helper function
    MovieNode* found = searchHelper(root, title); 
    
    if(found == NULL){
     cout << "Movie not found." << endl;
    }
    else{
      cout << "Movie Info:" << endl;
      cout << "==================" << endl;
      cout << "Ranking:" << found->ranking << endl;
      cout << "Title :" << found->title << endl;
      cout << "Year :" << found->year << endl;
      cout << "rating :" << found->rating << endl;
    }
}

float rate = 0.0;
int yr = 0;
void preOrder(MovieNode* m){ //preorder traversal
  if(m !=NULL){ //while the movie exists
    if(m->rating > rate && m->year > yr){
      cout << m->title << "(" << m->year << ") " << m->rating << endl;
    }
    preOrder(m->left);
    preOrder(m->right);

  }
}

void MovieTree::queryMovies(float rating, int year) { //print all movies depending on conditions
  if(root==NULL){ //if there is no movie entry in the tree 
    cout << "Tree is Empty. Cannot query Movies" << endl;
  }
  else{
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    yr = year; //update year
    rate = rating; //update rating
    preOrder(root); //call preOrder traversal to print from root 
  }
}

float printAvgHelper(MovieNode* m, float& total){
  if(m == NULL){
    return;
  }
  else{ //traverse
    printAvgHelper(m->left, total);
    total = total + m->rating;
    printAvgHelper(m->right,total);
  }
}

float getTotal(MovieNode* m){ //gets total number of values that are valid 
  if(m==NULL){
    return 0;
  }
  return(getTotal(m->right)+getTotal(m->left) + 1);

}

void MovieTree::averageRating() {
  //write your code
  float total = 0.0;

  if(root == NULL){ //if there is no movie entry in the tree
    cout << "Average rating:0.0" << endl;
  }
  else{
    printAvgHelper(root, total);
    float totalNum = getTotal(root);
    float average = total / totalNum;
    cout << "Average rating:" << average << endl;
  }
}

void printLevelHelper(MovieNode* m, int k){
  if(root == NULL){
    return;
  }
  if(k == 0){
    // for every Movie node (m) in the tree
    cout << "Movie: " << m->title << " " << m->rating << endl;
    return;
  }
  else{
    printLevelHelper(m->left, k-1);
    printLevelHelper(m->right, k-1);
  }
}

void MovieTree::printLevelNodes(int level) {
  //write your code
  printLevelHelper(root, level);

}