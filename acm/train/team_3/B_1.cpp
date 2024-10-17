#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n,k=0,k1=1,k2=0,k3=1,k4=0;
    ll s=0;
    cin>>n;
    k1=n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        s+=x;
    }
    while(k1<s){
        if(k1<=s&&k1*2>=s){
            if(s-k1>=k1*2-s){
                k++;
                k1*=2;
                break;
            }else break;
        }
        k++;
        k1*=2;
    }
    if(s<k1)s-=k1/n*(n-1);
    else s-=k1;
    while(s>0){
        s-=n*k3;
        k4+=k3;
        k3*=2;
        k2++;
    }
    cout<<k4+k1/n<<endl;
}
