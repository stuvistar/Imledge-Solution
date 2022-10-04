#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#include <chrono>
using namespace std::chrono;
//-------------------------------------
typedef long long int  ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
#define forr(i,a) for(ll i=0; i<a; i++)
#define rfor(i,a)for(ll i=a-1; i>=0;i--);
#define all(x) x.begin() ,x.end()
#define nl '\n'
#define pb push_back


	const ll p = 31; 
	const ll m = 1e9 + 7;
	unordered_map<ll , ll > mp;
	vector<ll> p_pow;
	ll rabin_karp(string & s) {
	    ll S = s.size() ;
	    long long h_s = 0; 
	    for (int i = 0; i < S; i++) {

	        h_s = (h_s + ((s[i] - 'a' + 1) * p_pow[i]) % m)%m; 

	   
	    }
	    return h_s;
	}
	   int dp[30];
	ll recur(ll i , string & s ){
	    if(i == s.size()){
	        return 1;
	    }
	    if(dp[i] != -1)
	        return dp[i];
	    int ans = 0;
	    ll cur = 0;
	    for(int k = i ,  j = 0 ; k < s.size() ; k++ , j++){

	        cur = ((cur + (s[k] - 'a' + 1) * p_pow[j])% m)%m;
	        if(mp.find(cur) != mp.end() and (k - i + 1) != s.size() ){
	            ans |= recur(k + 1 , s );
	        }
	    }
	    
	    return dp[i] = ans;

	}
	static bool cmp(string &a , string &b){
	    int sza = a.size();
	    int szb = b.size();
	    return sza < szb or (sza == szb and a > b);
	}
void solve() {

    string s;
    vector<string > v;
    p_pow.assign(30 , 0);
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;
    while(getline(cin , s) ){
        v.pb(s);

        ll cur = rabin_karp(s);
        mp[cur] = 1;
            // cout << cur << endl;
    }
    sort(all(v) , cmp);
    int n = v.size();
    bool flag = true;
    for(int i = n - 1 ; i >=0 ; i--){
        memset(dp , -1 ,sizeof(dp));
        ll check = recur(0 , v[i] );
        if(check){
            if(flag ){
                cout << "Longest Compound Word is: " << v[i] <<endl<<"Size: "<<v[i].size()<<endl;
                flag = false;
            }
            else{
                cout << "2nd Longest Compound Word is: "<<v[i] <<endl<<"Size: "<<v[i].size()<<endl;
                break;
            }
        }
    }

}


int main() {

  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout.tie(NULL);
  cout<<fixed<<setprecision(100);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  auto start = high_resolution_clock::now();
  
  solve();

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
 

	cout << "Time took: "<<duration.count() << endl;
	return 0;

}
