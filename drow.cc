#include "drow.h"
#include "tgmath.h"

Drow::Drow() {
	gold = 0;
	health = 150;
    attack = 25;
    defence = 15;
    sign = 'd';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Drow::attack(Enemy *enemy) {
	enemy->beAttack(this);
}

void Drow::beAttack(Human *h) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Drow::beAttack(Dwarf *d) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Drow::beAttack(Elf *e) {
	int hit1 = rand() % 2 + 0;
	int hit2= rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	if (hit1) health -= damage;
	if (hit2) health -= damage;
}

void Drow::beAttack(Orcs *o) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	if (hit) health -= damage;
}

void Drow::beAttack(Merchant *m) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 70);
	if (hit) health -= damage;
}

void Drow::beAttack(Dragon *d) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Drow::beAttack(Halfling *h) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 15);
	if (hit) health -= damage;
}
