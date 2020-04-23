#include "LL.hpp"

using namespace std;


//constructor for empty linked list
LL::LL(){
    head = NULL;
}


//checks if linked list is empty 
//return true if empty; otherwise false
bool LL::isEmpty(){
    return (head == NULL);
}


//add new ID number to the list
void LL::insertNode(Node *left, int id){
    //edge case: check if head is null i.e. list is empty
    if(head == NULL){
        cout << "adding: " << id << " (HEAD)" << endl;
        head = new Node;
        head->key = id;
        head->next = NULL;
    }

    //if list is not empty, look for previous(left) and append node there
    else if(left == NULL){ //inserting at the beginning of LL
        cout << "adding: " << id << " (HEAD)" << endl;
        Node* newNode = new Node;
        newNode->key = id;
        newNode->next = NULL;
        head = newNode;
    }
    else{
        cout << "adding: " << id << " (prev: " << left->key << ")" << endl;
        Node* newNode = new Node;   //allocate memory for new node
        newNode->key = id;          //update key value (id number)
        newNode->next = left->next; //update the next pointers for newNode and left node
        left->next = newNode;
    }

}

//search for specific id number (key of node) and return a pointer to that node
Node* LL::search(int key){
    Node* ptr = head;
    //search until head is null or id is found
    while(ptr != NULL && ptr->key != key){
        ptr = ptr->next; //once its found, set pointer 
    }
    return ptr;
}


//print the keys (id numbers) of the linked list 
void LL::display(){
    cout << "CURRENT LIST: " << endl;
    Node* temp = head;
    
    if(isEmpty() == true){//if list is empty
        cout << "nothing in list" << endl;
    } 
    //otherwise, print list
    else{
        while(temp->next != NULL){
            cout << temp->key << " -> ";
            temp = temp->next;
        }
        cout << temp->key << endl;
        cout << "end of path";
    }
}