// MyStopWatch.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "MyStopWatch.h"

using namespace std::chrono;

MyStopWatch::MyStopWatch(std::ostream& log, const char* name) :
	m_log(log),
	m_name(name),
	m_start(system_clock::now())
{
	Show("start");
}

MyStopWatch::~MyStopWatch()
{
	Show("stop");
}

void MyStopWatch::Show(const char* event)
{
	m_log << m_name << ": " << event << " " << GetMs() << "ms\n";
}

unsigned long long MyStopWatch::GetMs()
{
	auto diff = system_clock::now() - m_start;
	return (unsigned long long)duration_cast<milliseconds>(diff).count();
}
