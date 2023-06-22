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
};

TreeNode<int>*takeInputLevelWise()
{
    int rootData;
    cin>>rootData;

    TreeNode<int>*root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pending;

    pending.push(root);

    while(pending.size()!=0)
    {
        TreeNode<int>*front=pending.front();
        pending.pop();

        int numChild;
        cin>>numChild;

        for(int i=0;i<numChild;i++)
        {
            int childData;
            cin>>childData;

            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pending.push(child);
        }

    }

    return root;

}

void printLevelWise( TreeNode<int>*root)
{
    queue<TreeNode<int>*>pending;
    pending.push(root);

    while(pending.size()!=0)
    {
        TreeNode<int>*front=pending.front();
        pending.pop();

        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++)
        {
            cout<< front->children[i]->data<<",";
            pending.push(front->children[i]);
        }

        cout<<endl;
    }

}

void printNodeAtDepthK(TreeNode<int>*root,int d)
{
    if(d==0)
        {
            cout<<root->data<<" ";
            return;
        }

    for(int i=0;i<root->children.size();i++)
    {
        printNodeAtDepthK(root->children[i],d-1);
    }

}

int main()
{
    TreeNode<int>*root=takeInputLevelWise();
    //printLevelWise(root);

    printNodeAtDepthK(root,1);
}

