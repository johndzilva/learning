#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

void unordered_map_function()
{
    unordered_map<string, int> my_map;

    // insert
    pair<string, int> p("key", 1);
    my_map.insert(p);

    // or insert like array
    my_map["abc"] = 2;
    my_map["a1"] = 3;
    my_map["a2"] = 4;
    my_map["a3"] = 5;

    // finding or printing
    cout << my_map["key"] << endl;
    // or using at() it is useful to handle exceptions when key,value is not available
    cout << my_map.at("abc") << endl;

    // when value is not available it will automatically create with the given key default value as 0
    cout << my_map["def"] << endl;

    // to search for whether the key is available or not
    if (my_map.count("deff") > 0)
        cout << "Available" << endl;
    else
        cout << "Not Available" << endl;

    // update
    my_map["abc"] = 22;

    // delete
    my_map.erase("def");

    cout << my_map.size() << endl;

    // Iterator for accesing the element

    for (unordered_map<string, int>::iterator itr = my_map.begin(); itr != my_map.end(); itr++)
    {
        cout << itr->first << " : " << itr->second << endl;
    }

    // or in c++11 way
    for (pair<string, int> element : my_map)
    {
        cout << element.first << " : " << element.second << endl;
    }
}

void map_function()
{
    map<string, int> mapVar;
    mapVar["def"] = 2;
    mapVar["d1"] = 3;
    mapVar["d2"] = 4;
    mapVar["d3"] = 5;
    cout << mapVar["d"] << endl;
    for (map<string, int>::iterator itr = mapVar.begin(); itr != mapVar.end(); itr++)
    {
        cout << itr->first << " : " << itr->second << endl;
    }

    // finding a element in a map
    // find() function will return .end() if value is not present
    if (mapVar.find("d4") != mapVar.end())
        cout << "Present" << endl;
    else
        cout << "Not Present" << endl;

    // Erasing
    auto it = mapVar.find("d3");
    mapVar.erase(it);

    for (auto itr = mapVar.begin(); itr != mapVar.end(); itr++)
    {
        cout << itr->first << " : " << itr->second << endl;
    }
}

int main(int argc, char const *argv[])
{
    // unordered_map_function();
    map_function();
    return 0;
}
