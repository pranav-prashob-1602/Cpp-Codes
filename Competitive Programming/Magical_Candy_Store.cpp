#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin>>T;
    while(T--) {
        ll N;
        cin >> N;
        ll a[N];
        ll l=0,t=-1;
        for(ll i=0;i<N;i++) {
            cin>>a[i];
            if(a[i] == 1) {
                if(i == 0) {
                    l=1;
                }else if(i != N-1) {
                    l=2;
                    t=i;
                }
            }
        }
        if(l == 1) {
            ll q;
            cin>>q;
            while(q--) {
                ll r;
                cin>>r;
                ll ans;
                if(r%N == 0) {
                    ans = (r/N)%mod;
                }else {
                    if(r%N == 1 && r > N ) {
                        ans = (r/N)%mod;
                    }else {
                        ans = (r/N+1)%mod;
                    }
                }
                cout<<ans<<endl;
            }
        }else if(l == 2) {
            ll sum=0,arr[100000]={};
            for(ll i=0;i<N-1;i++) {
                if(i == t-1) {
                    if(a[i]%2 == 0) {
                        sum=sum+a[i]-1;
                        arr[i]=sum;
                    }else {
                        sum+=a[i];
                        arr[i]=sum;
                    }
                }else {
                    if(a[i]%2==0) {
                        sum+=a[i];
                        arr[i]=sum;
                    }else {
                        sum+=a[i]-1;
                        arr[i]=sum;
                    }
                }
            }
            if(a[N-1]%2 == 0) {
                sum+=a[N-1]-1;
            }else {
                sum=sum+=a[N-1];
            }
            ll q;
            cin>>q;
            while(q--){
                ll r,x;
                cin>>r;
                if(r%N == 0) {
                    if(a[N-1]%2 == 0) {
                        x = ((r/N)*sum+1)%mod;
                    }else {
                        x = ((r/N)*sum)%mod;
                    }
                }else {
                    if(t == r%N-1) {
                        if(a[t-1]%2 == 0) {
                            x = ((r/N)*sum+2+arr[r%N-1])%mod;
                        }else {
                            x = ((r/N)*sum+arr[r%N-1])%mod;
                        }
                    }else if(t-1 == r%N-1) {
                        if(a[t-1]%2 == 0) {
                            x = ((r/N)*sum+arr[r%N-1]+1)%mod;
                        }else {
                            x = ((r/N)*sum+arr[r%N-1])%mod;
                        }
                    }else {
                        if(a[r%N-1]%2 != 0) {
                            x = ((r/N)*sum+arr[r%N-1]+1)%mod;
                        }else {
                            x = ((r/N)*sum+arr[r%N-1])%mod;
                        }
                    }
                }
                cout<<x<<endl;
            }
        }
        else{
           ll sum=0,arr[100000]={};
            for(ll i=0;i<N-1;i++) {
                if(a[i]%2 == 0) {
                    sum+=a[i];
                    arr[i]=sum;
                }else {
                    sum+=a[i]-1;
                    arr[i]=sum;
                }
            }
            if(a[N-1]%2 == 0) {
                sum+=a[N-1]-1;
            }else {
                sum=sum+=a[N-1];
            }
           ll q;
            cin>>q;
            while(q--) {
                ll r,x;
                cin >> r;
                if(r%N == 0) {
                    if(a[N-1]%2 == 0) {
                        x = ((r/N)*sum+1)%mod;
                    }else {
                        x = ((r/N)*sum)%mod;
                    }
                }else {
                    if(a[r%N-1]%2 != 0) {
                        x = ((r/N)*sum+arr[r%N-1]+1)%mod;
                    }else {
                        x = (((r/N)*sum+arr[r%N-1])%mod);
                    }
                }
                cout<<x<<endl;
            }
        }
    }
    return 0;
}
