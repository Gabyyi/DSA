#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <deque>
using namespace std;


template <typename T> class BinarySearchTree
{
public:
    T* pinfo;
    BinarySearchTree<T>* left_son, * right_son, * parent, * root;

    BinarySearchTree()
    {
        pinfo = NULL;
        left_son = right_son = parent = NULL;
        root = this;
    }

    void setInfo(T info)
    {
        pinfo = new T;
        *pinfo = info;
    }

    void setRoot(BinarySearchTree<T>* r)
    {
        root = r;
    }

    /// insert a new node
    void insert(T x)
    {
        ///if the tree is empty, this will be the first node
        if (pinfo == NULL)
            setInfo(x);
        ///if not, we insert it recursively
        else
            insert_rec(x);
    }

    void insert_rec(T x)
    {
        int next_son;
        /// if the value of the node is smaller, it will be the left son
        if (x <= (*pinfo))
            next_son = 0;
        /// if the value is greater, it will be the right son
        else
            next_son = 1;

        if (next_son == 0)    // left son
        {
            if (left_son == NULL)
            {
                left_son = new BinarySearchTree<T>;
                left_son->pinfo = new T;
                *(left_son->pinfo) = x;
                left_son->left_son = left_son->right_son = NULL;
                left_son->parent = this;
                left_son->root = root;
            }
            else
                left_son->insert_rec(x);
        }
        else     // right son
        {
            if (right_son == NULL)
            {
                right_son = new BinarySearchTree<T>;
                right_son->pinfo = new T;
                *(right_son->pinfo) = x;
                right_son->left_son = right_son->right_son = NULL;
                right_son->parent = this;
                right_son->root = root;
            }
            else
                right_son->insert_rec(x);
        }
    }

    ///find a certain node which contains the info x
    BinarySearchTree<T>* find(T x)
    {
        BinarySearchTree<T>* rez;

        if (pinfo == NULL)
            return NULL;

        if ((*pinfo) == x)
            return this;

        ///search in the left subtree
        if (left_son != NULL)
            rez = left_son->find(x);
        else
            rez = NULL;

        if (rez != NULL)
            return rez;
        else ///if not found, search in the right subtree
            if (right_son != NULL)
                return right_son->find(x);
            else
                return NULL;
    }

    ///search for a leaf --> let's test this function
    BinarySearchTree<T>* findLeaf()
    {
        if (left_son == NULL && right_son == NULL)
            return this;
        else if (left_son != NULL)
            return left_son->findLeaf();
        else
            return right_son->findLeaf();
    }

    ///call remove with the node that we want to delete (this)
    void remove()
    {
        BinarySearchTree<T>* leaf;

        /// find a leaf in this node's subtree
        /// we use it to put it in the place of the node that we delete
        leaf = findLeaf();

        ///if the current node is a leaf
        if (this == leaf)
        {
            ///we will remove the leaf
            if (parent == NULL) /// because this == root == leaf
            {
                if (this->pinfo != NULL)
                    delete this->pinfo;

                root->pinfo = NULL;
            }
            else
            {
                ///if what we remove is left son
                if (parent->left_son == this)
                    parent->left_son = NULL;
                else
                    ///if what we remove is right son
                    parent->right_son = NULL;

                delete this->pinfo;
                delete this;
            }
        }

        ///if the current node is not a leaf
        else
        {
            ///if it is a left son
            if (leaf->parent->left_son == leaf)
                leaf->parent->left_son = NULL;
            else
                ///if is a right son
                leaf->parent->right_son = NULL;

            ///replace the links for the leaf
            leaf->parent = parent;
            leaf->left_son = left_son;
            leaf->right_son = right_son;

            delete this->pinfo;

            ///the info of the current node becomes the info of the leaf
            this->pinfo = leaf->pinfo;
            delete leaf;
        }
    }

    void removeInfo(T x)
    {
        BinarySearchTree<T>* t = find(x);
        if (t != NULL)
            t->remove();
    }

    void preOrderTraversal()
    {
        ///display, left, right
        cout << *pinfo << " ";
        if (left_son != NULL)
            left_son->preOrderTraversal();
        if (right_son != NULL)
            right_son->preOrderTraversal();
    }

    void postOrderTraversal()
    {
        ///left, right, display
        if (left_son != NULL)
            left_son->postOrderTraversal();
        if (right_son != NULL)
            right_son->postOrderTraversal();
        cout << *pinfo << " ";
    }

    void inOrderTraversal()
    {
        ///left, display, right
        if (left_son != NULL)
            left_son->inOrderTraversal();
        cout << *pinfo << " ";
        if (right_son != NULL)
            right_son->inOrderTraversal();
    }

    void preOrderTraversalLevels(int level)
    {
        int i;
        for (i = 0; i < level; i++)
            cout << "-";
        cout << *pinfo << endl;

        if (left_son != NULL)
            left_son->preOrderTraversalLevels(level + 1);
        if (right_son != NULL)
            right_son->preOrderTraversalLevels(level + 1);
    }
    bool isEmpty()
    {
        return pinfo == NULL;
    }
    T greatestValue()
    {
        BinarySearchTree<T>* paux = root;
        while (paux != NULL && paux->right_son != NULL)
            paux = paux->right_son;
        if (*(paux->pinfo) != NULL)
            return *(paux->pinfo);
        else return 0;
    }
    T lowestValue() {
        BinarySearchTree<T>* paux = root;
        while (paux != NULL && paux->left_son != NULL)
            paux = paux->left_son;
        if (*(paux->pinfo) != NULL)
            return *(paux->pinfo);
        else return 0;
    }
    BinarySearchTree<T>* generateEncodingTree(BinarySearchTree<T>* bst) {
        std::deque<BinarySearchTree<T>*> tree;

      
        while (!bst->isEmpty()) {
            T minValue = bst->lowestValue();
            bst->removeInfo(minValue); 

            BinarySearchTree<T>* node = new BinarySearchTree<T>();
            node->setInfo(minValue);
            tree.push_back(node);
        }

        
        while (tree.size() > 1) {
           
            sort(tree);

            
            BinarySearchTree<T>* node1 = tree.front();
            tree.pop_front();
            BinarySearchTree<T>* node2 = tree.front();
            tree.pop_front();

            
            BinarySearchTree<T>* newNode = new BinarySearchTree<T>();
            newNode->setInfo(*(node1->pinfo) + *(node2->pinfo));
            newNode->left_son = node1;
            newNode->right_son = node2;
            node1->parent = newNode;
            node2->parent = newNode;

           
            tree.push_back(newNode);
        }

        
        return tree.front();
    }

   
    void sort(std::deque<BinarySearchTree<T>*>& tree) {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (size_t i = 0; i < tree.size() - 1; i++) {
                if (*(tree[i]->pinfo) > *(tree[i + 1]->pinfo)) {
                    std::swap(tree[i], tree[i + 1]);
                    sorted = false;
                }
            }
        }
    }


    bool findInEncodingTree(T value, std::string& path) {
        
        if (this == NULL) {
            return false;
        }

       
        if (pinfo != NULL && *pinfo == value) {
            return true;
        }

      
        if (left_son != NULL) {
            path.push_back('0');
            if (left_son->findInEncodingTree(value, path)) {
                return true;
            }
            path.pop_back(); 
        }

       
        if (right_son != NULL) {
            path.push_back('1'); 
            if (right_son->findInEncodingTree(value, path)) {
                return true;
            }
            path.pop_back(); 
        }

        return false;
    }

    T maxTRaverse(BinarySearchTree<T>* node,std::string& path)
    {    
            if (path[0] == '0')
            {
                if(node->left_son==NULL)
                {
                    std::cout << "\n";
                    return *(node->pinfo);
                }
                else
                {
                    path = path.substr(1, path.length() - 1);
                    return maxTRaverse(node->left_son, path);
                }

            }
            else if (path[0] == '1')
            {
                if (node->right_son == NULL)
                {
                    std::cout << "\n";
                    return *(node->pinfo);
                }
                else {
                    
                    path = path.substr(1, path.length() - 1);
                    return maxTRaverse(node->right_son, path);
                }
            }
            else {
                std::cout << "\n";
                return *(node->pinfo);
            }
                
            
        
        
    }

   void maximumHeight(int level, int& maxLevel)
   {
       if (level > maxLevel)
           maxLevel = level;
       if (left_son != NULL)
           left_son->maximumHeight(level + 1, maxLevel);
       if (right_son != NULL)
           right_son->maximumHeight(level + 1, maxLevel);

   }

   void displayLevel(int level,int n)
    {
        if (level == n)
            cout << *pinfo << " ";

        if (left_son != NULL)
            left_son->displayLevel(level + 1,n);
        if (right_son != NULL)
            right_son->displayLevel(level + 1,n);
   
    }


 
   void displayLevels() {
       int maxLevel;
       maximumHeight(0, maxLevel);
       for (int i = 0; i <= maxLevel; i++)
       {
           cout << "\n";
           cout << "Level " << i << " : ";
           displayLevel(0, i);

       }
       cout << "\n";
   }


    

};






