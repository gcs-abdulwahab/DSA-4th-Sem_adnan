#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node() : data(0), next(NULL) {}

    Node(int data, Node* next = NULL){
        setData(data);
        setNext(next);
    }
    
    void setData(int data)      { this->data = data; }
    void setNext(Node* next)    { this->next = next; }
    int getData()               { return this->data; }
    Node* getNext()             { return this->next; }
};

class LinkedList{
private:
    Node* head;
    
public:
    LinkedList() : head(NULL)   {}
    LinkedList(Node* head)      { setHead(head); }
    bool isEmpty()              { return (head == NULL); }
    void setHead(Node* head)    { this->head = head; }
    Node* getHead()             { return head; }
    Node* getFirst()            { return head; }
    Node* getLast()             { return getNode(getLength()); }

    int getLength(){
        int count = 0;
        if (!isEmpty() ){
            Node* temp = head;
            while(temp != NULL){
                temp = temp->getNext();
                count++;
            }
        }
        return count;
    }

    void print(){
        if (!isEmpty()){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->getData() << ' ';
                temp = temp->getNext();
            }
        }
        else{
            cout<<"empty ?";
        }
    }

    Node* getNode(int index = 0){
        Node* temp = head;
        if (!isEmpty()){
            for(int i = 0 ; i < (index - 1) ; i++){
                temp = temp->getNext();
            }
            return temp;
        }
        return head;
    }

    void insertAtBeginning(int value){
        Node* temp = new Node(value);
        temp->setNext(head);
        head = temp;
    }

    void insertAtLast(int value){
        Node* newNode = new Node(value);
        Node* temp = getLast();
        temp->setNext(newNode);
    }

    void removeFromFirst(){
        Node* temp = head->getNext();
        delete head;
        head = temp;
    }

    void removeFromLast(){
        int len = getLength();
        Node* newTail = getNode(len-1);
        Node* tail = getLast();
        delete tail;
        newTail->setNext(NULL);
    }

};

int main(){
    
    LinkedList l1;
    // l1.insertAtLast(2);
     l1.insertAtBeginning(0);
     l1.insertAtBeginning(-1);
     l1.insertAtBeginning(-2);
        l1.insertAtBeginning(-3);
     
     l1.removeFromLast();
    
     
    l1.print();
} 
