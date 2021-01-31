#include <iostream>

//Your task is to construct a building which will be a pile of n cubes. The cube at the bottom will have a volume of n^3, the cube above will have volume of (n-1)^3 and so on until the top which will have a volume of 1^3.
//You are given the total volume m of the building. Being given m can you find the number n of cubes you will have to build?
//The parameter of the function findNb (find_nb, find-nb, findNb) will be an integer m and you have to return the integer n such as n^3 + (n-1)^3 + ... + 1^3 = m if such a n exists or -1 if there is no such n.

class ASum
{
  public:
  static long long findNb(long long m);
};


long long ASum::findNb(long long m) {
	long n = 0;
	do {
		//one possible option would be to start at 0 and calculate up however an easier solution is to just decrement the starting number down to 0
		m -= (n * n * n); //an option would be to use pow however there are issues when dealing with very large numbers; however this would also require an additional header cmath.h
		if(m == 0) { return n; } //breaking condition
		n++; //update number after possible return to avoid return erro
	} while( m > 0 ); //breaking condition; no further computing required
	return -1; //default return condition if not foind
}

int main() {
	std::cout << "\nCount A: " << ASum::findNb(1025292944081385001); // --> 45001
	std::cout << "\nCount B: " << ASum::findNb(4183059834009);// 2022
	std::cout << "\nCount C: " << ASum::findNb(1071225);// 45
	std::cout << "\nCount D: " << ASum::findNb(91716553919377);// -1
	std::cout << "\nCount E: " << ASum::findNb(2304422822859502500);// 55100
	std::cout << "\nCount F: " << ASum::findNb(45001);// -1
	std::cout << "\n";
}
