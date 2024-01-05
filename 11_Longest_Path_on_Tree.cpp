/* 
Description
Given a undirected tree $G = (V, E)$ in which $V = \{1,…,N\}$ is the set of nodes. Each edge $(u,v) \in E$ has weight $w(u,v)$. The length of a path is defined to be the sum of weights of edges of this path. Find the longest elementary path on $G$.

Input
Line 1: positive integer $N$ ($1 \leq N \leq 10^5$)
Line $i + 1$ ($i = 1,…,N-1$): positive integers $u, v, w$ in which $w$ is the weight of edge $(u,v)$ (1 ≤ w ≤ 100)

Output
The weight of the longest path on the given tree

Example

Input
6 
1 3 3
1 6 2 
2 6 5 
4 5 2
4 6 1

Output
10 
*/

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited) {
    visited[node] = true;
    pair<int, int> maxDist(0, node);

    for (auto edge : graph[node]) {
        int neighbor = edge.first;
        int weight = edge.second;

        if (!visited[neighbor]) {
            pair<int, int> dist = dfs(neighbor, graph, visited);
            dist.first += weight;

            if (dist.first > maxDist.first) {
                maxDist = dist;
            }
        }
    }

    return maxDist;
}

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    pair<int, int> p = dfs(1, graph, visited);
    fill(visited.begin(), visited.end(), false);
    pair<int, int> longestPath = dfs(p.second, graph, visited);
    cout << longestPath.first << endl;

    return 0;
}