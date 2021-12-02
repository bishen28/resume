#include <bits/stdc++.h>
using namespace std;


void findall(int n, string osf, string &str, vector<string> &ans, int k){

     if(osf.length()==k){
        ans.push_back(osf);
        return;
     }
     for(int i=0;i<n;i++){
        findall(n,osf+str[i],str,ans,k);
     }
}



void solve(){

   int n,k; cin>>n;
   string str;
   for(int i=0;i<n;i++){
      string s;cin>>s;
      str+=s;
   }
   cin>>k;
   vector<string> ans;
   string osf = "";
   findall(n,osf,str,ans,k);

   sort(ans.begin(),ans.end());

   for(int i=0;i<ans.size();i++){
     cout << ans[i];
     if(i<ans.size()-1) cout << endl;
   }

}

int main(){
  
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);

    solve();
  
    return 0;
}
