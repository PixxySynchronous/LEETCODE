// They are either stored as an adjacency matrix or an adjacency list.
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // we are given an edges vector where in each row has 2 coloumns, first column is u and the 
    // other column is v. So for the 0th edge u becomes edges[0][0] and v becomes [0][1]
    // for each element we need all the nodes it is connected to.
    // so for n nodes we need n vectors, each vector having all the nodes it is connected to, 
    vector<int> neighbours[n]; // declaring n vectors. negihbours[i] will have the vector of all the nodes connected to i. 
    for (int i = 0 ; i<m ; i++){
        int u = edges[i][0];
        int v = edges[i][1]; 
        neighbours[u].push_back(v); 
        //and since it is an unidirectional graph, u is connected to v means v is connected to u, 
        neighbours[v].push_back(u); 
    }
    vector<vector<int>> adj(n); //at index i , a vector of neighbours of i will be there. 
//     This creates a vector containing n empty vectors.

//     For example, if n = 3:
//     adj[0] = {};
//     adj[1] = {};
//     adj[2] = {};
    for (int i=0 ; i<n; i++){
        adj[i].push_back(i); //sample output wants the node itself first. 
        for (int j = 0; j<neighbours[i].size(); j++) //traversing the neighb ours vector of node i
            adj[i].push_back(neighbours[i][j]); 
    }
    return adj; 
    

}
// it can also be implemented using a map, where the key is the node and the value is a vector of all the nodes it is connected to.