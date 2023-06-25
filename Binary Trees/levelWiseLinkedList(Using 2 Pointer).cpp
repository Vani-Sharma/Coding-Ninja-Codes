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

vector<Node<int>*>levelWiseLinkedList(BinaryTreeNode<int>*root)
{
    vector<Node<int>*> v;
    if(root==NULL)
        return v ;

    queue<BinaryTreeNode<int>*>pending;
    pending.push(root);
    pending.push(NULL);


    Node<int>*head=NULL;
    Node<int>*tail=NULL;

    while(pending.size()!=0)
    {
        BinaryTreeNode<int>*frontt=pending.front();
        pending.pop();

        if(pending.empty())
            break;

        else if(frontt!=NULL)
            {
                Node<int>*newNode=new Node<int>(frontt->data);
                if(head==NULL)
                {
                    head=newNode;
                    tail=newNode;
                    v.push_back(head);
                }

                else
                {
                    tail->next=newNode;
                    tail=newNode;
                }

                if(frontt->left!=NULL)
                   pending.push(frontt->left);

                if(frontt->right!=NULL)
                   pending.push(frontt->right);
            }

        else
            {
                head=tail=NULL;
                pending.push(frontt);
            }

    }

    return v;

}


int main()
{
    BinaryTreeNode<int>*root=takeInputLevelWise();
    vector<Node<int>*>v=levelWiseLinkedList(root);

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

