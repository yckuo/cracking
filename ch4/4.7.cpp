/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<string, string> PSS;

class Solution {
public:
    vector<string> TopologicalSort(vector<string>& nodes, vector<PSS>& dependencies) {
        vector<string> ret;
        unordered_map<string, int> indegrees;
        unordered_map<string, vector<string>> graph;
        for (PSS dependency : dependencies) {
            // dependency {A, B} means A depends on B, i.e., B needs to occur before A. Add an edge B -> A to the graph
            graph[dependency.second].push_back(dependency.first);
            indegrees[dependency.first]++;
        }

        queue<string> q;
        for (string node : nodes) {
            if (indegrees[node] == 0) {
                q.push(node);
            }
        }

        while (!q.empty()) {
            string node = q.front();
            q.pop();
            ret.push_back(node);
            for (string target : graph[node]) {
                if (--indegrees[target] == 0) {
                    q.push(target);
                }
            }
        }
        
        if (ret.size() == nodes.size()) return ret;
        return vector<string>();
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line1, line2;
    while (getline(cin, line1)) {
        getline(cin, line2);
        istringstream iss1(line1), iss2(line2);
        vector<string> nodes;
        string node;
        while (iss1 >> node) {
            nodes.push_back(node);
        }
        
        vector<PSS> dependencies;
        string a, b;
        while (iss2 >> a >> b) {
            dependencies.push_back({a, b});
        }

        vector<string> res = sol.TopologicalSort(nodes, dependencies);
        for (int i=0; i<res.size(); i++) {
            if (i > 0) cout << " -> ";
            cout << res[i];
        }
        cout << endl;
    }

    return 0;
}
