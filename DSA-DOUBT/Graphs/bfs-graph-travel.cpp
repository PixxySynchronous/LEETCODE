void bfs (vector<vector<int>> &adj,unordered_map <int, bool>& visited,
    vector<int>&ans, int node){
        visited[node]=true; 
        queue<int> q; 
        q.push(node); 
        while (!q.empty()){
            int ansNode = q.front(); 
            q.pop(); 
            ans.push_back (ansNode); 
            for (int i = 0 ; i<adj[ansNode].size(); i++){
                if (!visited[adj[ansNode][i]]){
                    q.push(adj[ansNode][i]); 
                    visited[adj[ansNode][i]] = true; 
                }
                    
            }
        }
    }


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Logic is simple, you build the adjList first, then use a visited array and a
    // queue. While queue is not empty, pop the node, mark it visited and then put its adj list. 
    //. in the queue. 
    //Here we have the adj list already. 
    unordered_map <int, bool> visited; 
    vector<int> ans;  
    // for (int i = 0 ; i<n ; i++){
    //     // Disconnected graphs have nodes which are not connected to anything. 
    //     // These nodes need to be included in bfs traversal as well. 
    //     // So this for loop is used. For every node which hasnt been visited, it calls the bfs function
    //     // So first it calls bfs for the source Node. That bfs calls marks the nodes which are 
    //     // connected with it as visited, so all the disonnected nodes are still marked as not visited. 
    //     // hence these nodes will trigger the if condition in next iterations and bfs will be done for them too. 
    //     if (visited[i] == false) // i represents the node as adj list's index is the node. 
    //         bfs (adj,visited,ans,i); 
    // }
    bfs (adj,visited,ans,0); //this qsn dont want disconnected nodes. 
    return ans; 
}