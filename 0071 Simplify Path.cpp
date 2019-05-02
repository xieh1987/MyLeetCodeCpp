class Solution {
public:
    string simplifyPath(string path) {
        deque<string> mydeque;
        string foldername, res;
        for(int i=0;i<path.size();++i)
        {
            if(path[i]=='/')
            {
                if(mydeque.empty()||mydeque.back()!="/")
                    mydeque.push_back("/");
                else if(mydeque.back()==".")
                    mydeque.pop_back();
            }
            else if(path[i]=='.')
            {
                while(i<path.size()&&path[i]!='/')
                    foldername += path[i++];
                if(foldername==".") foldername = "";
                else if(foldername=="..")
                {
                    mydeque.pop_back();
                    if(mydeque.empty()) mydeque.push_back("/");
                    else mydeque.pop_back();
                }
                else mydeque.push_back(foldername);
                foldername = "";
                --i;
            }
            else
            {
                while(i<path.size()&&path[i]-'A'>=0&&path[i]<='z')
                    foldername += path[i++];
                mydeque.push_back(foldername);
                foldername = "";
                --i;
            }
        }
        while(!mydeque.empty()&&mydeque.back()=="/") mydeque.pop_back();
        if(mydeque.empty()) mydeque.push_back("/");
        while(!mydeque.empty())
        {
            res += mydeque.front();
            mydeque.pop_front();
        }
        return res;
    }
};
