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

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
	if(inLength==0 || preLength==0)
	return NULL;

	BinaryTreeNode<int>*root=new BinaryTreeNode<int>(preorder[0]);

    int i;
	for( i=0;i<inLength;i++)
	{
		if(inorder[i]==preorder[0])
		break;
	}

	int k=i;

	root->left=buildTree(preorder+1,k , inorder, k);
	root->right=buildTree(preorder+k+1, preLength-k-1, inorder+k+1, inLength-k-1);


	return root;
}

int main()
{
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};

    int inLength=sizeof(inorder)/sizeof(inorder[0]);
    int preLength=sizeof(preorder)/sizeof(preorder[0]);
    BinaryTreeNode<int>*root=buildTree(preorder,preLength,inorder,inLength);
    printTree(root);

    delete root;
}





