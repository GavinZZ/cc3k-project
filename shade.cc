#include "shade.h"
#include "tgmath.h"
#include <sstream>

Shade::Shade() {
	gold = 0;
	health = 125;
    attack = 25;
    defence = 25;
    sign = 'S';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Shade::attack(Enemy *enemy, std::string &action) {
	enemy->beAttack(this, action);
}

void Shade::beAttack(Human *h, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " H deals " << total_damage << " to PC.";
	action = oss.str();
}

void Shade::beAttack(Dwarf *d, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " W deals " << total_damage << " to PC.";
	action = oss.str();
}

void Shade::beAttack(Elf *e, std::string &action) {
	std::ostring stream oss{action};
	int hit1 = rand() % 2 + 0;
	int hit2= rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	int total_damage = (hit1 + hit2) * damage;
	health -= total_damage;
	oss << " E deals " << total_damage << " to PC.";
	action = oss.str();
}

void Shade::beAttack(Orcs *o, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " O deals " << total_damage << " to PC.";
	action = oss.str();
}

void Shade::beAttack(Merchant *m, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 70);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " M deals " << total_damage << " to PC.";
	action = oss.str();
}

void Shade::beAttack(Dragon *d, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " D deals " << total_damage << " to PC.";
	action = oss.str();
}

void Shade::beAttack(Halfling *h, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 15);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " L deals " << total_damage << " to PC.";
	action = oss.str();
}
