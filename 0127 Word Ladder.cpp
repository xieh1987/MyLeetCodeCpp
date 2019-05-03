class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size()==0||endWord.size()==0) return 0;
        if(beginWord.size()!=endWord.size()) return 0;
        
        unordered_set<string> mylist(wordList.begin(), wordList.end());
        if(mylist.find(endWord)==mylist.end()) return 0;
        unordered_set<string> head, tail;
        head.insert(beginWord);
        tail.insert(endWord);
        int step = 2;
        
        while(!head.empty()&&!tail.empty()){
            if(head.size()>tail.size()){
                unordered_set<string> tmp(head);
                head = tail;
                tail = tmp;
            }
            
            unordered_set<string> temp_set;
            unordered_set<string>::iterator it;
            for(it=head.begin();it!=head.end();++it){
                string word = *it;
                mylist.erase(word);
                int n = word.size();
                for(int i=0;i<n;++i){
                    string temp = word;
                    for(char l='a';l<='z';++l){
                        if(temp[i]!=l){
                            temp[i] = l;
                            if(tail.find(temp)!=tail.end())
                                return step;
                            if(mylist.find(temp)!=mylist.end()){
                                temp_set.insert(temp);
                                mylist.erase(temp);
                            }
                        }
                    }
                }
            }
            ++step;
            swap(head, temp_set);
        }
        return 0;
    }
};
