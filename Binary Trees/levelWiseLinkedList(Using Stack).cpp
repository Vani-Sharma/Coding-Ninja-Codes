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

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
	vector<Node<int>*> vec;

	if(root==NULL)
	return vec;

	queue<BinaryTreeNode<int>*>pending;
	stack<Node<int>*>stacks;
	pending.push(root);
	pending.push(NULL);

	while(pending.size()!=0)
	{
		BinaryTreeNode<int>*front=pending.front();
		pending.pop();

		if(pending.empty())
		return vec;

		if(front!=NULL)
		{
			Node<int>*node=new Node<int>(front->data);
			if(stacks.empty())
			vec.push_back(node);

			else
			{
					Node<int>*oldNode=stacks.top();
					stacks.pop();
				    oldNode->next=node;
			}

			stacks.push(node);

			if(front->left!=NULL)
			{
				pending.push(front->left);
			}

			if(front->right!=NULL)
			{
				pending.push(front->right);
			}
		}

		else{
			stacks.pop();
			pending.push(NULL);
		}
	}

	return vec;
}


int main()
{
    BinaryTreeNode<int>*root=takeInputLevelWise();
    vector<Node<int>*>v=constructLinkedListForEachLevel(root);

    for(int i=0;i<v.size();i++)
    {
       Node<int>*temp=v.at(i);

       while(temp!=NULL)
       {
           cout<<temp->data<<" ";
           temp=temp->next;
       }

       cout<<endl;
    }

}


