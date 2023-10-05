#include <iostream>
#include <vector>

using namespace std;

//Resolved: Oct 5, 2023

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(int i=0; i<strs.size(); i++){
            string value = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(value);
        }

        vector<vector<string>> res;
        for(auto k : m)
            res.push_back(k.second);

        return res;
}