#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

/* ------------------------------------------------------ */
//constructor
MovieTree::MovieTree()
{
	root = NULL;
}


void deleteHelper(TreeNode* currNode){ //free memory that was allocated 
    if(currNode==NULL){
        return;
    }
    if(currNode->leftChild != NULL){
        deleteHelper(currNode->leftChild);
    }
    if(currNode->rightChild != NULL){
        deleteHelper(currNode->rightChild);
    }
    LLMovieNode* temp;
    LLMovieNode* crawler = currNode->head;
    
    while(crawler!=NULL){
        temp = currNode->head->next;
        delete currNode->head;
        currNode->head = temp;
        crawler = currNode->head;
    }
    currNode->head = NULL;
    delete currNode;
    return; 
}

//destructor
MovieTree::~MovieTree(){
    deleteHelper(root);
}


void printHelper(TreeNode* node){ //alphabetical order of titles
    if(node!= NULL){ //tree is not empty
        printHelper(node->leftChild); //left is always less than the right
        // for every TreeNode (t) in the tree
        cout << "Movies starting with letter: " << node->titleChar << endl;

        LLMovieNode* m = node->head;
        // for every LLMovieNode (m) attached to t
        while(m!=NULL){ //traverse
            cout << " >> " << m->title << " " << m->rating << endl;
            m=m->next;
        }
        printHelper(node->rightChild); //now prints the larger values
    }
}

void MovieTree::printMovieInventory(){
    printHelper(root);
}

//add in correct place based on title
TreeNode* addMovieHelper(TreeNode* &current, TreeNode* newNode)
{
   if (current == NULL){
       return newNode;
   }

   if (newNode->titleChar < current->titleChar){
       TreeNode* leftNode = addMovieHelper(current->leftChild, newNode);
       current->leftChild = leftNode;
       leftNode->parent = current;
   }
   
   else if (newNode->titleChar > current->titleChar){
       TreeNode* rightNode = addMovieHelper(current->rightChild, newNode);
       current->rightChild = rightNode;
       rightNode->parent = current;
   }
   else if (newNode->titleChar == current->titleChar){
       LLMovieNode* nodeToInsert = newNode->head;
       LLMovieNode* curr = current->head;
       LLMovieNode* prev = NULL;
       while(curr != NULL && curr->title.compare(nodeToInsert->title) < 0){
           prev = curr;
           curr = curr->next;
       }

       if(curr != NULL && curr->title.compare(nodeToInsert->title) == 0){
           return current; //same
       }
       else{
           if prev == NULL){
               nodeToInsert->next = current->head;
               current->head = nodeToInsert;
           }
           else if(curr == NULL){
               prev->next = nodeToInsert;
           }
           else{
               prev->next = nodeToInsert;
               nodeToInsert->next = curr;
           }
       }
   }

   return current;
} 

void MovieTree::addMovie(int ranking, std::string title, int year, float rating)
{
   LLMovieNode* newMovie = new LLMovieNode(ranking, title, year, rating);
   TreeNode* newNode = new TreeNode;
   newNode->titleChar = title[0];
   newNode->head = newMovie;
   newNode->leftChild = NULL;
   newNode->rightChild = NULL;
   newNode->parent = NULL;

   root = addMovieHelper(root, newNode);
}


TreeNode* deleteMovHelper(TreeNode* currNode, string title){
    //if the movie node does not exist
    if(currNode==NULL){ 
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return currNode;
    }
    
    if(title[0] < currNode->titleChar){ //less than, lies in left subtree
        currNode->leftChild = deleteMovHelper(currNode->leftChild, title);
    }
    else if(title[0] > currNode->titleChar){ //greater than, right traversal
        currNode->rightChild = deleteMovHelper(currNode->rightChild, title);
    }
    //we found the movie node 
    else{ 
        LLMovieNode* prev = NULL;
        LLMovieNode* pres = currNode->head;

        while(pres!=NULL && pres->title != title){ //traverse the LL
            prev = pres;
            pres = pres->next;

        }
        if(pres==NULL){
            cout << "Movie: " << title << " not found, cannot delete." << endl;
            return currNode;
        }

        if(prev == NULL && currNode->head->next != NULL){
            currNode->head = currNode->head->next;
            return currNode;
        }
        if(prev != NULL && pres != NULL){
            prev->next = pres->next;
            return currNode;

        }
        //no child
        if(currNode->leftChild == NULL && currNode->rightChild == NULL){
            delete currNode;
        }
        //only right child
        else if(currNode->leftChild == NULL){ 
            TreeNode* temp = currNode;
            currNode->rightChild->parent = currNode->parent; //adjust parent pointer
            currNode = currNode->rightChild;
            delete temp;

        }
        //only left child
        else if(currNode->rightChild == NULL){
            TreeNode* temp = currNode;
            currNode->leftChild->parent = currNode->parent;
            currNode = currNode->leftChild;
            delete temp;
        }
        //both left and right
        else{
            TreeNode* temp = currNode->rightChild;
            while(temp->leftChild != NULL){
                temp = temp->leftChild;
            }
            currNode->head = temp->head;
            currNode->titleChar = temp->titleChar;

            currNode->rightChild = deleteMovHelper(currNode->rightChild, temp->head->title);
        }
    }
    return currNode;

}


void MovieTree::deleteMovie(std::string title)
{
    deleteMovHelper(root, title);
}

void MovieTree::leftRotation(TreeNode* curr)
{
    TreeNode* node = curr->rightChild;
    curr->rightChild = node->leftChild;
    if(node->leftChild != NULL){
        node->leftChild->parent = curr;
    }
    node->parent = curr->parent;
    if(curr->parent == NULL){
        root = node;
    }
    else{
        if(curr == curr->parent->leftChild){
            curr->parent->leftChild = node;
        }
        else{
            curr->parent->rightChild = node;
        }
    }
    node->leftChild = curr;
    curr->parent = node;
}


//------ Given Methods--------//
void _grader_inorderTraversal(TreeNode * root)
{
	if (root == NULL) {
		return;
	}

	_grader_inorderTraversal(root->leftChild);
	cout << root->titleChar << " ";
	_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}



TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchChar(char key)
{
    return searchCharHelper(root, key);
}


 // LLMovieNode* crawler = currNode->head;
    // while(crawler != NULL){
    //     cout << "deleting: " <<
    // }