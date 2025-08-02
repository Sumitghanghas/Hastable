#include <iostream>
using namespace std;

//-------Node class-----//
template <typename v, typename k>
class Node
{
public:
    v key;
    k data;
    Node *next;

    Node(v ke, k value);
};

//-------HashaTable class-----//
template <typename v, typename k>
class Hash
{
private:
    int size;
    int thrashold = 75;
    int capacity;
    Node<v, k> **table;

    void resize();

    int hashFunction(int key)
    {
        return key % size;
    }

    int hashFunction(string key)
    {
        int hash = 0;
        for (char ch : key)
        {
            hash = (hash * 31 + ch) % size;
        }
        return hash;
    }

public:
    Hash(int s);
    Hash(const Hash<v, k> &other);
    Hash<v, k> &operator=(const Hash<v, k> &other);
    void insert(v key, k value);
    void remove(v key, k value);
    void display();
    int search(v key, k value);
    ~Hash();
};
#include "source.cpp"
