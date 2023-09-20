#include <iostream>
#include <vector>
using namespace std;

// return all subset.
// solved 09/12/2023

void rec(int start, vector<int>& nums, vector<int> ret, vector< vector<int> >& res){
    res.push_back(ret);
    for(int i=start; i<nums.size(); i++){
        ret.push_back(nums[i]);
        rec(i+1, nums, ret, res);
        ret.pop_back();
    }
        
}
vector< vector<int> > subsets(vector<int>& nums){
    vector< vector<int> > res;
    vector<int> ret;
    rec(0, nums, ret, res);
    return res;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    subsets(nums);

    return 0;
}