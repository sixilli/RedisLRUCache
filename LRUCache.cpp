#include "LRUCache.h"

template <class KeyType, class ValueType>
LRUCache<KeyType, ValueType>::LRUCache(size_t capacity)
{
    this.capacity = capacity;
}

template <class KeyType, class ValueType>
void LRUCache<KeyType, ValueType>::set(KeyType key, ValueType value)
{
    KeyValuePair<KeyType, ValueType> kvp = { .key = key, .value = value};
    
    if (map.contains(key))
    {
        list.erase(map[key]);
        list.push_front(kvp);
        map[key] = list.begin();
        return;
    }

    if (size == capacity)
    {
        map.erase(list.back().key);
        list.pop_back();
        list.push_front(kvp);
        map[key] = list.begin();
        return;
    }

    if (size < capacity)
    {
        size += 1;
        list.push_front(kvp);
        map[key] = list.begin();
    }
}

//template <class KeyType, class ValueType>
//std::optional<ValueType> LRUCache<KeyType, ValueType>::get(KeyType key)
//{
    //if (is_full())
        //return;
//}

template <class KeyType, class ValueType>
bool LRUCache<KeyType, ValueType>::is_full()
{
    if (size >= capacity)
        return true;

}

template <class KeyType, class ValueType>
void LRUCache<KeyType, ValueType>::handle_remove(KeyType key, ValueType value)
{
}

template <class KeyType, class ValueType>
void LRUCache<KeyType, ValueType>::handle_insert(KeyType key, ValueType value)
{
}
