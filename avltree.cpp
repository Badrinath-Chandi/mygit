/* AVL Tree Implementation in C++*/

#include<iostream>
#include<stdio.h>

using namespace std;

class treeNode
{
public:

	int data;
	int height;

	treeNode* left;
	treeNode* right;

	treeNode(int data) :data(data), left(NULL), right(NULL),height(1) {}

	int getBalance(treeNode* left, treeNode* right)
	{
		if (left == NULL && right == NULL)
			return 0;
		if (left == NULL)
			return (0 - right->height);
		if (right == NULL)
			return left->height;
		return (left->height - right->height);
	}

	int max(int a, int b) {
		return (a > b) ? a : b;
	}
	int getHeight(treeNode* node) {
		if (node == NULL)
			return 0;
		return max(getHeight(node->left), getHeight(node->right)) + 1;
	}

	treeNode*  rightRotate(treeNode* node)
	{
		treeNode* x = node->left;
		treeNode* y = x->right;
		x->right = node;
		node->left = y;
		x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
		return x;
	}

	treeNode*  leftRotate(treeNode* node)
	{
		treeNode* x = node->right;
		treeNode* y = x->left;

		x->left = node;
		node->right = y;

		x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
		return x;
	}
	treeNode* insert(treeNode*node, int data)
	{
		if (node == NULL)
			return new treeNode(data);
		if (node->data > data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);\

		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

		int balance = getBalance(node->left, node->right);

		if (balance > 1 && data < node->left->data)
		{
			return rightRotate(node);
		}
		else if (balance > 1 && data > node->left->data)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		else if (balance < -1 && data > node->right->data)
		{
			return leftRotate(node);
		}
		else if (balance < -1)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}

	void preOrder(treeNode* node)
	{
		if (node == NULL)
			return;
		cout << node->data << endl;
		preOrder(node->left);
		preOrder(node->right);
	}

	treeNode* getminright(treeNode* node)
	{
		treeNode* tmp = node;
		while (node) {
			tmp = node;
			node = node->left;
		}
		return tmp;
	}

	int getSingleNodeBalance(treeNode *node)
	{
		return getBalance(node->left, node->right);
	}
	treeNode* deleteNode(treeNode* node, int data)
	{
		if (node == NULL)
			return node;
		if (data < node->data)
			node->left = deleteNode(node->left, data);
		else if (data > node->data)
			node->right = deleteNode(node->right, data);
		else {
			/* Delete Node*/
			treeNode* tmp = NULL;
			if (node->left == NULL || node->right == NULL) {
				tmp = (node->left) ? node->left : node->right;
				//No Child for node Case
				if (tmp == NULL) {
					delete(node);
					node = NULL;
				}
				else {
					if (tmp == node->left) {
						node->data = node->left->data;
						node->left = deleteNode(node->left, node->left->data);
					}
					else {
						node->data = node->right->data;
						node->right = deleteNode(node->right, node->right->data);
					}
				}
			}
			/* Both Children Alive*/
			else {
				treeNode* tmp = getminright(node->right);
				node->data = tmp->data;
				node->right = deleteNode(node->right, tmp->data);
			}
		}
			if (node == NULL)
				return node;
			node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
			int balance = getBalance(node->left, node->right);

			if (balance > 1 && (getSingleNodeBalance(node->left) >= 0)) {
				return rightRotate(node);
			}
			else if (balance > 1 && (getSingleNodeBalance(node->left) < 0)) {
				node->left  = leftRotate(node->left);
				return rightRotate(node);
			}
			else if (balance < -1 && getSingleNodeBalance(node->right) <= 0) {
				return leftRotate(node);
			}
			else if (balance < -1 && getSingleNodeBalance(node->right) > 0) {
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
			return node;
		}
	
	
};

int main()
{
	treeNode *root = new treeNode(9);
	root = root->insert(root, 5);
	root = root->insert(root, 10);
	root = root->insert(root, 0);
	root = root->insert(root, 6);
	root = root->insert(root, 11);	
	root = root->insert(root, -1);
	root = root->insert(root, 1);
	root = root->insert(root, 2);
	cout << "Pre order traversal of the constructed AVL tree is " << endl;
	root->preOrder(root);
	root = root->deleteNode(root, 10);
	cout << "Pre order traversal of the deleted AVL tree is " << endl;
	root->preOrder(root);

	getchar();
	return 0;
}
