#include <iostream>
#include <vector>

using namespace std;


bool pal(string s, int l, int r){
    while(l<r){
        if(s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void rec(string word, vector<string>& ret, vector<vector<string> >& res, int index){
    if(index == word.size()){
        res.push_back(ret);
        return;
    }

    for(int i=index; i<word.size(); i++){
        if(pal(word, index, i)){
            string str = word.substr(index, i-index+1);
            ret.push_back(str);
            rec(word, ret, res, i+1);
            ret.pop_back();
        }
    }

}

int main(){
    string word = "aab"; 
    vector<string> ret;
    vector<vector<string> > res;
    rec(word, ret, res, 0);

    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << "\"" << res[i][j] << "\"";
        }
    }
    cout << "HELLO";
}