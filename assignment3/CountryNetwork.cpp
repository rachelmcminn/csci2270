/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;


/*
 * This function will insert an element to an array at the smallest vacant index. 
 * If array is full, the function should perform array doubling and then insert the element to the new array.
 * @return true if array doubling was performed, otherwise false
 */
//str_arr is an array in which you insert elements. A reference to this array pointer is passed to your function.
//s is the new string you want in your array
//numEntries keeps track of the number of elements that have been inserted in your array
//arraySize is the current size of your arrray

// bool append(string* &str_arr, string s, int &numEntries, int &arraySize)
// {
//     //TODO: Complete this function
//     if(numEntries-1 == arraySize){ //if array is full
//         //doubling array
//         int newSize = arraySize*2;
//         string *double_arr = new string[newSize]; //allocate memory for a dynamic array that is 2n long
    
//         for(int i=0; i < arraySize; i++){ //traverse thru to copy the contents of the first array into the second array
//            double_arr[i] = str_arr[i]; 
//            str_arr[i] = s;
//         }
        
//         delete [] str_arr; //return memory to heap
//         str_arr = double_arr; //assign old array to point to new array
//         arraySize = newSize; //update the size
//         return true;
//     }
    
//     else{ // if array is not full
//         str_arr[numEntries] = s;
//         numEntries++;
//     }
//     return false;
    
// }

// //---------------------------------------------------------------
// bool append(string* &str_arr, string s, int &numEntries, int &arraySize)
// {
//     if(numEntries-1 == arraySize) { // if array is full
//         int newSize = arraySize * 2;
//         string* newArray = new string[newSize];
//         for(int i=0; i < arraySize; i++) {
//             newArray[i] = str_arr[i];
//         }
//         delete[] str_arr;
//         str_arr = newArray;
//         //arraySize = newSize;
//         return true;
//     }
//     else{
//         str_arr[numEntries] = s;      
//     }
//         return false;
//     } 
// }
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = NULL;

}

/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    // TODO: Complete the definition

       if(head == NULL){ //if list is empty
        head = new Country;
        head->name = countryName;
        head->next = nullptr;
        cout << "adding: " << countryName << " (HEAD)" << endl;
    }
    else if(previous == NULL){
        Country* new_node = new Country;
        new_node->name = countryName;
        new_node->next = head;
        head = new_node;
        cout << "adding: " << countryName << " (HEAD)" << endl;
    }
    else{
        Country* new_node = new Country;
        new_node->name = countryName;
        new_node->next = previous->next;
        previous->next = new_node;
        cout << "adding: " << countryName << " (prev: " << previous->name <<
        ")" << endl;
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    // TODO
    Country* US = new Country;
    US->name = "United States"; //assigns the struct element
    head = US;
    cout << "adding: United States (HEAD)" << endl;

    Country* Canada = new Country;
    Canada->name = "Canada";
    head->next = Canada;
    cout << "adding: Canada (prev: United States)" << endl;

    Country* Brazil = new Country;
    Brazil->name = "Brazil";
    Canada->next = Brazil;
    cout << "adding: Brazil (prev: Canada)" << endl;

    Country* India = new Country;
    India->name = "India";
    Brazil->next = India;
    cout << "adding: India (prev: Brazil)" << endl;

    Country* China = new Country;
    China->name = "China";
    India->next = China;
    cout << "adding: China (prev: India)" << endl;

    Country* Australia = new Country;
    Australia->name = "Australia";
    China->next = Australia;
    cout << "adding: Australia (prev: China)" << endl;

}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    // TODO
    Country* search = head; //declare variable at the head 
    while(search != NULL && search->name != countryName){ //loop thru to look for name
        search = search->next; //if found, updated
    }
    return search; //null if not found
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    // TODO
    
    if(head == NULL){ //if list is empty
        cout << "Empty list" << endl;
        return;
    }

    if(head != NULL && searchNetwork(receiver) == NULL){ //if list is not empty but the node is not found
        cout << "Country not found" << endl;
        return;
    }

    else{
        Country* node = head;
        while(node != NULL && node->name != receiver){ //traverse the list
            node->message = message;
            node->numberMessages += 1;
            cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message << endl;
            node = node->next; //increment
        }

        if(node->name == receiver){
            node->message = message;
            node->numberMessages += 1;
            cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message << endl;
        }
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    // TODO
    Country* node = head;
    cout << "== CURRENT PATH ==" << endl;

    if(node == nullptr){ //if list is empty
        cout << "nothing in path" << endl;
    }
    else{ 
        while(node != nullptr){ //while node is not empty
            cout << node->name << " -> "; //print the current list
            node = node->next; //points to next node in path
        }
        cout << "NULL" << endl;
    }
    
    cout << "===" << endl;
}

