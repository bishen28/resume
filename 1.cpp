// https://developer.mozilla.org/en-US/docs/Learn/Server-side/Django/Introduction/basic-django.png


#include <bits/stdc++.h>
using namespace std;

void solve(){
     
   int n;
   cin>>n;
   vector<pair<int,int>> vec;

   for(int i=0;i<n;i++){
    int Si,Di;cin>>Si>>Di;
    vec.push_back({Si,Si+Di-1});
   }

 sort(vec.begin(), vec.end(), [](auto &left, auto &right){
    return left.second < right.second;
 });

vector<pair<int,int>> ans;
ans.push_back(vec[0]);

for(int i=1;i<n;i++){
    if(vec[i].first>ans.back().second){
        ans.push_back(vec[i]);
    }
}
  cout << ans.size();

}




int main(){


     solve();
  
    return 0;
}
