#include "Header.h"

Node::Node(string key, string value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
}

HashTable::HashTable() {
    table = new Node * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* start = table[i];

        while (start != NULL) {
            Node* previous = start;
            start = start->next;
            delete previous;
        }
    }
    delete[] table;
}

int HashTable::hashing(string key) {
    int hash_key = 0;
    for (size_t i = 0; i < key.length(); i++)
        hash_key += key[i];
    return hash_key % TABLE_SIZE;
}

void HashTable::insert(string key, string value) {
    int hash_key = hashing(key);
    Node* previous = NULL;
    Node* start = table[hash_key];

    while (start != NULL) {
        previous = start;
        start = start->next;
    }
    if (start == NULL) {
        start = new Node(key, value);
        if (previous == NULL) {
            table[hash_key] = start;
        }
        else {
            previous->next = start;
        }
    }        
}

string HashTable::search(string key) {
    bool flag = false;
    int hash_key = hashing(key);
    Node* start = table[hash_key];
    while (start != NULL) {
        if (start->key == key) {
            return start->value;
        }
        start = start->next;
    }
    return "";
}

void HashTable::remove(string key) {
    int hash_key = hashing(key);
    Node* previous = NULL;
    Node* start = table[hash_key];
    if (start == NULL || (start->key != key && start->next == NULL)) {
        cout << "no key match found" << endl;
        return;
    }
    if (start->key == key) {
        table[hash_key] = start->next;
        return;
    }
    while (start->next != NULL) {
        previous = start;
        start = start->next;

        if (start->key == key) {
            previous->next = start->next;
            return;
        }
    }
}

void HashTable::show_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << " ";
        if (table[i] == NULL)
            cout << "NULL" << endl;
        else {
            Node* previous = NULL;
            Node* start = table[i];
            while (start != NULL)
            {
                previous = start;
                start = start->next;
                cout << " ---> " << previous->key;
            }
            cout << endl;
        }
    }
}