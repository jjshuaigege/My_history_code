#include <bits/stdc++.h>
using namespace std;
template <typename T>
int toInt(T s)
{
	int res;
	stringstream ss;
	ss << s;
	ss >> res;
	return res;
}
string toStr(int n)
{
	string res;
	stringstream ss;
	ss << n;
	ss >> res;
	return res;
}
void addZero(string &s, int n, bool pre = true)
{
	string temp(n, '0');
	s = pre ? temp + s : s + temp;
}
void removeZero(string &s)
{
	int i = 0;
	while (i < s.length() && s[i] == '0')
		++i;
	if (i < s.length())
		s = s.substr(i);
	else
		s = "0";
}

string add(string a, string b)
{
	string res;
	removeZero(a);
	removeZero(b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int l = max((int)a.size(), (int)b.size());
	for (int i = 0, j = 0; j || i < l; ++i)
	{
		int t = j;
		if (i < a.size())
			t += toInt(a[i]);
		if (i < b.size())
			t += toInt(b[i]);
		int q = t % 2;   
		res = char(q + '0') + res;
		j = t / 2;        
	}
	return res;
}
string sub(string a, string b)
{
	string res;
	removeZero(a);
	removeZero(b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int lx = (int)a.size(), ly = (int)b.size(), j = 0;
	int *temp = (int *)calloc(lx, sizeof(int));
	for (int i = 0; i < lx; ++i)
	{
		int ai = toInt(a[i]);
		int bi = i < ly ? toInt(b[i]) : 0;
		temp[j++] = ai - bi;
	}
	for (int i = 0; i < lx; ++i)
	{
		if (temp[i] < 0)
		{
			temp[i] += 2;    
			--temp[i + 1];
		}
	}
	for (int i = lx - 1; i >= 0; --i)
	{
		res += toStr(temp[i]);
	}
	return res;
}
string mul(string a, string b)
{
	string res;
	int n = 2;
	if (a.size() > 2 || b.size() > 2)
	{
		n = 4;
		while (n < a.size() || n < b.size())
			n <<= 1;
		addZero(a, n - (int)a.size());
		addZero(b, n - (int)b.size());
	}
	if (a.size() == 1)
		addZero(a, 1);
	if (b.size() == 1)
		addZero(b, 1);
	if (n == 2)
	{
		int temp = toInt(a) * toInt(b);
		res = toStr(temp);
	}
	else
	{
		string a1, a0, b1, b0, c2, c1, c0;
		a1 = a.substr(0, n / 2);
		a0 = a.substr(n / 2);
		b1 = b.substr(0, n / 2);
		b0 = b.substr(n / 2);
		c2 = mul(a1, b1);
		c0 = mul(a0, b0);
		c1 = sub(mul(add(a0, a1), add(b0, b1)), add(c2, c0));
		addZero(c2, n, false);
		addZero(c1, n / 2, false);
		res = add(add(c2, c1), c0);
	}
	return res;
}
int main()
{
    while(1){
	string a, b;
	cout<< "Input:" <<endl;

	cin >> a >> b;

    cout<< "Output:" << endl << mul(a, b) << endl << endl;
    }
}
