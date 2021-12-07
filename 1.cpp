#include <bits/stdc++.h>
using namespace std;

string smallest(string s){
    
    int l = s.length();
    string ans = "";

    for (int i = 0; i < l-1; i++) {

        if (s[i] > s[i + 1]) {
            for (int j = 0; j < l; j++) {
                if (i != j)
                    ans += s[j];
            }
            return ans;
        }
    }
    ans = s.substr(0, l - 1);
    return ans;
}


int main(){

     string s;
     cin>>s;
    
    cout << smallest(s);

    return 0;
}
