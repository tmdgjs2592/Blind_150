#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;







int main()
{
    int N;
    cin >> N;
    vector<int> m;
    for(int i=0; i<N; i++){
        int l;
        cin >> l;
        m.push_back(l);
    }
    int res = 0;
    for(int i=0; i<N; i++){
        res += m[i];
    }
    res -= N;
    cout << res;



    return 0;
}