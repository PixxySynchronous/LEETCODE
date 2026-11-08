// Problem statement
// Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

// E is the number of edges present in graph G.
// Note :
// The Graph may not be connected i.e there may exist multiple components in a graph.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 2 <= V <= 10^3
// 1 <= E <= (5 * (10^3))

// Time Limit: 1sec
// Sample Input 1:
// 5 4
// 0 2
// 0 1
// 1 2
// 3 4
// Sample Output 1:
// 2
// 0 1 2
// 3 4
// Explanation For Sample Input 1:
// If we do a DFS traversal from vertex 0 we will get a component with vertices [0, 2, 1]. If we do a DFS traversal from 3 we will get another component with vertices [3, 4]

// Hence,  we have two disconnected components so on the first line, print 2. Now, print each component in increasing order. On the first line print 0 1 2 and on the second line, print 3 4.

// [0 1 2] comes before [3 4] as the first vertex 0 from the first component is smaller than the first vertex 3 from the second component.
// Sample Input 2:
// 9 7
// 0 1
// 0 2
// 0 5
// 3 6
// 7 4
// 4 8
// 7 8
// Sample Output 2:
// 3
// 0 1 2 5
// 3 6
// 4 7 8
void createAdj (unordered_map <int, list<int>>& adjList, vector<vector<int>>&edges){
     for (int i = 0 ; i<edges.size() ; i++){
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        adjList[u].push_back(v); 
        adjList[v].push_back(u); 
    }
}

void dfs (int node, vector<int>& component,unordered_map <int, list<int>>& adj, unordered_map<int,bool>& visited){
    visited[node]= true; 
    component.push_back(node);
   for (int neighbor : adj[node]) { //traversing the map 
        if (!visited[neighbor]) {
            dfs(neighbor, component, adj, visited);//dfs using recursive stack, we can also use iterative stack to do dfs traversal
        }
    }
}
   
   

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map <int, list<int>> adjList; 
    createAdj (adjList,edges);
    unordered_map<int,bool> visited; 
    vector<vector<int>> ans; 
    for (int i = 0 ; i<V; i++){
        if (!visited[i]){
            vector<int> component; //component is used to store the vertices of a connected component, as the qns wants us to print the vertices of each component in a separate line.
            dfs(i, component, adjList,visited); 
            ans.push_back(component);
        }
    }
    return ans; 

}