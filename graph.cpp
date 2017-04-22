#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
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
    bool CheckNode ( int x ){
        if (nodes.count(x)) return 1;
        else return 0;
    };

    void InsertNode( Node x ){
        if (CheckNode(x.id)) { cout << "ID exists." ;}
        else { nodes[x.id] = x;};
    };

    void InsertEdge( int x, int y ){
        if (!CheckNode(x) or !CheckNode(y)){
            cout << "No such node." << endl;
        } else {
            edges[x].push_back(y);
        }
    };

    void CommonNeighbor( int x, int y ){
        vector <int> i;
        if (!CheckNode(x) or !CheckNode(y)) { cout << "No such node." << endl;}
            else {
            sort(edges[x].begin(),edges[x].end(),less<int>());
            sort(edges[y].begin(),edges[y].end(),less<int>());
            set_intersection(edges[x].begin(), edges[x].end(),
                             edges[y].begin(), edges[y].end(),
                             inserter(i, i.begin()));
            if (i.empty()) { cout << "No common neighbor." << endl;}
            else{
                for (vector<int>::iterator itr = i.begin(); itr != i.end(); itr++){
                    cout << *itr << " " << nodes[*itr].name << endl;
                }
            }
        }
    };

    void ShortestPath(int source, int destination){
        queue<int> q;
        map<int,int> previous;
        map<int,bool> visited;
        bool found = false;
        if (source == destination){cout<< source << " " << nodes[source].name << endl;} else {

            if (!CheckNode(source) or !CheckNode(destination)){ cout << "No such node." << endl; }
            else {
                for (map<int, Node >::iterator itr = nodes.begin(); itr != nodes.end(); itr++){
                    visited[(*itr).first] = false;
                    previous[(*itr).first] = -1;
                }
                q.push(source);
                visited[source] = true;
                int current,steps = 0;

                while (q.empty() == false && found == false){
                    steps++;
                    current = q.front();
                    q.pop();

                    if (current == destination){
                        int list[steps];
                        found = true;
                        int count = 0;
                        do{
                            list[count++] = current;
                            current = previous[current];
                        }while (current != source);
                        list[count++] = current;
                        for (int i=count-1; i>=0; i--){
                            cout<< list[i] << " " << nodes[list[i]].name << endl;
                        };
                        break;
                    };

                    for (vector<int>::iterator itr = edges[current].begin(); itr != edges[current].end(); itr++){
                        if (visited[*itr] == false){
                            q.push(*itr);
                            visited[*itr] = true;
                            previous[*itr] = current;
                        }
                    };
                };
                if (!found) cout << "No path found." << endl;
            };
        };
    }; // You can add more member functions to help your implementation.
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
            cin >> id1 >> id2;
            g.CommonNeighbor(id1, id2);
        }else if (command == "ShortestPath"){
            cin >> id1 >> id2;
            g.ShortestPath(id1, id2);
        }else if (command == "Exit"){
            return 0;
        }
    }
}
