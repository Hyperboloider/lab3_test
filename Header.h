#include <iostream>
#include <string>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <math.h>
#include <algorithm>
namespace fs = std::filesystem;
using namespace std;

class Node {
public:
    string key;
    string value;
    Node* next;

    Node(string key, string value);
};

class HashTable {
private:
    int TABLE_SIZE = 1025;
    Node** table;

public:
    HashTable();
    ~HashTable();
    int hashing(string key);
    void insert(string key, string value);
    string search(string key);
    void remove(string key);
    void show_table();
};

struct definition {
    string key;
    string value;
};

void work_loop(HashTable table, string key);
string get_working_dir();
void parse_file(string path, HashTable& table);
definition parse_line(string line);