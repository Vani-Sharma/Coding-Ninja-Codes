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

vector<int>* getPath(BinarySearchTree<int> *root , int data) {
	// Write your code here

	if(root==NULL)
	return NULL;

	if(root->data ==data)
	{
		vector<int>*v=new vector<int>;
		v->push_back(root->data);
		return v;
	}


	if(data < root->data)
	{
		vector<int>*v=getPath(root->left,data);
		if(v!=NULL)
		{
			v->push_back(root->data);
			return v;
		}
	}


	else if(data > root->data)
	{
		vector<int>*v=getPath(root->right,data);
		if(v!=NULL)
		{
			v->push_back(root->data);
			return v;
		}
	}


}

int main()
{
    BinarySearchTree<int>*root=takeInputLevelWise();
    //printLevelWise(root);

    int k=10;
    vector<int>*v = getPath(root,k);
    for(int i=0;i<v->size();i++)
        cout<<v->at(i)<<" ";

}





