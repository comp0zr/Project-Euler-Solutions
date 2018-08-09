#include <bits/stdc++.h>
using namespace std;

long long memo[10000000] = {0};
long long length[10000000] = {0};
long long ans[5000001] = {0};


long long Collatz(long long n)
{
	long long res = 0;

	while(n != 1)
	{
		if(n < 10000000 && memo[n] != 0)
		{
			return res + memo[n];
		}
		n = (n % 2 == 0) ? n / 2 : n * 3 + 1;
		res++;
	}
	return res + 1;
}

int main()
{
	long long largest = 0;

	for(long long i = 1; i <= 5000000; i++)
	{
		memo[i] = Collatz(i);
		length[memo[i]] = max(length[memo[i]], i);
		largest = max(largest, memo[i]);

		ans[i] = length[largest];
	}
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		cout << ans[n] << "\n";
	}

	return 0;
}
