#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

/**
 * Definition of cachelist node, it's double linked list node.
 */
struct CacheNode {
  int key;
  int value;
  CacheNode *pre, *next;
  CacheNode(int k, int v) : key(k), value(v), pre(NULL), next(NULL) {}
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
private:
    int size;
    CacheNode *head, *tail;
    map<int, CacheNode *> mp;         
public:
    LRUCache(int capacity) {
        size=capacity;
        head=tail=NULL;
    }
    
    int get(int key) {
        map<int, CacheNode *>::iterator it = mp.find(key);  
        if(it!=mp.end()){
            CacheNode *node=it->second;
            remove(node);
            addHead(node);
            return node->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        map<int, CacheNode *>::iterator it = mp.find(key);
        if(it!=mp.end()){
            /*链表存在此元素*/
            CacheNode *node=it->second;
            node->value=value;
            remove(node);
            addHead(node);
        }else{
            /*不存在就建立此元素*/
            CacheNode *node=new CacheNode(key,value);
            if(mp.size()>=size){
                /*如果容量超了，就删除链表最末尾元素*/
                map<int, CacheNode *>::iterator iter = mp.find(tail -> key);
                remove(tail);
                mp.erase(iter);
            }
            addHead(node);
            mp[key]=node;
        }
    }
    
    void addHead(CacheNode *node){ 
        /*基本操作: 链表头部插入
        *   - 如果头部为空，head=node
        *   - 如果尾部为空，tail=head 
        * */
        node->next=head;
        node->pre=NULL;
        if(head!=NULL){
            head->pre=node;
        }
        head=node;
        //只有一个节点，tail=head;
        if(tail==NULL){
            tail=head;
        }
    }
    void remove(CacheNode *node){
        /*基本操作之，删除链表中的某元素*/
        /*判断是否是头结点*/
        if(node->pre!=NULL){
            node->pre->next=node->next;
        }else{
            head=node->next;
        }
        /*判断是否是屁股节点 */
        if(node->next!=NULL){
            node->next->pre=node->pre;
        }else{
            tail=node->pre;
        }
    }
};



int main(){
    LRUCache *lruCache = new LRUCache(2);
    lruCache -> put(2, 1);
    lruCache -> put(1, 1);
    cout << lruCache -> get(2) << endl;
    lruCache -> put(4, 1);
    cout << lruCache -> get(1) << endl;
    cout << lruCache -> get(2) << endl;



    return 0;
}