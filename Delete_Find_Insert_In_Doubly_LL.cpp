#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DLL
{
    public:
    Node* head;
    Node* tail;
    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void InsertAtHead(int val) //Insert At head
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtPosition(int val, int pos) // Insert at position
    {
        cout<<endl<<"Insert Node At given Position"<<endl;
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i=0;i<pos-1;i++) // find temp
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        temp->prev->prev = newNode;
        newNode->prev = temp;

    }

    void insert_at_end(int val) //Insert at end
    {
        cout<<endl<<"Insert at end"<<endl;
        Node* newNode = new Node(val);
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }

    void deletetion()// Delete from Head
    {
        cout<<endl<<"Delete from Head"<<endl;
        Node* temp = head;
        head = head->next;
        if(head != NULL)
        {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void delete_from_poosition(int pos)// Delete from position
    {
        cout<<endl<<"Delete Node from position"<<endl;
        Node* temp = head;
        for(int i=0;i<pos;i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void pop_back()// Delete from end
    {
        cout<<endl<<"Delete from end"<<endl;
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void find(int val)// Find a value
    {
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data == val)
            {
                cout<<endl<<"Found the value "<<temp->data<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<endl<<"Value not Found"<<endl;
    }

    void printList()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    DLL l;
    cout<<"Insert At Head"<<endl;
    l.InsertAtHead(50);
    l.InsertAtHead(40);
    l.InsertAtHead(30);
    l.InsertAtHead(20);
    l.InsertAtHead(10);
    l.printList();

    l.deletetion();
    l.printList();

    l.find(30);

    l.insertAtPosition(11,3);
    l.printList();

    l.delete_from_poosition(3);
    l.printList();

    l.insert_at_end(5);
    l.printList();

    l.pop_back();
    l.printList();

    return 0;
}