
1. list中维护一个超过capacity需要删除的节点顺序
2. 不管是get还是put 都要对list的节点顺序更新
3. 当超限时，弹出list尾部的节点，同步更新unordered_map数据
4. 实际的value 存在于 list<int,int>的second中
5. unordered_map的存在满足了o(1)的查找
6. 如果get或者put的数据类型为set,则list<int,int>变成list<int>也应可行



class LRUCache {
public:
    LRUCache(int capacity) : _cap(capacity) {}
    
    // O(1)
    // hash 查找，如果找到了，就把 list 中的节点接下来移到头部
    int get(int key) {
        auto it = _m.find(key);
        if (it == _m.end()) return -1;
        int val = it->second->second;
        _list.erase(it->second);
        _list.push_front(make_pair(key, val));
        _m[key] = _list.begin();
        return it->second->second;
    }
    
    // O(1)
    // 先查找旧 key 是否存在，如果存在，将节点移动到首部。
    // 如果不存在，插入新节点。
    // 如果容量超限，删除最脏的节点。
    void put(int key, int value) {
        auto it = _m.find(key);
        if (it != _m.end()) {
            _list.erase(it->second);
        }
        
        _list.push_front(make_pair(key, value));
        _m[key] = _list.begin();
        
        if (_list.size() > _cap) {
            int key = _list.back().first;
            _m.erase(key);
            _list.pop_back();
        }
    }
private:
    unordered_map<int, list<pair<int,int>>::iterator> _m;
    // 新节点或刚访问的节点插入表头，因为表头指针可以通过 begin 很方便的获取到。
    list<pair<int,int>> _list;
    int _cap;
};







///适用于  key  value 同值的get put
class LRUCache {
public:
    LRUCache(int capacity) : _cap(capacity) {}
    
    // O(1)
    // hash 查找，如果找到了，就把 list 中的节点接下来移到头部
    int get(int key) {
        auto it = _m.find(key);
        if (it == _m.end()) return -1;
        int val = *(it->second);
        _list.erase(it->second);
        _list.push_front(key);
        _m[key] = _list.begin();
        return  *;
    }
    
    // O(1)
    // 先查找旧 key 是否存在，如果存在，将节点移动到首部。
    // 如果不存在，插入新节点。
    // 如果容量超限，删除最脏的节点。
    void put(int key, int value) {
        auto it = _m.find(key);
        if (it != _m.end()) {
            _list.erase(it->second);
        }
        
        _list.push_front(key);
        _m[key]= _list.begin();
        
        if (_list.size() > _cap) {
            int key = _list.back();
            _m.erase(key);
            _list.pop_back();
        }
    }
private:
    unordered_map<int, list<int>::iterator> _m;
    // 新节点或刚访问的节点插入表头，因为表头指针可以通过 begin 很方便的获取到。
    list<int> _list;
    int _cap;
};
