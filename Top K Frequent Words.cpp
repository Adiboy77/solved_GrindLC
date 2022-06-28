/*
O(N) for hashmap, O(NlogK) for pq --- O(logK) each time
S(K) for hashmap, S(K) for pq
trick : whenever we have a new pair, push it to the pq first
let the pq decide the order, and then pop the top if pq.size() > k
Min-heap: return int a > int b (keep larger one)
low-alphabetical order : string a < string b (keep lower one)
*/
//Min heap is used which sorts the hasmap in ascending order of frequency and pops whenever its size > k, and at last we store the min heap elements in reverse order and return it.
/*
Use this print function to understand the code in between:
 void pv( priority_queue<pair<int, string>,vector<pair<int, string>>, MyComp> pq)
    {
            while(!pq.empty())
            {
                cout<<pq.top().second<<" ";
                pq.pop();
            }
          cout<<endl;      
    }
*/
class Solution {
public:
     struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) 
        {
            if(a.first != b.first) {
                return a.first > b.first;//why does it sorts in ascending order ?
            }
            else {
                return a.second < b.second;
            }
        }
    };
   
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hashmap;
        for(string& word : words) {
            hashmap[word] += 1;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
        for(auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            //cout<<"pushed "<<it->second<<" "<<it->first<<endl;
            //pv(pq);
            if(pq.size() > k) pq.pop();
        }
        vector<string> res;
        while(!pq.empty()) {
            res.insert(res.begin(), pq.top().second);//Here we take the elements in reverse order stored in priority queue
            pq.pop();
        }
        return res;
    }

   
};
