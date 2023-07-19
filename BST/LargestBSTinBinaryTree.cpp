#include<iostream>
#include<climits>
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

bool checkBST(BinaryTreeNode<int>*root,int min=INT_MIN, int max=INT_MAX)
{
	if(root==NULL)
	return true;

	if(root->data < min  || root->data > max)
	return false;

	bool isLeftOk=checkBST(root->left,min,root->data-1);
	bool isRightOk=checkBST(root->right, root->data+1 , max);

	return isLeftOk&&isRightOk;
}

int height(BinaryTreeNode<int>*root)
{
	if(root==NULL)
	return 0;

	int lh=1+height(root->left);
	int rh=1+height(root->right);

	return max(lh,rh);
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	bool ans=checkBST(root);
	if(ans)
	{
		return height(root);
	}
	int lh=largestBSTSubtree(root->left);
	int rh=largestBSTSubtree(root->right);

	return max(lh,rh);

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
    cout<<largestBSTSubtree(root);
    delete root;
}


