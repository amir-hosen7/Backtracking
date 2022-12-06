#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//

//ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
//string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 2e5 + 50;
const ll mod = 1e9 + 7;

ll board[10][10], val[10][10], res;

bool isSafe(ll row, ll col) {
    for (ll i = 0; i < 8; i++) {
        if (board[row][i]) return false;
    }
    for (ll i = row, j = col; i >= 0 and j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    for (ll i = row, j = col; i < 8 and j >= 0; i++, j--) {
        if (board[i][j]) return false;
    }
    return true;
}

void NQueen(ll col) {
    if (col >= 8) {
        ll sum = 0;
        for (ll i = 0; i < 8; i++) {
            for (ll j = 0; j < 8; j++) {
                if (board[i][j] == 1) {
                    sum += val[i][j];
                }
            }
        }
        res = max(res, sum);
        return;
    }
    for (ll i = 0; i < 8; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            NQueen(col + 1);
            board[i][col] = 0;
        }
    }
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        res = 0;
        for (ll i = 0; i < 8; i++) {
            for (ll j = 0; j < 8; j++) {
                board[i][j] = 0;
                cin >> val[i][j];
            }
        }
        NQueen(0);
        printf("%5lld\n", res);
    }
    return 0;
}




/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//

//ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
//string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 2e5 + 50;
const ll mod = 1e9 + 7;

ll board[10], val[10][10], res;

bool isSafe(ll row, ll col) {
    for (ll i = 1; i <= col; i++) {
        if (board[i] == row) return false;
        ll x = abs(row - board[i]), y = abs(col - i);
        if (x == y) return false;
    }
    return true;
}

void NQueen(ll col) {
    if (col > 8) {
        ll sum = 0;
        for (ll i = 1; i <= 8; i++) {
            if (board[i]) {
                sum += val[board[i]][i];
            }
        }
        res = max(res, sum);
        return;
    }
    for (ll i = 1; i <= 8; i++) {
        if (isSafe(i, col)) {
            board[col] = i;
            NQueen(col + 1);
            board[col] = 0;
        }
    }
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        res = 0;
        for (ll i = 1; i <= 8; i++) {
            for (ll j = 1; j <= 8; j++) {
                board[i] = 0;
                cin >> val[i][j];
            }
        }
        NQueen(1);
        printf("%5lld\n", res);
    }
    return 0;
}







*/
