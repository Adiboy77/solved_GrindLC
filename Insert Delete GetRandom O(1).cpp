class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
        s.clear();
    }
    
    bool insert(int val) {
        if(s.find(val) == s.end())
        {
            s.insert(val);
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end())
        {
            s.erase(val);
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
        int res = rand() % s.size();
        
        //May avoid the below for loop if return *(s.begin() + res); works
        //So the below for loop basically returns *(s.begin() + res);
        for(auto it = s.begin();it!=s.end();it++)
        {
            if(res == 0)
                return *it;
            res--;
        }
        return -1;//never reaches here because its given that when getRandom is called then the set is not empty
    }
};
