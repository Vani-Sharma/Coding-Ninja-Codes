#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<int>*> children;

    TreeNode(T data)
    {
        this->data=data;
    }

    ~TreeNode()
    {
        for(int i=0;i<children.size();i++)
            delete children[i];
    }
};

template<typename T>
class Pair
{
public:
T sum;
TreeNode<T>*node;

};

TreeNode<int>*takeInputLevelWise()
{
    int rootData;
    cin>>rootData;

    TreeNode<int>*root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cin>>numChild;

        for(int i=0;i<numChild;i++)
        {
            int childData;
            cin>>childData;

            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTree(TreeNode<int>*root)
{
   if(root==NULL)
        return;

        queue<TreeNode<int>*>pending;
        pending.push(root);

        while(pending.size()!=0)
        {
            TreeNode<int>*front=pending.front();
            pending.pop();
            cout<<front->data<<":";

            for(int i=0;i<front->children.size();i++)
            {
                cout<<front->children[i]->data<<" ";
                pending.push(front->children[i]);
            }

            cout<<endl;
        }

}

Pair<int>* helperMax(TreeNode<int>*root)
{
    Pair<int>*ans=new Pair<int>();
    if(root==NULL)
    {
        ans->node=NULL;
        ans->sum=INT_MIN;
        return ans;
    }

    int sum=root->data;
    ans->node=root;

    for(int i=0;i<root->children.size();i++)
    {
       sum+=root->children[i]->data;
    }

    ans->sum=sum;

     for(int i=0;i<root->children.size();i++)
    {
        Pair<int>*childSum=helperMax(root->children[i]);
        if(childSum->sum > ans->sum)
        {
           ans=childSum;
        }
    }

    return ans;

}

TreeNode<int>* maxChildSum(TreeNode<int>* root) {
  return helperMax(root)->node;
}

int main()
{
    TreeNode<int>*root=takeInputLevelWise();
    //printTree(root);

    cout<<maxChildSum(root)->data;
    delete root;
}





