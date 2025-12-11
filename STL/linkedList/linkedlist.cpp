#include<bits/stdc++.h>
using namespace std;

//creating a node

//method 1
struct node{
    int data;
    node* next;

    node(int value, node* nextNode = nullptr){
        data = value;
        next = nextNode;
    }
};

//method 2
struct Node{
    int data;
    Node* next;

    Node(int data, Node* next = nullptr){
        this->data = data;
        this->next = next;
    }
};

//method 3 
struct NODE{
    int data;
    NODE* next;

    NODE(int data, NODE* next)
        : data(data) , next(next) {}
};

//printList(head); linkdedlist
void printList(node* head){
    node* curr = head;
    while(curr != nullptr){
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

//insert at head
void insertHead(node*& head, node* newNode){ // I have done mistake of not passing head by reference
    newNode->next = head;
    head = newNode;
}

//insert at tail
void insertLast(node*& head, node* newNode){
    node* curr = head;
    if(curr == nullptr) {
        head = newNode;
        return; // improvement to end function their 
    }
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = newNode;
}

//find length of linked list
int len(node* head){
    node* curr = head;
    int length = 0;
    while(curr != nullptr){
        length++;
        curr = curr->next;
    }
    return length;
}

//insert at position
void insertAtPos(node*& head, node* newNode, int pos){ // never pass new Node by reference
    int length = len(head);
    if(pos > (length+1)){
        cout << "Insertion Not possible" << endl;
        return;
    }
    else if(pos == 1){
        insertHead(head, newNode);
        return;
    }
    else if(pos == length+1){
        insertLast(head, newNode);
        return;
    };
    node* curr = head;
    for(int i = 1; i < pos-1; i++){
        curr = curr->next;
    }
    node* copy = curr->next;
    curr->next = newNode;
    newNode->next = copy;
}


int main()
{   

    node* a = new node(3);
    node* b = new node(5);

    a->next = b;

    node* head = nullptr;
    head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);

    printList(head);

    node* zero = new node(0);
    insertHead(head, zero);

    printList(head);

    node* four = new node(4);
    insertLast(head, four);

    printList(head);

    node* negThree = new node(-3);
    int position = 3;
    insertAtPos(head, negThree, position);


    
    


    // cout << a->data << endl;
    // cout << a->next->data << endl;

    
    return 0;
}