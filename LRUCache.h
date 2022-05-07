#pragma once

#include <optional>
#include <list>
#include <map>
#include <string>

#include "KeyValuePair.h"

template<class KeyType, class ValueType>
class LRUCache
{
public:
    LRUCache(size_t size);

    void set(KeyType key, ValueType value);
    std::optional<ValueType> get(KeyType key);
private:
    // capacity == K from the research paper
    size_t size, capacity;
    std::map<KeyType, std::list<int, std::string>> map;
    std::list<KeyValuePair<KeyType, ValueType>> list;

    // Utility functions
    bool is_full();
    void handle_remove(KeyType key, ValueType value);
    void handle_insert(KeyType key, ValueType value);
};

