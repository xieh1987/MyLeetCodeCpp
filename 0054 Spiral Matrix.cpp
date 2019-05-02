class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        while(!matrix.empty())
        {
            vector<int> topline = matrix.front();
            for(vector<int>::iterator it=topline.begin();it!=topline.end();++it)
                res.push_back(*it);
            matrix.erase(matrix.begin());
            for(vector<vector<int>>::iterator it=matrix.begin();it!=matrix.end();++it)
            {
                if(!it->empty())
                {
                    res.push_back(it->back());
                    it->pop_back();
                }
            }
            if(!matrix.empty())
            {
                vector<int> bottomline = matrix.back();
                for(vector<int>::reverse_iterator it=bottomline.rbegin();it!=bottomline.rend();++it)
                    res.push_back(*it);
                matrix.pop_back();
            }
            for(vector<vector<int>>::reverse_iterator it=matrix.rbegin();it!=matrix.rend();++it)
            {
                if(!it->empty())
                {
                    res.push_back(it->front());
                    it->erase(it->begin());
                }
            }
        }
        return res;
    }
};
