# HighAccuracyWindowsStopwatch

Provies an easy way to time a function.

# Usage

```

function WairForTwoMilliSeconds()
{
	//Creates a stopwatch with a lambda called upon the destruction of the timer.
	Stopwatch stopwatch([=](double timePassed)
	{
		//When the while statement closes, output the time passed
		std::cout << "Time taken: " << std::to_string(timePassed) << std::endl;
	});
	
	//Perform function
	std::this_thread::sleep_for(std::chrono::milliseconds(2));
}
```
