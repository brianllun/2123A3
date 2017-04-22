#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

class Node{
public:
    Node(){};
    Node(int i,string s){
        id = i;
        name = s;
    };
    int id;
    string name;
};

class Graph{
public:
    void InsertNode( Node x ){
        nodes[x.id] = x;
    };
    void InsertEdge( int x, int y ){
        if (!edges.count(x) or !edges.count(y)){
            cout << "No such nodes!" << endl;
        } else {
            edges[x].push_back(y);
        }
    };
    void CommonNeighbor( int x, int y );
    void ShortestPath(int source, int destination); // You can add more member functions to help your implementation.
private:
    map < int, Node > nodes;
    map < int, vector<int> > edges;

};

int main(){
    Graph g;
    string command;
    int id1, id2;
    string name;
    while (cin >> command){
        if (command == "InsertNode"){
            cin >> id1 >> name;
            Node n(id1,name);
            g.InsertNode(n);
        }
        if (command == "InsertEdge"){
            cin >> id1 >> id2;
            g.InsertEdge(id1,id2);
        }else if (command == "CommonNeighbor"){
            // cin >> id1 >> id2;
            // g.CommonNeighbor(id1, id2);
        }else if (command == "ShortestPath"){
            // cin >> id1 >> id2;
            // g.ShortestPath(id1, id2);
        }else if (command == "Exit"){
            return 0;
        }
    }
}

// Node::Node(){
// }

// Node::Node(int i,string s){
//     id = i;
//     name = s;
// }
