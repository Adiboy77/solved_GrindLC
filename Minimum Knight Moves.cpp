class Solution {
public:
    int minKnightMoves(int x, int y) {
        x=abs(x);
        y=abs(y);
     vector<pair<int, int>> direction {{2,1}, {-2,1},{2,-1},{-2,-1}, 
                                   {1,2},{1,-2}, {-1,2},{-1,-2}};   
        pair<int, int> start {0,0};
        int hops = 0;
       
        queue<pair<int, int> > q;
        q.push(start);
        
        set<pair<int, int>> visited;
        while(!q.empty()){
            
            int q_size = q.size();
            
            for(int i=0;i<q_size;i++)
            {
                
                pair<int, int> p = q.front();
                visited.insert(p);
                if(p.first==x&&p.second==y) return hops;
                q.pop();
                for(auto d: direction)
                {
                        if(visited.find({p.first+d.first,p.second+d.second})==visited.end() && p.first+d.first>= -2 && p.second+d.second>= -2)//last 2 conditions are because we only wanna travel to the positive side due to changes we have made at line 4 and 5
                    {
                        q.push({p.first+d.first, p.second+d.second});
                        visited.insert ({p.first+d.first, p.second+d.second});
                    }
                }
                    
            }
             hops++;
            
        }
         
        return -1;
    }
};
