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

    h.insert("c", "One");
    h.insert("c", "Eleven");
    h.insert("c", "Two");
    h.insert("c", "Twelve");
    h.insert("0", "Twenty-One");
    h.display();
       int r =  h.search("0", "Tdd");
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
