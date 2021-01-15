#include <iostream>
#include <chrono>
#include <thread>

// An auto-object Timer for simple timing

struct Timer
{
	// ctor to start the timer
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		// Convert duration to ms
		float ms = duration.count() * 1000.0f;
		std::cout << "Duration is: " << ms << " ms" << std::endl;
	}

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
};


int main()
{
	using namespace std::literals::chrono_literals;

	{
		Timer timer;
		std::this_thread::sleep_for(5s);
	}
	

	std::cin.get();
}