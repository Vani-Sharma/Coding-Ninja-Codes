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

int countLeafNode(TreeNode<int>*root)
{
    if(root==NULL)
        return 0;

    static int cnt=0;
    if(root->children.size()==0)
       cnt=cnt+1;

    for(int i=0;i<root->children.size();i++)
    {
        countLeafNode(root->children[i]);
    }

    return cnt;
}

int main()
{
    TreeNode<int>*root=takeInputLevelWise();
    printLevelWise(root);

    cout<<countLeafNode(root);
}


