#include "Include.hpp"

int main(int argc, char** argv)
{
	
	

	//Initialize the memory class, which gets the base address of the client and engine.dll in csgo to read form
	//so you can get information like enemy position, etc.
	if (!memory.initialize("csgo"))
		return 0;

	//Start the main thread that does all the hacks
	std::thread main_thread(hacks::main_thread);
	main_thread.detach();

	//If you press delete, close program
	while (!GetAsyncKeyState(VK_DELETE) & 1)
	{
		

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	return 1;
}