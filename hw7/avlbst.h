#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath> 
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
AVLNode<Key, Value>* max_height_child(AVLNode<Key, Value>* Curr_Node, std::string& right);//returns child with max height
int get_height(AVLNode<Key, Value>* x);
bool is_right_child(AVLNode<Key, Value>* z);
bool is_left_child(AVLNode<Key, Value>* z);


//INSERT HELPERS
void balance(Node<Key, Value>* new_node);
void rotate(AVLNode<Key, Value>* z, std::string& zig_zag);//determines the kind of rotation and then performs it
//Each indentation is a helper function of less indented functions
    void left_rotate(AVLNode<Key, Value>* z);
    void right_rotate(AVLNode<Key, Value>* z);
    void d_left_rotate(AVLNode<Key, Value>* z);//double rotations
    void d_right_rotate(AVLNode<Key, Value>* z);//double rotations
        void replace_node(AVLNode<Key, Value>* z, AVLNode<Key, Value>* y);//this only changes relationship between z's parent and y
bool is_balanced(AVLNode<Key, Value>* z);
bool is_balanced(Node<Key, Value>* z);
void update_height(AVLNode<Key, Value>* x);
AVLNode<Key, Value>* insert_helper(AVLNode<Key, Value>& Curr_Node,const std::pair<Key, Value>& keyValuePair);

//REMOVE HELPERS

//int leaf_children_number(Node<Key, Value>* new_node);
    bool is_leaf(Node<Key, Value>* new_node);
    bool has_right_child(Node<Key, Value>* z);
    bool has_left_child(Node<Key, Value>* z);
    void disconnect_node(Node<Key, Value>* node);



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

}

