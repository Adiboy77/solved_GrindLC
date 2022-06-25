//Important feature: Using upper bound with maps(not unordered_maps) because upper bound needs sorted elements, that's why we have used it with the inner
//set in our code and not with the outer unordered map
class TimeMap {
public:
    unordered_map<string,map<int,string>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        auto it=m[key].upper_bound(timestamp);
        if(it==m[key].begin())return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
