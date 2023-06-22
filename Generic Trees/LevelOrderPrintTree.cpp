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
    cout<<"Enter root data:";
    int rootData;
    cin>>rootData;

    TreeNode<int>*root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter no.of children of "<<front->data<<":";
        int numChild;
        cin>>numChild;

        for(int i=0;i<numChild;i++)
        {
            cout<<"Enter "<<i<<"th child data: ";
            int childData;
            cin>>childData;

            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printLevelWise(TreeNode<int>*root)
{
    if(root==NULL)
        return;

     queue<TreeNode<int>*> pending;
        pending.push(root);
        while(pending.size()!=0){
            TreeNode<int>* frontt=pending.front();
            pending.pop();
            cout << frontt->data << ":";

            for(int i=0;i<frontt->children.size();i++){
                cout<<frontt->children[i]->data;
                 pending.push(frontt->children[i]);

                if (frontt->children.size()-1!=i)
                cout<<",";
            }

              cout << endl;
            }

}

int main()
{
    TreeNode<int>*root=takeInputLevelWise();
    printLevelWise(root);
}
