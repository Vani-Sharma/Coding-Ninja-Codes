#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;

    BinaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>*takeInputLevelWise()
{
    int rootdata;
    cin>>rootdata;

    if(rootdata==-1)
        return NULL;

    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*>pending;
    pending.push(root);

    while(pending.size()!=0)
    {
        BinaryTreeNode<int>*front=pending.front();
        pending.pop();


        int lchild,rchild;
        cin>>lchild>>rchild;

        if(lchild!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(lchild);
            front->left=child;
            pending.push(child);
        }

        if(rchild!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rchild);
            front->right=child;
            pending.push(child);
        }
    }

    return root;
}

void printLevel(BinaryTreeNode<int>*root)
{
    if(root==NULL)
        return;

    queue<BinaryTreeNode<int>*>pending;
    pending.push(root);
    pending.push(NULL);

    while(pending.size()!=0)
    {
        BinaryTreeNode<int>*front=pending.front();
        pending.pop();

        if(pending.empty())
            break;

        if(front!=NULL)
        {
            cout<<front->data<<" ";
            if(front->left)
                pending.push(front->left);

            if(front->right)
                pending.push(front->right);
        }

        else
            {
                cout<<endl;
                pending.push(NULL);
            }
    }
}

BinaryTreeNode<int>*removeLeafNode(BinaryTreeNode<int>*root)
{
    if(root==NULL)
        return NULL;

    if(root->left==NULL && root->right==NULL)
        return NULL;

    BinaryTreeNode<int>*left=removeLeafNode(root->left);
    if(left==NULL)
    {
        root->left=NULL;
        delete left;
    }

    BinaryTreeNode<int>*right=removeLeafNode(root->right);
    if(right==NULL)
    {
        root->right=NULL;
        delete right;
    }

    return root;
}

int main()
{
    BinaryTreeNode<int>*root=takeInputLevelWise();
    removeLeafNode(root);
    printLevel(root);
}
