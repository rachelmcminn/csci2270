#ifndef LL_HPP
#define LL_HPP

#include <iostream>

struct Node{
    int key;        //key of node (tracking ID)
    Node *next;     //pointer to next node
};

class LL{
    private:
     Node *head;    //pointer to head of linked list

    public:
     LL();
     bool isEmpty(); 
     void insertNode(Node* left, int id);
     Node* search(int key);
     void display();
     void traverse();
     void deleteNode(int value);

};

#endif
