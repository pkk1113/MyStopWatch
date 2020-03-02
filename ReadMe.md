MyStopWatch
--

Optimized C++ 3장의 StopWatch 라이브러리입니다.
C++11의 chrono를 사용하여 구현되었습니다.
RAII를 사용하며 생성과 동시에 타이머를 시작하고 소멸과 동시에 결과를 출력합니다.
출력은 생성자의 매개변수로 받은 ostream 파생 객체를 사용합니다.

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
