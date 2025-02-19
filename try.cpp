#include<bits/stdc++.h>
using namespace std;

class Complex {
public:
	int a, b; // a + i * b
	Complex() {
		a = b = 0;
	}
	Complex(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void print() {
		cout << this->a << " " << this->b << '\n';
	}
	Complex add(Complex c1, Complex c2) {
		Complex res;
		res.a = c1.a + c2.a;
		res.b = c1.b + c2.b;
		return res;
	}
	Complex add(Complex other) {
		Complex res;
		res.a = this->a + other.a;
		res.b = this->b + other.b;
		return res;
	}
	Complex sub(Complex other) {
		Complex res;
		res.a = this->a - other.a;
		res.b = this->b - other.b;
		return res;
	}

	Complex operator+(Complex&other) {
		return add(other);
	}
	Complex operator-(Complex&other) {
		return sub(other);
	}
};

class Parent {
public:
	void print() {
		cout<<"parent\n";
	}
};
class Child : public Parent {
public:
	void print() {
		cout<<"child\n";
	}
};

class D {
public:
	int* ptr;
	D () {
	}
	D(int a) {
		this->ptr = new int(a);
	}
	D (const D& other) {
		cout<<"Hello\n";
		ptr = new int(*other.ptr);
	}
	~ D() {
		delete ptr;
	}
	void print() {
		cout << (*ptr) << '\n';
	}
};
class Base {
public:
    virtual ~Base() {} // Virtual destructor
};

class Derived : public Base {
public:
    virtual ~Derived() {
        std::cout << "Derived destructor called.\n";
    }
};

class Singleton {
private:
	static Singleton* ptr;
	static mutex mtx;
	string name;
	Singleton () {}

public:
	Singleton(Singleton &obj) = delete;
	static Singleton* getInstance() {
		if (ptr == nullptr) {
			lock_guard<mutex> lock(mtx);//this will make it thread safe.
			if (ptr == nullptr) {
				ptr = new Singleton();
			}
		}
		return ptr;
	}
	void setName(string name) {
		this->name = name;
	}
	void print() {
		cout<<this->name<<'\n';
	}
};

Singleton* Singleton::ptr = NULL;
mutex Singleton::mtx;

int main() {
	Singleton* ptr = Singleton::getInstance();
	ptr->setName("shivom");
	ptr->print();
	Singleton* ptr2 = Singleton::getInstance();
	ptr2->print();
}
