#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <typename T> class BinarySearchTree
{
public:
    T *pinfo;
    BinarySearchTree<T> *left_son, *right_son, *parent, *root;

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

    void setRoot(BinarySearchTree<T> *r)
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
        BinarySearchTree<T> *rez;

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
        BinarySearchTree<T> *leaf;

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
        BinarySearchTree<T> *t = find(x);
        if (t != NULL)
            t->remove();
    }

    void preOrderTraversal()
    {
        ///display, left, right
        cout<<*pinfo <<" ";
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
        cout<<*pinfo <<" ";
    }

    void inOrderTraversal()
    {
        ///left, display, right
        if (left_son != NULL)
            left_son->inOrderTraversal();
        cout<<*pinfo <<" ";
        if (right_son != NULL)
            right_son->inOrderTraversal();
    }

    void preOrderTraversalLevels(int level)
    {
        int i;
        for (i = 0; i < level; i++)
            cout<<"-";
        cout<<*pinfo<<endl;

        if (left_son != NULL)
            left_son->preOrderTraversalLevels(level + 1);
        if (right_son != NULL)
            right_son->preOrderTraversalLevels(level + 1);
    }



    //-----Exercise 1-----

    T findMax(BinarySearchTree<T>* root){
        if(root==NULL){
            cout<<"Tree is empty."<<endl;
            return 0;
        }
        BinarySearchTree<T>* current=root;
        while(current->right_son!=NULL){
            current=current->right_son;
        }
        return *(current->pinfo);
    }


    //-----Exercise 2-----

    void maxHeigth(int heigth,int &maxheigth){
        if(heigth>maxheigth) maxheigth=heigth;
        if(left_son!=NULL)
            left_son->maxHeigth(heigth+1,maxheigth);
        if(right_son!=NULL)
            right_son->maxHeigth(heigth+1,maxheigth);
    }
    void maxLeft(int heigth, int &maxheigth){
        if(heigth>maxheigth) maxheigth=heigth;
        if(left_son!=NULL)
            left_son->maxHeigth(heigth+1,maxheigth);
    }
    void maxRigth(int heigth, int &maxheigth){
        if(heigth>maxheigth) maxheigth=heigth;
        if(right_son!=NULL)
            right_son->maxHeigth(heigth+1,maxheigth);
    }

    //-----Exercise 4----

    void displayLevel(BinarySearchTree<T> *root,int level){
        if(root==NULL)
            return;
        if(level==0)
            cout<<*root->pinfo<<" ";
        else{
            displayLevel(root->left_son,level-1);
            displayLevel(root->right_son,level-1);
        }
    }

    //-----Exercise 5-----

    int getHeight(BinarySearchTree<T> *root){
        int left,right,max;
        if(root==NULL)
            return -1;
        left=getHeight(root->left_son);
        right=getHeight(root->right_son);
        if(left>right)
            max=left;
        else max=right;
        return max+1;
    }
    void displayTree(BinarySearchTree<T> *root){
        int height=getHeight(root->root);
        for(int i=0;i<=height;i++){
            cout<<"Level "<<i<<": ";
            displayLevel(root->root,i);
            cout<<endl;
        }
    }

    //-----Exercise 6-----

    void displayValuesBetween(BinarySearchTree<int>* root,int x,int y){
        if(root==NULL)
            return;
        if(*root->pinfo>x)
            displayValuesBetween(root->left_son,x,y);
        if(*root->pinfo>=x && *root->pinfo<=y)
            cout<<*root->pinfo<< " ";
        if(*root->pinfo<y)
            displayValuesBetween(root->right_son,x,y);
    }

};

int main()
{
    BinarySearchTree<int> *r = new BinarySearchTree<int>;
    r->setRoot(r); /// optional
    r->insert(6);
    r->insert(8);
    r->insert(1);
    r->insert(9);
	r->insert(10);
    r->insert(4);
    r->insert(12);
    r->insert(1);
    r->insert(7);

    cout<<"Preorder1\n";
    r->preOrderTraversal();

    cout<<"\nPreorder2\n";
    r->preOrderTraversalLevels(0);

    cout<<"\nPostorder\n";
    r->postOrderTraversal();

    cout<<"\nInorder\n";
    r->inOrderTraversal();

    cout<<"\n\n";
    cout<<r->find(100)<<endl;
    cout<<r->find(10)<<endl;
    //(r->find(6))->remove();
    cout<<"new root: "<<*r->pinfo<<endl;

    cout<<"_______\n"<<*r->find(10)->pinfo;
    cout<<"\n"<<r->find(4);
    cout<<"\n"<<r->find(12);
    cout<<"\n"<<r->find(8);

    //-----Exercise 1-----
    
    cout<<"\n\n-----Exercise 1-----\n";
    cout<<"\nThe greatest value in the BST is "<<r->findMax(r);

    //-----Exercise 2-----

    cout<<"\n\n-----Exercise 2-----\n";
    int maxheigth=0;
    r->maxHeigth(0,maxheigth);
    cout<<"\nThe heigth of the tree is "<<maxheigth+1;
    
    //-----Exercise 3-----

    cout<<"\n\n-----Exercise 3-----\n";
    int maxheigthL=0;
    r->maxLeft(0,maxheigthL);
    cout<<"\nThe heigth of the left side of the tree is "<<maxheigthL;
    int maxheigthR=0;
    r->maxRigth(0,maxheigthR);
    cout<<"\nThe heigth of the rigth side of the tree is "<<maxheigthR;
    cout<<"\nThe difference is "<<maxheigthL-maxheigthR;
    
    //-----Exercise 4-----

    cout<<"\n\n-----Exercise 4-----\n\n";
    r->displayLevel(r->root,2);

    //-----Exercise 5-----
    
    cout<<"\n\n-----Exercise 5-----\n\n";
    r->displayTree(r->root);

    //-----Exercise 6-----

    cout<<"\n\n-----Exercise 6-----\n\n";
    r->displayValuesBetween(r->root,2,7);
    return 0;
}





