#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<int>*>children;

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

TreeNode<int>* takeInputLevelWise()
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

void printLevelWise(TreeNode<int>*root)
{
    static int cnt=0;
    queue<TreeNode<int>*>pending;
    pending.push(root);

    while(pending.size()!=0)
    {
        TreeNode<int>*front=pending.front();
        pending.pop();

        if(cnt==0)
        {
            cnt++;
            cout<<root->data<<endl;
        }
         for(int i=0;i<front->children.size();i++)
         {
            cout<<front->children[i]->data<<" ";
            pending.push(front->children[i]);

         }

         cout<<endl;

    }
}
/*
-------> APPROACH 1 ------->
void depth(TreeNode<int>*root,int d)
{
    root->data=d;
    for(int i=0;i<root->children.size();i++)
    {
        depth(root->children[i],d+1);
    }
}

void replaceDepth(TreeNode<int>*root)
{
    depth(root,0);
}
*/


//-------> APPROACH 2 ------->
TreeNode<int>* replaceDepth(TreeNode<int>*root)
{
    static int cnt=0;
    root->data=cnt;
    cnt++;

    for(int i=0;i<root->children.size();i++)
    {
        replaceDepth(root->children[i]);
        cnt--;
    }

    return root;

}

int main()
{
    TreeNode<int>*root=takeInputLevelWise();

    TreeNode<int>*node1=replaceDepth(root);
    printLevelWise(node1);


}


