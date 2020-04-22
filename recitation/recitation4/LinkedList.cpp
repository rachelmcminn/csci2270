#include "LinkedList.h"

using namespace std;

//head is the first 
//next pointer stores the address of the next node in the list (links them all)

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){ 

  //Check if head is Null i.e list is empty
  if(head == NULL){ //edge case; if linked list is empty
    head = new Node; //create a new node at the head
    head->key = newKey; 
    head->next = NULL; 
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL){ //inserting at the beginning of the linked list 
      Node* newNode = new Node; 
      newNode->key = newKey; 
      newNode->next = head; 
      head = newNode;
  }

  else{
      Node* newNode = new Node; //allocate memory for new node
      newNode->key = newKey; //update the key in it
      newNode->next = prev->next; //update the next pointers for newNode and prev
      prev->next = newNode; 

    }
  }

//node at index 0 is key 1 (head node) if this is 
//node at index 1 is key 2
//node at index 3 is key 4

// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  // Special case to delete the head
    if (n == 0){ //index 0
        //TODO
        Node *temp = head; //store head in temp 
        head = head->next; //head pointer points to the next index
        delete temp; //free the memory allocated w the head node
        return true;
    }

  Node *pres = head;
	Node *prev = NULL;

    // TODO
    if(n != 0){
      int count = 0;
      while(pres->next != NULL && count < n){
        prev = pres; //previous (null) equals head (right before it)
        pres = pres->next; //pres equals pres next, the next element in index
        count++;
      }
      prev->next = pres->next;
      delete pres;
      isDeleted = true;
    }
    
	return isDeleted;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    if(head == NULL) { 
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }

    // TODO (take care of the edge case when your linkedlist has just 2 nodes)
    Node *temp = head->next; //temp equals index 1
    if(temp->next == NULL){ //if index two does not exist
      Node * temp2 = head; //temp 2 = 
      head = temp;
      head->next = temp2;
      temp2->next = NULL;
    }
    else{
      


    }

    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){ //while temp is not equal to null
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;  //once its found, set it equal
    }
    return ptr; //return found 
}


//pres->next = previous;

// if(n != 0){
//       int count = 0;
//       while(pres != NULL && count < 0){
//         prev->next = pres->next;
//         delete pres;
//         count++;
//       }
      
//     }
    