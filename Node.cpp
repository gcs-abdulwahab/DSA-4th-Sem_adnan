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

int getNodeLength(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->getNext();
        count++;
    }
    return count;
}

void printNodeElements(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->getData() << ' ';
        temp = temp->getNext();
    }
}

Node* getNode(Node* head,int index = 0){
    Node* temp = head;
    if (index != 0){
        for(int i = 0 ; i < (index - 1) ; i++){
            temp = temp->getNext();
        }
        return temp;
    }
    return head;
}

Node* getFirstNode(Node * head){
    return head;
}

Node* getLastNode(Node* head){
    return getNode(head,getNodeLength(head));
}

void insertNode(Node* head,int value){
    Node* newNode = new Node(value);
    Node* temp = getLastNode(head);
    temp->setNext(newNode);
}

int main(){
    Node* firstNode = NULL;
    Node* lastNode = NULL;
    Node* nthNode = NULL;
    int length = 0;
    int n = 20;

    // Default (head)
    Node head(2);

    // linker
    Node* link = &head;

    // dynamically making Nodes and joining them
    while(n--){
        Node* temp = new Node(n);
        link->setNext(temp);
        link = link->getNext();
    }

    // Getting first,last and n'th node and the length
 
    firstNode = getFirstNode(&head);
    lastNode = getLastNode(&head);
    nthNode = getNode(&head,8);
    length = getNodeLength(&head);

    // Displaying
    
    cout << "\nFirst Node : " << firstNode->getData();
    cout << "\nLast  Node : " << lastNode->getData();
    cout << "\nnth   Node : " << nthNode->getData();
    cout << "\nNode Length   : " << length;
    cout << "\nComplete Node : ";
    printNodeElements(&head);


    // Bonus (Add new node)
    insertNode(&head,100);
    
    // New Node
    lastNode = getLastNode(&head);
    
    // Displaying New Node
    cout << "\nNew Node : " << lastNode->getData();
    cout << "\nNew Length : " << getNodeLength(&head);


}
