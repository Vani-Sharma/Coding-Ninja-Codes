#include<iostream>
#include<queue>
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

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
	if(inLength==0 || postLength==0)
	return NULL;

	BinaryTreeNode<int>*root=new BinaryTreeNode<int>(postorder[postLength-1]);
	int i;
	for(i=0;i<inLength;i++)
	{
		if(inorder[i]==root->data)
		break;
	}

	int k=i;
	root->left=buildTree(postorder, k, inorder, k);
	root->right=buildTree(postorder+k, postLength-k-1, inorder+k+1, inLength-k-1);

	return root;
}

int main()
{
    int postOrder[]={2,9,3,6,10,5};
    int inorder[]={2,6,3,9,5,10};

    int inLength=sizeof(inorder)/sizeof(inorder[0]);
    int postLength=sizeof(postOrder)/sizeof(postOrder[0]);
    BinaryTreeNode<int>*root=buildTree(postOrder,postLength,inorder,inLength);
    printTree(root);

    delete root;
}
