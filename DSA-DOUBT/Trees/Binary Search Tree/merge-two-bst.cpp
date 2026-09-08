//  Merge Two BSTs
// Moderate
// 80/80
// Average time to solve is 10m
// Contributed by
// 197 upvotes
// Asked in companies
// Problem statement
// You are given two binary search trees of integers having ‘N’ and ‘M’ nodes. Return an array that contains elements of both BST in sorted order.



// A binary search tree (BST) is a binary tree data structure with the following properties.

// • The left subtree of a node contains only nodes with data less than the node’s data.

// • The right subtree of a node contains only nodes with data greater than the node’s data.

// • Both the left and right subtrees must also be binary search trees.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 2 1 3 -1 -1 -1 -1
// 4 -1 -1
// Sample Output 1:
// 1 2 3 4 
// Explanation For Sample Output 1:
//  The given BST are:-


// The output will be 1 2 3 4
// Sample Input 2:
// 4 2 7 -1 3 -1 -1 -1 -1  
// 5 1 7 -1 -1 -1 -1
// Sample Output 2:
// 1 2 3 4 5 7 7 
// Constraints:
// 1 <= 'N', 'M' <= 10^5

// Time Limit: 1 sec
/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
    void convertBSTintoSortedDLL (TreeNode *root, TreeNode* &head, TreeNode*& prev){
        //here the head varaible will point to the first node in the sorted LL. 
        //prev points to the last processed node. 
        if (root == NULL)
            return; 
        //Process the left subtree as we want shortest elements first. 
        convertBSTintoSortedDLL(root->left, head, prev); 
        if (head == NULL)
            head = root; //first element becomes the root as no element is in yet as head is null. 
        if (prev != NULL){ //prev node -> right = curr node. 
            prev -> right = root; 
            root -> left = prev; //curr node -> left = prev node. 
        }
        prev = root; //since curr node has been processed it is the last processed node. 
        convertBSTintoSortedDLL(root->right, head, prev); //process the right subtree. 
    }

    TreeNode* mergeTwoLL (TreeNode* root1,TreeNode *root2){
        TreeNode *head = NULL; 
        TreeNode *tail = NULL; 
        TreeNode *p1 = root1;
        TreeNode *p2 = root2; 
        while (p1 != NULL && p2 != NULL){
            if (p1->data < p2 -> data){
                if (head == NULL){ //first element. 
                    head = p1; 
                    tail = p1; 
                    p1 -> left = NULL; 
                    p1 = p1 -> right; 
                } 
                else{
                    tail -> right = p1;
                    p1 -> left = tail; 
                    tail = p1; 
                    p1 = p1 -> right; 
                }  

            }
            else{
                if (head == NULL){ //first element. 
                    head = p2; 
                    tail = p2;
                    p2 -> left = NULL;  
                    p2 = p2 -> right; 
                } 
                else{
                    tail -> right = p2;
                    p2 -> left = tail;
                    tail = p2; 
                    p2 = p2 -> right; 
                }  

            }
        }
        while ( p1 != NULL){
          if (head == NULL){ //first element. 
                    head = p1; 
                    tail = p1; 
                    p1 -> left = NULL; 
                    p1 = p1 -> right; 
                } 
                else{
                    tail -> right = p1;
                    p1 -> left = tail; 
                    tail = p1; 
                    p1 = p1 -> right; 
                } 
        }
        while ( p2 != NULL){
            if (head == NULL){ //first element. 
                    head = p2; 
                    tail = p2;
                    p2 -> left = NULL;  
                    p2 = p2 -> right; 
                } 
                else{
                    tail -> right = p2;
                    p2 -> left = tail;
                    tail = p2; 
                    p2 = p2 -> right; 
                }    
        }
        return head; 

    }
    int countNodes (TreeNode* root){
        int count = 0; 
        while ( root != NULL){
            count++;
            root = root -> right; 
        }
        return count; 
    }

    TreeNode* LLtoBst (TreeNode* &head, int n){
        //head points to the start of the tree(it gets incremented and reaches the end of the list).
        // n indicates its size. 
        if (n<=0||head == NULL)
            return NULL; 
        //make left subtree. 
        TreeNode* left = LLtoBst(head,n/2); //After the left recursive call finishes, head points to the first unprocessed node, which becomes the root..
        TreeNode* root = head; 
        root -> left = left; 
        head = head -> right; //this is the starting of the right subtree. 
        root -> right = LLtoBst(head, n-n/2-1); 
        return root; 

    }

    vector<int> morrisInorder(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr = root;

    while (curr != NULL) {

        if (curr->left == NULL) {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else {
            TreeNode* pred = curr->left;

            while (pred->right != NULL && pred->right != curr)
                pred = pred->right;

            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

    vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
    {
        //One simple approach is to convert both into inorder, then merge inorders, then make bst from inorder. 
        //However tc=o(m+n)= SC as both the inorder arrays will take up space. 
        //We can do this with another approach of SC = o(h1+h2) by using sorted LL. 
        //If we convert both the trees into LL (in-place), then merge the 2 LL (in-place)
        //and then make BST from LL then sc will be less. 

        //Step1: Convert BST into sortedLL. Here since we dont want to loose the pointers we will make it into a Doubly LL. 
        TreeNode * head1 = NULL;
        TreeNode * prev1 = NULL; 
        convertBSTintoSortedDLL (root1,head1,prev1); 
        root1 = head1;
        if (prev1!=NULL)
            prev1->right = NULL; //last elem's right is null. 

        TreeNode * head2 = NULL;
        TreeNode * prev2 = NULL; 
        convertBSTintoSortedDLL (root2,head2,prev2); 
        root2 =head2; 
        if(prev2!=NULL)
            prev2->right = NULL; //last elems right is NULL. 

        //Step 2: Merge the 2 sorted LL. 
        TreeNode* root = mergeTwoLL (root1, root2); 

        //Step 3: Make BST from sorted LL. 
        // We can use the approach used to make BST from inorder but then we will have to find mid again and again. 
        // So instead of that, we know that if there are n nodes, 0-n/2 will be left subtree. n/2 plus 1 becomes root. 
        // and the remaining (n - n/2 -1(the root)) becomes the right subtree. 
        int n = countNodes (root); //nodes in the LL. 
        root = LLtoBst (root,n); 
        return morrisInorder(root);
    }