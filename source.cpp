
//--------Node constructore--------//
template <typename v, typename k>
Node<v, k>::Node(v ke, k value)
{
    key = ke;
    data = value;
    next = nullptr;
}

//--------HashTable constructore--------//
template <typename v, typename k>
Hash<v, k>::Hash(int s)
{
    size = s;
    table = new Node<v, k> *[size];
    for (int i = 0; i < size; i++)
    {
        table[i] = nullptr;
    }
}

//--------Insert the value--------//
template <typename v, typename k>
void Hash<v, k>::insert(v key, k value)
{
    int index = hashFunction(key);
    Node<v, k> *newNode = new Node<v, k>(key, value);

    newNode->next = table[index];
    table[index] = newNode;
}

//--------Remove the value--------//
template <typename v, typename k>
void Hash<v, k>::remove(v key, k value)
{
    int index = hashFunction(key);
    Node<v, k> *temp = table[index];
    Node<v, k> *prev = nullptr;

    while (temp != nullptr && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return;
    }

    if (prev == nullptr)
    {
        table[index] = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
}

//--------Search the value--------//
template <typename v, typename k>
int Hash<v, k>::search(v key,k value){
    int index = hashFunction(key);
        Node<v, k> *temp = table[index];
    while(temp != nullptr && temp->data != value){
        temp = temp->next;
    }
     if (temp != nullptr && temp->data == value) {
        return 1;
    } else {
        return 0;
    }
}

//--------Display the table--------//
template <typename v, typename k>
void Hash<v, k>::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "]: ";
        Node<v, k> *temp = table[i];
        while (temp != nullptr)
        {
            cout << "(" << temp->key << ", " << temp->data << ") -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

//--------HashTable deconstructore--------//
template <typename v, typename k>
Hash<v, k>::~Hash()
{
    cout << "Decostructure call" << endl;
    for (int i = 0; i < size; i++)
    {
        Node<v, k> *current = table[i];
        while (current != nullptr)
        {
            Node<v, k> *prev = current;
            current = current->next;
            delete prev;
        }
    }
    delete[] table;
}