template<typename Key, typename Value>
void AVLTree<Key, Value>::insert(const std::pair<Key, Value>& keyValuePair)
{//to access inherited members use this->
    //to make mRoot into an AVL node use
    //every new node is defined as an avl node
    // TODO

    //heights are only updated during rotations but not during insertions

    if(this->mRoot == NULL)
    {//this is when you add to the tree for the first time
        AVLNode<Key, Value>* new_node = new AVLNode<Key, Value>(keyValuePair.first, keyValuePair.second, NULL);
        
        //make root into new node
        this->mRoot = new_node ;
        return;
    }


    //find within first. If found then overwrite the value, else insert_helper is called



    Node<Key, Value>* insert_location = this->internalFind(keyValuePair.first);



    if(insert_location == NULL)//means it is not already present
    {
        Node<Key, Value>* new_node = insert_helper(*(static_cast<AVLNode<Key,Value>*>(this->mRoot)), keyValuePair);//pointer to the node which has just been inserted
        balance(new_node);
    //     AVLNode<Key, Value>* new_node_ancestor = static_cast<AVLNode<Key,Value>*>( new_node->getParent() );

    //     if(new_node_ancestor !=NULL)//if new node ancestor is not the root
    //     for (; i < count; ++i)
    //     {
    //         /* code */
    //     }







        //checking balance
        // if(new_node->getParent() == this->mRoot) new_node_ancestor = static_cast<AVLNode<Key,Value>*>(new_node->getParent());
        // else new_node_ancestor = new_node->getParent();



        

    }
    else//it is already present so overwrite the value
    {//no need to balance since tree configuration is not changing but only the value of one of the nodes
        insert_location->setValue(keyValuePair.second);
    }

/*
    Start at the newly-inserted node and walk up to the root, checking if each node is balanced (the height- balance rule applies to this node). If a node is unbalanced, rotate the subtree rooted at that node. Rotate the following three nodes:
1. Let z be (a pointer to) the first unbalanced node on the way up. In this case, that node is the one holding the value 78.
2. Let y be the child of z with greater height (hint: this is always an ancestor of the node you inserted. Why?). Why are ties impossible?
3. Let x be the child of y with greater height (this is always an ancestor of the node you inserted, or the node itself. Why?). Why are ties impossible?

*/





    //BinarySearchTree< Key, Value>::insert(keyValuePair);
    //std::cout<<"AVLTREE INSERT"<<std::endl;
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

    Node<Key, Value>* del_node = this->internalFind(key);

    if(del_node == NULL)
    {//if youre attempting to remove a node which is not present do not do anything
        std::cout<<"ATTEMPTING TO REMOVE"<<key<<"WHICH IS NOT A NODE OF THE TREE \n";
        return;
    }
    else
    {
        
        if(this->mRoot == del_node)
        {
            this->mRoot = NULL;
        }
        else if (is_leaf(del_node))
        {//disconnect node from parent(from tree)

           Node<Key, Value>* parent_del_node = del_node->getParent();

           disconnect_node(del_node);
           balance(parent_del_node);
        }
        else if(!has_right_child(del_node))
        {//deleted node doesnt have a right child
    
            Node<Key, Value>* parent_del_node = del_node->getParent();
            Node<Key, Value>* left_child = del_node->getLeft();
            replace_node(static_cast<AVLNode<Key,Value>*> (del_node),static_cast<AVLNode<Key,Value>*>(left_child));
//this only changes relationship between del_node's parent and second param node
            balance(parent_del_node);
        }

        else if(has_right_child(del_node))
        {
            Node<Key, Value>* sucessor = del_node->getRight();//initially the right child
            while(has_left_child(sucessor))
            {
                sucessor = sucessor->getLeft();
            }//now arrived at the leftmost child

            Node<Key, Value>* parent_sucessor = sucessor->getParent();
                

            if(is_leaf(sucessor))
            {
                disconnect_node(del_node);//parents of node have that child set to Null now
                replace_node(static_cast<AVLNode<Key,Value>*> (del_node), static_cast<AVLNode<Key,Value>*> (sucessor));
                sucessor->setLeft(del_node->getLeft());
                sucessor->setRight(del_node->getRight());

            }
            else if(has_right_child(sucessor))
            {
                Node<Key, Value>* right_of_successor = sucessor->getRight();
                disconnect_node(right_of_successor);//parents of node have that child set to Null now
                replace_node(static_cast<AVLNode<Key,Value>*> (sucessor), static_cast<AVLNode<Key,Value>*> (right_of_successor));
            }

            balance(parent_sucessor);
        }

        delete del_node;

    }

}

//HELPER FUNCTIONS

template<typename Key, typename Value>
void AVLTree<Key, Value>::disconnect_node(Node<Key, Value>* node)
//disconnects kid from parents but maintains parent of the kid
{
    if(is_right_child(static_cast<AVLNode<Key,Value>*> (node)))
    {
        (node->getParent())->setRight(NULL);
    }
    else if(is_left_child(static_cast<AVLNode<Key,Value>*>(node)))
    {
      (node->getParent())->setLeft(NULL);
    }
}




template<typename Key, typename Value>
bool AVLTree<Key, Value>::is_leaf(Node<Key, Value>* node)
{
    if(node == NULL)
    {
        std::cout<<"Checking if a NULL is a leaf \n";
        return false;
    }
    if ((node->getLeft() == NULL) && (node->getRight() == NULL))
    {
        return true;
    }
    else
    {
        return false;
    }    
}
template<typename Key, typename Value>
bool AVLTree<Key, Value>::has_right_child(Node<Key, Value>* z)
{
    return (!(z->getRight() == NULL));
}
template<typename Key, typename Value>
bool AVLTree<Key, Value>::has_left_child(Node<Key, Value>* z)
{
    return (!(z->getLeft() == NULL));
}


