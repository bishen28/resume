#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    
    vector<vector<int>> st;
    vector<int> ans(n);
    st.push_back({1000000000,0});
    st.push_back({vec[0],0});
    
    for(int i=1;i<n;i++){
        if(vec[i] >= st.back().at(0)){
            int cnt= 0;
            while(st.size() >1 && st.back().at(0)<= vec[i]){
                if(st.back().at(1)) cnt+=st.back().at(1) +1;
                else cnt++;
                st.pop_back();
            }
            ans[i] = cnt;
            st.push_back({vec[i],ans[i]});
        }else{
            ans[i] = 0;
            st.push_back({vec[i],0});
        }
    }
    
    for(int i=0;i<n;i++){
        cout << ans[i];
        if(i<n-1) cout << " ";
    }
    
}


int main() {
    solve();
    return 0;
}
