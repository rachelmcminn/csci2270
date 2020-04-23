#include "hash.hpp"
#include <iostream>
using namespace std;


int main()
{
    int a[] = {15, 11, 27, 8, 12, 7, 18, 8};
    int n = 8;

    // 7 is count of buckets in hash table
    HashTable ht(8);

    // insert the keys into the hash table.
    // SILVER TODO : Complete insertItem() function
    for (int i = 0; i < n; i++) {
        ht.insertItem(a[i]);
    }

    cout<< "Contents of the hash table are: "<<endl;
    // SILVER TODO : Complete printTable() function
    ht.printTable();

    cout<<endl;

    int searchFor = 11;
    // SILVER TODO : Complete searchItem() function
    if(ht.searchItem(searchFor))
     {
       cout<<searchFor<<" found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" not found in the hash table"<<endl;
    }
    cout<<"------------------------------------"<<endl;

    //int sum = 19;
    ht.getNumOfCollision();


    return 0;
}