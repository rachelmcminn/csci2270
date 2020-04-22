#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

ProducerConsumer::ProducerConsumer(){
    queueFront = 0;
    queueEnd = 0;
}

bool ProducerConsumer::isEmpty(){
    bool empty = false; //declare
    for(int i=0; i < SIZE; i++){ //loops thru array
        if(queue[i] == ""){ //if array at that index is empty
            empty = true;

        }
        else{
            return false;
        }
    }
    return empty;
}

bool ProducerConsumer::isFull(){
    bool full = false; //declare
    for(int i = 0; i < SIZE; i++){ //loops thru indices
        if(queue[i] == ""){ //if empty
            return false;
        }
        else{
            full = true;
        }
    }
    return full;
}

void ProducerConsumer::enqueue(std::string item){
    //if queue is not full, add item to the end of queue
    if(!isFull()){
        queue[queueEnd] = item;
        queueEnd++;
        //if the last item of the queue is num 20, its the last of the array, so modify to make circular
        if(queueEnd == 20){
            queueEnd = queueFront;
        }
         counter++;
         
    }
    else{
        cout << "Queue full, cannot add new item" << endl;
        queueEnd = queueFront; //circular array
    }
}

void ProducerConsumer::dequeue(){
    //remove first item from queue if queue is not empty
    if(!isEmpty()){
        queue[queueFront] = "";
        queueFront ++;
        
        if(queueFront == 20){
            queueFront = 0;
        }
        counter--; //update size
    }
    else{
        cout << "Queue empty, cannot dequeue an item" << endl;
    }
}

int ProducerConsumer::queueSize(){
    //return num of items in the queue
    return counter;
}

string ProducerConsumer::peek(){
    if(isEmpty()){
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }
    else{
        return queue[queueFront];
    }
}
