/*
Class Node dan LinkedList
*/
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

using namespace std;
/*
Kelas node merupakan representasi data pada LinkedList
Model LinkedList yang diimplementasikan adalah model dengan
satu pointer dan tidak membuat loop
*/
template <class T>
class Node{
public:
    //konstruktor kelas node dengan nilai sesuai kelas template
    Node(T);
    //copy constructor untuk kelas node
    Node(const Node& N){
        data = N.data;
        next = N.next;
    }
    /*tidak ada destruktor karena Node* next tidak ingin dihancurkan ketika kelas Node dihancurkan*/
    
    //operator assignment untuk kelas node
    Node& operator=(const Node& N){
        data = N.data;
        next = N.next;
        return *this;
    }
    //setter dan getter
    //getter untuk node selanjutnya
    Node* getNext() const;
    //getter untuk value yang disimpan dalam node
    T getVal() const;
    //setter untuk data yang disimpan node
    void setData(T);
    //setter untuk node selanjutnya
    void setNext(Node*);
private:
    T data;         //data yang disimpan oleh tiap Node
    Node* next;     //pointer ke node selanjutnya
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
//deklarasi kelas LinkedList
template <class T>
class LinkedList;


/*
implementasi operator stream untuk kelas LinkedList
contoh penggunaan : 
    cin >> List >> List;
*/
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
//------------------------------

//deklarasi badan kelas LinkedList
template <class T>
class LinkedList{
public:
    //constructor, copy constructor, destructor, operator=, dan operator stream
    LinkedList();
    LinkedList(Node<T>);
    ~LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    friend ostream& operator<< <>(ostream& s,const LinkedList& L);
    friend istream& operator>> <>(istream& s,LinkedList& L);
    
    //method
    //mengembalikan indeks LinkedList pertama kali yang mengandung nilai T
    int find(T) const;
    //mengembalikan apakah LinkedList kosong
    bool isEmpty() const;
    //mengembalikan jumlah elemen
    int getAmmount()const;
    //mengembalikan node di indeks ke-i
    Node<T>* getNode(int) const;
    //menambahkan Node dengan nilai T di akhir LinkedList
    void add(T);
    //menghapus seluruh Node dalam LinkedList yang memiliki value T
    void remove(T);
    //menghapus Node sesuai dengan indeks masukan
    void del(int);
    //mengembalikan nilai dari node pada indeks ke-i
    T get(int i) const;
    //operator [] sesuai pada array, mengembalikan nilai dari node pada indeks ke-i
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
        next = head->getNext();
        delete current;
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
