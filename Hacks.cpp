#include "Hacks.hpp"

namespace hacks {

	void triggerbot()
	{
		//If you don't hold trigger key, ignore rest of function
		static bool is_holding = false;
		static bool set_delay = false;

		if (!(GetAsyncKeyState(VK_XBUTTON2) & 0x8000))
		{
			is_holding = false;
			set_delay = false;
		}
		else
			is_holding = true;

		//Get local player
		auto local_player = Player::get_local_player();

		//Check if your player is valid
		if (!local_player.is_valid())
			return;

		//Get player ID of the person in your crosshair
		const auto cross_id = local_player.get_crosshair_id();
		//Check if there even is a player in your crosshair
		if (cross_id > 0 && cross_id < 65)
		{
			//Get the player entity that you are aiming at
			auto aiming_at = Player::get_player_from_id(cross_id - 1);

			//Check if that player is valid
			if (!aiming_at.is_valid_player())
				return;

			//Check it's not a teammate
			if (aiming_at.get_team_num() == local_player.get_team_num())
				return;

			//Shoot
			if (is_holding)
			{
				if (is_holding && !set_delay)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(rand() % (150 - 100 + 1) + 100)); // max - min + min
					set_delay = true;
				}
				engine::force_attack();
			}
		}
	}


	void main_thread()
	{
		//Loop to run all the cheats
		while (true)
		{
				triggerbot();
			
				std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
	}

}