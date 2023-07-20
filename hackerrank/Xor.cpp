#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

void doit()
{
    int N;
    scanf("%d", &N);
    vector<int> V(N);
    vector<ll> pow2(N + 1);
    pow2[0] = 1;
    for (int i = 1; i < N + 1; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    for (int &x : V)
        scanf("%d", &x);
    ll ans = 0;
    for (int i = 0; i < 30; i++)
    {
        int cont[2] = {0, 0};
        for (int &x : V)
            cont[(x >> i) & 1]++;
        if (cont[1] == 0)
            continue;
        ll tmp = (pow2[cont[0]] * pow2[cont[1] - 1]) % MOD;
        ans = (ans + tmp * (1ll << i)) % MOD;
    }
    printf("%lld\n", ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        doit();
    return 0;
}
