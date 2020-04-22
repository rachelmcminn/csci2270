#include <iostream>
#include <fstream>
#include "Graph.hpp"

using namespace std;

Graph::Graph(){

}

void Graph::addVertex(std::string name)
{
    bool found = false;
    for(int i=0; i < vertices.size(); i++){
        if(vertices[i]->name == name){
            found = true;
            break;
        }
    }
    if(found==false){
        vertex* v = new vertex;
        v->name = name;
        vertices.push_back(v);
    }
}

void Graph::addEdge(std::string v1, std::string v2)
{
    for(int x=0; x<vertices.size(); x++){
        if(vertices[x]->name == v1){ //v1 is found
            for(int y=0; y<vertices.size(); y++){
                if(vertices[y]->name == v2 && x!=y){ //v2 is also found
                    adjVertex av1;
                    av1.v = vertices[y];
                    vertices[x]->adj.push_back(av1);  //add new
                    adjVertex av2;
                    av2.v = vertices[x];
                    vertices[y]->adj.push_back(av2); //add new
                  }  
            }
        }
    }
}
 
void Graph::displayEdges()
{
   for(unsigned int i=0; i < vertices.size(); i++){
       cout << vertices[i]->name << " --> ";
       for(unsigned int j=0; j < vertices[i]->adj.size(); j++){
           cout << vertices[i]->adj[j].v->name;
           if(j != vertices[i]->adj.size() - 1){
               cout << " ";
           }
       }
       cout << endl;
   }
}

void Graph::displayEdges()
{
   for(unsigned int x=0; x < vertices.size();x++){
       cout << vertices[x]->name << " --> ";
       for(unsigned int y=0; y < vertices[x]->adj.size(); y++){
           cout << vertices[x]->adj[y].v->name;
           if(y != vertices[x]->adj.size() - 1){
               cout << " ";
           }
       }
       cout << endl;
   }
}

void Graph::breadthFirstTraverse(string sourceVertex) {
    vertex* vStart;
    for (unsigned int i = 0; i < vertices.size(); i++) {
  		if (vertices[i]->name == sourceVertex) { //traversing vertices to find source
  			vStart = vertices[i];
  			vStart->visited = true; //found
        vStart->distance = 0; //0 since it is root
        break;
  		}
    }
    
    //creating queue for bfs
    queue<vertex*> queue;
    queue.push(vStart); //puts first element into queue
    cout<< "Starting vertex (root): " << vStart->name << "-> ";

    while(!queue.empty()){
      vertex* node = queue.front();
      node->visited = true;
      vector<adjVertex> adjNode = node->adj;

      for(unsigned int a=0; a < adjNode.size(); a++){ //loops thru other nodes
        vertex* v = adjNode[a].v;
        if(!v->visited){
          v->distance = node->distance + 1;
          queue.push(v); // pushes adj node in queue
          cout << v->name <<"("<< v->distance <<")"<< " ";
        }
      }
      queue.pop();
      }
  }
  
int Graph::getConnectedComponents(){
  queue<vertex*> queue; //intiialize queue for dfs
  vertex* v; //initialize vertex to traverse
  int counter = 0;

//depth first search on each vertice, increase count by 1
  for(unsigned int i=0; i < vertices.size(); i++){
    if(!vertices[i]->visited){
      vertices[i]->visited = true;
      queue.push(vertices[i]);

      while(!queue.empty()){
        v = queue.front();
        queue.pop();
        for(unsigned int j=0; j < v->adj.size(); j++){
          if(!v->adj[j].v->visited){
            queue.push(v->adj[j].v); //push adj into queue
            v->adj[j].v->visited = true; //visited
          }
        }
      }
      counter++;
    }
  }
  return counter;
}