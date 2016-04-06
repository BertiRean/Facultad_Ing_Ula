#include <tpl_sort_utils.H>
#include <gsl/gsl_rng.h>
#include <fstream>
#include <tpl_dynArray.H>
#include <ahNow.H>

using namespace std;
using namespace Aleph;

template<typename T>
double take_time(DynArray<T> & a, Now & timer)
{
	timer.start();
	insertion_sort(a,0,a.size());
	return timer.elapsed();
}

int main()
{
	const int N = 1000000;
	const int n = 10000;

	double tim;
	Now timer;

	DynArray<int> a1,a2,a3;

	gsl_rng * g = gsl_rng_alloc(gsl_rng_mt19937);

	ofstream file1("timer_sort.txt"); 
	ofstream file2("timer_random.txt");
	ofstream file3("timer_inverse_sort.txt");

	for (int i = 0; i < N; i+=2)
	{
		for (int j = 0; j < n; ++j)
		{
			a1.append(j);
			a2.append(gsl_rng_uniform_int(g, n));
			a3.append(n -j);
		}
		
		tim = take_time(a1, timer);

		file1 << n << " " << tim << '\n';

		tim = take_time(a2, timer);

		file2 << n << " " << tim << '\n';

		tim = take_time(a3, timer);
		file3 << n << " " << tim << '\n';
	}

	file1.close();
	file2.close();
	file3.close();
	return 0;
}