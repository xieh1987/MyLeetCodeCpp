class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> hash;
        for (int i=0;i<secret.size();++i) {
            if (secret[i]==guess[i]) bulls++;
            else {
                if (hash.find(secret[i])==hash.end()) 
                    hash[secret[i]] = 1;
                else {
                    if (hash[secret[i]]<0) {
                        ++cows;
                    }
                    ++hash[secret[i]];
                }
                
                if (hash.find(guess[i])==hash.end()) 
                    hash[guess[i]] = -1;
                else {
                    if (hash[guess[i]]>0) {
                        ++cows;
                    }
                    --hash[guess[i]];
                }
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
