class LRUCache {
public:
class Node {
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int _key, int _val){
        key=_key;
        val=_val;
    }
};

Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);
int cap;
unordered_map<int,Node*>m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode_fun(Node* add_node){
        Node* add_next = head->next;
        head->next = add_node;
        add_node->prev = head;
        add_node->next = add_next;
        add_next->prev = add_node;
    }
    
    void deletenode_fun(Node* del_node){
        Node* prev1 = del_node->prev;
        Node* next1 = del_node->next;
        prev1->next = next1;
        next1->prev = prev1;
    }

    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* ptr = m[key];
            int val = ptr->val;
            m.erase(key);
            deletenode_fun(ptr);
            addnode_fun(ptr);
            m[key]=head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* temp = m[key];
            m.erase(key);
            deletenode_fun(temp);
        }
        if(cap==m.size()){
            m.erase(tail->prev->key);
            deletenode_fun(tail->prev);
        }

        Node* new_node = new Node(key,value);
        addnode_fun(new_node);
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */