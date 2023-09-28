#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Solved: Sep 23, 2023
void rec(string ret, string num, vector<string>& res, int index){
        if(num.size() == 0)
            return;
        if(ret.size() == num.size()){
            res.push_back(ret);
            return;
        }
        if(num[index] == '7'){
            for(int j=0; j<4; j++){
                ret += (char)(97 + ((int)(num[index]-'0') - 2) * 3 + j);
                rec(ret, num, res, index+1);
                ret.erase(index, 1);
            }
        } else if(num[index] == '8'){
            for(int j=0; j<3; j++){
                ret += (char)(97 + ((int)(num[index]-'0') - 2) * 3 + j+1);
                rec(ret, num, res, index+1);
                ret.erase(index, 1);
            }
        } else if(num[index] == '9'){
            for(int j=0; j<4; j++){
                ret += (char)(97 + ((int)(num[index]-'0') - 2) * 3 + j+1);
                rec(ret, num, res, index+1);
                ret.erase(index, 1);
            }
        }
        else{
            for(int j=0; j<3; j++){
                ret += (char)(97 + ((int)(num[index]-'0') - 2) * 3 + j);
                rec(ret, num, res, index+1);
                ret.erase(index, 1);
            }
        }
        
    }
    
vector<string> letterCombinations(string digits) {
    vector<string> res;
    rec("", digits, res, 0);
    return res;
}
    

int main(){

    cout << "HEEE";

    return 0;
} 