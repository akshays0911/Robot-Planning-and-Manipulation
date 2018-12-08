/*
 Author: Akshay Swaminathan
 Date: 04-04-2018
 Course : Robot Planning and Manipulation
 Purpose: Random X-Y Coordinate (node) Generator with the distance between two nodes
 Since its implemented in an Autonomous vehicle environment, 
 we are just considering the x and y coordinates.
 I am going to consider this as a graph problem with vertices and edges with its weights.
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() 
{
    // Initializing the necessary values 
    int vertices, number_of_edges;
    string filename;
    
    // Allowing the user to select the number of nodes and vertices 
    cout << "How many vertices do you want: ";
    cin >> vertices;
    cout << "How many edges do you want: ";
    cin >> number_of_edges;
    cout << "Output file name (Don't add .txt): ";
    cin >> filename;
    
    filename += ".txt";
    
    // File operation
    ofstream out(filename.c_str());
    if (!out.is_open()) {
        cerr << "Error........ Could not create file " << filename << endl;
        return -1;
    }
    
    out << vertices << " " << number_of_edges << endl;
    
    //This is the random number generator
    srand(time(0));
    
    //An array to store all the edges
    int edges[vertices][vertices];
    
    //Initialize all values to zero
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            edges[i][j] = 0;
        }
    }
    //Populating the edges
    int new_edges = 0;
    while (new_edges < number_of_edges) {
        bool edge_made = false;
        while (!edge_made) {
            int v1 = rand() % vertices;
            int v2 = 0;
            while (v2 == 0 || v2 == v1) {
                v2 = rand() % vertices;
            }
            int weight = (rand() % 50) + 1;
            int temp = edges[v1][v2];
            if (temp == 0) {
                edges[v1][v2] = weight;
                edges[v2][v1] = -1;
                edge_made = true;
            }
        }
        new_edges++;
    }
    
    //Printing the edge to the file
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            int temp = edges[i][j];
            if (temp > 0) {
                out << i+1 << " " << j+1 << " " << edges[i][j] << endl;
                cout << i+1 << " " << j+1 << " " << edges[i][j] << endl;
            }
        }
    }
    
    out.close();
    
    cout << "File created.........." << endl;
    
    return 0;
}
