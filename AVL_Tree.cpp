#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	int height;
	Node* left;
	Node* right;
};

int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
} 

Node *rightRotate(Node* &y)  
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

Node *leftRotate(Node* &x)  
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
    return height(N->left) -  
           height(N->right);  
}   

Node* newNode(int key)  
{  
    Node* node = new Node(); 
    node->data = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;
    return(node);  
}

class BST
{
	private:
		
		int* inorderArr;
		int index;
		
		int size;

		int max(int a, int b)  
		{	  
    		return (a > b)? a : b;  
		}
		
	public:
		
		Node* root;
		
		BST();
		
		Node* find(int);
		Node* insert(int key, Node* &node);
		Node* deleteNode(int data, Node* &root);
		
		int min(Node*);
		int max(Node*);
		
		int successor(int);
		int predecessor(int);
		
		void inorder(Node*);
		void preorder(Node*);
};

BST::BST()
{
	root = NULL;
	size = 0;
	
	index = -1;
	inorderArr = NULL;
}

Node* BST::find(int data)
{
	if (!root)
	{
		return NULL;
	}
	
	Node* temp = root;
	
	while(1)
	{
		if (temp->data == data)
		{
			return temp;
		}
		
		if (data < temp->data)
		{
			if (temp->left)
			{
				temp = temp->left;
				continue;
			}
			
			else
			{
				return temp;
			}
		}
		
		if (data > temp->data)
		{
			if (temp->right)
			{
				temp = temp->right;
				continue;
			}
			
			else
			{
				return temp;
			}
		}
	}
}

Node* BST::insert(int key, Node* &node)
{
	if (node == NULL)  
    {
    	node = newNode(key);
    	return node;
	}
  
    if (key < node->data)  
        node->left = insert(key, node->left);  
    else if (key > node->data)  
        node->right = insert(key, node->right);  
    else
        return node;  
  
    node->height = 1 + max(height(node->left), height(node->right));  
  
    int balance = getBalance(node);  
  
    if (balance > 1 && key < node->left->data)  
        return rightRotate(node);  
  
    if (balance < -1 && key > node->right->data)  
        return leftRotate(node);  
  
    if (balance > 1 && key > node->left->data)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  

    if (balance < -1 && key < node->right->data)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
    
    return node;
}

Node* BST::deleteNode(int data, Node* &root)
{
	if (!root)
	{
		return NULL;
	}
	
	if (data < root->data)
	{
		root->left = deleteNode(data, root->left);
	}
	
	else if (data > root->data)
	{
		root->right = deleteNode(data, root->right);
	}
	
	else
	{
		if (!root->left && !root->right)
		{
			delete root;
			root = NULL;
		}
		
		else if (root->left && root->right)
		{
			int temp = max(root->left);
			root->data = temp;
			root->left = deleteNode(temp, root->left);
		}
		
		else
		{
			Node* temp;
			if (root->left)
			{
				temp = root->left;
			}
			
			else
			{
				temp = root->right;
			}
			
			delete root;
			root = temp;
		}
	}
	
	if (root == NULL)  
    return root;  
  
    root->height = 1 + max(height(root->left), height(root->right));  
  
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
  
    if (balance < -1 && getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }
  
    return root;
}

int BST::min(Node* root)
{
	if (root)
	{
		Node* temp = root;
		
		while(temp->left)
		{
			temp = temp->left;
		}
		
		return temp->data;
	}

	else
	{
		return 0;
	}
}

int BST::max(Node* root)
{
	if (root)
	{
		Node* temp = root;
		
		while(temp->right)
		{
			temp = temp->right;
		}
		
		return temp->data;
	}

	else
	{
		return 0;
	}
}

int BST::successor(int data)
{
	inorderArr = new int[size];
	int temp = 0;
	
	inorder(root);
	
	for (int a = 0; a < index; a++)
	{
		if (inorderArr[a] == data)
		{
			temp = inorderArr[a+1];
			break;
		}
	}
	
	delete inorderArr;
	inorderArr = NULL;
	index = -1;
	
	return temp;
}

int BST::predecessor(int data)
{
	inorderArr = new int[size];
	int temp = 0;
	
	inorder(root);
	
	for (int a = 1; a <= index; a++)
	{
		if (inorderArr[a] == data)
		{
			temp = inorderArr[a-1];
			break;
		}
	}
	
	delete inorderArr;
	inorderArr = NULL;
	index = -1;
	
	return temp;
}

void BST::inorder(Node* root)
{
	if (!root)
	{
		return;
	}
			
	inorder(root->left);
		
	if (inorderArr)
	{
		inorderArr[++index] = root->data;
	}
			
	else
	{
		cout << root->data << endl;
	}

	inorder(root->right);
}

void BST::preorder(Node* root)
{
	if (!root)
	{
		return;
	}
	
	cout << root->data << endl;
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	BST tree;
	
	int choice = -1, temp, temparr[100];
	while (choice != 11)
	{
		cout << "1. Insert\n2. Delete\n3. Search\n4. Minimum\n5. Maximum\n6. Predecessor\n7. Successor\n8. Insert Sequence\n9. Print Inorder\n10. Print Preorder\n11. Exit\n";
		cout << "Enter Choice: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				cout << "Enter Value: ";
				cin >> temp;
				tree.root = tree.insert(temp, tree.root);
				break;

			case 2:
				cout << "Enter Value: ";
				cin >> temp;
				tree.root = tree.deleteNode(temp, tree.root);
				break;

			case 3:
				cout << "Enter Value: ";
				cin >> temp;
				if (tree.find(temp) && tree.find(temp)->data == temp)
				{
					cout << "Found" << endl;
				}
				else
				{
					cout << "Not Found" << endl;
				}

			case 4:
				cout << tree.min(tree.root) << endl;
				break;

			case 5:
				cout << tree.max(tree.root) << endl;
				break;

			case 6:
				cout << "Enter Value: ";
				cin >> temp;
				cout << tree.predecessor(temp) << endl;
				break;

			case 7:
				cout << "Enter Value: ";
				cin >> temp;
				cout << tree.successor(temp) << endl;
				break;

			case 8:
				cout << "Enter Number of Values to Insert: ";		
				cin >> temp;
				for (int a = 0; a < temp; a++)
				{
					cout << "Enter Value: ";
					cin >> temparr[a];
					tree.root = tree.insert(temparr[a], tree.root);
				}
				break;

			case 9:
				tree.inorder(tree.root);
				break;

			case 10:
				tree.preorder(tree.root);
				break;

			case 11:
				break;

			default:
				cout << "Invalid" << endl;
				break;
		}

		cout << endl << endl;
	}
}

