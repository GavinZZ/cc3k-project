#include "troll.h"
#include "tgmath.h"
#include <sstream>

Troll::Troll() {
	gold = 0;
	health = 120;
    attack = 25;
    defence = 15;
    sign = 'T';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Troll::attack(Enemy *enemy, std::string &action) {
	enemy->beAttack(this, action);
}

void Troll::beAttack(Human *h, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " H deals " << total_damage << " to PC.";
	action = oss.str();
}

void Troll::beAttack(Dwarf *d, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " W deals " << total_damage << " to PC.";
	action = oss.str();
}

void Troll::beAttack(Elf *e, std::string &action) {
	std::ostringstream oss{action};
	int hit1 = rand() % 2 + 0;
	int hit2= rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	int total_damage = (hit1 + hit2) * damage;
	health -= total_damage;
	oss << " E deals " << total_damage << " to PC.";
	action = oss.str();
}

void Troll::beAttack(Orcs *o, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " O deals " << total_damage << " to PC.";
	action = oss.str();
}

void Troll::beAttack(Merchant *m, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 70);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " M deals " << total_damage << " to PC.";
	action = oss.str();
}

void Troll::beAttack(Dragon *d, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " D deals " << total_damage << " to PC.";
	action = oss.str();
}

void Troll::beAttack(Halfling *h, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 15);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " L deals " << total_damage << " to PC.";
	action = oss.str();
}
