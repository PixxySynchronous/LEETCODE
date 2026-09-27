// 146. LRU Cache
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

 

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
 

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 104
// 0 <= value <= 105
// At most 2 * 105 calls will be made to get and put.
 
class Node {
    public:
        int key;
        int value;  
        Node* prev; 
        Node* next; 
        Node(int key, int value){
            this ->key = key;
            this ->value = value;  
            this -> next = NULL; 
            this -> prev = NULL; 
        }
}; 

class LRUCache {
public:
    // all the variables below need to be accessed by all functions and hence are written here
    unordered_map<int, Node*> mp; //map has value of a pointer which points to the exxact node we need so we get to the node in o(1) space. 
    int maxSize; // capacity 
    Node* dummyHead; 
    Node* dummyTail; 
    LRUCache(int capacity) { //constructor 
        maxSize = capacity; 
        dummyHead = new Node (-1, -1); 
        dummyTail = new Node (-1, -1);
        dummyHead -> next = dummyTail; 
        dummyTail -> prev = dummyHead;  
        // we are going for a <head> <--> <key,val> <--> <tail> structure. 
        // the tail side keeps the MRU node, the head side keeps the LRU node. 
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1; 
        else {
            int ans = mp[key] -> value; //need to return this. 
            Node* currNodeprev = mp[key] -> prev; 
            Node* currNodenext = mp[key] -> next; 
            currNodeprev -> next = currNodenext; 
            currNodenext -> prev = currNodeprev; 
            // above removes the currNode from its position. 
            Node* prevTail = dummyTail -> prev; 
            prevTail -> next = mp[key]; 
            mp[key] -> next = dummyTail;    
            mp[key] -> prev = prevTail; 
            dummyTail -> prev = mp[key]; 
            // above inserts it at the MRU position.
            return ans; 
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end() && mp.size()< maxSize){
            // key doesnt exist but the size is not max so we can insert it. 
            Node* newNode = new Node (key, value); //make the new node 
            Node* prevTail = dummyTail -> prev; 
            prevTail -> next = newNode; 
            newNode -> prev = prevTail ; 
            newNode -> next = dummyTail; 
            dummyTail -> prev = newNode; 
            // insert the new node in the end (MRU side)
            mp[key] = newNode; //make a map key pointing to the node. 
        }
        else if (mp.find(key) != mp.end()){ //node exists, we need to update value. 
            mp[key] -> value = value; //upadte the value of the node. 
            //Sicne node was used it needs to move to MRU side. 
            Node* currNodeprev = mp[key] -> prev; 
            Node* currNodenext = mp[key] -> next; 
            currNodeprev -> next = currNodenext; 
            currNodenext -> prev = currNodeprev; 
            // above removes the currNode from its position. 
            Node* prevTail = dummyTail -> prev; 
            prevTail -> next = mp[key]; 
            mp[key] -> next = dummyTail;    
            mp[key] -> prev = prevTail; 
            dummyTail -> prev = mp[key]; 
            // above inserts it at the MRU position. 
        }
        else{ //key dont exist, but inserting it exceeds capacity. 
            Node* newNode = new Node (key, value); 
            // INSERT THE NODE AT THE END 
            Node* prevTail = dummyTail -> prev; 
            prevTail -> next = newNode; 
            newNode -> prev = prevTail ; 
            newNode -> next = dummyTail; 
            dummyTail -> prev = newNode; 
            mp[key] = newNode;
            // DELETE THE LRU NODE (DUMMYHEAD -> NEXT)
            Node* delNode = dummyHead -> next; 
            dummyHead -> next = delNode -> next; 
            delNode -> next ->prev = dummyHead;
            // DELETE THE KEY FROM THE HASHMAP
            mp.erase(delNode -> key); 
            delete delNode; 
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
