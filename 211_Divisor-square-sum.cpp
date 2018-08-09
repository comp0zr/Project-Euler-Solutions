#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

ULL sums[6000001] = {0};
ULL BIT[6000010] = {0};

ULL max_n = 0, max_k = 0;

void Update(ULL i, ULL val)
{
	for(; i <= max_k + 1; i += i&-i)
	{
		BIT[i] += val;
	}
}

ULL Query(ULL i)
{
	ULL res = 0;

	for(; i > 0; i -= i&-i)
	{
		res += BIT[i];
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;

	pair<int, int> queries[q];
	vector<vector<ULL>> S(6000001);

	for(int i=0; i<q; i++)
	{
		ULL N, K;
		cin >> N >> K;

		max_n = max(max_n, N);
		max_k = max(max_k, K);
		queries[i] = {N, K};
		S[N].push_back(K);
	}

	int index = 0;

	for(ULL i = 2; i <= 2450; i++)
	{
		for(ULL j = i; i * j <= 6000000; j++)
		{
			sums[i * j] += (i * i);

			if(i != j) sums[i * j] += (j * j);
		}
	}
	map<pair<int, int>, ULL> ans;

	for(ULL n=1; n <= max_n; n++)
	{
		if(n != 1) sums[n] += (n * n);

		sums[n]++;

		ULL sum = sums[n];
		ULL sq = (ULL)sqrt(sum);

		ULL L = sq * sq;
		ULL R = (sq+1) * (sq+1);
		ULL distance = min(sum - L, R - sum);

		if(distance <= max_k)
		{
			Update(distance + 1, n);
		}
		if(!S[n].empty())
		{
			for(auto k : S[n])
			{
				ans[{n, k}] = Query(k + 1);
			}
		}
	}
	for(int i=0; i<q; i++)
	{
		ULL N = queries[i].first, K = queries[i].second;

		cout << ans[{N, K}] << "\n";
	}
	return 0;
}
