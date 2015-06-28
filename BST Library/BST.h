//Node structure is inspired from the online BST tutorial: http://www.cprogramming.com/tutorial/lesson18.html
//Many methods have been created by using the pseudo code from CLRS

#pragma once

#include <iostream>     
using namespace std;

struct node
{
	int key_value;
	node *left;
	node *right;
	node *parent;
};

class btree
{
public:
	~btree();

	btree::btree()
	{
		root = NULL;
		cout << "New tree has been created" << endl;
	}

	void btree::insert(int key)
	{
		node *leaf = new node;
		leaf->key_value = key;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->parent = NULL;
		insert(key, leaf);
	}

	node *btree::search(int key)
	{
		return search(key, root);
	}

	node btree::minimum()
	{
		return *minimum(root);
	}

	node btree::maximum()
	{
		return *maximum(root);
	}

	node btree::successor(int key)
	{
		return *successor(search(key, root));
	}

	node btree::predecessor(int key)
	{
		return *predecessor(search(key, root));
	}

	void btree::delete_node(int key)
	{
		delete_node(search(key, root));
	}

	void btree::print_inorder_tree_walk()
	{
		inorder_tree_walk(root);
		cout << endl;
	}

	void btree::print_minimum()
	{
		cout << "minimum: " << minimum().key_value << endl;
	}

	void btree::print_maximum()
	{
		cout << "maximum: " << maximum().key_value << endl;
	}

	void btree::print_successor(int key)
	{
		cout << "successor of " << key << " is: " << successor(key).key_value << endl;
	}

	void btree::print_predecessor(int key)
	{
		cout << "predecessor of " << key << " is: " << predecessor(key).key_value << endl;
	}

	void btree::print_delete_node(int key)
	{
		delete_node(key);
		cout << key << " has been deleted" << endl;
	}

	void print_insert(int key)
	{
		insert(key);
		cout << key << " has been inserted" << endl;
	}

private:
	node *root;

	//returns the node with the closest lesser value
	node *btree::successor(node *leaf)
	{
		node* y;
		if (leaf->right != NULL)
		{
			return minimum(leaf->right);
		}
		y = leaf->parent;

		while (y != NULL && leaf == y->right)
		{
			leaf = y;
			y = y->parent;
		}
		return y;
	}

	//returns the node with the closest larger value
	node *btree::predecessor(node *leaf)
	{
		node* y;
		if (leaf->left != NULL)
		{
			return maximum(leaf->left);
		}
		y = leaf->parent;

		while (y != NULL && leaf == y->left)
		{
			leaf = y;
			y = y->parent;
		}
		return y;
	}

	//returns the node with minimum value
	node *btree::minimum(node *leaf)
	{
		while (leaf->left != NULL)
		{
			leaf = leaf->left;
		}
		return leaf;
	}

	//returns the node with maximum value
	node *btree::maximum(node *leaf)
	{
		while (leaf->right != NULL)
		{
			leaf = leaf->right;
		}
		return leaf;
	}

	//walks through the tree, in order, and prints out the keys, in order.
	void btree::inorder_tree_walk(node *leaf)
	{
		if (leaf != NULL)
		{
			inorder_tree_walk(leaf->left);
			cout << leaf->key_value << " ";
			inorder_tree_walk(leaf->right);
		}
	}

	//An iterative way to insert values into the BST
	void btree::insert(int key, node *leaf)
	{
		node *x = root;
		node *y = NULL;
		while (x != NULL)
		{
			y = x;
			if (leaf->key_value < x->key_value)
				x = x->left;
			else
				x = x->right;
		}
		leaf->parent = y;
		if (y == NULL)
			root = leaf;
		else if (leaf->key_value < y->key_value)
			y->left = leaf;
		else
			y->right = leaf;
	}

	//looks up a value iteratively and returns a node.
	node *btree::search(int key, node *leaf)
	{
		while (leaf != NULL && key != leaf->key_value)
		{
			if (key < leaf->key_value)
				leaf = leaf->left;
			else
				leaf = leaf->right;
		}
		return leaf;
	}

	//transplant is an auxillary method to delete_node, to simplify deleting specific nodes which must be resolved by moving subtrees around the BST
	void transplant(node *u, node *v)
	{
		if (u->parent == NULL)
			root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;

		if (v != NULL)
			v->parent = u->parent;
	}

	//deletes a node in the BST
	void delete_node(node *z)
	{
		if (z->left == NULL)
			transplant(z, z->right);
		else if (z->right == NULL)
			transplant(z, z->left);
		else
		{
			node *y = minimum(z->right);
			if (y->parent != z)
			{
				transplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			transplant(z, y);
			y->left = z->left;
			y->left->parent = y;
		}
	}
};

