#include<iostream>
#include<numeric>
#include<cassert>
#include<set>
using namespace std;
class num {
private:
	int up;
	int down;
public:
	num(int x=0,int y=1):up{x},down{y}
	{
		assert(y != 0 && "the down cant be 0");
		gcdnum();
	}

	void gcdnum() {
		up /= gcd(up, down);
		down /= gcd(up, down);
	}

	friend num operator+(num& x,num& y) {
		num z{ x.up * y.down + x.down * y.up,x.down * y.down };
		z.gcdnum();
		return z;
	}

	friend num operator-(num& x, num& y) {
		num z{ x.up * y.down - x.down * y.up,x.down * y.down };
		z.gcdnum();
		return z;
	}

	friend num operator*(num& x, num& y) {
		num z{ x.up * y.up,x.down * y.down };
		z.gcdnum();
		return z;
	}

	friend num operator/(num& x, num& y) {
		num z{ x.up * y.down,x.down * y.up };
		z.gcdnum();
		return z;
	}

	friend bool operator==(num& x, num& y) {
		return (x.up == y.up) && (x.down == y.down);
	}

	void showme() {
		cout << up << '/' << down << endl;
	}
};

class setr {
private:
	set<int> num;
public:

	friend setr operator+(setr& x, setr& y) {
		for (int i : y.num) {
			x.num.insert(i);
		}
		return x;
	}

	friend setr operator-(setr& x, setr& y) {
		for (int i : y.num) {
			x.num.erase(i);
		}
		return x;
	}

	friend setr operator*(setr& x, setr& y) {
		setr z;
		for (int i : y.num) {
			for (int k : x.num) {
				if (i == k)
					z.num.insert(i);
			}
		}
		return z;
	}

	friend ostream& operator<<(ostream& out, setr& y) {
		for (int i : y.num) {
			out << i << " ";
		}
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& in, setr& y) {
		int i = 0;
		while (true) {
			in >> i;
			if (i == -1) break;
			y.num.insert(i);
		}
		return in;
	}

	void showme(){
		for (int i : num) {
			cout << i << ' ';
		}
		cout << endl;
	}

};

int main() {
	num x{ 4,1 };
	num y{ 1,2 };
	num z = x / y;
	z.showme();
	setr n,m,b;
	cin >> n >> m;
	b = n * m;
	b.showme();
}