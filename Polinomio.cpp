#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <strstream>
using namespace std;
string numComoStr (double x) {
	strstream f;
	string res;
	f << x;
	f >> res;
	return res;
}
template <class T> T max (T x, T y) {
	if (x>y)
		return x;
	else 
		return y;
}
template <class T> T min (T x, T y) {
	if (x<y)
		return x;
	else 
		return y;
}
class Polinomio {
private:
	vector<double> coefs;
public:
	Polinomio () {
	}
	Polinomio (int n) {
		for (int i=0; i<n; i++) {
			coefs.push_back(0);
		}
	}
	int grado () {
		return coefs.size()-1;
	}
	double & operator [] (int i) {
		return coefs[i];
	}
	string comoCadena() {
		string s, t;
		s="Polinomio(";
		for (int i=0; i<coefs.size(); i++) {
			s+=numComoStr(coefs[i]);
			if (i!=coefs.size()-1)
				s+=",";
		}
		s+=")";
		return s;
	}
};
Polinomio operator+ (Polinomio & p1, Polinomio & p2) {
	Polinomio pmax, pmin;
	if (max(p1.grado(), p2.grado())==p1.grado()) {
		pmax=p1;
		pmin=p2;
	} else {
		pmax=p2;
		pmin=p1;
	}
	for (int i=0; i<=pmin.grado(); i++) {
		pmax[i]+=pmin[i];
	}
	return pmax;
}
ostream& operator<< (ostream& co, Polinomio & p) {
	co << p.comoCadena();
	return co;
}
void main() {
	Polinomio p1(2), p2(3);
	p1[0]=3; p1[1]=4; 
	p2[0]=1; p2[1]=2; p2[2]=3;
	cout << "El polinomio p1 es: " << p1 << endl;
	cout << "El polinomio p2 es: " << p2 << endl;
	cout << "La suma es: " << (p1 + p2) << endl; 
}
