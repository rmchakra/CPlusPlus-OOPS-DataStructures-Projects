#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include "bst.h"

/**
* A special kind of node for an AVL tree, which adds the height as a data member, plus 
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
	// Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int getHeight() const;
    void setHeight(int height);

    // Getters for parent, left, and right. These need to be redefined since they 
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int mHeight;
};

/*
--------------------------------------------
Begin implementations for the AVLNode class.
--------------------------------------------
*/

/**
* Constructor for an AVLNode. Nodes are initialized with a height of 0.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent)
    : Node<Key, Value>(key, value, parent)
    , mHeight(0)
{

}

/**
* Destructor.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* Getter function for the height. 
*/
template<typename Key, typename Value>
int AVLNode<Key, Value>::getHeight() const
{
    return mHeight;
}

/**
* Setter function for the height. 
*/
template<typename Key, typename Value>
void AVLNode<Key, Value>::setHeight(int height)
{
    mHeight = height;
}

/**
* Getter function for the parent. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key,Value>*>(this->mParent);
}

/**
* Getter function for the left child. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key,Value>*>(this->mLeft);
}

/**
* Getter function for the right child. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key,Value>*>(this->mRight);
}

/*
------------------------------------------
End implementations for the AVLNode class.
------------------------------------------
*/

/**
* A templated balanced binary search tree implemented as an AVL tree.
*/
template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
	// Methods for inserting/removing elements from the tree. You must implement
	// both of these methods. 
    AVLTree();
    virtual void insert(const std::pair<Key, Value>& keyValuePair) override;
    void remove(const Key& key);

private:
	/* Helper functions are strongly encouraged to help separate the problem
	   into smaller pieces. You should not need additional data members. */
int get_height(AVLNode<Key, Value>* x);
void left_rotate(AVLNode<Key, Value>* z, AVLNode<Key, Value>* y, AVLNode<Key, Value>* x);
void right_rotate(AVLNode<Key, Value>* z, AVLNode<Key, Value>* y, AVLNode<Key, Value>* x);
void balance();
bool is_balanced(AVLNode<Key, Value>& x);
void update_height(AVLNode<Key, Value>& x);

};

/*
--------------------------------------------
Begin implementations for the AVLTree class.
--------------------------------------------
*/

/**
* Insert function for a key value pair. Finds location to insert the node and then balances the tree. 
*/
template<typename Key, typename Value>
AVLTree<Key, Value>::AVLTree()
{//TODO - my own TODO - this redefines mRoot as AVL Node

    std::cout<<"AVL TREE BEING CONSTRUCTED"<<std::endl;
}
template<typename Key, typename Value>
void AVLTree<Key, Value>::insert(const std::pair<Key, Value>& keyValuePair)
{//to access inherited members use this->
    //to make mRoot into an AVL node use
    // TODO
    BinarySearchTree< Key, Value>::insert(keyValuePair);
    std::cout<<"AVLTREE INSERT"<<std::endl;
    //now call find on the inserted key
    //but find gives a pair
    //so write another find_node function
}   


/**
* Remove function for a given key. Finds the node, reattaches pointers, and then balances when finished. 
*/
template<typename Key, typename Value>
void AVLTree<Key, Value>::remove(const Key& key)
{
   // TODO
}
template<typename Key, typename Value>
int get_height(AVLNode<Key, Value>* x)
{
    if(x==NULL) return -1;//if its a NULL pointer height is -1
    return x->getHeight();
}

template<typename Key, typename Value>
void left_rotate(AVLNode<Key, Value>* z)
{//z is the unbalanced node

    // AVLNode<Key, Value>* y = z.right;
    
    // y.parent = z.parent//y's parent is set as parent of z
    // if(y.parent == NULL)
    // {//if z previously was the root
    //     this->mRoot = y;
    // }
    // else
    // {//setting y as child of z's parent

    //      z.is right child
    //     {
    //         z.parent.right = y;
    //     }

    //     z.is left child
    //     {
    //         z.parent.left = y;
    //     }
    // }

    // z.right = y.left; 
    // if(z.right!=NULL)
    // {
    //     z.right.parent = z
    // }

    // z.is left child
    // y.left = z;
    // z.parent = y
    // update_height(z)
    // update_height(y)
}
template<typename Key, typename Value>
void right_rotate(AVLNode<Key, Value>* z, AVLNode<Key, Value>* y, AVLNode<Key, Value>* x)
{

}
template<typename Key, typename Value>
void balance()
{

}
template<typename Key, typename Value>
bool is_balanced(AVLNode<Key, Value>& x)
{
    return true;//dummy value for now
}

template<typename Key, typename Value>
void update_height(AVLNode<Key, Value>& x)
{
    x.setHeight(1+std::max(get_height(x.getLeft()),get_height(x.getRight())));
}
/*
------------------------------------------
End implementations for the AVLTree class.
------------------------------------------
*/

#endif