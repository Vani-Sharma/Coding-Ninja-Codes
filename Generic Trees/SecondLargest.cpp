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

template<typename T>
class Pair
{
    public:
    TreeNode<T>* second;
    TreeNode<T>* max;
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

Pair<int>*helper(TreeNode<int>* root)
{
 Pair<int>*ans=new Pair<int>();
   if(root==NULL)
   {
       ans->second=NULL;
       ans->max=NULL;
       return NULL;
   }

   ans->max=root;
   ans->second=NULL;

   for(int i=0;i<root->children.size();i++)
   {
       Pair<int>*temp=helper(root->children[i]);
       if(ans->max->data < temp->max->data)
       {
           if(temp->second==NULL)
           {
               ans->second=ans->max;
               ans->max=temp->max;
           }

           else
           {
               if(ans->max->data < temp->second->data)
           {
               ans->second=temp->second;
               ans->max=temp->max;
           }

           else
           {
               ans->second=ans->max;
               ans->max=temp->max;
           }
           }


       }

       else
       {
           if((ans->max->data!=temp->max->data)&&
           (ans->second==NULL || ans->second->data < temp->max->data))
           {
               ans->second=temp->max;
           }
       }

}

return ans;
   }

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {

return helper(root)->second;

}

int main()
{
    TreeNode<int>*root=takeInputLevelWise();
    //printLevelWise(root);

    cout<<getSecondLargestNode(root)->data;;
}



