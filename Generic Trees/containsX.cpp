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

bool containsX(TreeNode<int>*root,int x)
{
    bool ans=false;
    if(root->data==x)
        return true;

    for(int i=0;i<root->children.size();i++)
         {
             ans=containsX(root->children[i],x);
             if(ans)
                return true;
         }

    return ans;

}

int main()
{
    TreeNode<int>*root=takeInputLevelWise();
    printTree(root);

    int x=4;
    cout<<containsX(root,x);
    delete root;
}


