#include <bits/stdc++.h>
using namespace std;

long MAX = 1e12;
double b, u;

set<double> found;

double F(double n)
{
	double e = (b - powl(n, 2.00000L));
	double power1 = floor(powl(2.0000000L, e));
	double power2 = 1000000000L;

	return power1 / power2;
}

int main()
{
	cin >> u >> b;

	double prev = u, next;
	found.insert(u);

	for(long i=1; i<=MAX; i++)
	{
		next = F(prev);

		if(found.count(next) && found.count(prev))
		{
			break;
		}
		found.insert(next);
		prev = next;
	}
	cout << fixed << setprecision(9) << next + prev << endl;
	return 0;
}
