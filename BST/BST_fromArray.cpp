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

void preOrder(BinarySearchTree<int>* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

BinarySearchTree<int>* BSTFromArray(int*arr,int startIndex,int endIndex)
{
    if(startIndex> endIndex)
        return NULL;

    int ind=(startIndex+endIndex)/2;

    BinarySearchTree<int>*root=new BinarySearchTree<int>(arr[ind]);

    root->left=BSTFromArray(arr,startIndex,ind-1);
    root->right=BSTFromArray(arr,ind+1,endIndex);

    return root;
}

int main()
{
    //BinarySearchTree<int>*root=takeInputLevelWise();
    //printLevelWise(root);

    int *arr,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    BinarySearchTree<int>*root1=BSTFromArray(arr,0,n-1);
    preOrder(root1);
}



