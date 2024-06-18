// make a vector of diff-profit pair. sort based on difficulty. Then do a max to left type
// algo on difficulty and store the max profit for each difficulty. Sort the workers, keep 2 pointers,
// one at the start of workers, one on sorted vector. move ahead in jobs until you reacha job suitable 
// for a current worker. add that jobs max profit to final ans and move on. remember: workers can be jobless too.

// https://leetcode.com/problems/most-profit-assigning-work/?envType=daily-question&envId=2024-06-18


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({difficulty[i],profit[i]});
        }
        sort(temp.begin(),temp.end());

        vector<int>max_profit;
        int curr_max=0;
        for(int i=0;i<n;i++){
            curr_max=max(curr_max,temp[i].second);
            max_profit.push_back(curr_max);
        }
        int m=worker.size();
        int w=0,j=0;
        int ans=0;
        sort(worker.begin(),worker.end());
        while(w<m && j<n){
            if(temp[j].first<=worker[w]){
                if(j==n-1 || temp[j+1].first>worker[w]) {
                    ans+=max_profit[j];
                    w++;}
                else j++;
            }
            else w++;
            

        }
        return ans;
    }
};
