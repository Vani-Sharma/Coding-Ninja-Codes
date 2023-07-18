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

int getLCA(BinaryTreeNode<int>* root , int a , int b){
    // Write your code here
	if(root==NULL)
	return -1;

	if(root->data==a || root->data==b)
	return root->data;

	int left=-1,right=-1;
	if(root->data > a && root->data > b)
	 left=getLCA(root->left, a,b);

	if(root->data < a && root->data < b)
	 right=getLCA(root->right,  a,  b);

	else
	{
		 left=getLCA(root->left, a, b);
		 right=getLCA(root->right, a, b);
	}

	if(left==-1 && right==-1)
        return -1;

    if(left==-1)
        return right;

    if(right==-1)
        return left;

    return root->data;
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
    cout<<getLCA(root,2,10);
    delete root;
}


