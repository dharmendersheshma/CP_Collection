#include <bits/stdc++.h> 
using namespace std; 
  
struct node{
	struct node* left;
	struct node* right;
	int data;
};

struct node* newNode(int val)
{
	struct node* node = new struct node();
	node->left = NULL;
	node->right = NULL;
	node->data = val;
	return node;
}
 
void printInorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->data << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 

void swap(int k, struct node* root, int l)
{
	if(root==NULL)
	{
		return;
	}
	if(l%k==0)
	{
		struct node* temp = root->left;
		root->left = root->right;
		root->right = temp;
		temp = NULL;
	}
	swap(k, root->left,l+1);
	swap(k, root->right, l+1);
}


int main() 
{ 
    int n;
    cin>>n;
    struct node* root = newNode(1);
    struct node* move = root;
    queue<struct node*> q;
    q.push(move);
    for(int i = 0; i < n; i++)
    {
    	int a, b;
    	cin>>a>>b;
    	if(a==-1 && b==-1)
    	{
    		q.pop();
    	}
    	else if(a==-1)
    	{
	    	struct node* temp = q.front();
	    	q.pop();
	    	temp->right = newNode(b);
	    	temp->left = NULL;
	    	q.push(temp->right);
    	}
    	else if(b==-1)
    	{
	    	struct node* temp = q.front();
	    	q.pop();
	    	temp->left = newNode(a);
	    	temp->right = NULL;
	    	q.push(temp->left);
    	}
    	else
    	{
    		struct node* temp = q.front();
	    	q.pop();
	    	temp->left = newNode(a);
	    	temp->right = newNode(b);
	    	q.push(temp->left);
	    	q.push(temp->right);
    	}
    }
    int t;
    cin>>t;
    while(t--)
    {
    	int x;
    	cin>>x;
    	swap(x,root, 1);
    	printInorder(root);
    	cout<<endl;
    }
    
    return 0; 
} 
  