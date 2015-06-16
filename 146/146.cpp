class LRUCache{
public:
    LRUCache(int capacity){
        m_maxlen = capacity;
    }

    int get(int key){
        int value = -1;
        unordered_map<int,list<pair<int,int>>::iterator>::iterator iter = m_map.find(key);
        if(iter != m_map.end()){
            value = iter->second->second;
            m_cache.erase(iter->second);
            m_cache.push_front(make_pair(key,value));
            iter->second = m_cache.begin();
        }
        return value;
    }

    void set(int key, int value){
        unordered_map<int,list<pair<int,int>>::iterator>::iterator iter = m_map.find(key);
        if(iter != m_map.end()){
            m_cache.erase(iter->second);
            m_cache.push_front(make_pair(key,value));
            iter->second = m_cache.begin();
        }else{
            if(m_cache.size() >= m_maxlen){
                m_map.erase(m_cache.back().first);
                m_cache.pop_back();
            }
            m_cache.push_front(make_pair(key,value));
            m_map[key] = m_cache.begin();
        }
    }

private:
    //用双向链表来实现O(1)的插入和删除
    //用hash表来实现O(1)的查找
    list<pair<int,int>> m_cache;
    unordered_map<int,list<pair<int,int>>::iterator> m_map;
    int m_maxlen;
};