/*
Problem
Design an in-memory file system to simulate the following functions:

ls: Given a path in string format. If it is a file path, return a list that only contains this file’s name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.

mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don’t exist either, you should create them as well. This function has void return type.

addContentToFile: Given a file path and file content in string format. If the file doesn’t exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.

readContentFromFile: Given a file path, return its content in string format.

See test cases from internet or youtube as well
*/
// Time:  ls: O(l + klogk), l is the path length, k is the number of entries in the last level directory
//        mkdir: O(l)
//        addContentToFile: O(l + c), c is the content size
//        readContentFromFile: O(l + c)
// Space: O(n + s), n is the number of dir/file nodes, s is the total content size.

class FileSystem {
public:
    FileSystem() : root_(new TrieNode()) {
        
    }
    
    vector<string> ls(string path) {
        auto curr = getNode(path);
        
        if (curr->isFile) {
            return {split(path, '/').back()};
        }
        
        vector<string> result;
        for (const auto& child : curr->children) {
            result.emplace_back(child.first);
        }
        sort(result.begin(), result.end());
        return result; 
    }
    
    void mkdir(string path) {
        auto curr = putNode(path);
        curr->isFile = false;
    }
    
    void addContentToFile(string filePath, string content) {
        auto curr = putNode(filePath);
        curr->isFile = true;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        return getNode(filePath)->content;
    }

private:
    struct TrieNode {
        bool isFile;
        unordered_map<string, TrieNode *> children;
        string content;
    };

    TrieNode *root_;
    
    TrieNode *getNode(const string& path) {
        vector<string> strs = split(path, '/');
        auto curr = root_;
        for (const auto& str : strs) {
            curr = curr->children[str];
        }
        return curr;
    }

    TrieNode *putNode(const string& path) {
        vector<string> strs = split(path, '/');
        auto curr = root_;
        for (const auto& str : strs) {
            if (!curr->children.count(str)) {
                curr->children[str] = new TrieNode();
            }
            curr = curr->children[str];
        }
        return curr;
    }

    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            if (!token.empty()) {
                tokens.emplace_back(token);
            }
        }
        return tokens;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
