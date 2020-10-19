#include<bits/stdc++.h>
using namespace std;

struct Tree{
int val;
struct Tree* left;
struct Tree* right;
};


Tree* create(int data){
Tree* newnode = new Tree();
newnode->val = data;
newnode->left = newnode->right = NULL;
return newnode;
}

Tree* insert(Tree* root, int data){
	
	if(root == NULL){
		root = create(data);
	}
	else if (data <= root->val){
		root->left = insert(root->left,data);
	}
	else
		root->right = insert(root->right,data);
		return root;
	}

bool search(Tree* root, int data){
	if(root == NULL)
		return false;
	else if(root->val == data)
		return true;
	else if(data <= root->val)
	return search(root->left,data);
	else
	return search(root->right,data);
}

Tree* Find(Tree* root, int data){
	if(root == NULL)
		return NULL;
	else if(root->val == data)
		return root;
	else if(data <= root->val)
		return Find(root->left,data);
	else
		return Find(root->right,data);
}

Tree* max(Tree* root){
	while(root->right!=NULL)
		root = root->right;
	return root;
}

Tree* min(Tree* root){
	while(root->left!=NULL)
		root = root->left;
	return root;
}

Tree* deleteNode(int data, Tree* &root)
{
    if (!root)
    {
        return NULL;
    }
    
    if (data < root->val)
    {
        root->left = deleteNode(data, root->left);
    }
    
    else if (data > root->val)
    {
        root->right = deleteNode(data, root->right);
    }
    
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        
        else if (root->left && root->right)
        {
            int temp = max(root->left)->val;
            root->val = temp;
            root->left = deleteNode(temp, root->left);
        }
        
        else
        {
            Tree* temp;
            if (root->left)
            {
                temp = root->left;
            }
            
            else
            {
                temp = root->right;
            }
            
            delete root;
            return temp;
        }
    }
    
    return root;
}

Tree* suc(Tree* root, int data){

struct Tree* curr = Find(root,data);

if(curr == NULL)
    return NULL;

if(curr->right!=NULL)
    return min(curr->right);

else{
    struct Tree* ancestor = root;
    struct Tree* successor = NULL;
    while(ancestor!=curr){
    if(curr->val < ancestor->val){
    successor = ancestor;
    ancestor = ancestor->left;
    }
    else
    ancestor = ancestor->right;
}

return successor;
}

}


Tree* pre(Tree* root, int data) {

struct Tree* curr = Find(root,data);

if(curr == NULL)
    return NULL;

if(curr->left!=NULL)
    return max(curr->left);

else{
    struct Tree* ancestor = root;
    struct Tree* predecessor = NULL;
    while(ancestor!=curr){
        if(curr->val > ancestor->val){
        predecessor = ancestor;
        ancestor = ancestor->right;
    }

    else
        ancestor = ancestor->left;
}

return predecessor;
}

}


void preorder(Tree* root){
if(root == NULL)
return;
cout<<root->val<<" ";
preorder(root->left);
preorder(root->right);
}



int main(){
Tree* root = NULL;
int z;

do
    {
        cout<<"Enter Choice\n";
        cout<<" 1. Insert elements\n 2. Search for an element\n 3. Find Maximum element in tree\n 4. Find Minimum element in tree\n 5. Find successor\n 6. Find predecessor\n 7. Delete an element\n 8. Print\n0. Exit\n";
        cin>>z;
        switch (z)
        {
            case 1:
                cout<<"Enter number of elements: ";
                int n;
                cin>>n;
                cout<<"Enter the elements: ";
                while(n--){
                    int k;
                    cin>>k;
                    root = insert(root,k);
                }
                break;
            case 2:
                int x;
                cout << "Enter element \n";
                cin>>x;
                if(search(root,x)){
                    cout<<"The element was found\n";

                }
                else
                    cout<<"The element not present in BST\n";

                break;
            case 3:
                cout<<"The maximum element is: "<<max(root)->val<<endl;
                break;
            case 4:
                cout<<"The minimum element is: "<<min(root)->val<<endl;
                break;
            case 5:
                int k;
                cout<<"Enter the value to find successor: \n";
                cin>>k;

                cout<<"The successor is: "<<suc(root,k)->val<<endl;
                break;
            case 6:
                int r;
                cout<<"Enter the value to find predecessor: \n";
                cin>>r;

                cout<<"The predecessor is: "<<pre(root,r)->val<<endl;
                break;
            case 7:
                int d;
                cout<<"Enter the value to be deleted\n";
                cin>>d;
                deleteNode(d, root);
                break;
            
            case 8:
            cout << "The Entered Tree is \n";  
            preorder(root);
            cout<<"\n";
            break;
            
            case 0:
                break;
            
            default:
               cout<<"Wrong Option";
        }
    } while (z != 0);

}