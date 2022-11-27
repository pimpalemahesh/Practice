#include <bits/stdc++.h>
using namespace std;

inline bool job_cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    vector<pair<int,int>> jobs = {{2, 100}, {1, 199}, {2, 207}, {1, 25}, {1, 15}, {3, 1200}, {1, 400}, {4, 1200}};
    sort(jobs.begin(), jobs.end(), job_cmp);
    int mx_deadline = 0;
    for(int i = 0; i < jobs.size(); i++){
        mx_deadline = max(mx_deadline, jobs[i].first);
    }

    vector<int> ans(mx_deadline, 0);
    
    for (int i = 0; i < jobs.size() - 1; i++)
    {
        if(ans[jobs[i].first-1] == 0){
            ans[jobs[i].first-1] = jobs[i].second;
        } else{
            int j = jobs[i].first;
            while(j >= 0 && ans[j] != 0){
                j--;
            }
            ans[j] = jobs[i].second;
        }
    }
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}