#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//Solved: Oct 8,2023

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> par;
    vector<int> rank;
    for(int i=0; i<=n; i++){
        par.push_back(i);
        rank.push_back(1);
    }

    for(int i=0; i<n; i++){
        if(!unionn(edges[i][0], edges[i][1], par, rank))
            return {edges[i][0], edges[i][1]};
    }
    return {};


}
int find(int num, vector<int>& par){
    int p = par[num];
    while(p != par[p]){
        par[p] = par[par[p]];
        p = par[p];
    }
    return p;
}
bool unionn(int num1, int num2, vector<int>& par, vector<int>& rank){
    int n1 = find(num1, par);
    int n2 = find(num2, par);
    if(n1 == n2)
        return false;
    if(rank[n1] > rank[n2]){
        par[n2] = n1;
        rank[n1] += rank[n2];
    }
    else{
        par[n1] = n2;
        rank[n2] += rank[n1];
    }

        return true;
}