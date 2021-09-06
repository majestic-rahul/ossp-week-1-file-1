#include<iostream>
#include <stdbool.h>
#include <stdio.h>
#include<string>
#include <vector>
#include <string>

#define V 8

// a custom made strucutre for the input type and graph
const char* arr[V] = {"Whatsapp", "Facebook", "Apple TV", "Spotify", "Netflix", "Amazon", "Uber", "Google Chrome"};
//int V;
void printSolution(int color[]);
 

bool isSafe(
    int v, bool graph[V][V],
    int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (
            graph[v][i] && c == color[i])
            return false;
    return true;
}
 

bool graphColoringUtil(
    bool graph[V][V], int m,
    int color[], int v)
{
   
    if (v == V)
        return true;
 
    
    for (int c = 1; c <= m; c++) {
       
        if (isSafe(
                v, graph, color, c)) {
            color[v] = c;
 
           
            if (
                graphColoringUtil(
                    graph, m, color, v + 1)
                == true)
                return true;
 
          
            color[v] = 0;
        }
    }
 
    
    return false;
}
 

bool graphColoring(
    bool graph[V][V], int m)
{
    
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
 
  
    if (
        graphColoringUtil(
            graph, m, color, 0)
        == false) {
        printf("Solution does not exist");
        return false;
    }
 
   
    printSolution(color);
    return true;
}
 

void printSolution(int color[])
{
    printf(
        "Solution Exists:"
        " Following are the assigned colors \n");
    for (int i = 0; i < V; i++){
    std::cout << "the colour assigned is :" << color[i] << " : the application :" << arr[color[i]] ;
    printf("\n");
    }
    // printf(" %d ", color[i] ," :" , arr[color[i]]);
    printf("\n");
    printf("\n");
}
 



int main()
{
  //cin>>V;
  
    bool graph[V][V] = {
        { 0, 1, 1, 1 ,1 ,1 ,1 ,0},
        { 1, 0, 1, 0 ,1 ,1 ,1 ,1},
        { 1, 1, 0, 1 ,1 ,1 ,1 ,1},
        { 1, 0, 1, 0 ,1, 1 ,1 ,1},
        { 1 ,1, 1 ,1 ,0 ,1 ,1 ,1},
        { 1 ,1 ,1 ,1 ,1 ,0 ,1 ,1},
        { 1 ,1 ,1 ,1 ,1 ,1 ,0, 1},
        { 0 ,1 ,1 ,1 ,1 ,1 ,1 ,0},
        

    };

//     custom gg[4][4] = {
//     {
// { "hello" , 5},

// {"Whatsapp" , 100} ,

// {"Facebook" , 200}, 

// {"Apple TV" , 850} 
//        }, 

//     {
// {"Spotify" , 250},

// {"Netflix" , 190},

// {"Amazon" , 210},

// {"Uber" , 700}
//         },

//     {
// {"Google Chrome" ,1200},

// {"Safari" , 900},

// {"Finder" , 340},

// {"Maps" , 500 }
//     },
// {
//     {"mozilla", 500},
//     {"microsoft edge" , 880},
//     {"calculator" , 1001},
//     {"inshorts" , 232}
//     },

    // };

    
    int m = 6; // Number of colors
    graphColoring(graph, m);
    return 0;
}