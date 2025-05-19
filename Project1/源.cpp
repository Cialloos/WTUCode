#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Vector {
private:
	int x, y, z;
public:
	Vector(int a=0,int b=0,int c=0)
		:x{a},y{b},z{c}
	{}

	friend Vector operator+(Vector&, Vector&);
	friend bool operator==(Vector&, Vector&);

	friend istream& operator>>(istream& in,Vector& a) {
		in >> a.x >> a.y >> a.z;
		return in;
	}

	friend ostream& operator<<(ostream& out,Vector& a) {
		out << '(' << a.x << ',' << a.y << ',' << a.z << ')';
		return out;
	}
};

Vector operator+(Vector& a, Vector& b) {
	Vector c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z = b.z;
	return c;
}

bool operator==(Vector& a, Vector& b) {
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

int count(vector<int>& v,int tag) {
	int count = 0;
	for (int i : v) {
		if (i == tag) count++;
	}
	return count;
}

class vehicle {
public:
	string name;
	double whel, wegt,deca,maxspd;

	vehicle(string s,double a,double b,double c,double d)
		:name{s},whel{a},wegt{b},deca{c},maxspd{d}
	{}

	friend ostream& operator<<(ostream& out, vehicle& v) {
		out << "name " << v.name << ' ' << " wheels " << v.whel << " weight " << v.wegt
			<< " delivery capacity " << v.deca << " max speed " << v.maxspd;
		return out;
	}
};

class truck:protected vehicle {
private:
	int passload;
	double payload;
public:
	truck(int p,double pa, string s, double a, double b, double c, double d)
		:passload{ p }, payload{pa}, vehicle{ s,a,b,c,d }
	{}

	friend ostream& operator<<(ostream& out, truck& t) {
		vehicle v = t;
		out << v << endl << "passload " << t.passload << " payload " << t.payload;
		return out;
	}
};

class car :protected vehicle {
private:
	int paload;
public:
	car(int p, string s, double a, double b, double c, double d)
		:paload{ p }, vehicle{ s,a,b,c,d }
	{}

	friend ostream& operator<<(ostream& out, car& c) {
		vehicle v = c;
		out << v << endl << "passload " << c.paload;
		return out;
	}
};

int main() {
	/*
	Vector v, v2(1, 2, 3), v3(1, 2, 4);
	cin >> v;
	bool a = (v == v2), b = (v == v3);
	cout << v << endl << a << b;
	*/
	car c(5, "xiaomi", 12, 15, 46, 48);
	truck t(2, 200, "bba", 15, 16, 18, 33);

	cout << c << endl << t;
}