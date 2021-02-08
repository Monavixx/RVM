#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	clock_t start, end, ReResult, PyResult;

	start = clock();
	system("..\\x64\\Release\\RelaxVM ..\\..\\Relasm\\Relasm\\test.ree");
	end = clock();
	ReResult = end - start;

	start = clock();
	system("python piton.py");
	end = clock();
	PyResult = end - start;

	cout << "\n\n\nRelax: " << ReResult << "ms\n";
	cout << "Python: " << PyResult << "ms\n";
}