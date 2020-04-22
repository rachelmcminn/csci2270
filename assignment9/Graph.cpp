#include <iostream>
#include <fstream>
#include "Graph.hpp"
using namespace std;


//make a connection b/t v1 and v2 like last assignment,
//but this time add weights to the edges
void Graph::addEdge(string v1, string v2, int num){
  for(int i=0; i < vertices.size(); i++){
    if(vertices[i]->name == v1){ //found v1
      for(int j=0; j < vertices.size(); j++){
        if(vertices[j]->name == v2 && i!=j) { //found v2
          adjVertex av;
          av.v = vertices[j];
          av.weight = num;
          vertices[i]->adj.push_back(av); //add new vertex for edge

          adjVertex av2;
          av2.v = vertices[i];
          av2.weight = num;
          vertices[j]->adj.push_back(av2); //add new vertex for edge on other side
        }
      }
    }
  }
}

void dftHelper(vertex* vertex){
    vertex->visited = true;
    cout << vertex->name << " -> "; // for printing the path found through DF Traversal (each node)
    for(int x=0; x < vertex->adj.size(); x++){ //loop thru to traverse
        if(!vertex->adj[x].v->visited){
            vertex->adj[x].v->visited = true; //mark true when visited; each node only visited once
            dftHelper(vertex->adj[x].v); //recursion
        }
    }
}

void Graph::depthFirstTraversal(string sourceVertex){
    for(int i=0; i<vertices.size(); i++){
        if(vertices[i]->name == sourceVertex){ //beginning city name found
            dftHelper(vertices[i]); //call to traverse
            
        }
    }
    
// print “DONE” at the end when all the cities have been visited.
cout << "DONE";
}



vertex* dijkstraHelper(string start, string end){
    vertex* vStart;
    vertex* vEnd;
    vector<vertex*> solvedList; //create vector to store solved vertices
    for(unsigned int i=0; i < vertices.size(); i++){
        vertices[i]->visited = false;
        if(vertices[i]->name == start){ //found starting vertex
            vStart = vertices[i];
            vStart->visited = true;
            vStart->distance = 0;
            solvedList.push_back(vStart); //push starting vertex into solved vector
        }
        if(vertices[i]->name == end){ //found end vertex
            vEnd = vertices[i];
        }
    }
    vertex* solvedV = NULL; //temp pointer
    while(!vEnd->visited) {
    int minDist = 10000000; //creating minimum distance
    for(unsigned int x=0; x < solvedList.size(); x++){
        vertex* s = solvedList[x];
        //now iterate across s adj list
        for(unsigned int y=0; y < s->adj.size(); y++){
            if(!solvedList[x]->adj[y].v->visited) { //only visit unsolved
                int dist = s->distance + s->adj[y].weight;
                if(dist < minDist) { //distance smaller than minDist
                    solvedV = s->adj[y].v;
                    minDist = dist;
                    s->adj[y].v->pred = s; //set pointer to keep track of path
                    solvedV->pred = s;
                }
            }
        }
    }
    solvedV->distance = minDist;
    solvedV->visited = true;
    solvedList.push_back(solvedV);
    }

    vEnd->distance = solvedV->distance;
    return vEnd;
}


//num 3
void Graph::dijkstraTraverse(string source)
{   
    vertex* vStart;
    vertex* vEnd;
    vector<vertex*> solvedList; //create vector to store solved vertices
    for(int i=0; i < vertices.size(); i++){
        vertices[i]->visited = false;
        if(vertices[i]->name == source){ //found source vertex
            vStart = vertices[i];
            vStart->visited = true;
            vStart->distance = 0;
            solvedList.push_back(vStart); //push starting vertex into solved vector
        }
        // if(vertices[i]->name == end){ //found end vertex
        //     vEnd = vertices[i];
        // }
    }
    vertex* solvedV = NULL; //temp pointer
    while(!vEnd->visited) {
    int minDist = 10000000; //creating minimum distance
    for(int x=0; x < solvedList.size(); x++){
        vertex* s = solvedList[x];
        //now iterate across s adj list
        for(int y=0; y < s->adj.size(); y++){
            if(!solvedList[x]->adj[y].v->visited) { //only visit unsolved
                int dist = s->distance + s->adj[y].weight;
                if(dist < minDist) { //distance smaller than minDist
                    solvedV = s->adj[y].v;
                    minDist = dist;
                    s->adj[y].v->pred = s; //set pointer to keep track of path
                    solvedV->pred = s;
                }
            }
        }
    }
    solvedV->distance = minDist;
    solvedV->visited = true;
    solvedList.push_back(solvedV);
    }

    vEnd->distance = solvedV->distance;
    return vEnd;
   
}



/* num 4
steps:

1)call dijkstras with start.

2)search vertices vector for the vertex "end"

3)create a while loop (you are doing the traversal with the while loop from the end 
and tracing backwards till you reach "start", using pred as your guide)

4)in while loop you are pushing the associated vertex "pred" into a vector

5)once you have reached the start vertex in the loop. the loop will terminate and you should now 
have all vertices in shortest path from start to end

6)use another for loop to traverse the vector that has all the verticsof the shortest path in it. 
but remember you started at the end so you'll have to traverse the vector backwards


*/

void Graph::shortestPath(string start, string end){
  //for printing the shortest path
  vector<string> path;
  vertex* vStart = NULL;
  vertex* vEnd = NULL;
  for(int i=0; i < vertices.size(); i++){
    if(vertices[i]->name == start){ //found starting vertex
      vStart = vertices[i];
    }
    if(vertices[i]->name == end){ //found end vertex
      vEnd = vertices[i];
    }
  }
  path.push_back(vEnd->name);
  while(vEnd->name != vStart->name){
    path.push_back(vEnd->pred->name);
    vEnd = vEnd->pred; //storing path backwards
  }
  for(int j= path.size(); j > 0; j--){ //backwards loop through path
    cout << n->name << " -> ";
  }
  cout << endl;
  cout << "DONE";
}

// for printing the path found through dijkstraTraverse (each node)

// print “DONE” and path distance at the end


