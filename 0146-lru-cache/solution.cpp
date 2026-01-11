class node{
    public:
    int data;
    node*prev;
    node*next;
    node(){
        data=-1;
        prev=nullptr;
        next=nullptr;
    }
    node(int value){
        data=value;
        prev=nullptr;
        next=nullptr;
    }
};
void cacheupdate(node*head,node*node){
    node->prev->next=node->next;
    node->next->prev=node->prev;
    node->next=head->next;
    node->prev=head;
    head->next->prev=node;
    head->next=node; 
}

class LRUCache {
public:
    node*head;
    node*tail;
    unordered_map<int,node*> mpp;
    int cachecapacity;
    LRUCache(int capacity){
        head=new node();
        tail=new node();
        head->prev = nullptr;
        tail->next = nullptr;
        head->next=tail;
        tail->prev=head;
        cachecapacity=capacity;
    }
    int get(int key) {
        int res=-1;
        auto it=mpp.find(key);
        if(it==mpp.end()) return res;
        else{
            if(it->second)
            res=it->second->data;
            cacheupdate(head,it->second);
        }
        return res;
    }
    void put(int key, int value) {
        if(cachecapacity == 0) return;

        if(mpp.size()==cachecapacity){
            auto it1=mpp.find(key);
            if(it1!=mpp.end()){
                it1->second->data=value;
                cacheupdate(head,it1->second);               
            }else{
                node* lru=tail->prev;
                for(auto& it2:mpp){
                    
                    if(it2.second==lru){
                        lru->data=value;
                        int oldkey=it2.first;
                        mpp.erase(oldkey);
                        mpp[key]=lru;
                        cacheupdate(head,lru);
                        break;
                    }
                }
              
            }
        }else{
            auto it=mpp.find(key);
            if(it!=mpp.end()){
                it->second->data=value;
                cacheupdate(head,it->second); 
            }
            else{
                node*newNode=new node(value);
                newNode->next=head->next;
                newNode->prev=head;
                head->next->prev=newNode;
                head->next=newNode;
                mpp.insert({key,newNode});
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
