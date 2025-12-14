// Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

class Solution {
  public:
  
    void solve (vector<vector<int>> &maze,vector<vector<int>> &visited, vector <string> &output,string path, int posx, int posy, int n){
        if (posx==n-1 && posy == n-1){
            output.push_back(path);
            return; 
        }
        
        
        if (posx-1>=0 && maze[posx-1][posy]!= 0 && visited[posx-1][posy]!= 1){
            path+="U";
            visited[posx-1][posy] = 1;
            solve (maze,visited,output,path,posx-1,posy,n); 
            path.pop_back();
            visited[posx-1][posy] = 0;
            
        }
        if (posx+1< n && maze[posx+1][posy]!= 0 && visited[posx+1][posy]!= 1){
            path+="D";
            visited[posx+1][posy] = 1;
            solve (maze,visited,output,path,posx+1,posy,n); 
            path.pop_back();
            visited[posx+1][posy] = 0;
        }
        if (posy-1>=0 && maze[posx][posy-1]!= 0 && visited[posx][posy-1]!= 1){
            path+="L";
            visited[posx][posy-1] = 1;
            solve (maze,visited,output,path,posx,posy-1,n);
            path.pop_back();
            visited[posx][posy-1] = 0;
        }
        if (posy+1<n && maze[posx][posy+1]!= 0 && visited[posx][posy+1]!= 1){
            path+="R";
            visited[posx][posy+1] = 1;
            solve (maze,visited,output,path,posx,posy+1,n); 
            path.pop_back();
            visited[posx][posy+1] = 0; 
        }

        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        if (maze[0][0] == 0) return {};
        int n = maze[0].size(); 
        vector <vector<int>> visited (n, vector <int>(n,0)); 
        visited[0][0]=1; 
        vector <string> output; 
        int startposx = 0 ;
        int startposy = 0 ; 
        string path= ""; 
        solve (maze,visited, output,path, startposx , startposy, n); 
        sort(output.begin(),output.end()); 
        return output; 
        
    }
};



//simple to understand, just didnt realize that we need to mark visited and unvisited while backtracking
//also didnt consider visited matrix at all which is imp for preventing infinte loops. 