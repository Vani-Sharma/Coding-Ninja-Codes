#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

Node *takeInput()
{
    int data;
    cin>>data;

    Node *head,*tail=NULL;
    while(data!=-1)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
            {
                head=tail=newNode;
            }
        else
        {
            tail->next=newNode;
            tail=tail->next;

        }

        cin>>data;
    }

    return head;
}

void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}


Node *deletePos(Node *head)
{
    int pos;
    cout<<endl<<"Enter pos to delete element: ";
    cin>>pos;

    Node*temp=head;

    for(int i=2;i<pos && temp!=NULL;i++)
        temp=temp->next;

if(temp!=NULL)
{
   if(pos ==1)
        {
            head=temp->next;
            delete temp;

        }

    else
    {
        Node*temp2=temp->next;
        temp->next=temp2->next;
        delete temp2;
    }
}


    return head;
}

int main()
{
    Node *head=takeInput();
    print(head);

    head=deletePos(head);
    print(head);
}

