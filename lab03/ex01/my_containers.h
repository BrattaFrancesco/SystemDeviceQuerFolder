#include <vector>
#include <list>
#include <iostream>

using namespace std;
using std::vector;
using std::cout;
using std::endl;

template <class T>
struct my_stack{
    private:
        vector<T> s;
        int size = 0;
    public:
        void push(const T i);
        T pop(void);
        void visit(void);       
        int getSize(void);
        bool empty(void);
};

template <class T>
struct my_queue{
    private:
        list<T> l;
        int size = 0;
    public:
        void enqueue(const T s);
        T dequeue(void);
        void visit(void);
        int getSize(void);
        bool empty(void);
};