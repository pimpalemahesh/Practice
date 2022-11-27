#include <bits/stdc++.h>
using namespace std;

inline bool cmp(pair<double, double> a, pair<double, double> b){
    return a.first/a.second > b.first/b.second;
}
int main()
{
    double cap = 20, profit = 0;
    vector<pair<double, double>> Items = {{25, 18}, {24, 15}, {15, 10}};
    sort(Items.begin(), Items.end(), cmp);
    for(auto item : Items){
        if(item.second <= cap){
            cap -= item.second;
            profit += item.first;
        } else{
            profit += item.first * (cap/item.second);
            break;
        }
    }
    cout << "Profit = " << profit << endl;
    return 0;
}