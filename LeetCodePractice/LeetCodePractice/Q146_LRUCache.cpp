#include "LCHeader.h"
/*
Runtime: 76 ms, faster than 97.37% of C++ online submissions for LRU Cache.
Memory Usage: 40 MB, less than 77.50% of C++ online submissions for LRU Cache.
*/

class LRUCache {
private:
    class Node {
    public:
        Node* prev = nullptr;
        Node* next = nullptr;
        int value;
        int key;
    };
public:
    Node* front = new Node();
    Node* end = new Node();
    int cap;
    unordered_map<int, Node*> map;
    LRUCache(int capacity) :cap(capacity) {
        front->next = end;
        end->prev = front;
    }
    ~LRUCache() {
        for (auto& x : map) {
            delete x.second;
        }
    }
    int get(int key) {
        if (map.count(key) == 0) {
            return -1;
        }
        auto node = map[key];
        if (cap == 1 || node->next == end) {
            return node->value;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = end->prev;
        node->next = end;
        end->prev->next = node;
        end->prev = node;
        return node->value;
    }

    void put(int key, int value) {
        if (map.count(key) > 0) {
            map[key]->value = value;
            get(key);
            return;
        }


        Node* node = new Node();
        node->value = value;
        node->key = key;
        map[key] = node;


        node->prev = end->prev;
        node->next = end;
        end->prev->next = node;
        end->prev = node;

        if (map.size() > cap) {
            Node* tmp = front->next;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            map.erase(tmp->key);
            delete tmp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */