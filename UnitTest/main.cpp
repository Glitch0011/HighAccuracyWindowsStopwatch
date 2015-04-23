#include <Stopwatch.h>

#include <chrono>
#include <thread>
#include <string>

int main()
{
	while (true)
	{
		//Creates a stopwatch, passing a lambda that's activated upon the destruction of the timer allowing handling of the passed time.
		Stopwatch stopwatch([=](double timePassed)
		{
			//When the while statement closes, output the time passed
			std::cout << "Time taken: " << std::to_string(timePassed) << std::endl;
		});

		//Perform function
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}
}