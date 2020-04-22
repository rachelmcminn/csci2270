#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

//write a program to analyze the word frequency in a document
//implementing a dynamically doubling array to store the necessary info

struct wordItem {
string word;
int count;
};

/*This function should read the stop words from the file with the name stored in
ignoreWordFileName and store them in the ignoreWords array. You can
assume there will be exactly 50 stop words. There is no return value
*/
void getStopWords(const char *ignoreWordFileName, string ignoreWords[]){
    ifstream file;
    string line;
    int i=0;
    string line="";
    file.open(ignoreWordFileName);
    if(file.is_open()){
        while(getline(file,line)){
            ignoreWords[i] = line;
            i++;
        }
    }
    else{
        cout << "Failed to open " << ignoreWordFileName << endl;
    }

}

//This function should return whether word is in the ignoreWords array.
bool isStopWord(string word, string ignoreWords[]){
    int n=1;
    for(int i=0; i < 50; i++){
        if(word == ignoreWords[i]){
            n = 0;
        }
    }
    if(n == 0){
        return true;
    }
    else if(n == 1){
        return false;
    }
}


/*This function should compute the total number of words in the entire document
by summing up all the counts of the individual unique words. The function should
return this sum
*/
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
    int count = 0;
    for(int i=0; i < length; i++){
        int sum;
        sum = uniqueWords[i].count;
        count += sum;
    }
    return count;
}

/*
sort the uniqueWords array (which contains length
initialized elements) by word count such that the most frequent words are sorted
to the beginning. 
*/
void arraySort(wordItem uniqueWords[], int length){
    int frequency;
    string word_;
    for(int i=0; i < length; i++){
        for(int j=1; j < length; j++){
            if(uniqueWords[j-1].count < uniqueWords[j].count){
                frequency = uniqueWords[j].count;
                uniqueWords[j].count = uniqueWords[j-1].count;
                uniqueWords[j-1].count = frequency;
                word_ = uniqueWords[j].word;
                uniqueWords[j].word = uniqueWords[j-1].word;
                uniqueWords[j-1].word = word_;
            }
        }
    }
}

/*
should print the next 10 words after the starting index N from
sorted array of uniqueWords. These 10 words should be printed with their
probability of occurrence up to 4 decimal places
*/
void printNext10(wordItem uniqueWords[], int N, int totalNumWords){
    for(int i=N; i < N+10; i++){
        float probability = float(uniqueWords[i].count) / float(totalNumWords);
        cout << fixed << setprecision(4) << probability;
        cout << " - " << uniqueWords[i].word << endl;

    }

    //probability-of-occurrence = (float) uniqueWords[ind].count / totalNumWords
}

int main(int argc, char *argv[]){
    if(argc > 3){ //the correct number of command arguments arent passed, print below and exit program
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    }
    
    wordItem *wi = new wordItem[100];//array-doubling should be done in main function
    string *endArray = new string[50];
    wordItem *unique new wordItem[size];
    string ignoreWords[50]; 
    
    int n = 100;
    int count = 0;
    int total = 0;
    int idx = 0;
    int num = stoi(argv[1]);

    ifstream readfile(argv[2]); //file to be read and analyzed
    const char* ignorefile = argv[3]; //file to be ignored
    string line;
    if(readfile.is(open())){
        while(getline(readfile,line)){
            if(getTotalNumberNonStopWords(unique, n) == n){//array is fwull
                wordItem *temp = new wordItem[2*n];
                for(int i=0; i<n; i++){
                    temp[i] = wi[i];
                }
                delete[] wi;
                wi = temp;
                n = n*2;
                count++;    

            }
            else{
                if(isStopWord(line, endArray) == false){
                    if(isUniqueWord(wi, n, line) == false){
                        wi[idx].word = line;
                        wi[idx].count = 1;
                        idx++;

                    }
                }
            }
            arraySort(words, n);
            int wordCount;
            wordCount = getTotalNumberNonStopWords(words,n);
            cout << "Array doubled: " << counter << endl;
            cout << "#" << endl;
            cout << "Unique non-common words: " << total << endl;
            cout << "#" << endl;
            cout << "Total non-common words: " << wordCount << endl;
            cout << "#" << endl;
            cout << "Probability of next " << n <<  " words from rank " << idx << endl;
            cout << "---------------------------------------" << endl;
            int N = stoi(argv[1]);
            printNext10(words, N, wordCount);

        }

    }
    if(readfile.fail()){
        cout << "Failed to open " argv[2] << endl;
    }

}