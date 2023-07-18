#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int>*left;
    BinaryTreeNode<int>*right;

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

vector<int>*makeArray(BinaryTreeNode<int>*root,vector<int>&v)
{
    if(root==NULL)
        return NULL;

    v.push_back(root->data);
    makeArray(root->left,v);
    makeArray(root->right,v);

}

void pairSum(BinaryTreeNode<int>*root,int s)
{
    if(root==NULL)
        return;

    vector<int>v;
    makeArray(root,v);
    sort(v.begin(),v.end());
    int i=0,j=v.size()-1;
    while(i<j)
    {
        if(v.at(i)+v.at(j)==s)
            {
                cout<<v.at(i)<<" "<<v.at(j)<<endl;
                i++;
                j--;
            }

        if(v.at(i)+v.at(j)<s)
          i++;

        if(v.at(i)+v.at(j)>s)
            j--;
    }

}

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cin>>rootData;

    if(rootData==-1)
        return NULL;

    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();

        int leftChild,rightChild;
        cin>>leftChild>>rightChild;

        if(leftChild!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftChild);
            front->left=child;
            pendingNodes.push(child);
        }

        if(rightChild!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightChild);
            front->right=child;
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTree(BinaryTreeNode<int>*root)
{
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<": L:";
        if(front->left!=NULL)
        {
            cout<<front->left->data;
            pendingNodes.push(front->left);
        }

        if(front->left==NULL)
            cout<<"-1";

        cout<<" R:";
        if(front->right!=NULL)
        {
            cout<<front->right->data<<endl;
            pendingNodes.push(front->right);
        }

        if(front->right==NULL)
            cout<<"-1\n";

        cout<<endl;
    }
}

int main()
{
    BinaryTreeNode<int>*root=takeInputLevelWise();
    pairSum(root,15);
    delete root;
}







