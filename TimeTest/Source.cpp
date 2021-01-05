#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	clock_t start, end, result;

	start = clock();
	system("RelaxVM test.ree");
	end = clock();
	result = end - start;
	cout << "\nRelax: " << result << "ms\n\n\n";

	start = clock();
	system("python piton.py");
	end = clock();
	result = end - start;
	cout << "\nPython: " << result << "ms\n\n\n";
}