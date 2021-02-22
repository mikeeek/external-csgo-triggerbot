#include "Engine.hpp"

#include "Include.hpp"

namespace engine {

	void force_attack()
	{
		memory.write_memory<bool>(memory.get_client().module_base + addresses::force_attack, true);
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		memory.write_memory<bool>(memory.get_client().module_base + addresses::force_attack, false);
	}
}