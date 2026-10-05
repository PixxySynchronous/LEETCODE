/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

#include <bits/stdc++.h>
class TrieNode {
    //Each node in trie has 3 things. One is its data. Second is its children. Third is 
    //the fact that it is a terminal node or not (is it the end of a string or not)
    public:
        bool isTerminal; 
        char data; 
        TrieNode* children[26]; //each node can have atmost 26 children A-Z. Assuming only capital letters.
        TrieNode (char c){ //constructor. 
            data = c; 
            isTerminal = false; 
            for (int i = 0 ; i<26; i++)
                children[i] = NULL; 
        }
}; 
class Trie{

    public:
    TrieNode* root; // needs to be accessiible 
    Trie(){
        //Initialising a Trie means making a root node. 
        root = new TrieNode('\0');
    }
    void insertUtil (TrieNode* node, string word){
        //base case: when all the letters of the words have been processed. 
        if (word.size() == 0){
            // this means we are at the last node so we need to set its flag. 
            node -> isTerminal = true; 
            return; 
        }
        // we need to check if the current letter is a child of the node. 
        int index = word[0] - 'a'; //assuming only caps. 
        TrieNode* nextNode; 
        // case - child exists. 
        if (node -> children[index] != NULL)
            nextNode = node -> children[index]; 
        else{
            nextNode = new TrieNode (word[0]); 
            node -> children [index] = nextNode; 
        } //child dont exist so we make a node and make it its child. 
        // Then move to its child and pass the next letter. 
        insertUtil (nextNode, word.substr(1));
        return; 
        //deletes current letter
        
    }

    void insert(string word){
        // insertion is done recursively. We go to root node and see if its children
        // has the first letter of the word. If it does, we move to that node and 
        // see if its children have the second letter. If not we add that node and then
        // move to it. Recursively repeat. Since to implement this, we need to pass a node and 
        // the word in the parameters we need to make a separate function as this one just takes
        // in the word as a parameter. 
        insertUtil (root, word); //first node to be checked is root. 
    }


    bool searchUtil (TrieNode* node, string word){
        if (word.size()==0) {
            return node -> isTerminal; 
        }
        int index = word[0] - 'a'; 
        TrieNode* nextNode; 
        if (node -> children[index]!= NULL){
            nextNode = node -> children [index]; 
        }
        else 
            return false; 
        return searchUtil (nextNode, word.substr(1));
        
    }
    bool search(string word) {
        //To search for a word we would look for the child nodes. If child node of the current letter
        //is null we return false. ALso for example if we insert timer and search for time, our word ends on e but
        //since e is not a terminal node we return false. 
        // Since we need to ttraverse the nodes we need to make a util function like insertion. 
        return searchUtil (root,word); 
    }
    
    bool prefixUtil (TrieNode* node, string word){
          if (word.size()==0) {
            return true; 
        }
        int index = word[0] - 'a'; 
        TrieNode* nextNode; 
        if (node -> children[index]!= NULL){
            nextNode = node -> children [index]; 
        }
        else 
            return false; 
        return prefixUtil (nextNode, word.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        //this is basically like searching a word but we dont really care if the last node we end up on
        //is a terminal node or not since we are checking prefix. 
        return prefixUtil (root,prefix);
    }
};

   
// Time Complexity: O(n) where n is the length of the word to be inserted. For all insertion search and removal
// Space Complexity: O(ALPHABET_SIZE * N) where N is the total number of characters in all words.