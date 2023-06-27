#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinarySearchTree
{
public:
    T data;
    BinarySearchTree<int>*left;
    BinarySearchTree<int>*right;

    BinarySearchTree(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BinarySearchTree()
    {
        delete left;
        delete right;
    }
};

BinarySearchTree<int>*takeInputLevelWise()
{
    int rootData;
    cin>>rootData;

    if(rootData==-1)
        return NULL;
    queue<BinarySearchTree<int>*>pending;
    BinarySearchTree<int>*root=new BinarySearchTree<int>(rootData);
    pending.push(root);

    while(pending.size()!=0)
    {
        BinarySearchTree<int>*front=pending.front();
        pending.pop();

        int lchild,rchild;
        cin>>lchild>>rchild;

        if(lchild!=-1)
        {
            BinarySearchTree<int>*child=new BinarySearchTree<int>(lchild);
            pending.push(child);
            front->left=child;
        }

        if(rchild!=-1)
        {
            BinarySearchTree<int>*child=new BinarySearchTree<int>(rchild);
            pending.push(child);
            front->right=child;
        }
    }

    return root;
}

void printLevelWise(BinarySearchTree<int>*root)
{
    if(root==NULL)
        return;
    queue<BinarySearchTree<int>*>pending;
    pending.push(root);
    pending.push(NULL);

    while(pending.size()!=0)
    {
        BinarySearchTree<int>*front=pending.front();
        pending.pop();

        if(pending.empty())
            break;

        else if(front!=NULL)
        {
            cout<<front->data<<" ";
            if(front->left!=NULL)
                pending.push(front->left);

            if(front->right!=NULL)
                pending.push(front->right);
        }

        else
        {
            cout<<endl;
            pending.push(front);
        }
    }
}

void ElementsBetween(BinarySearchTree<int>*root,int k1,int k2)
{
    if(root==NULL)
        return;

    if(k1<root->data)
        ElementsBetween(root->left,k1,k2);

    if(root->data >=k1 && root->data<=k2)
        cout<<root->data<<" ";

    if(k2 > root->data)
        ElementsBetween(root->right,k1,k2);

}

int main()
{
    BinarySearchTree<int>*root=takeInputLevelWise();
    //printLevelWise(root);

    ElementsBetween(root,5,30);
}

