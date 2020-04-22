/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>

void displayMenu();  // declaration for main's helper-function

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
CountryNetwork cn;
    string input;
    int inputNum = 0;
    

    while(input != "5"){
        displayMenu();
        getline(cin, input);
        inputNum = stoi(input);

    switch(inputNum){
        case 1: { //build network
            cn.loadDefaultSetup();
            cn.printPath();
            break;
        }

        case 2: { //print network path
            cn.printPath(); //call the printPath function
            break;
        }

        case 3: { //transmit message
            cout << "Enter name of the country to receive the message:" << endl; //prompt user for name of country to send message
            string country;
            getline(cin, country);
            cin.clear();
            cout << "Enter the message to send:" << endl; //prompt user for message
            cout << endl;
            string message;
            getline(cin, message);
            cin.clear();
            cn.transmitMsg(country, message); //pass message and country name to transmitMsg function
            break;
        }
        
        case 4: { //add country
            int count = 0;
            cout << "Enter a new country name:" << endl; //prompt user for new country to add to the network
            string newCountry;
            getline(cin, newCountry);
            cin.clear();
            cout << "Enter the previous country name (or First):" << endl; //prompt user for the previous country that will precede the new one
            string previous;
            getline(cin, previous);
            //cin.clear();
            
            newCountry[0] = toupper(newCountry[0]);
            previous[0] = toupper(previous[0]);

            if(previous == "First"){ //if user wants to add the new country to the head 
                cn.insertCountry(NULL, newCountry);
                count = 1;
            }
            
            Country *ptr = cn.searchNetwork(previous);

            if(count == 0){
                while(ptr == NULL){
                cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                getline(cin, previous);
                ptr = cn.searchNetwork(previous);
                cin.clear();
                previous[0] = toupper(previous[0]);
                count = 1;
                }
            }

            if(previous != "First"){
                cn.insertCountry(ptr, newCountry);
            }
            
            cn.printPath();
            break;
        }

        case 5: { //quit
            cout << "Quitting..." << endl;
            cout << "Goodbye!" << endl;
            break;
        }
        default: {
            cout << "Invalid Input" << endl;
        }
    }
}

    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
