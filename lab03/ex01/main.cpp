#include <iostream>
#include "my_containers.h"
#include "my_containers.hpp"

using namespace std;

int main(){
    my_stack<int> intStack;

    cout << "isEmpty: " << intStack.empty() << endl;
    
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    cout << "isEmpty: " << intStack.empty() << endl;
    cout << "Size: " << intStack.getSize() << endl;

    intStack.visit();

    int i = intStack.pop();
    cout << "Popped: " << i << endl;
    cout << "Size: " << intStack.getSize() << endl;

    intStack.visit();

    my_stack<string> strStack;

    cout << "isEmpty: " << strStack.empty() << endl;
    
    strStack.push("1");
    strStack.push("2");
    strStack.push("3");

    cout << "isEmpty: " << strStack.empty() << endl;
    cout << "Size: " << strStack.getSize() << endl;

    strStack.visit();

    string i = strStack.pop();
    cout << "Popped: " << i << endl;
    cout << "Size: " << strStack.getSize() << endl;

    strStack.visit();

    my_queue<string> strQueue;

    cout << "isEmpty: " << strQueue.empty() << endl;
    
    strQueue.enqueue("Ciao");
    strQueue.enqueue("Cane");
    strQueue.enqueue("Gatto");

    cout << "isEmpty: " << strQueue.empty() << endl;
    cout << "Size: " << strQueue.getSize() << endl;

    strQueue.visit();

    string s = strQueue.dequeue();
    cout << "Dequeued: " << s << endl;
    cout << "Size: " << strQueue.getSize() << endl;

    strQueue.visit();
}