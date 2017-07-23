#include "vampire.h"
#include "tgmath.h"

Vampire::Vampire() {
	gold = 0;
	health = 50;
    attack = 25;
    defence = 25;
    sign = 'v';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Vampire::attack(Enemy *enemy) {
	enemy->beAttack(this);
	if (!enemy->getSign() == 'W') health += 5;
}

void Vampire::beAttack(Human *h) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Vampire::beAttack(Dwarf *d) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Vampire::beAttack(Elf *e) {
	int hit1 = rand() % 2 + 0;
	int hit2= rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	if (hit1) health -= damage;
	if (hit2) health -= damage;
}

void Vampire::beAttack(Orcs *o) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	if (hit) health -= damage;
}

void Vampire::beAttack(Merchant *m) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 70);
	if (hit) health -= damage;
}

void Vampire::beAttack(Dragon *d) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Vampire::beAttack(Halfling *h) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 15);
	if (hit) health -= damage;
}
