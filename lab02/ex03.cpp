#include <vector>
#include <iostream>

using namespace std;
using std::vector;
using std::cout;
using std::endl;

struct my_stack{
    private:
        vector<int> s;
        int size = 0;
    public:
        void push(int i){
            s.push_back(i);
            size++;
        }

        int pop(void){
            int value = s.back();
            s.pop_back();
            size--;
            return value;
        }

        void visit(void){
            cout << "Content of the stack: " << endl;
            for(int i : s){
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
    my_stack stack;

    cout << "isEmpty: " << stack.empty() << endl;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "isEmpty: " << stack.empty() << endl;
    cout << "Size: " << stack.getSize() << endl;

    stack.visit();

    int i = stack.pop();
    cout << "Popped: " << i << endl;
    cout << "Size: " << stack.getSize() << endl;

    stack.visit();


}