template<typename Key, typename Value>
void  AVLTree<Key, Value>::balance(Node<Key, Value>* new_node_ancestor)
{//THIS IS ACTUALLY THE NEW NODE BUT WE DO AN EXTRA CHECK BECAUSE FOR DELETED NODE WE DONT WANT IT TO NOT HAPPEN

    // std::cout<<"ENTERS BALANCE"<<new_node_ancestor->getKey()<<" \n";
    if(new_node_ancestor == NULL)
    {
        
        return;
    }

//
    //Node<Key, Value>* new_node_ancestor = new_node->getParent();
    
    while(new_node_ancestor!=NULL)
        {
            update_height(static_cast<AVLNode<Key,Value>*> (new_node_ancestor));


            if(!is_balanced(static_cast<AVLNode<Key,Value>*>(new_node_ancestor)))//if the node is not balanced
            {

                // std::cout<<"In insert:UNBALANCED NODE "<<new_node_ancestor->getKey(); //<< "with height"<< new_node_ancestor->getHeight()<<"\n";
                //new_node_ancestor is z
                std::string zig_zag = "";
                AVLNode<Key, Value>* y = max_height_child(static_cast<AVLNode<Key,Value>*>(new_node_ancestor), zig_zag);
                // AVLNode<Key, Value>* x =
                max_height_child(y, zig_zag);

                // std::cout<<"zig zag is"<< zig_zag<< "\n";
                
                rotate(static_cast<AVLNode<Key,Value>*>(new_node_ancestor), zig_zag);
            }


            // if(new_node_ancestor->getParent() == this->mRoot) new_node_ancestor = static_cast<AVLNode<Key,Value>*>(new_node_ancestor->getParent());
            // else new_node_ancestor = new_node_ancestor ->getParent();
            new_node_ancestor = new_node_ancestor ->getParent();
        }
}
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::max_height_child(AVLNode<Key, Value>* z, std::string& right)//right is 1 left is 0
{//zig zag goes from left before and adds to the right of it
    AVLNode<Key, Value>* left_child = z->getLeft();
    AVLNode<Key, Value>* right_child = z->getRight();

    if(get_height(right_child) > get_height(left_child))
    {
        right+='1';
        return right_child;
    }
    else if(get_height(right_child) < get_height(left_child))
    {
        right+='0';
        return left_child;
    }
    else
    {//if its a tie then make it be a single and not a double rotation. Ties are impossible for insert
        //so this is only for delete
        right+=right;
        if(right == "00")
        {
            return left_child;
        }
        else if(right == "11")
        {    
            return right_child;
        }
        std::cout<<"ENTERS AN IMPOSSIBLE CASE in max_height_child\n";
    
    }

    std::cout<<"ENTERS AN IMPOSSIBLE CASE AND max_height_child GIVES NULL VALUE \n";
    return NULL;//This is to satisfy the compiler that control wont reach end of a NON-Void function

}



template<typename Key, typename Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::insert_helper(AVLNode<Key, Value>& Curr_Node,const std::pair<Key, Value>& keyValuePair)
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
            return insert_helper(*(Curr_Node.getLeft()),keyValuePair);
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
            return insert_helper(*(Curr_Node.getRight()),keyValuePair);
        }
    }
}



template<typename Key, typename Value>
bool AVLTree<Key, Value>::is_balanced(AVLNode<Key, Value>* z)
{
    // std::cout<< "ENTERS IS_BALANCED_AVLNODEAVLTREE \n";
    AVLNode<Key, Value>* left_child = z->getLeft();
    AVLNode<Key, Value>* right_child = z->getRight();

    if((std::abs(get_height(right_child)-get_height(left_child)))> 1)
    {
        // std::cout<<z->getKey() <<"UNBALANCED with diff :"<<(std::abs(get_height(right_child)-get_height(left_child))) <<"\n"; 
        return false;
    }
    else
    {
        // std::cout<< z->getKey() <<" BALANCED in is_balanced"<<(std::abs(get_height(right_child)-get_height(left_child))) << "\n";
        // std::cout<<" LEFT HEIGHT:"<<get_height(left_child) << "\n";
        // std::cout<<" RIGHT HEIGHT:"<<get_height(right_child) << "\n";

        // std::cout<<" RIGHT child:"<<right_child->getKey() << "\n";
        // std::cout<<"parent of n is :"<<((this->internalFind("n"))->getParent())->getKey();
        // std::cout<<" RIGHT grand child:"<<(right_child->getLeft())->getKey() << "\n";
       return true;
    }

        
}

