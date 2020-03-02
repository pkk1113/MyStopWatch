MyStopWatch
--

Optimized C++ 3���� StopWatch ���̺귯���Դϴ�.
C++11�� chrono�� ����Ͽ� �����Ǿ����ϴ�.
RAII�� ����ϸ� ������ ���ÿ� Ÿ�̸Ӹ� �����ϰ� �Ҹ�� ���ÿ� ����� ����մϴ�.
����� �������� �Ű������� ���� ostream �Ļ� ��ü�� ����մϴ�.

How to use
--

```C++
// Main.cpp
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
		DoSome();
	}
}
```

```
// log.txt
do some: start 0ms
do some: stop 1ms
```
