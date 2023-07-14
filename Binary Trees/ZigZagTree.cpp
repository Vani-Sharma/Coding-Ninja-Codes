#include<iostream>
#include<queue>
#include<stack>
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

template<typename T>
class Node
{
public:
    T data;
    Node*next;

    Node(T data)
    {
        this->data=data;
        next=NULL;
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

void zigZagOrder(BinaryTreeNode<int> *root) {
	if(root==NULL)
	return;

	stack<BinaryTreeNode<int>*> s1;
	stack<BinaryTreeNode<int>*> s2;

	s1.push(root);
	int flag=0;
	while(!s1.empty() || !s2.empty())
	{
		if(!s1.empty() && flag==0)
		{
		cout<<s1.top()->data<<" ";
		if(s1.top() ->left !=NULL)
		s2.push(s1.top()->left);

		if(s1.top() ->right !=NULL)
		s2.push(s1.top()->right);

		s1.pop();

		if(s1.empty())
		{
		cout<<endl;
		}

		continue;
		}


		if(!s2.empty())
		{
			flag=1;
		cout<<s2.top()->data<<" ";

		if(s2.top() ->right !=NULL)
		s1.push(s2.top()->right);

		if(s2.top() ->left !=NULL)
		s1.push(s2.top()->left);

		s2.pop();

		if(s2.empty())
		{
		cout<<endl;
		flag=0;
		}

		}

	}

}


int main()
{
    BinaryTreeNode<int>*root=takeInputLevelWise();
    zigZagOrder(root);

}


