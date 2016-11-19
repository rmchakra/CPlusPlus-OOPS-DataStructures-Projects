#ifndef BST_H
#define BST_H

#include <iostream>
#include <cstdlib>
#include <utility>

/**
* A templated class for a Node in a search tree. This represents a node in a normal
* binary search tree, but can also be extended in the future for other kinds of search trees, 
* such as Red Black trees, Splay trees, and AVL trees. You do NOT need to implement any 
* functionality or add additional data members or helper functions.
*/
template <typename Key, typename Value>
class Node 
{
public:
	// Constructor/destructor
	Node(const Key& key, const Value& value, Node<Key, Value>* parent);
	virtual ~Node();

	// Getters for the data in this node.
	const std::pair<Key, Value>& getItem() const;
	std::pair<Key, Value>& getItem();
	const Key& getKey() const;
	const Value& getValue() const;
	Key& getKey();
	Value& getValue();

	// These functions are virtual so that any derived classes, such as the 
	// AVLNode, can be overwritten to return AVLNode pointers. This is one
	// of the many advantages to using getters/setters instead of public data
	// in a struct.
	virtual Node<Key, Value>* getParent() const;
	virtual Node<Key, Value>* getLeft() const;
	virtual Node<Key, Value>* getRight() const;

	// Setters for the nodes data.
	void setParent(Node<Key, Value>* parent);
	void setLeft(Node<Key, Value>* left);
	void setRight(Node<Key, Value>* right);
	void setValue(const Value &value);

protected:
	std::pair<Key, Value> mItem;
	Node<Key, Value>* mParent;
	Node<Key, Value>* mLeft;
	Node<Key, Value>* mRight;
};

/*  
-----------------------------------------
Begin implementations for the Node class.
-----------------------------------------
*/

