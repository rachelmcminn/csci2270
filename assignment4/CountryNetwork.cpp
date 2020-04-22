/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
/* finished. do not touch. */
    head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) {
    
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        cout << "adding: " << countryName << " (HEAD)" << endl;
        head = new Country;
        head->name = countryName;
        head->numberMessages = 0;
        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL )
    {
        //case where it's a new head Country
        cout << "adding: " << countryName << " (HEAD)" << endl;
        Country *c = new Country;
        c->name = countryName;
        c->numberMessages = 0;
        c->next = head;
        head = c;
    }else{
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        Country *newCountry = new Country;
        newCountry->name = countryName;
        newCountry->numberMessages = 0;
        newCountry->next = previous->next;
        previous->next = newCountry;
    }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {
    //TODO: Complete this function
    if(searchNetwork(countryName) == NULL)
    {
        cout << "Country does not exist." << endl;
        return;
    }

    Country* crawler = head;
    if(head->name == countryName){ //if country to be deleted is the head
        Country* temp = new Country; 
        crawler = head;
        head = head->next;
        delete crawler;
    }
    else{
        while(crawler->next->name != countryName){
            crawler = crawler->next;
        }
        crawler->next = crawler->next->next;
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    int num_countries = 6;
    string countries[] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    // deleteEntireNetwork();
    Country* prev = NULL;
    for(int i = 0; i < num_countries; i++)
    {
        insertCountry(prev, countries[i]);
        prev = searchNetwork(countries[i]);
    }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
// Search until the head is NULL, or we find the country
    Country* ptr = head;
    while (ptr != NULL && ptr->name != countryName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
* Purpose: Creates a loop from last node to the country specified.
* @param countryName name of the country to loop back
* returns pointer to last node before loop creation (to break the loop)
*/
Country* CountryNetwork::createLoop(string countryName)
{
    //TODO: Complete this function
    Country* node = head;
    Country* ptr = NULL;
    Country* temp;
    
    while(node != NULL){  //traverse thru list
        if(node->name == countryName){  //if node is found,
            ptr = node;                   
        } 
        temp = node; 
        node = node->next;  
    }
    if(ptr != NULL){
        temp->next = ptr;
    }
    
    //return last node
    return temp;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    //TODO: Complete this function
    Country* node = head;

    if(head == NULL){
        return;
    }
    else{
        while(node != NULL){
            Country* temp = new Country;
            cout << "deleting: " << node->name << endl;
            temp = node->next;
            delete node;
            node = temp;

        }
    }
    head = NULL;
    if(head == NULL){
        cout << "Deleted network" << endl;
    }
}

/*
*Purpose: to detect loop in the linkedlist
* @param
* returns true if loop is detected. Otherwise return false.
*/
bool CountryNetwork::detectLoop() {
    //TODO: Complete this function

    Country* fast = head;
    Country* slow = head;
    
     while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            return true;
        }
    }
    return false;
}

/*
* Purpose: Take the chunk of nodes from start index to end index
*          Move that chunk at the end of the List
*@param: start index
*@param: end index
* return none

Manipulate next pointers to readjust the linked list. 
Here, startIndex is index of a node
from starting. Similarly endIndex is index of a node from beginning. The function will
send the chunk of the link list between start index and end index at the end of the linked
list. Consider the node at head as index 0.

For example, if you have linked list like this: “A -> B -> C -> D -> E-> NULL”,
and startIndex=1 and endIndex=3, then the linked list after readjustNetwork should be
“A -> E -> B -> C -> D-> NULL”.
If you have linked list like this: “A -> B -> C -> D -> NULL”, and startIndex=0
and endIndex=2, then the linked list after readjustNetwork should be “D-> A -> B ->
C -> NULL”. Here, “D” is the new head.

➔ If the linked list is empty, print “Linked List is Empty”.
➔ If endIndex is bigger than the number of nodes in the linked list or smaller than 0, then
print “Invalid end index”.
➔ endIndex should be lesser than the index of the last element in the linked list.
Otherwise print “Invalid end index”.
➔ If startIndex is bigger than the number of nodes in the linked list or smaller than 0, then
print “Invalid start index”.
➔ If startIndex > endIndex print “Invalid indices”.
*/



void CountryNetwork:: readjustNetwork(int start_index, int end_index)
{
    //TODO: Complete this function
    Country* node = head;
    if(node == NULL){
        cout <<  "Linked List is Empty" << endl;
        return;
    }

    if(start_index > end_index){
        cout << "Invalid indices" << endl;
        return;
    }

    int length = 0;
    while(node != NULL){
        node = node->next;
        length++;
    }
    if(end_index < 0 || end_index > length)
    {
        cout << "Invalid end index" << endl;
        return;
    }
    if(start_index < 0 || start_index > length){
        cout << "Invalid start index" << endl;
        return;
    }

    Country* newnode = head; //index 0
    Country* prev = NULL;
    int count = 0;
    Country* prev_;
    Country* current;
    Country* last;
    
    while(newnode != NULL){
        if(count == start_index){
            prev_ = prev;
            current = newnode;
        }
        if(count == end_index){
            last = newnode;
        }
        prev = newnode;
        newnode = newnode->next;
        count++;
    }
    prev->next = current;
    Country* temp = last->next;
    last->next = NULL;

    if(start_index == 0){
        head = temp;
    }
   else{
        prev_->next = temp;
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    Country* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr->next != NULL)
        {
            cout << ptr->name << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
