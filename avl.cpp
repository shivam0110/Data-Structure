#include<bits/stdc++.h> 
using namespace std; 
  
class Node  
{  
    public: 
    int key;  
    Node *left;  
    Node *right;  
    int height;  
};  

void preOrder(Node *root){  
    if(root != NULL){  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}

int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
   
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  

Node* newNode(int key)  
{  
    Node* root = new Node(); 
    root->key = key;  
    root->left = NULL;  
    root->right = NULL;  
    root->height = 1; 
      
    return(root);  
}  
  

Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    x->right = y;  
    y->left = T2;  
  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    return x;  
}  
  

Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    y->left = x;  
    x->right = T2;  
  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    return y;  
}  
  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
  
 
Node* insert(Node* root, int key)  
{  
    if (root == NULL)  
        return(newNode(key));  
  
    if (key < root->key)  
        root->left = insert(root->left, key);  
    else if (key > root->key)  
        root->right = insert(root->right, key);  
    else 
        return root;  
  
    root->height = 1 + max(height(root->left),  
                        height(root->right));  

    int balance = getBalance(root);  

    if (balance > 1 && key < root->left->key)  
        return rightRotate(root);  
  
    if (balance < -1 && key > root->right->key)  
        return leftRotate(root);  
  
    if (balance > 1 && key > root->left->key)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    if (balance < -1 && key < root->right->key)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  

Node * minValueNode(Node* root)  
{  
    Node* current = root;  
  
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  
  

Node* deleteNode(Node* root, int key)  
{  
      
    if (root == NULL)  
        return root;  
  
 
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
 
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
  
    else
    {  
        if( (root->left == NULL) || (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else  
            *root = *temp; 

            free(temp);  
        }  
        else
        {  
            Node* temp = minValueNode(root->right);  
  
            root->key = temp->key;  
  
            root->right = deleteNode(root->right, temp->key);  
        }  
    }  
   
    if (root == NULL)  
    return root;  
  

    root->height = 1 + max(height(root->left),  height(root->right));  

    int balance = getBalance(root);  
  
    if (balance > 1 && getBalance(root->left) >= 0)  
        return rightRotate(root);  
 
    if (balance > 1 && getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    if (balance < -1 && getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    if (balance < -1 && getBalance(root->right) > 0){  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
} 
  
  
int main()  
{  
    Node *root = NULL;  
    
    //creating AVL tree  
    root = insert(root, 5); 
    root = insert(root, 3); 
    root = insert(root, 2); 
    root = insert(root, 4); 
    root = insert(root, 7); 
    root = insert(root, 6); 
    root = insert(root, 8); 
    
    int a,x;
    while(1){
    cout<<" \n----------------------------------------------------------------------"<<endl;
    
    cout<<"\n1.Insert in AVL Tree.\n2.Delete a Node\n3.Pre-order traversal\n";
    cout<<"4.Exit\nEnter option:";
    cin>>a;
    cout<<"\n";
    switch(a){
        case 1: cout<<"Enter number to insert.";
                cin>>x;
                insert(root,x);
                cout<<"Node Inserted...\n";

                break;
        case 2: cout<<"Enter number to delete ";
                cin>>x;
                root = deleteNode(root, x);
                cout<<"\n"<<x<<" deleted\n";
                break;
        case 3: cout<<"\nPreorder traversal of binary tree is \n"; 
                preOrder(root); 
                break;  
        case 4: cout<<"Exiting...";
                exit(0);
        default:cout<<"Enter a valid option.";
                break;
        }
    }

    return 0;  
}