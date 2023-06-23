#include<iostream>
#include<vector>
#include<queue>
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

TreeNode<int>* maxChildSum(TreeNode<int>*root)
{
    TreeNode<int>* maxNode=root;
    int sum=root->data;

    for(int i=0;i<root->children.size();i++)
        sum+=root->children[i]->data;

    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int>*node=maxChildSum(root->children[i]);
        int nodeSum=node->data;

        for(int i=0;i<node->children.size();i++)
            nodeSum+=node->children[i]->data;

        if(nodeSum > sum)
        {
            sum=nodeSum;
            maxNode=node;
        }
    }

    return maxNode;
}

int main()
{
    TreeNode<int>*root=takeInputLevelWise();
    //printTree(root);

    cout<<maxChildSum(root)->data;
    delete root;
}




