#include <Stopwatch.h>

#include <chrono>
#include <thread>
#include <string>

int main()
{
	while (true)
	{
		Stopwatch stopwatch([=](double timePassed)
		{
			std::cout << "Time taken: " << std::to_string(timePassed) << std::endl;
		});

		//Perform function
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}
}