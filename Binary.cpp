#include <iostream>
#include <stdlib.h>
using namespace std;

class TreeNode
{
public:
		int value;
		TreeNode *right;
		TreeNode *left;

		TreeNode() 
		{
			value = -1;
			right = NULL;
			left = NULL;
		}
};

//Binary Search Tree
class BST
{
public:
		TreeNode *root;

		BST()
		{
			root = NULL;
		}

		bool searchBST(TreeNode *start, int key)
		{
			if (start == NULL)
				return false;
			if (start->value == key)
				return true;
			if (key > start->value)
				searchBST(start->right, key);
			else
				searchBST(start->left, key);
		}

		void addNodeBST(int key)
		{
			TreeNode *newNode = new TreeNode;
			TreeNode *chase, *follow;
			chase = follow = root;
			newNode->value = key;

			if(root == NULL)
			{
				root = newNode;
				return;
			}
			while (chase)
			{
				follow = chase;
				if (key == chase->value)
				{
					cout << "No duplicates, please!" << endl;
					return;
				}
				if (key < chase->value)
					chase = chase->left;
				else
					chase = chase->right;
			}
			//at this point, chase falls off and follow is pointing to parent
			if(key > follow->value)
				follow->right = newNode;
			else
				follow->left = newNode;
		}

		TreeNode* deleteBST(TreeNode *match, int key) 
		{
			TreeNode *temp;
			if(root == NULL) 
			{
				cout << "There is nothing in the tree to delete." << endl;
				return NULL;
			}
			//Go left if smaller
			else if(key < match->value) 
			{
				match->left = deleteBST(match->left, key);
			}
			//Go right if larger
			else if(key > match->value) 
			{
				match->right = deleteBST(match->right, key);
			}
			//If equal, delete
			else 
			{
				//Case 2: One child
				if(match->left == NULL) 
				{
					temp = match->right;
					delete match;
					return temp;
				} 
				else if(match->right == NULL) 
				{
					temp = match->left;
					delete match;
					return temp;
				}
				//Case 3: Two Children
				temp = match->right;
				while(temp->left != NULL) 
				{
					temp = temp->left;
				}
				match->value = temp->value;
				match->right = deleteBST(match->right, temp->value);
			}
			return match;
		}

		void preDisplayBST(TreeNode *current)
		{
			if(current != NULL)
			{
				cout << current->value << endl;
				preDisplayBST(current->left);
				preDisplayBST(current->right);
			}
		}

		void postDisplayBST(TreeNode *current)
		{
			if(current != NULL)
			{
				postDisplayBST(current->left);
				postDisplayBST(current->right);
				cout << current->value << endl;
			}
		}

		void inOrdDisplayBST(TreeNode *current)
		{
			if(current != NULL)
			{
				inOrdDisplayBST(current->left);
				cout << current->value << endl;
				inOrdDisplayBST(current->right);
			}
		}
		
		void display(char answer)
		{
			TreeNode *current;
			current = root;
			if(answer == 'a')
				preDisplayBST(current);
			else if(answer == 'b')
				postDisplayBST(current);
			else if(answer == 'c')
				inOrdDisplayBST(current);
			else
				cout << "Incorrect option." << endl;
		}
};

int main()
{
	TreeNode *pointer;
	int choice, value;
	char answer;
	BST treeObj;

	while(1)
	{
		cout << "____________" << endl;
		cout << "1 to Add" << endl;
		cout << "2 to Search" << endl;
		cout << "3 to Delete" << endl;
		cout << "4 to Display" <<endl;
		cout << "____________" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1: cout << "Add what?" << endl;
						cin >> value;
						treeObj.addNodeBST(value);
						break;
			case 2: cout << "Search for?" << endl;
						cin >> value;
						cout << treeObj.searchBST(treeObj.root, value) << endl << endl;
						break;
			case 3: cout << "Delete what?" << endl;
						cin >> value;
						treeObj.deleteBST(treeObj.root, value);
						break;
			case 4: cout << "Display in (a) preorder, (b) postorder, or (c) in order? " << endl << endl;
						cin >> answer;
						treeObj.display(answer);
						break;

			default: exit(1);
		}
	}
	return 1;
}