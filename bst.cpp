#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int key; 
    struct Node *left, *right; 
};
  
Node* newNode(int item){ 
    Node* temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

Node* insert(Node* Node, int key){ 
    if (Node == NULL) 
        return newNode(key); 
  
    if (key < Node->key) 
        Node->left = insert(Node->left, key); 
    else
        Node->right = insert(Node->right, key); 
    return Node; 
} 

Node* deleteNode(Node* root, int k){ 
    if (root == NULL) 
        return root; 
  
    if (root->key > k) { 
        root->left = deleteNode(root->left, k); 
        return root; 
    } 
    else if (root->key < k) { 
        root->right = deleteNode(root->right, k); 
        return root; 
    } 
  
    if (root->left == NULL) { 
        Node* temp = root->right; 
        delete root; 
        return temp; 
    } 
    else if (root->right == NULL) { 
        Node* temp = root->left; 
        delete root; 
        return temp; 
    } 
    else { 
  
        Node* succParent = root; 
          
        Node *succ = root->right; 
        while (succ->left != NULL) { 
            succParent = succ; 
            succ = succ->left; 
        } 
  
        if (succParent != root) 
            succParent->left = succ->right; 
        else
            succParent->right = succ->right; 
  
        root->key = succ->key; 
  
        delete succ;          
        return root; 
    } 
}

int maxDepth(struct Node* Node){ 
   if (Node==NULL)  
       return 0; 
   else 
   { 
       int lDepth = maxDepth(Node->left); 
       int rDepth = maxDepth(Node->right); 
  
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}

int getLeafCount(struct Node* Node){  
    if(Node == NULL)      
        return 0;  
    if(Node->left == NULL && Node->right == NULL)  
        return 1;          
    else
        return getLeafCount(Node->left)+  
            getLeafCount(Node->right);  
}

int countNonleaf(struct Node* root){ 
    if (root == NULL || (root->left == NULL &&  
                         root->right == NULL)) 
        return 0; 
  
    return 1 + countNonleaf(root->left) +  
               countNonleaf(root->right); 
}

void printPreorder(struct Node* Node){ 
    if (Node == NULL) 
        return; 
    cout << Node->key << " "; 
    printPreorder(Node->left);  
    printPreorder(Node->right); 
} 

void printPostorder(struct Node* Node){ 
    if (Node == NULL) 
        return; 
    printPostorder(Node->left); 
    printPostorder(Node->right); 
    cout << Node->key << " "; 
}

void inOrder(struct Node *root){ 
    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        while (curr !=  NULL) 
        { 
            s.push(curr); 
            curr = curr->left; 
        } 
  
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->key << " "; 
        curr = curr->right; 
  
    }
}

int main(){ 

    //1. creating BST 5,3,2,4,7,6,8
    Node* root = NULL; 

    root = insert(root, 5); 
    root = insert(root, 3); 
    root = insert(root, 2); 
    root = insert(root, 4); 
    root = insert(root, 7); 
    root = insert(root, 6); 
    root = insert(root, 8); 
    
    int a,x;
    while(1){
    cout<<"\n\n----------------------------------------------------------------------"<<endl;

    cout<<"\n\n1.Insert in BST.\n2.Delete a Node\n3.Print Height of BST\n4.Node count (internal and external)\n5.Pre-order traversal(recursive)\n";
    cout<<"6.Post-order Traversal(recursive)\n7.In-order Traversal(iterative)\n8.Exit\n\n\nEnter option:";
    cin>>a;
    cout<<"\n\n";
    switch(a){
        case 1: cout<<"Enter number to insert.";
                cin>>x;
                insert(root,x);
                cout<<"\n\nNode Inserted...\n";

                break;
        case 2: cout<<"Enter number to delete ";
                cin>>x;
                root = deleteNode(root, x);
                cout<<"\n"<<x<<"deleted\n";
                break;
        case 3: cout<<"Height of tree: "<<maxDepth(root);
                break;
        case 4: cout<<"External Nodes of the BST is : "<<getLeafCount(root)<<endl;
                cout<<"Internal Nodes of the BST is : "<<countNonleaf(root); 
                break;
        case 5: cout<<"\nPreorder traversal of binary tree is \n"; 
                printPreorder(root); 
                break;
        case 6: cout<<"\nPostorder traversal of binary tree is \n"; 
                printPostorder(root); 
                break;
        case 7: cout<<"In-order traversal of the BST (iterative) : "<<endl;
                inOrder(root); 
                break;
        case 8: cout<<"Exiting...";
                exit(0);
        default:cout<<"Enter a valid option.";
                break;
        }
    }
  
    return 0;  
}  