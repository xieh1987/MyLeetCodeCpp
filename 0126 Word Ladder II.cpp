/*DFS with trim: LTE
//transform is not a good method. Instead should use 'a' to 'z' to check transform possibilites.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<string> path;
        vector<bool> visited(wordList.size(), false);
        for(int i=0;i<visited.size();i++) {
            if(wordList[i]==beginWord) visited[i] = true;
        }
        path.push_back(beginWord);
        helper(beginWord, endWord, wordList, res, path, visited);
        return res;
    }
    
    void helper(string& beginWord, string& endWord, vector<string>& wordList, vector<vector<string>>& res, vector<string>& path, vector<bool>& visited) {
        if(!res.empty()&&res[0].size()<path.size()) return;
        if(beginWord==endWord) {
            if(res.empty()||res[0].size()==path.size()) res.push_back(path);
            else if(res[0].size()>path.size()) {
                res.clear();
                res.push_back(path);
            }
            return;
        }
        for(int i=0;i<wordList.size();i++) {
            if(!visited[i]&&transform(beginWord, wordList[i])) {
                visited[i] = true;
                path.push_back(wordList[i]);
                helper(wordList[i], endWord, wordList, res, path, visited);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
    
    bool transform(string& w1, string& w2) {
        int count = 0;
        for(int i=0;i<w1.size();i++) {
            if(w1[i]!=w2[i]) count++;
        }
        return count==1;
    }
};
*/

//BSF
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        queue<vector<string>> q;
        q.push({beginWord});
        bool stop = false;
        unordered_set<string> used = {beginWord};
        unordered_set<string> words(wordList.begin(), wordList.end());
        while(!q.empty()) {
            for(auto w : used) words.erase(w);
            used.clear();
            if(stop) {
                while(!q.empty()) {
                    vector<string> path = q.front(); q.pop();
                    if(path.back()==endWord) res.push_back(path);
                }
                break;
            }
            int count = q.size();
            for(int i=0;i<count;i++) {
                vector<string> path = q.front(); q.pop();
                for(int j=0;j<beginWord.size();j++) {
                    for(auto ch='a';ch<='z';ch++) {
                        string lastword = path.back();
                        lastword[j] = ch;
                        if(words.count(lastword)) {
                            used.insert(lastword);
                            vector<string> vec = path;
                            vec.push_back(lastword);
                            q.push(vec);
                            if(lastword==endWord) stop = true;
                        }
                    }
                }
            }
        }
        return res;
    }
};
