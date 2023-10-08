#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

};

Node*takeInput()
{
    int data;
    cin>>data;

    Node*head,*tail=NULL;

    while(data!=-1)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
            head=tail=newNode;
        else
        {
            tail->next=newNode;
            tail=newNode;
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


Node *insertPos(Node *head)
{
    int pos,data;
    cout<<endl<<"Enter position and data: ";
    cin>>pos>>data;

    Node *newNode=new Node(data);
    Node *temp=head;

       if(pos==0)
    {
        newNode->next=temp;
        head=newNode;
        return head;
    }

    int cnt=1;
    while(temp!=NULL)
    {
        if(cnt==pos)
        {
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }

        temp=temp->next;
        cnt++;
    }

  return head;

}


int main()
{
    Node *head=takeInput();
    print(head);

    head=insertPos(head);
    print(head);

}
