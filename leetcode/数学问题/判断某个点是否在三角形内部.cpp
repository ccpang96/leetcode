#include<iostream>
using std::cout;
using std::endl;
struct Point {
	float x;
	float y;
};

float absValue = 0.0001;

float getSquar(const Point &p1, const Point &p2, const Point &p3) {
	//Ð¬´ø¹«Ê½
	float squar;
	squar = abs(p1.x*p2.y + p2.x*p3.y+p3.x*p1.y - p1.y*p2.x-p2.y*p3.x-p3.y*p1.x) *0.5;
	return squar;
}

bool isInTriangle(const Point &A, const Point &B, const Point &C, const Point &P) {
	float SABC, SABP, SAPC, SPBC;
	SABC = getSquar(A, B, C);
	SABP = getSquar(A, B, P);
	SAPC = getSquar(A, P, C);
	SPBC = getSquar(P, B, C);
	cout << SABC << "   " << SABP << "   " << SAPC << "   " << SPBC << endl;
	float sumSquar = SABP + SAPC + SPBC;
	if (abs(SABC - sumSquar) < absValue)
		return true;
	else
		return false;
}

//int main() {
//	Point A{ 0,0 };
//	Point B{ 2,0 };
//	Point C{ 1,1 };
//	Point P1{ 0.5,0.5 };
//	Point P2{ 3 ,3 };
//
//	bool result1 = isInTriangle(A, B, C, P1);
//	bool result2 = isInTriangle(A, B, C, P2);
//	cout << result1 << "   " << result2 << endl;
//	system("pause");
//	return 0;
//}