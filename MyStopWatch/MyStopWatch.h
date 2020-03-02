#pragma once
#include <ostream>
#include <chrono>

class MyStopWatch
{
public:
	MyStopWatch(std::ostream& log, const char* name =  "stopwatch");
	~MyStopWatch();

	void Show(const char* event = "show");

private:
	unsigned long long GetMs();

	const char* m_name;
	std::ostream& m_log;
	std::chrono::system_clock::time_point m_start;
};