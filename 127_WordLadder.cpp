#include <iostream>
#include <vector>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int count = 0;
    for(int i=0; i<wordList.size(); i++){
        int dif1 = diff(beginWord, wordList[i]);
        if(dif1 == 0 || dif1 >=2)
            continue;
        int dif2 = diff(wordList[i], endWord);
        if(dif1 > dif2){
            beginWord = wordList[i];
            count ++;
        }
        if(beginWord == endWord)
            return count;
        
    }
    return 0;

}
int diff(string w1, string w2){
    int ret = 0;
    for(int i=0; i<w1.size(); i++){
        if(w1[i] != w2[i])
            ret++;
    }
    return ret;
}