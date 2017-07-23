#include "shade.h"
#include "tgmath.h"

Shade::Shade() {
	gold = 0;
	health = 125;
    attack = 25;
    defence = 25;
    sign = 's';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Shade::attack(Enemy *enemy) {
	enemy->beAttack(this);
}

void Shade::beAttack(Human *h) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Shade::beAttack(Dwarf *d) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Shade::beAttack(Elf *e) {
	int hit1 = rand() % 2 + 0;
	int hit2= rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	if (hit1) health -= damage;
	if (hit2) health -= damage;
}

void Shade::beAttack(Orcs *o) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	if (hit) health -= damage;
}

void Shade::beAttack(Merchant *m) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 70);
	if (hit) health -= damage;
}

void Shade::beAttack(Dragon *d) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Shade::beAttack(Halfling *h) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 15);
	if (hit) health -= damage;
}
