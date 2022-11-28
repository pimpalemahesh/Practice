#include <bits/stdc++.h>
using namespace std;
class Job
{
public:
    char id;
    int deadLine, profit;
    Job(char id, int d, int p)
    {
        this->id = id;
        this->deadLine = d;
        this->profit = p;
    }
};

int find(int s, vector<int> &parent)
{
    if (s == parent[s])
    {
        return s;
    }
    return parent[s] = find(parent[s], parent);
}

void merge(int u, int v, vector<int> &parent)
{
    parent[v] = u;
}

inline bool cmp(Job a, Job b)
{
    return (a.profit > b.profit);
}

int findMaxDeadline(vector<Job> Jobs)
{
    int mx = 0;
    for (int i = 0; i < Jobs.size(); i++)
    {
        mx = max(mx, Jobs[i].deadLine);
    }
    return mx;
}
int printJobScheduling(vector<Job> Jobs)
{
    sort(Jobs.begin(), Jobs.end(), cmp);
    int maxDeadline = findMaxDeadline(Jobs);
    vector<int> parent(maxDeadline + 1);
    for(int i = 0; i < maxDeadline+1; i++){
        parent[i] = i;
    }
    for (auto job : Jobs)
    {
        int availableSlot = find(job.deadLine, parent);
        if (availableSlot > 0)
        {
            merge(find(availableSlot - 1, parent), availableSlot, parent);
            cout << job.id << " ";
        }
    }
}
int main()
{
    vector<Job> jobs = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 3, 25}, {'e', 3, 15}};
    cout << "Job Sequence for maximum profit :" << endl;
    printJobScheduling(jobs);
    return 0;
}
