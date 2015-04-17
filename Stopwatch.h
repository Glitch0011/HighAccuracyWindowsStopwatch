#pragma once

#include <Windows.h>
#include <iostream>

//http://stackoverflow.com/questions/1739259/how-to-use-queryperformancecounter

//Upon death, callback contains double of seconds passed
class Stopwatch
{
	typedef std::function<void(double)> StopwatchEndFunction;

	double PCFreq = 0.0;
	__int64 CounterStart = 0;

	StopwatchEndFunction onEnd;

public:
	Stopwatch(StopwatchEndFunction onEnd = nullptr)
	{
		this->onEnd = onEnd;

		this->StartTime();
	}

	void StartTime()
	{
		LARGE_INTEGER li;

		if (!QueryPerformanceFrequency(&li))
			std::cout << "QueryPerformanceFrequencyFailed!\n";

		this->PCFreq = double(li.QuadPart);

		QueryPerformanceCounter(&li);
		this->CounterStart = li.QuadPart;
	}

	double GetTime()
	{
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);

		return double(li.QuadPart - CounterStart) / this->PCFreq;
	}

	~Stopwatch()
	{
		if (this->onEnd != nullptr)
			this->onEnd(this->GetTime());
	}
};