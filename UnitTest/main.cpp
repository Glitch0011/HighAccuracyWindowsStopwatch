#include <Stopwatch.h>

#include <chrono>
#include <thread>
#include <string>

#include <UnitTest.h>

int main()
{
	UnitTest::TestWithin<double>([=]
	{
		Stopwatch stopwatch;

		//Perform function
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		auto time = stopwatch.GetTime();

		return time;
	}, 1.0, 0.25);

	UnitTest::TestWithin<double>([=]
	{
		Stopwatch stopwatch;

		//Perform function
		std::this_thread::sleep_for(std::chrono::seconds(3));

		auto time = stopwatch.GetTime();

		return time;
	}, 3.0, 0.25);
}