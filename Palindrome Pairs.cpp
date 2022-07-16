
    /* USING TRIE: GOOD SOLUTION: but don't know why TLE
    It can be solved by trie data strcuture, as we have to find whether two strings after concatenating can become a palindrome or not... We insert all words in reverse in trie.. So if there is a word[i] and we break it into two parts , say left and right w[l] and w[r] so if w[l] is present in trie that means there is a word present which after reversing equals to w[l] so that reverse(founded_word)== w[l] and w[r] is a palindrome then we can append founded_word at the end of current word like this -:: w[l] + w[r] + founded_word and it can be easily determined that it is a palindrome... So idea is clear , now use trie to reduce time for searching and inserting.. 
    
    struct trienode{  // make structure of trie..
      bool isendofword;
        trienode* children[26];
    };
    trienode* getnode(){   // for generating new trienode
        struct trienode* ne=new trienode;
        ne->isendofword=false;
        for(int i=0;i<26;i++){
            ne->children[i]=NULL;
        }
        return ne;
    }
    void insert(trienode* root,string &key){   //  insertion in trienode
        struct trienode* cp=root;
        for(int i=0;i<key.size();i++){
            int ind=key[i]-'a';
            if(cp->children[ind]==NULL){
                cp->children[ind]=getnode();
            }
            cp=cp->children[ind];
        }
        cp->isendofword=true;
    }
    bool search(trienode* root,string &key){  // searching in trienode
        struct trienode* cp=root;
        for(int i=0;i<key.size();i++){
            int ind=key[i]-'a';
            if(cp->children[ind]==NULL){   // if not found return false;
                return false;
            }
            cp=cp->children[ind];
        }
        return cp->isendofword==true; // check if it is end of word or not.
    }
    bool ispalindrome(string t){ // to check if it is palindrome or not
        int i=0,j=t.size()-1;
        while(i<j){
            if(t[i++]!=t[j--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        struct trienode* rt=getnode();
        map<string,int> mp;
        for(int i=0;i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
            mp[words[i]]=i; // mapping words to index
            insert(rt,words[i]); // inserting words
            reverse(words[i].begin(),words[i].end());
        }
        vector<vector<int> > ans;
        if(mp.count("")){
            for(int i=0;i<words.size();i++){
                if(words[i]!="" && ispalindrome(words[i])){
                    ans.push_back({mp[""],i});  // making a seperate case for empty strings
                }
            }
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                string left=words[i].substr(0,j),right=words[i].substr(j);  // breaking string in 2 parts
                if(search(rt,left) && ispalindrome(right) && mp[left]!=i){  // as discussed
                    ans.push_back({i,mp[left]});
                }
                if(search(rt,right) && ispalindrome(left) && mp[right]!=i){// as discussed
                    ans.push_back({mp[right],i});
                }
            }
        }
        return ans;
    }
    */

//with hashing O(n*k^2)
class Solution {
public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string> & words)
    {
        std::vector<std::string> storage;  // Storage for unordered_map that using string_view: can be avoided with C++20 heterogeneous lookup
        storage.reserve(std::size(words));
        for (auto & word : words)
            storage.emplace_back(std::rbegin(word), std::rend(word));
        
        // Put reversed words with their indices to the dictionary
        std::unordered_map<std::string_view, int> m;
        for (int i = 0; i < std::size(storage); ++i)
            m[storage[i]] = i;

        std::vector<std::vector<int>> result;
        for (int i = 0; i < std::size(words); ++i)
            if (!std::empty(words[i]))            
                for (int j = 0; j <= std::size(words[i]); ++j)
                {
                    const std::string_view left { words[i].c_str(), (size_t)j };
                    const std::string_view right { words[i].c_str() + j };

                    auto it = m.find(left);
                    if (it != std::end(m) && it->second != i && std::equal(std::begin(right), std::begin(right) + (std::size(right) >> 1), std::rbegin(right)))
                        result.emplace_back(std::vector<int> { i, it->second });

                    it = m.find(right);
                    if (it != std::end(m) && it->second != i && j && std::equal(std::begin(left), std::begin(left) + (std::size(left) >> 1), std::rbegin(left)))
                        result.emplace_back(std::vector<int> { it->second, i });
                }
        
        return result;
    }
};
