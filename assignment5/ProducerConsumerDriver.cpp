/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{	
	string option;
	int input;
	ProducerConsumer pc;
	
	while(option != "3"){
		menu();
		getline(cin, option);
		input = stoi(option);

		switch(input){
			case 1: //producer (produce items to the queue) (enqueue operation)
			{
				int numItems; //number of items user wants to produce
				int itemNo = 1; //keeps track of the items entered
				string produceItems; //input
				string inputItems;

				cout << "Enter the number of items to be produced:" << endl;
				getline(cin, produceItems);
				numItems = stoi(produceItems);

				while(itemNo <= numItems){ //loop for user to enter each item to be produced
					cout << "Item" << itemNo << ":" << endl; //prompt user to enter each item
					getline(cin, inputItems);
					pc.enqueue(inputItems); //enqueue each item to the queue
					itemNo++; //increase count of items user enters
				}

				break;
			}

			case 2: //consumer (consume items from queue)(dequeue operation)
			{
				string consumeItems; //input - num of items user wants to consume
				int numItems; //number of items user wants to consume
				int count = 0;

				cout << "Enter the number of items to be consumed:" << endl;
				getline(cin, consumeItems);
				numItems = stoi(consumeItems);
				cin.clear();

				if(numItems > pc.queueSize()){ //while items to be consumed is greater than total items in queue
					numItems = pc.queueSize();
					
					while(count < numItems){
						cout << "Consumed: " << pc.peek() << endl;
						pc.dequeue(); //dequeue
						count++;
					}
					cout << "No more items to consume from queue" << endl;
				}
				else{
					while(count < numItems){
						cout << "Consumed: " << pc.peek() << endl;
						pc.dequeue(); //dequeue
						count++;
					}
				}

				break;
			}

			case 3:
			{
				cout << "Number of items in the queue:" << pc.queueSize();
				return 0;

			}
		
		}
	}
	return 0;
}