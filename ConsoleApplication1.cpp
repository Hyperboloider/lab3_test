#include "Header.h"

int main() {
    HashTable table;
    string key;

    parse_file(get_working_dir() + +"\\" + "dict.txt", table);
    table.show_table();

    work_loop(table, key);

    return 0;
}