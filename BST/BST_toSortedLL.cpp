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

template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;

    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
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


pair <Node<int>*, Node<int>*> SortedLL(BinarySearchTree<int>*root)
{
	pair <Node<int>*, Node<int>*> obj;
	if(root==NULL)
	{
		obj.first=NULL;
		obj.second=NULL;
		return obj;
	}

	pair <Node<int>*, Node<int>*> left=SortedLL(root->left);
	pair <Node<int>*, Node<int>*> right=SortedLL(root->right);

	Node<int>*newNode=new Node<int>(root->data);

	if(left.first==NULL)
	left.first=newNode;

	if(left.second!=NULL)
	left.second->next=newNode;

	if(right.second==NULL)
	right.second=newNode;

	newNode->next=right.first;
	obj.first=left.first;
	obj.second=right.second;

	return obj;
}

Node<int>* constructLinkedList(BinarySearchTree<int>* root) {
	// Write your code here
	return SortedLL(root).first;

}

void printLinkedList(Node<int>*node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
}


int main()
{
    BinarySearchTree<int>*root=takeInputLevelWise();
    //printLevelWise(root);

    Node<int>*node=constructLinkedList(root);
    printLinkedList(node);


}




