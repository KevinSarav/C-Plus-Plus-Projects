#include <iostream>
using namespace std;

class Figure {
public:
	virtual void erase()=0;
	virtual void draw()=0;
	virtual void center()=0;
};

class Rectangle : public Figure {
public:
	void erase() {
		cout << "Rectangle object called erase function \n";=
	}
	void draw() {
		cout << "Rectangle object called draw function \n";
	}
	void center() {
		cout << "Derived Rectangle object calling center() \n" <<
			"Rectangle object called center function \n";
		erase();
		draw();
	}
};

class Triangle : public Figure {
public:
	void erase() {
		cout << "Triangle object called erase function \n";
	}
	void draw() {
		cout << "Triangle object called draw function \n";
	}
	void center() {
		cout << "Derived Triangle object calling center() \n" <<
			"Triangle object called center function \n";
		erase();
		draw();
	}
};

int main() {
	Triangle Tri;
	Rectangle Rect;

	Tri.draw();
	Tri.erase();
	Tri.center();

	Rect.draw();
	Rect.erase();
	Rect.center();
}