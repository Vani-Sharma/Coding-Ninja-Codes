#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode*>children;

    TreeNode(T data)
    {
        this->data=data;
    }

};

TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root data:";
    cin>>rootData;

    TreeNode<int>*root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNode;

    pendingNode.push(root);

    while(pendingNode.size()!=0)
    {
        TreeNode<int>*front=pendingNode.front();
        pendingNode.pop();

        cout<<"Enter no. of children of "<<front->data<<":";
        int numChild;
        cin>>numChild;

        for(int i=0;i<numChild;i++)
        {
            cout<<"Enter "<<i<<"th child of "<<front->data<<":";
            int childData;
            cin>>childData;

            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }

    return root;
}

void printTreeNode(TreeNode<int>*root)
{
    if(root==NULL)
        return;

    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
        cout<<root->children[i]->data<<",";

    cout<<endl;

    for(int i=0;i<root->children.size();i++)
        printTreeNode(root->children[i]);

}

int main()
{
    TreeNode<int> *root=takeInputLevelWise();
    printTreeNode(root);
}