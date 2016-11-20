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
bool is_right_child(AVLNode<Key, Value>* z);
bool is_left_child(AVLNode<Key, Value>* z);
void replace_node(AVLNode<Key, Value>* z, AVLNode<Key, Value>* y);

//this only changes relationship between z's parent and y
void left_rotate(AVLNode<Key, Value>* z);
void right_rotate(AVLNode<Key, Value>* z);
void d_left_rotate(AVLNode<Key, Value>* z);//double rotations
void d_right_rotate(AVLNode<Key, Value>* z);//double rotations
void balance();
bool is_balanced(AVLNode<Key, Value>& z);
void update_height(AVLNode<Key, Value>& x);
AVLNode<Key, Value>* insert_helper(AVLNode<Key, Value>& Curr_Node,const std::pair<Key, Value>& keyValuePair);
//Later insert helper should return the pointer to the node so that it can be rebalanced from there
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
    //every new node is defined as an avl node
    // TODO

    if(this->mRoot == NULL)
    {//this is when you add to the tree for the first time
        AVLNode<Key, Value>* new_node = new AVLNode<Key, Value>(keyValuePair.first, keyValuePair.second, NULL);
        
        //make root into new node
        this->mRoot = new_node ;
        return;
    }


    AVLNode<Key, Value>* new_node = insert_helper(*(this->mRoot), keyValuePair);


    //BinarySearchTree< Key, Value>::insert(keyValuePair);
    //std::cout<<"AVLTREE INSERT"<<std::endl;
    //now call find on the inserted key
    //but find gives a pair
    //so write another find_node function
}
//Later insert helper should return the pointer to the node so that it can be rebalanced from there
template<typename Key, typename Value>
AVLNode<Key, Value>* insert_helper(AVLNode<Key, Value>& Curr_Node,const std::pair<Key, Value>& keyValuePair)
{
    if(keyValuePair.first < Curr_Node.getKey())
    {
        if(Curr_Node.getLeft() == NULL)
        {
            AVLNode<Key, Value>* new_node = new AVLNode<Key, Value>(keyValuePair.first, keyValuePair.second, &Curr_Node);
            Curr_Node.setLeft(new_node);
            return new_node;
        
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
            AVLNode<Key, Value>* new_node = new AVLNode<Key, Value>(keyValuePair.first, keyValuePair.second, &Curr_Node);
            Curr_Node.setRight(new_node);
            return new_node;

        }
        else
        {
             insert_helper(*(Curr_Node.getRight()),keyValuePair);
        }
    }
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
int AVLTree<Key, Value>::get_height(AVLNode<Key, Value>* x)
{
    if(x==NULL) return -1;//if its a NULL pointer height is -1
    return x->getHeight();
}
template<typename Key, typename Value>
bool AVLTree<Key, Value>::is_right_child(AVLNode<Key, Value>* z)
{
    if(z->getParent() == NULL) return false;
    if((z->getParent())->getRight() == z)return true;

    return false;
}

template<typename Key, typename Value>
bool AVLTree<Key, Value>::is_left_child(AVLNode<Key, Value>* z)
{
    if(z->getParent() == NULL) return false;
    if((z->getParent())->getLeft() == z)return true;

    return false;
}





































template<typename Key, typename Value>
void AVLTree<Key, Value>::replace_node(AVLNode<Key, Value>* z, AVLNode<Key, Value>* y)
{//this only changes relationship between z's parent and y
//      y.parent = z.parent//y's parent is set as parent of z
//     if(y.parent == NULL)
//     {//if z previously was the root
//         this->mRoot = y;
//     }
//     else
//     {//setting y as child of z's parent

//          z.is right child
//         {
//             z.parent.right = y;
//         }

//         z.is left child
//         {
//             z.parent.left = y;
//         }
//     }

    //PSEUDOCODE ABOVE THIS POINT    
    y->setParent(z->getParent());
    if(y->getParent() == NULL)
    {//if z previously was the root
        this->mRoot = y;
    }
    else
    {//setting y as child of z's parent

         if(is_right_child(z))
        {
           ( z->getParent())->setRight(y);
        }

        if(is_left_child(z))
        {
             ( z->getParent())->setLeft(y);
        }
    }

}





template<typename Key, typename Value>
void AVLTree<Key, Value>::left_rotate(AVLNode<Key, Value>* z)
{//z is the unbalanced node

     //AVLNode<Key, Value>* y = z.right;
    
    //replace_node(z, y);

    // z.right = y.left; 
    // if(z.right!=NULL)
    // {
    //     z.right.parent = z;
    // }

    // y.left = z;
    // z.parent = y;

    // update_height(z)//which is now a child of y
    // update_height(y)


    //PSEUDOCODE ABOVE THIS POINT  
//setParent(z->getParent()

    AVLNode<Key, Value>* y = z->getRight();
    replace_node(z, y);

    z->setRight(y->getLeft()); 
    if(z->getRight()!=NULL)
    {
        (z->getRight())->setParent(z);
    }

    y->setLeft(z);
    z->setParent(y);

   // update_height(z)//which is now a child of y
    //update_height(y)
















}
template<typename Key, typename Value>
void AVLTree<Key, Value>::right_rotate(AVLNode<Key, Value>* z)
{
    //AVLNode<Key, Value>* y = z.left;
    //replace_node(z, y);

    // z.left = y.right; 
    // if(z.left!=NULL)
    // {
    //     z.left.parent = z;
    // }

    // y.right = z;
    // z.parent = y
    // update_height(z)
    // update_height(y)
}
template<typename Key, typename Value>
void AVLTree<Key, Value>::d_left_rotate(AVLNode<Key, Value>* z)
//double rotations
{
    //AVLNode<Key, Value>* y = z.right;
    //AVLNode<Key, Value>x = y.left;
    
    //replace_node(z, x);

    // z.right = x.left; 
    // if(z.right!=NULL)
    // {
    //     z.right.parent = z;
    // }

    // x.left = z;
    // z.parent = x;

    //above this does LHS Z actions

    //Now RHS y actions

    //y.left = x.right;
    //if(y.left!=NULL)
    // {
    //     y.left.parent = y;
    // }

    // x.right = y;
    // y.parent = x;






}
template<typename Key, typename Value>
void AVLTree<Key, Value>::d_right_rotate(AVLNode<Key, Value>* z)
//double rotations
{
     //AVLNode<Key, Value>* y = z.left;
    //AVLNode<Key, Value>x = y.right;

    
    //replace_node(z, x);

    // y.right = x.left; 
    // if(y.right!=NULL)
    // {
    //     y.right.parent = z;
    // }

    // x.left = y;
    // y.parent = x;

    //above this does LHS Y actions

    //Now RHS y actions

    //z.left = x.right;
    //if(z.left!=NULL)
    // {
    //     z.left.parent = z;
    // }

    // x.right = z;
    // z.parent = x;
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::balance()
{

}
template<typename Key, typename Value>
bool AVLTree<Key, Value>::is_balanced(AVLNode<Key, Value>& z)
{
    return true;//dummy value for now
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::update_height(AVLNode<Key, Value>& x)
{
    x.setHeight(1+std::max(get_height(x.getLeft()),get_height(x.getRight())));
}
/*
------------------------------------------
End implementations for the AVLTree class.
------------------------------------------
*/

#endif