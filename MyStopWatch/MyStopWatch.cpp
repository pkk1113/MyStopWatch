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

unsigned long long  MyStopWatch::Show(const char* event)
{
	auto ms = GetMs();
	m_log << m_name << ": " << event << " " << ms << "ms\n";
	return ms;
}

unsigned long long MyStopWatch::GetMs()
{
	auto diff = system_clock::now() - m_start;
	return (unsigned long long)duration_cast<milliseconds>(diff).count();
}
