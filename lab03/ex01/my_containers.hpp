#include <vector>
#include <list>
#include <iostream>

using namespace std;
using std::vector;
using std::cout;
using std::endl;

template <class T>
void my_stack<T>::push(const T i){
    s.push_back(i);
    size++;
}

template <class T>
T my_stack<T>::pop(void){
    T value = s.back();
    s.pop_back();
    size--;
    return value;
}

template <class T>
void my_stack<T>::visit(void){
    cout << "Content of the stack: " << endl;
    for(T i : s){
        cout << i << " ";
    }
    cout << endl;
}

template <class T>
int my_stack<T>::getSize(void){
    return size;
}

template <class T>
bool my_stack<T>::empty(void){
    if( size == 0 )
        return true;
    else
        return false;
}

template <class T>
void my_queue<T>::enqueue(const T s){
    l.push_front(s);
    size++;
}

template <class T>
T my_queue<T>::dequeue(void){
    T s = l.back();
    l.pop_back();
    size--;
    return s;
}

template <class T>
void my_queue<T>::visit(void){
    cout << "Content of the queue: " << endl;
    for(T i : l){
        cout << i << " ";
    }
    cout << endl;
}

template <class T>
int my_queue<T>::getSize(void){
    return size;
}

template <class T>
bool my_queue<T>::empty(void){
    if( size == 0 )
        return true;
    else
        return false;
}