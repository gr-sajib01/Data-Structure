#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void insertEnd(Node** head, Node** tail,int value){
    Node *newNode=new Node();
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(*head==NULL){
        *head=newNode;
        *tail=newNode;
    }
    else{
        (*tail)->next=newNode;
        newNode->prev=*tail;
        *tail=newNode;
    }
}

void deleteEnd(Node** head, Node** tail){
    if (*head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    if(*head==*tail){
        delete *head;
        *head=NULL;
        *tail=NULL;
    }
    else{
        Node* temp=*tail;
        *tail=(*tail)->prev;
        (*tail)->next=NULL;
        delete temp;
    }
}

void displayList(Node *head){
    if (head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void push(Node** top,int value){
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=*top;
    *top=newNode;
}

void pop(Node** top){
    if (*top==NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }

    Node* temp=*top;
    *top=(*top)->next;
    delete temp;
}

void displayStack(Node* top){
    if (top==NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }

    Node* temp=top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void enqueue(Node** front,Node** rear,int value){
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=NULL;

    if (*rear==NULL){
        *front=newNode;
        *rear=newNode;
    }
    else{
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void dequeue(Node** front,Node** rear){
    if (*front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }

    Node *temp=*front;
    *front=(*front)->next;

    if(*front == NULL){
        *rear=NULL;
    }

    delete temp;
}

void displayQueue(Node* front){
    if (front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }

    Node *temp=front;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

void insert(Node** head,int value){
    Node *newNode=new Node();
    newNode->data=value;
    newNode->next=*head;
    *head=newNode;
}

void sortList(Node *head){
    if (head==NULL||head->next==NULL){
        return;
    }

    int swap=1;
    Node *last=NULL;

    while(swap){
        swap=0;
        Node *current=head;

        for(;current->next!=last;current=current->next){
            if(current->data>current->next->data){
                int temp=current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swap = 1;
            }
        }
        last = current;
    }
}

int main() {
    cout << "---Doubly Linked List---" << endl;
    Node* head = NULL;
    Node* tail = NULL;

    insertEnd(&head, &tail, 10);
    insertEnd(&head, &tail, 20);
    insertEnd(&head, &tail, 30);
    cout << "List: ";
    displayList(head);

    deleteEnd(&head, &tail);
    cout << "After delete: ";
    displayList(head);

    cout << endl << "---Stack---" << endl;
    Node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    cout << "Stack: ";
    displayStack(top);

    pop(&top);
    cout << "After pop: ";
    displayStack(top);

    cout << endl << "---Queue---" << endl;
    Node* front = NULL;
    Node* rear = NULL;
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    cout << "Queue: ";
    displayQueue(front);

    dequeue(&front, &rear);
    cout << "After dequeue: ";
    displayQueue(front);

    cout << endl << "--Linked list sorting--" << endl;
    Node *sortHead = NULL;
    insert(&sortHead, 50);
    insert(&sortHead, 20);
    insert(&sortHead, 80);
    insert(&sortHead, 10);
    insert(&sortHead, 30);

    cout << "Before sort: ";
    displayList(sortHead);

    sortList(sortHead);
    cout << "After sort: ";
    displayList(sortHead);

    return 0;
}