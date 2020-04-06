#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}
    
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
class LFUCache {
    // 缓存容量，时间戳
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it -> second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else {
            // 这里和 get() 函数类似
            Node cache = it -> second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it -> second = cache;
        }
    }
};


class LFUCache {
    class Bucket;
    class Key {
        public:
        int key, val; 
        Bucket *pfreq;

        Key *prev, *next;
        Key(int k, int v, Bucket* f) : key(k), val(v), pfreq(f) {}
        Key(Key* p, Key* n) : prev(p), next(n) {}
    };

    class Bucket {
        Key _head = Key(&_head, &_head);
        Key *head = &_head;

        public:
        int refc, sz = 0;
        Bucket() {}

        bool empty() {
            return sz == 0; 
        }

        void removeKey(Key* pkey) {
            pkey->prev->next = pkey->next;
            pkey->next->prev = pkey->prev;
            --sz;
        }

        void insertKey(Key* pkey) {
            pkey->next = head->next;
            pkey->prev = head;
            head->next->prev = pkey;
            head->next = pkey;
            ++sz;
        }

        int popLast() {
            Key *rm = head->prev;
            int key = rm->key;
            removeKey(rm);
            delete rm;
            return key;
        }
    };
    
    unordered_map<int, Bucket> blist;
    unordered_map<int, Key*> cache;

    int cap;
    Bucket* minf = NULL, *pzero = &blist[0];

    void add(int key, int v) {
        minf = pzero;
        Key* newKey = new Key(key, v, pzero);
        pzero->insertKey(newKey);
        cache.insert(make_pair(key, newKey));
    }

    int& val(int key) {
        Key* entry = cache[key];  
        Bucket *before = entry->pfreq, *after = &blist[before->refc + 1];
        after->refc = before->refc + 1;
        entry->pfreq = after;

        before->removeKey(entry);
        after->insertKey(entry);
        if(before->empty() && before == minf)
            minf = after;
        if(before->refc && before->empty())
            blist.erase(before->refc);
        
        return entry->val;
    }

    void pop() {
        int outkey = minf->popLast();
        cache.erase(outkey);
        if(minf->refc && minf->empty())
            blist.erase(minf->refc);
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        pzero->refc = 0;
    }

    int get(int key) {
        if(!cap || !cache.count(key)) 
            return -1;
        return val(key);
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(!cache.count(key)) {
            if(cache.size() == cap)
                pop();
            add(key, value);
        }
        else {
            val(key) = value;
        }
    }
};



int main(){
    LFUCache* cache = new LFUCache( 2 /* capacity (缓存容量) */ );

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1)<<endl;       // 返回 1
    cache->put(3, 3);    // 去除 key 2
    cout << cache->get(2)<<endl;       // 返回 -1 (未找到key 2)
    cout << cache->get(3)  <<endl;       // 返回 3
    cache->put(4, 4);    // 去除 key 1
    cout << cache->get(1)<<endl;       // 返回 -1 (未找到 key 1)
    cout << cache->get(3)<<endl;       // 返回 3
    cout << cache->get(4)<<endl;       // 返回 4


    return 0;
}