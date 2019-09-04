/*
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
*/

//Simpler version
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        unordered_map<char, int> m;
        for(int i=0;i<secret.size();i++) {
            if(secret[i]==guess[i]) bull++;
            else {
                if(m.find(secret[i])!=m.end()&&m[secret[i]]<0)
                    cow++;
                m[secret[i]]++;
                if(m.find(guess[i])!=m.end()&&m[guess[i]]>0)
                    cow++;
                m[guess[i]]--;
            }
        }
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};
