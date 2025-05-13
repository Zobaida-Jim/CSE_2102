#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class List{
    public:
    Node* head;
    Node* tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void Deletion(int val) //Find and delete a value from Linked List
    {
        Node* temp = head;
        while(temp != NULL && temp->next->data != val)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        cout<<"Deletion Done"<<endl;
    }
    void printList()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    List LL;
    LL.push_front(50);
    LL.push_front(40);
    LL.push_front(30);
    LL.push_front(20);
    LL.push_front(10);
    LL.printList();

    LL.Deletion(30);
    LL.printList();
    return 0;
}