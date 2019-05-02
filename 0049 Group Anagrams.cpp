class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        
        for(auto word : strs){
            string word_copy = word;
            sort(word_copy.begin(), word_copy.end());
            if(hash.find(word_copy)!=hash.end())
                hash[word_copy].push_back(word);
            else{
                vector<string> tmp{word};
                hash[word_copy] = tmp;
            }
        }
        for(auto a : hash){
            res.push_back(hash[a.first]);
        }
        return res;
    }
};
