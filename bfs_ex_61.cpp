#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    string value;
    
    vector<Node> neighbours;

    public:

    Node(string value) {
        this->value = value;
        neighbours = {};
    }

    Node() {
        this->value = "";
        neighbours = {};
    }
};

int main() {

    Node *start = new Node("start");

    Node *start_1 = new Node();

    Node *start_2 = new Node();

    start->neighbours = {start_1, start_2};

    Node *finish = new Node("finish");

    start_1->neighbours = { finish, new Node()};

    Node *start_2_1 = new Node();

    start_2_1->neighbours = { finish, new Node() };

    start_2->neighbours = { start_2_1, new Node() }; 


    // bfs

    Node *cur = start;

    while(cur != NULL) {
        
    }

    return 0;
}