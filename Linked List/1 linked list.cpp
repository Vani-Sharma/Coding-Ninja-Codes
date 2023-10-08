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

int main()
{
   Node obj(1);
   Node *head=&obj;
   Node obj2(2);
   obj.next=&obj2;

   Node *obj3=new Node(3);
   Node *obj4=new Node(4);

   obj3->next=obj4;
   Node *head2=obj3;

   cout<<obj.data<<" "<<obj2.data;
}
