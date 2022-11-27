#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    int deadline;
    int profit;
    Job(int d, int p)
    {
        this->deadline = d;
        this->profit = p;
    }
};

bool job_cmp(Job a, Job b)
{
    return a.profit > b.profit;
}
int main()
{

    vector<Job> jobs = {{2, 100}, {1, 199}, {2, 207}, {1, 25}, {1, 15}, {3, 1200}, {1, 400}, {4, 1200}};
    sort(jobs.begin(), jobs.end(), job_cmp);
    int mx_deadline = 0;
    for(int i = 0; i < jobs.size(); i++){
        mx_deadline = max(mx_deadline, jobs[i].deadline);
    }

    vector<int> ans(mx_deadline, 0);
    
    for (int i = 0; i < jobs.size() - 1; i++)
    {
        if(ans[jobs[i].deadline-1] == 0){
            ans[jobs[i].deadline-1] = jobs[i].profit;
        } else{
            // int j = mx_deadline
            int j = i;
            while(j >= 0 && ans[j] != 0){
                j--;
            }
            ans[j] = jobs[i].profit;
        }
    }
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}