class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;

        for(auto i: stones)
        p.push(i);

        while(p.size() > 1) {
            int stone = p.top();
            p.pop();
            int next = stone - p.top();
            p.pop();
            if(next!=0)
            p.push(next);
        }

        if(p.size() == 1)
        return p.top();

        else
        return 0;
    }
};