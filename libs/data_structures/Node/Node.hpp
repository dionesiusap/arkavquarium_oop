#ifndef Node_HPP
#define Node_HPP
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
#endif