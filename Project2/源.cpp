#include<iostream>
#include<cmath>
#define int double
#define PI 3.14
using namespace std;
class figure {
public:
	int radius;
	virtual int area() = 0;
	virtual int volume() = 0;
	virtual ~figure() = default;
};

class sphere :public figure {
public:
	sphere(int x = 0) {
		radius = x;
	}

	int area() override {
		return 4 * PI * pow(radius, 2);
	}

	int volume() override {
		return (4 / 3) * PI * pow(radius,3);
	}

	virtual ~sphere() = default;
};

class column :public figure {
private:
	int high;
public:
	column(int x = 0, int y = 0) {
		radius = x;
		high = y;
	}

	int area() override {
		return 4 * PI * pow(radius, 2) * 2 + 2 * PI * radius * high;
	}

	int volume() override {
		return (4 / 3) * PI * pow(radius, 3) * high;
	}

	virtual ~column() = default;
};


signed main() {
	sphere s{ 1 };
	column c{ 1,1 };
	cout << s.area() << ' ' << s.volume() << '\n';
	cout << c.area() << ' ' << c.volume() << '\n';
}