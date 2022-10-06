#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;
    Node *previous;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }

    // Deleting node
    // Desctructor for node
    ~Node(){
        if(next!=NULL){
            delete next;
        }
        // cout<<"Deleting node with data "<<data<<endl;
    }

    friend class DoublyLinkedList;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    // Constructor
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    // Methods
    // print
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Insert at Beginning
    void push_front(int data)
    {
        if (head == NULL)
        {
            // No existing linked list, we have to create a new linked list.
            Node *newNode = new Node(data);
            head = tail = newNode;
        }
        else
        {
            // there exist a linked list
            Node *newNode = new Node(data);
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }

    // Insert at end
    void push_back(int data)
    {
        if (head == NULL)
        {
            // No existing linked list, we have to create a new linked list.
            Node *newNode = new Node(data);
            head = tail = newNode;
        }
        else
        {
            // there exist a linked list
            Node *newNode = new Node(data);
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    // Insert at given position
    void insert(int pos, int data)
    {
        if (pos == 1)
        {
            push_front(data);
        }
        else
        {
            // always, pos<=len of DLL
            Node *newNode = new Node(data);
            Node *temp = head;

            for (int jump = 1; jump < pos - 1; jump++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next->previous = newNode;

            temp->next = newNode;
            newNode->previous = temp;
        }
    }

    // Deleting entire linked list 
    // Destructor for linked list
    ~DoublyLinkedList(){
        if(head!=NULL){
            delete head;
            head = NULL;
        }
    }

    //Deleting Front node of DLL
    void pop_front(){
        if(head==NULL){
            cout<<"Linked List is already Empty.\n";
        }
        else if(head->next==NULL){
            head = NULL;
            delete head;
        }
        else{
            Node* temp = head;
            head = head->next;
            head->previous = NULL;
            temp->next = NULL;
            delete temp;
        }
    }

    //Deleting Last node of DLL
    void pop_back(){
        if(head==NULL){
            cout<<"Linked List is already Empty.\n";
        }
        else if(head->next==NULL){
            head = NULL;
            delete head;
        }
        else{
            Node* temp = head;
            //after this loop temp will reach to last node
            while(temp->next!=NULL){
                temp = temp->next;
            }

            tail = temp->previous;
            tail->next = NULL;
            temp->previous = NULL;
            delete temp;
        }
    }

    // Deleting node at given position
    void deleteAtPos(int pos){
        // assume that pos <= len
        if(pos==1){
            // head node delete krna hai
            pop_front();
            return;

        }
        // jo node delete krna hai us pr point
        // krega temp.
        Node*  temp = head;
        for (int jump = 1; jump <= pos-1; jump++)
        {
            temp = temp->next;
        }
        if(temp->next == NULL){
            pop_back();
            return;
        }
        Node * del = temp;
        temp->previous->next = del->next;
        del->next->previous = temp->previous;

        temp->next = NULL;
        temp->previous = NULL;
        delete temp;
        del->next = NULL;
        del->previous = NULL;
        delete del;
    }
};
