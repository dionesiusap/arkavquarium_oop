#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

using namespace std;

template <class T>
class Node{
public:
    Node(T);
    Node(const Node& N){
        data = N.data;
        next = N.next;
    }
    Node& operator=(const Node& N){
        data = N.data;
        next = N.next;
        return *this;
    }
    Node* getNext() const;
    T getVal() const;
    void setData(T);
    void setNext(Node*);
private:
    T data;
    Node* next;
};

template <class T>
Node<T>::Node(T _data){
    data = _data;
    next = NULL;
}
template <class T>
Node<T>* Node<T>::getNext() const{
    return next;
}
template <class T>
T Node<T>::getVal() const{
    return data;
}
template <class T>
void Node<T>::setData(T X){
    data = X;
}
template <class T>
void Node<T>::setNext(Node<T>* N){
    next = N;
}
template <class T>
class LinkedList;
template <class T>
ostream& operator<<(ostream& s, const LinkedList<T>& L){
    for(int i = 0; i < L.getAmmount(); i++){
        s << L[i] << endl;
    }
    return s;
}
template <class T>
istream& operator>>(istream& s,LinkedList<T>& L){
    T x;
    s>>x;
    L.add(x);
    return s;
}
template <class T>
class LinkedList{
public:
    LinkedList();
    LinkedList(Node<T>);
    ~LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    friend ostream& operator<< <>(ostream& s,const LinkedList& L);
    friend istream& operator>> <>(istream& s,LinkedList& L);
    //method
    int find(T) const;
    bool isEmpty() const;
    int getAmmount()const;
    Node<T>* getNode(int) const;
    void add(T);
    void remove(T);
    void del(int);
    T get(int i) const;
    T operator[](int i) const;
private:
    Node<T> *head;
    int ammount;
};

template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    ammount = 0;
}
template <class T>
int LinkedList<T>::getAmmount() const{
    return ammount;
}

template <class T>
LinkedList<T>::LinkedList(Node<T> N){
    head = &N;
    ammount = 1;
}

template <class T>
LinkedList<T>::~LinkedList(){
    Node<T>* current = head;
    Node<T>* next = 0;
    if(current){
        delete current;
        next = head->getNext();
    }
    while(next){
        current = next;
        next = current->getNext();
        delete current;
    }
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L){
    ammount = L.ammount;
    head = new Node<T>(L.getVal());
    Node<T> current = head;
    for(int i = 1; i < ammount; i++){
        current.next = new Node<T>(L[i].next->getVal());
        current = current.next;
    }
    current.next = NULL;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L){
    Node<T>* current = head;
    Node<T>* next = head->getNext();
    delete current();
    while(next){
        current = next;
        next = current->getNext();
        delete current;
    }
    ammount = L.ammount;
    head = new Node<T>(L.getVal());
    current = head;
    for(int i = 1; i < ammount; i++){
        current->next = new Node<T>(L[i].next->getVal());
        current = current->next;
    }
    current->next = NULL;
    return *this;
}
template <class T>
int LinkedList<T>::find(T val) const{
    Node<T>* current = head;
    int i = 0;
    while(current->getVal() != val && ++i < ammount){
        current = current->getNext();
    }
    if(i == ammount){
        throw("Not Found");
    }else{
        return i;
    }
}
template <class T>
bool LinkedList<T>::isEmpty() const{
    return(ammount == 0);
}
template <class T>
void LinkedList<T>::add(T val){
    Node<T>* current = head;
    if(ammount == 0){
        current = head;
        head = new Node<T>(val);
    }else{
        while(current->getNext()){
            current = current->getNext();
        }
        Node<T>* N = new Node<T>(val);
        current->setNext(N);
    }
    ammount++;
}
template <class T>
void LinkedList<T>::remove(T val){
    Node<T>* prev;
    Node<T>* current = head;
    while(current){
        if(current->getVal() == val){
            Node<T>* curr = current;
            if(curr == head){
                head = curr->getNext();
            }else{
                current = current->getNext();
                prev->setNext(current);
            }
            delete curr;
            ammount--;
        }else{
            prev = current;
            current = current->getNext();
        }
    }
}
template <class T>
T LinkedList<T>::get(int i) const{
    if(i >= ammount){
        throw "List Index is beyond the ammount of data";
        return -1;
    }else{
        Node<T>* current = this->head;
        for(int j = 1; j <= i ;j++){
            current = current->getNext();
        }
        return current->getVal();
    }
}
template <class T>
T LinkedList<T>::operator[](int i) const{
    return(get(i));
}
template <class T>
Node<T>* LinkedList<T>::getNode(int i) const{
    Node<T>* current = head;
    if(i>=ammount){
       throw "List Index is beyond the ammount of data"; 
    }else{
        Node<T>* current = this->head;
        for(int j = 1; j <= i ;j++){
            current = current->getNext();
        }
        return current;        
    }
}
template <class T>
void LinkedList<T>::del(int i){
    if(i>=ammount){
       throw "List Index is beyond the ammount of data"; 
    }
    Node<T>* prev;
    Node<T>* current = head;
    int j = 0;
    while(j != i){ 
        prev = current;
        current = current->getNext();
    }
    Node<T>* curr = current;
    if(curr == head){
        head = curr->getNext();
    }else{
        current = current->getNext();
        prev->setNext(current);
    }
    delete curr;
    ammount--;
}
#endif