/**
* Explicit constructor for a node.
*/
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) 
	: mItem(key, value)
	, mParent(parent)
	, mLeft(NULL)
	, mRight(NULL)
{ 

} 

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed within the deleteAll() helper method in the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node() 
{ 

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<Key, Value>& Node<Key, Value>::getItem() const 
{ 
	return mItem; 
}

/**
* A non-const getter for the item. 
*/
template<typename Key, typename Value>
std::pair<Key, Value>& Node<Key, Value>::getItem() 
{ 
	return mItem; 
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const 
{ 
	return mItem.first; 
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const 
{ 
	return mItem.second; 
}

/**
* A non-const getter for the key.
*/
template<typename Key, typename Value>
Key& Node<Key, Value>::getKey()
{
	return mItem.first;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
	return mItem.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const 
{ 
	return mParent; 
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const 
{ 
	return mLeft; 
}

/**
* An implementation of the virtual function for retreiving the right child. 
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const 
{ 
	return mRight; 
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent) 
{ 
	mParent = parent; 
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left) 
{ 
	mLeft = left; 
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right) 
{ 
	mRight = right; 
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value) 
{ 
	mItem.second = value; 
}

/*  
---------------------------------------
End implementations for the Node class.
---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree 
{
	public:
		// Constructor/destructor.
		BinarySearchTree();
		~BinarySearchTree();
  
  		// A virtual insert function lets future derivations of this class implement
  		// their specific insert logic.
  		virtual void insert(const std::pair<Key, Value>& keyValuePair);


  		// Deletes all nodes in the tree and resets for use.
  		void clear();

  		// Prints the contents of the tree in a nice format. Useful for debugging.
  		void print() const;

	public:
		/**
		* An internal iterator class for traversing the contents of the BST.
		* TODO: You must implement this!
		*/
		class iterator 
		{
			public:
				// Constructors - must be implemented below!
				iterator();
				iterator(Node<Key,Value>* ptr);

				// Various operators - some must be implemented below!
				std::pair<Key,Value>& operator*(); // Already implemented for you.
				std::pair<Key,Value>* operator->(); // Already implemented for you.
				bool operator==(const iterator& rhs) const;
				bool operator!=(const iterator& rhs) const;
				iterator& operator=(const iterator& rhs);
				iterator& operator++();

			protected:
				// A pointer to the current node.
				Node<Key, Value>* mCurrent;

				/* Feel free to add additional data members and/or helper functions! */
		};

	public:
		// Access to data through iterators, just like you are used to with std::map, std::set, 
		// std::vector, etc.
		iterator begin();
		iterator end();
		iterator find(const Key& key) const;
  
	protected:
		Node<Key, Value>* internalFind(const Key& key) const;
		void printRoot (Node<Key, Value>* root) const;
		void deleteAll (Node<Key, Value>* root);

		/* Feel free to add additional member and/or helper functions! */

  		virtual void insert_helper(Node<Key, Value>& Curr_Node,const std::pair<Key, Value>& keyValuePair);	
		iterator find_helper(Node<Key, Value>& Curr_Node, const Key& key) const;



	public:
		// Main data member of the class.
		Node<Key, Value>* mRoot;
};

/*  
---------------------------------------------------------------
Begin implementations for the BinarySearchTree::iterator class.
---------------------------------------------------------------
*/  

/**
* Initialize the internal members of the iterator.
* You can choose what kind of iterator the default constructor should create.
*/
template<typename Key, typename Value>
BinarySearchTree<Key, Value>::iterator::iterator() 
{ //constructor scope doesnt extend outside iterator calss so cant access mRoot
	//but begin is outside the iterator class so can access mRoot
	// TODO

	mCurrent = NULL;

	//iterator(NULL);
}

/*

*/

/**
* Initialize the internal members of the iterator.
*/
template<typename Key, typename Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value>* ptr) 
{ 
	// TODO
	mCurrent = ptr;
}

/**
* Provides access to the item.
*/
template<typename Key, typename Value>
std::pair<Key, Value>& BinarySearchTree<Key, Value>::iterator::operator*() 
{ 
	return mCurrent->getItem();  
}

/**
* Provides access to the address of the item.
*/
template<typename Key, typename Value>
std::pair<Key, Value>* BinarySearchTree<Key, Value>::iterator::operator->() 
{ 
	return &(mCurrent->getItem()); 
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::iterator::operator==(const BinarySearchTree<Key, Value>::iterator& rhs) const
{
	// TODO
		return (mCurrent == rhs.mCurrent);
}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::iterator::operator!=(const BinarySearchTree<Key, Value>::iterator& rhs) const
{
	// TODO
	return (! (*this).operator== (rhs)); 
}

/**
* Sets one iterator equal to another iterator.
*/
template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator& BinarySearchTree<Key, Value>::iterator::operator=(const BinarySearchTree<Key, Value>::iterator& rhs)
{
	// TODO
		mCurrent = rhs.mCurrent;
		return *this;
}

/**
* Advances the iterator's location using an in-order traversal.
*/
template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator& BinarySearchTree<Key, Value>::iterator::operator++()
{
	// TODO
	//youre returning an iterator


	//if right child is not null then go right child then while to leftmost child
	if((*mCurrent).getRight()!=NULL)
	{
		mCurrent = (*mCurrent).getRight();
		while((*mCurrent).getLeft()!=NULL)
		{
			mCurrent = (*mCurrent).getLeft();
		}
	}
	//else
	else
	{
		Node<Key, Value>* parent = (*mCurrent).getParent();
		// then check if parent is null. 
		//reached here if not right children so return NULL
		if(parent == NULL) mCurrent = NULL;//reached node

		else
		{
				//if current node is the left child then only need to make current node point to parent
			if((*parent).getLeft() == mCurrent) mCurrent = parent;//if youre the left child then iterator 
			else
			{//else youre a right child or not a child (root)
					//then while youre the right child 
						//go to the parent
						//check if the current has no parent (youre reaching the root from right)then return NULL
					//after the while again go to the parent
				while((*parent).getRight() == mCurrent)
				{
					mCurrent = (*mCurrent).getParent();
					parent = (*mCurrent).getParent();
					if(parent == NULL) break;
				}
				mCurrent = parent;
			}

		}

	}	
	return *this;
}

/*  
-------------------------------------------------------------
End implementations for the BinarySearchTree::iterator class.
-------------------------------------------------------------
*/

/*  
-----------------------------------------------------
Begin implementations for the BinarySearchTree class.
-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree() 
	: mRoot(NULL)
{ 

}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree() 
{ 
	deleteAll(mRoot); 
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{ 
	printRoot(mRoot);
	std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/
template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::begin()
{
	// TODO


	Node<Key, Value>* curr_Node = mRoot;

	while((*curr_Node).getLeft() !=NULL)
	{
		curr_Node= (*curr_Node).getLeft();
	}

	return iterator(curr_Node); // A dummy return value until you provide your implementation. 
}

/**
* Returns an iterator whose value means INVALID
*/
template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::end()
{
	// TODO
	//effectively carries out return iterator(NULL); 
	return iterator();
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/


template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::find(const Key& key) const 
{
	// TODO
	//return iterator(); // A dummy return value until you provide your implementation. 
	if(mRoot == NULL)
	{//cant be found in an empty tree
		return iterator();
	}

	return find_helper(*mRoot, key);

}

/**
* An insert method to insert into a Binary Search Tree. The tree will not remain balanced when 
* inserting.  Implementing this will help you test your iterator, but is not necessary: if you
* don't implement it, then you can put your entire insert implementation in avlbst.h
*/
 template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::find_helper(Node<Key, Value>& Curr_Node, const Key& key) const
{
		if(key == Curr_Node.getKey())
		{//if its found give the iterator with the pointer to the correct value
			return iterator(&Curr_Node);
		}

		if(key < Curr_Node.getKey())
	    {
	       	if(Curr_Node.getLeft() == NULL)
	       	{//value will not be found
	       		return iterator();//returns iterator that points to NULL which means it isnt found
	      	
	       	}
	       	else
	       	{
	        	return find_helper(*(Curr_Node.getLeft()),key);
	       	}
	    }
	    // go right
	    else
	    {
	       	if(Curr_Node.getRight() == NULL)
	       	{
	       		//value will not be found
	       		return iterator();//returns iterator that points to NULL which means it isnt found
	      	
	       	}
	       	else
	       	{
	        	return find_helper(*(Curr_Node.getRight()),key);
	       	}
	    }
}


template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<Key, Value>& keyValuePair)
{//Curr node would be the root

	if(mRoot == NULL)
	{//this is when you add to the tree for the first time
		Node<Key, Value>* new_node = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, NULL);
      	
      	//make root into new node
      	mRoot = new_node;
		return;
	}


	insert_helper(*mRoot, keyValuePair);
}
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::insert_helper(Node<Key, Value>& Curr_Node,const std::pair<Key, Value>& keyValuePair)
{//if the left or right child is null  then add to that. If neither is then recursively call

    if(keyValuePair.first < Curr_Node.getKey())
    {
       	if(Curr_Node.getLeft() == NULL)
       	{
       		Node<Key, Value>* new_node = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, &Curr_Node);
       		Curr_Node.setLeft(new_node);
       		return;
      	
       	}
       	else
       	{
        	 insert_helper(*(Curr_Node.getLeft()),keyValuePair);
       	}
    }
    // go right
    else
    {
       	if(Curr_Node.getRight() == NULL)
       	{
       		Node<Key, Value>* new_node = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, &Curr_Node);
       		Curr_Node.setRight(new_node);
       		return;

       	}
       	else
       	{
        	 insert_helper(*(Curr_Node.getRight()),keyValuePair);
       	}
    }

}


/**
* A method to remove all contents of the tree and reset the values in the tree 
* for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
	deleteAll(mRoot);
	mRoot = NULL;
}

/**
* Helper function to find a node with given key, k and 
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const 
{
	Node<Key, Value>* curr = mRoot;
	while (curr) 
	{
		if (curr->getKey() == key) 
		{
			return curr;
		} 
		else if (key < curr->getKey()) 
		{
			curr = curr->getLeft();
		} 
		else 
		{
			curr = curr->getRight();
		}
	}
	return NULL;
}

/**
* Helper function to print the tree's contents
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::printRoot (Node<Key, Value>* root) const
{
	if (root != NULL)
	{
		std::cout << "[";
		printRoot (root->getLeft());
		std::cout << " (" << root->getKey() << ", " << root->getValue() << ") ";
		printRoot (root->getRight());
		std::cout << "]";
	}
}

/**
* Helper function to delete all the items
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::deleteAll (Node<Key, Value>* root)
{
	if (root != NULL)
	{
		deleteAll (root->getLeft());
		deleteAll (root->getRight());
		delete root;
	}
}

/*  
---------------------------------------------------
End implementations for the BinarySearchTree class.
---------------------------------------------------
*/

#endif
