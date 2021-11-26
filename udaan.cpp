//soln

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
unordered_set<string> users;
unordered_map<string, vector<pair<pair<int, int>, vector<string>>>> events;

string add_user(string &u){
    if (users.find(u) == users.end()){
        users.insert(u);
        return "success";
    }
    return "failure";
}

string create_event(string date, int start, int duration, int count, vector<string> &users){
    int finish = start + duration - 1;

    if (start < 0 or finish > 1440)
        return "failure";

    if (events.find(date) == events.end()){
        events[date].push_back({{start, finish}, users});
        return "success";
    }else{
        for (auto it : events[date]){
            int s = it.F.F, f = it.F.S;
            if ((start >= s and start <= f) or (finish >= s and finish <= f) or (start <= s and finish >= f)){
                for (auto name : it.second){
                    for (auto user : users){
                        if (name == user)
                            return "failure";
                    }
                }
            }
        }
        events[date].push_back({{start, finish}, users});
        return "success";
    }
}

bool isValid(string &str){
    string v[4] = {"add-user", "create-event", "show-events", "suggest-slot"};
    for (auto &s : v){
        if (s == str)
            return false;
    }
    return true;
}

bool isValidDate(string &str){
    return true;
}

bool is_number(string &s){
    auto it = s.begin();
    while (it != s.end() && isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

vector<string> split(string &s, string d){
    vector<string> output;
    char *str = &s[0];
    char *del = &d[0];
    char *token = strtok(str, del);
    while (token != NULL){
        output.push_back(token);
        token = strtok(NULL, del);
    }
    return output;
}

inline void failure(){
    cout << "failure\n";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        string s;

        getline(cin, s);

        vector<string> inp = split(s, " ");
        int inpSize = inp.size();
        string ins = inp[0];

        if (ins == "add-user"){
            if (inpSize != 2)
                failure();
            else
                cout << add_user(inp[1]) << endl;
        }
        else if (ins == "create-event"){
            if (inpSize < 6)
                failure();
            else{
                string date = inp[1], start = inp[2], dur = inp[3], size = inp[4];

                if (isValidDate(date) and is_number(start) and is_number(dur) and is_number(size)){
                    int startTime = stoi(start), duration = stoi(dur), numUsers = stoi(size);
                    vector<string> listusers;
                    for (int i = 5; i < inpSize; i++)
                        listusers.push_back(inp[i]);

                    cout << create_event(date, startTime, duration, numUsers, listusers) << endl;
                }
                else
                    failure();
            }
        }
        else if (ins == "show-events") {
            if (inpSize != 3)
                failure();
            else{
                string date = inp[1], user = inp[2];
                int cnt = 0;
                for (auto event : events[date]){
                    for (auto name : event.S){
                        if (name == user){
                            cout << event.F.F << "-" << event.F.S + 1 << " ";
                            for (auto name : event.S)cout << name << " ";
                            cout << endl;
                            cnt++;
                        }
                    }
                }
                if (cnt == 0)
                    cout << "none\n";
            }
        }
        else if (ins == "suggest-slot"){
            if (inpSize < 7)
                failure();
            else{
                string date = inp[1], start = inp[2], fin = inp[3], dur = inp[4], size = inp[5];

                if (isValidDate(date) and is_number(start) and is_number(fin) and is_number(dur) and is_number(size)){
                    int startTime = stoi(start), finish = stoi(fin), duration = stoi(dur), numUsers = stoi(size);
                    vector<string> listusers;
                    for (int i = 6; i < inpSize; i++)
                        listusers.push_back(inp[i]);

                    int ans = -1;

                    for (auto user : listusers){
                        int temp = startTime;
                        vector<pair<int, int>> times;

                        for (auto event : events[date])
                            times.push_back({event.F.F, event.F.S});

                        sort(times.begin(), times.end());

                        for (auto k : times)
                            if (temp + duration > k.F)
                                temp = max(temp, k.S + 1);

                        ans = max(ans, temp);
                    }
                    if (ans + duration < finish and ans >= startTime)
                        cout << ans << endl;
                    else
                        cout << "none\n";
                }
                else
                    failure();
            }
        }
        else
            failure();
    }
    return 0;
}
