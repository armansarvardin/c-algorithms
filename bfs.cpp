#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

bool bfs(map<string, vector<string>> graph, string name, string seller) {

    queue<string> search_queue {};
    
    for (string s: graph[name]) {
        search_queue.push(s);
    }

    set<string> searched {};

    while(!search_queue.empty()) {

        string person = search_queue.front();
        search_queue.pop();

        

        if (!searched.count(person)) {
            if (person == seller) {
                cout << person + " is a mango seller" << endl;
                return true;

            } else {
                for(string s: graph[person]) {
                    search_queue.push(s);
                }
                searched.insert(person);
            } 
        } 
    }

    return false;
}

int main() {

    // Given graph
    map<string, vector<string>> graph {};

    graph["you"] = {"alice", "bob", "claire"};
    graph["bob"] = {"anuj", "peggy"};
    graph["alice"] = {"peggy"};
    graph["claire"] = {"thom", "jonny"};
    graph["anuj"] = {};
    graph["peggy"] = {};
    graph["thom"] = {};
    graph["jonny"] = {};

    cout << "Result of bfs " << bfs(graph, "you", "anuj") << endl;

    return 0;
}