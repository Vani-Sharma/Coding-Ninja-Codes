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


bool printPath(vector<int>&vec)
{
	for(int i=0;i<vec.size();i++)
	cout<<vec.at(i)<<" ";

	cout<<endl;
	return true;
}

void getPath(BinarySearchTree<int>*root,int k,vector<int>&vec)
{
	if(root==NULL)
	return;

	vec.push_back(root->data);
	bool flag=false;

	if(root->data==k && root->left==NULL && root->right==NULL)
	{
		 flag=printPath(vec);
	}

	if(flag)
	{
		vec.pop_back();
		return ;

	}

	else
	getPath(root->left, k-root->data, vec);

	getPath(root->right, k-root->data , vec);
	vec.pop_back();

	return ;

}

void rootToLeafPathsSumToK(BinarySearchTree<int> *root, int k) {
  // Write your code here
  vector<int>vec;
  getPath(root,k,vec);

}

int main()
{
    BinarySearchTree<int>*root=takeInputLevelWise();
    //printLevelWise(root);
    int k=13;
    rootToLeafPathsSumToK(root,k);

}





