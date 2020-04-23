#ifndef BST_HPP
#define BST_HPP
#include <iostream>

struct Node{
    int key;
    Node* left;
    Node* right;
};

class BST{
    private:
     Node* root;
     Node* createNode(int);
     //since root is private, we need helper functions to access root for functions such as inserting, searching, and printing
     Node* insertNodeHelper(Node*, int);
     Node* searchHelper(Node*, int);
     void printTreeHelper(Node*);

     void destroyNode(Node *root);

    public:
     BST();                  //default constructor
     BST(int data);          //parameterized constructor
     ~BST();                 //destructor

     void insertNode(int);   
     bool search(int);
     void printTree();
};

#endif