#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string AND(string a, string b) {
	if (a.length() < b.length()) swap(a, b);
	int it = a.length()-b.length();
	for (int i = 0; i < it; ++i) {
		a[i] = '0';
	}
	for (int i = 0; i < b.length(); ++i) {
		if ((a[it] == '1') && (b[i] == '1'))
			a[it++] = '1';
		else
			a[it++] = '0';
	}
	return a;
}

string OR(string a, string b) {
	if (a.length() < b.length()) swap(a, b);
	int it = a.length()-b.length();
	for (int i = 0; i < b.length(); ++i) {
		if ((a[it] == '1') || (b[i] == '1'))
			a[it++] = '1';
		else
			a[it++] = '0';
	}
	return a;
}

string NOT(string a) {
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == '1') a[i] = '0';
		else a[i] = '1';
	}
	return a;
}

string XOR(string a, string b) {
	if (a.length() < b.length()) swap(a, b);
	int it = a.length()-b.length();
	for (int i = 0; i < b.length(); ++i) {
		if (a[it] != b[i])
			a[it++] ='1';
		else
			a[it++] = '0';
	}
	return a;
}

string LEF(string a) {
	return a + '0';
}

int main() {
	string a = "100101011";
	string b = "10100";
}

