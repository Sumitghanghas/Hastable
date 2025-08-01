#include <iostream>
#include "hash.h"
using namespace std;

int main()
{
    // Hash<int, string> h(10);

    // h.insert(1, "One");
    // h.insert(11, "Eleven");
    // h.insert(2, "Two");
    // h.insert(12, "Twelve");
    // h.insert(21, "Twenty-One");
    // h.display();

    // h.remove(21, "Twenty-One");

    // h.display();

        Hash<string, string> h(2);

    h.insert("ac", "One");
    h.insert("cc", "Eleven");
    h.insert("bcc", "Two");
    h.insert("icc", "Twelve");
    h.insert("t20", "Twenty-One");
    h.display();
       int r =  h.search("t20", "Tdd");
    if(r){
        cout<<"the node is exist"<<endl;
    }
    else{
                cout<<"the node is not exist"<<endl;

    }
    h.remove("icc", "Twelve");

    h.display();

    return 0;
}
