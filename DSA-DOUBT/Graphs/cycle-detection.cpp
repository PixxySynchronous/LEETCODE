#include <bits/stdc++.h>
bool isCycle(int srcNode, unordered_map<int,bool> &visited,
             unordered_map<int,list<int>> &adj){
    //The logic to detect a cycle is :
    //If a neighbour of a node is visited and is not the parent of the node, cycle detected. 
    //So creating parent ds. 
    unordered_map<int,int> parent; 
    parent[srcNode] = -1; 
    visited[srcNode] = true; 
    queue<int> q; 
    q.push(srcNode);
    while (!q.empty()){
        int front = q.front(); 
        q.pop(); 
        for (auto neighbour: adj[front]){
            if (visited[neighbour] == true && parent[front] != neighbour)
                return true; 
            else if (!visited[neighbour]){
                visited[neighbour] = true; 
                q.push(neighbour); 
                parent[neighbour] = front; 
            }
        }
       
    }
    return false; 
}







string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // 1. create adj list. 
    unordered_map <int,list<int>> adj; 
    for (int i = 0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1]; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    // 2. Create visited ds
    unordered_map<int,bool> visited; 

    // 3. Handle disconnected componenets. 

    for (int i = 0 ; i<n; i++){ //visiting all nodes
        if (!visited[i]){
            bool res = isCycle (i,visited,adj); 
            if (res == true)
                return "Yes"; 
            else
                continue; 
        }

    }
    return "No"; 
}
