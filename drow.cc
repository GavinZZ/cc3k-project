#include "drow.h"
#include "tgmath.h"
#include <sstream>

Drow::Drow() {
	gold = 0;
	health = 150;
    attack = 25;
    defence = 15;
    sign = 'D';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Drow::attack(Enemy *enemy, std::string &action) {
	enemy->beAttack(this, action);
}

void Drow::beAttack(Human *h, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " H deals " << total_damage << " to PC.";
	action = oss.str();
}

void Drow::beAttack(Dwarf *d, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " W deals " << total_damage << " to PC.";
	action = oss.str();
}

void Drow::beAttack(Elf *e, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " E deals " << total_damage << " to PC.";
	action = oss.str();
}

void Drow::beAttack(Orcs *o, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " O deals " << total_damage << " to PC.";
	action = oss.str();
}

void Drow::beAttack(Merchant *m, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 70);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " M deals " << total_damage << " to PC.";
	action = oss.str();
}

void Drow::beAttack(Dragon *d, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " D deals " << total_damage << " to PC.";
	action = oss.str();
}

void Drow::beAttack(Halfling *h, std::string &action) {
	std::ostringstream oss{action};
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 15);
	int total_damage = hit * damage;
	health -= total_damage;
	oss << " L deals " << total_damage << " to PC.";
	action = oss.str();
}
