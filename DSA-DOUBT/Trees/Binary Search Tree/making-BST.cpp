class Node {
    public:
    int data; 
    Node* left; 
    Node* right; 
    Node (int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertInBst (Node* root, int data){
    //base case is that if the root is NULL, we create a node and insert data in it 
    if ( root == NULL){
        return new Node (data);
    }
    if ( data > root -> data){
        root -> right = insertInBst (root -> right, data); 
    }
    else {
        root -> left = insertInBst (root -> left, data); 
    }
    return root;
}

void takeInput (){ 
    int data;
    cin >> data; 
    while (data != -1){
        root = insertInBst (root, data); 
        cin >> data; 
    }
    return; 
}