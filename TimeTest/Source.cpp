#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	clock_t start, end, ReResult, PyResult, JavaResult;

	start = clock();
	system("RelaxVM test.ree");
	end = clock();
	ReResult = end - start;

	start = clock();
	system("python piton.py");
	end = clock();
	PyResult = end - start;

	start = clock();
	system("java -jar main.jar");
	end = clock();
	JavaResult = end - start;

	cout << "\n\n\nRelax: " << ReResult << "ms\n";
	cout << "Python: " << PyResult << "ms\n";
	cout << "Java: " << JavaResult << "ms\n";
}