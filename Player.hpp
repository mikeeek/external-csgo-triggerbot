#pragma once
#include <cstdint>

#define FL_ONGROUND                     (1 << 0)
#define FL_DUCKING                      (1 << 1)
#define FL_WATER						(1 << 9)
#define LIFE_ALIVE						0


class Player
{
private:
	uintptr_t base_player;

public:
	static Player get_local_player();
	static Player get_player_from_id(int id);

	Player(uintptr_t address);

	uintptr_t get_address() const;
	bool is_valid() const;
	bool is_valid_player() const;

	int get_flags() const;
	int get_crosshair_id() const;
	int get_team_num() const;
	bool is_dormant() const;
	char get_life_state() const;
	int get_health() const;
	int get_class_id() const;
	uintptr_t get_weapon() const;
	int get_shotsfired() const;
};