template<typename Key, typename Value>
int AVLTree<Key, Value>::get_height(AVLNode<Key, Value>* x)
{
    if(x==NULL) return -1;//if its a NULL pointer height is -1
    return x->getHeight();
}

template<typename Key, typename Value>
void AVLTree<Key, Value>::update_height(AVLNode<Key, Value>* x)
{
    x->setHeight(1+std::max(get_height(x->getLeft()),get_height(x->getRight())));
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







//BELOW THIS IS ROTATION ACTIONS
template<typename Key, typename Value>
void AVLTree<Key, Value>::rotate(AVLNode<Key, Value>* z, std::string& zig_zag)
{//use this to determine the kind of rotation
    //for zig zag right is 1 and left is 0
    if(zig_zag == "11") left_rotate(z);
    else if(zig_zag == "00") right_rotate(z);
    else if(zig_zag == "10") d_left_rotate(z);
    else if(zig_zag == "01") d_right_rotate(z);

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

    //y could now possibly be the root which if it is, then z was the root earlier and hence needs to be static cast for the update height

    // update_height(z)//which is now a child of y
    // update_height(y)


    //PSEUDOCODE ABOVE THIS POINT  
//setParent(z->getParent()

    AVLNode<Key, Value>* y = z->getRight();
    replace_node(z, y);

    z->setRight(y->getLeft()); 
    if(y->getLeft()!=NULL)
    {
        (y->getLeft())->setParent(z);
    }

    y->setLeft(z);
    z->setParent(y);

    update_height(z);//which is now a child of y
    update_height(y);
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

    //PSEUDOCODE ABOVE THIS POINT  

    AVLNode<Key, Value>* y = z->getLeft();
    replace_node(z, y);

    z->setLeft(y->getRight()); 
    if(y->getRight()!=NULL)
    {
        (y->getRight())->setParent(z);
    }

    y->setRight(z);
    z->setParent(y);
    update_height(z);
    update_height(y);   
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

    // update_height(z);
    // update_height(y);
    // update_height(x);


    //PSEUDOCODE ABOVE THIS POINT  

    AVLNode<Key, Value>* y = z->getRight();
    AVLNode<Key, Value>* x = y->getLeft();
    
    replace_node(z, x);

    z->setRight(x->getLeft()); 
    if(z->getRight()!=NULL)
    {
        (z->getRight())->setParent(z);
    }

    z->setParent(x);
    x->setLeft(z);

    //above this does LHS Z actions

    //Now RHS y actions

    y->setLeft(x->getRight());
    if(x->getRight()!=NULL)
    {
        (x->getRight())->setParent(y);
    }

    x->setRight(y);
    y->setParent(x);

    update_height(z);
    update_height(y);
    update_height(x);
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


    // update_height(z);
    // update_height(y);
     // update_height(x);


    //PSEUDOCODE ABOVE THIS POINT  

    /*
->getRight()
->getLeft()
->setRight(y)
->setLeft(z)
->setParent(x)
    */

    AVLNode<Key, Value>* y = z->getLeft();
    AVLNode<Key, Value>* x = y->getRight();

    
    replace_node(z, x);

    y->setRight(x->getLeft()); 
    if(x->getLeft()!=NULL)
    {
        (x->getLeft())->setParent(z);
    }
    y->setParent(x);
    x->setLeft(y);

    //above this does LHS Y actions

    //Now RHS y actions

    z->setLeft(x->getRight());
    if(x->getRight()!=NULL)
    {
        (z->getLeft())->setParent(z);
    }
    z->setParent(x);
    x->setRight(z);

    update_height(z);
    update_height(y);
    update_height(x);


}


/*
------------------------------------------
End implementations for the AVLTree class.
------------------------------------------
*/

#endif