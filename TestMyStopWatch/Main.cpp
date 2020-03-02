#include <MyStopWatch.h>
#include <fstream>

void DoSome()
{
	int a = 1;
	int b = 1;
	int tmp;

	for( int i = 0; i < 50000; i++ )
	{
		tmp = a + b;
		b = a;
		a = tmp;
	}
}

int main()
{
	auto fout = std::ofstream("log.txt");

	{
		auto sw = MyStopWatch(fout, "do some");

		for( int i = 0; i < 2000; i++ )
		{
			DoSome();
		}
	}
}