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
    queue<TreeNode<int>*>pending;
    pending.push(root);

    while(pending.size()!=0)
    {
        TreeNode<int>*front=pending.front();
        pending.pop();

        cout<<front->data<<":";

         for(int i=0;i<front->children.size();i++)
         {
            cout<<front->children[i]->data<<",";
            pending.push(front->children[i]);

         }

         cout<<endl;

    }
}

bool structurallyIdentical(TreeNode<int>*root1,TreeNode<int>*root2)
{
   if(root1->data !=root2->data || root1->children.size()!=root2->children.size())
    return false;

    bool ans=true;
    for(int i=0;i<root1->children.size();i++)
    {
        ans=structurallyIdentical(root1->children[i], root2->children[i]);
        if(ans==false)
            return false;

    }

    return ans;
}

int main()
{
    TreeNode<int>*root1=takeInputLevelWise();
    //printLevelWise(root1);

    TreeNode<int>*root2=takeInputLevelWise();
    //printLevelWise(root2);


    cout<<((structurallyIdentical(root1,root2)==1)?"true":"false");
}

