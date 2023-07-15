#include<iostream>
using namespace std;

template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int>*left;
    BinaryTreeNode<int>*right;

    BinaryTreeNode(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

template<typename T>
class BST
{
    BinaryTreeNode<int>*root;

    BinaryTreeNode<int>* insertNode(BinaryTreeNode<int>*root,int data)
    {
        if(root==NULL)
        {
            BinaryTreeNode<int>*newNode=new BinaryTreeNode<int>(data);
            return newNode;
        }

        else if(root->data > data)
        {
            root->left=insertNode(root->left,data);
        }

        else
        {
            root->right=insertNode(root->right,data);
        }

        return root;
    }

    BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>*root,int data)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if(root->data > data)
            root->left=deleteNode(root->left,data);

        else if(root->data < data)
            root->right=deleteNode(root->right,data);

        else if(root->data==data)
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }

            else if(root->right==NULL)
            {
                BinaryTreeNode<int>*temp=root->left;
                root->left=NULL;
                delete root;
                return temp;

            }

            else if(root->left==NULL)
            {
                BinaryTreeNode<int>*temp=root->right;
                root->right=NULL;
                delete root;
                return temp;

            }

            else
            {
                BinaryTreeNode<int>*minNode=root->right;
                while(minNode->left!=NULL)
                    minNode=minNode->left;
                int rightMin=minNode->data;
                root->data=rightMin;
                root->right=deleteNode(root->right,rightMin);
            }
        }

        return root;
    }


    bool check_HasData(BinaryTreeNode<int>* root ,int data)
    {
        if(root==NULL)
            return false;

        if(root->data==data)
            return true;
        else if(root->data > data)
        {
            return check_HasData(root->left,data);
        }
        else
            return check_HasData(root->right,data);
    }

    void printRecursive(BinaryTreeNode<int>*root)
{
    if(root==NULL)
        return;

    cout<<root->data<<":";

    if(root->left!=NULL)
        cout<<"L"<<root->left->data<<" ";

    if(root->right!=NULL)
        cout<<"R"<<root->right->data<<" ";

    cout<<endl;

    printRecursive(root->left);
    printRecursive(root->right);
}

public:

    BST()
    {
        root=NULL;
    }

    ~BST()
    {
        delete root;
    }

    void insertNode(int data)
    {
        this->root=insertNode(this->root,data);
    }

     void deleteNode(int data)
    {
        this->root=deleteNode(root,data);
    }

    bool hasData(int data)
    {
        return check_HasData(root,data);
    }

    void printTree()
    {
        printRecursive(root);
    }
};

int main()
{
    BST<int> b;
    b.insertNode(20);
    b.insertNode(15);
    b.insertNode(5);
    b.insertNode(12);
    b.insertNode(33);
    b.insertNode(65);
    b.insertNode(4);
    b.insertNode(7);
    b.printTree();
    b.deleteNode(20);
    b.printTree();
    cout<<b.hasData(15);
}
