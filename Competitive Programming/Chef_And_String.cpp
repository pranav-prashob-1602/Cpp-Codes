#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

#define sz(x) (int)(x).size()

#define ff first
#define ss second

#define mp make_pair

#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
    string s;
    getline(cin, s,'\n');
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    s.clear();
    }
    return 0;
}



