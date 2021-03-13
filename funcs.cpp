#include "Header.h"

void work_loop(HashTable table, string key)
{
    cout << "If you want to finish searching insert 0" << endl;
    while (true)
    {
        cout << "Insert a word or a phrase: ";
        getline(cin, key);
        if (key == "0") 
        {
            exit(1);
        }
        if (table.search(key) == "")
        {
            cout << "No element found at key " << key << endl;
            continue;
        }
        else
        {
            cout << endl << "Here is the definition:" << endl;
            cout << table.search(key) << endl;
            continue;
        }
    }
}

string get_working_dir()
{
    fs::path res = fs::current_path();
    return res.string();
}

void parse_file(string path, HashTable& table) 
{
    string line;
    definition parsed_line;
    ifstream in(path);

    if (in.is_open())
    {
        while (getline(in, line))
        {
            parsed_line = parse_line(line);
            table.insert(parsed_line.key, parsed_line.value);
        }
    }
    in.close();
}

definition parse_line(string line)
{
    definition result;
    string key, value;
    size_t position = 0;
    
    while (line[position] != ';')
    {
        key += line[position];
        position++;
    }
    position++;
    while (position < line.length())
    {
        value += line[position];
        position++;
    }
    result.key = key;
    result.value = value;
    return result;
}