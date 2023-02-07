//GFG
class LRUCache
{
    private:
         list<int> keys;
         unordered_map<int,pair<int,list<int>::iterator>> mp;
         int capacity;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity=cap;
    }
    
    //Function to return value corresponding to the key.
     int get(int key)
    {
        int result=-1;
        if(mp.find(key)!=mp.end()){
            result=mp[key].first;
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key].second=keys.begin();
        }
        return result;
    }
    
    //Function for storing key-value pair.
     void set(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key].second=keys.begin();
            mp[key].first=value;
        }
        else{
            if(mp.size()==capacity){
                mp.erase(keys.back());
                keys.pop_back();
            }
            keys.push_front(key);
            mp[key]={value,keys.begin()};
        }
    }
};


//Leetcode
class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
};
class LRUCache {
    unordered_map<int,Node*> node_map;
    Node* head=new Node();
    Node* tail=new Node();
    int cache_capacity;
public:
    LRUCache(int capacity) {
        cache_capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        int result=-1;
        if(node_map.find(key)!=node_map.end()){
            Node* temp=node_map[key];
            result=temp->val;
            remove(temp);
            add(temp);
        }
        return result;
    }
    
    void put(int key, int value) {
        if(node_map.find(key)!=node_map.end()){
            Node* temp=node_map[key];
            remove(node_map[key]);
            temp->val=value;
            add(temp);
        }
        else{
            if(node_map.size()==cache_capacity){
                node_map.erase(tail->prev->key);
                remove(tail->prev);
            }
            Node* new_node=new Node();
            new_node->val=value;
            new_node->key=key;
            add(new_node);
            node_map[key]=new_node;
        }
    }
    void add(Node* node){//push_front of list
        Node* temp=head->next;
        node->next=temp;
        temp->prev=node;
        head->next=node;
        node->prev=head;
    }
    void remove(Node* node){//erase of list
        Node* next_node=node->next;
        Node* prev_node=node->prev;
        prev_node->next=next_node;
        next_node->prev=prev_node;
    }
};