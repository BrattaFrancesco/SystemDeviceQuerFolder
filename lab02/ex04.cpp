#include <iostream>
#include <list>
#include <string>

using namespace std;

struct my_queue{
    private:
        list<string> l;
        int size = 0;
    public:
        void enqueue(string s){
            l.push_front(s);
            size++;
        }

        string dequeue(void){
            string s = l.back();
            l.pop_back();
            size--;
            return s;
        }

        void visit(void){
            cout << "Content of the queue: " << endl;
            for(string i : l){
                cout << i << " ";
            }
            cout << endl;
        }

        int getSize(void){
            return size;
        }

        bool empty(void){
            if( size == 0 )
                return true;
            else
                return false;
        }
};

int main() {
    my_queue queue;

    cout << "isEmpty: " << queue.empty() << endl;
    
    queue.enqueue("Ciao");
    queue.enqueue("Cane");
    queue.enqueue("Gatto");

    cout << "isEmpty: " << queue.empty() << endl;
    cout << "Size: " << queue.getSize() << endl;

    queue.visit();

    string s = queue.dequeue();
    cout << "Dequeued: " << s << endl;
    cout << "Size: " << queue.getSize() << endl;

    queue.visit();

}