#include "goblin.h"
#include "tgmath.h"

Goblin::Goblin() {
	gold = 0;
	health = 110;
    attack = 15;
    defence = 20;
    sign = 'g';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Goblin::attack(Enemy *enemy) {
	enemy->beAttack(this);
	if (enemy->getHealth() <= 0) gold += 5;
}

void Goblin::beAttack(Human *h) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Goblin::beAttack(Dwarf *d) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Goblin::beAttack(Elf *e) {
	int hit1 = rand() % 2 + 0;
	int hit2= rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30);
	if (hit1) health -= damage;
	if (hit2) health -= damage;
}

void Goblin::beAttack(Orcs *o) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 30) * 2 / 3;
	if (hit) health -= damage;
}

void Goblin::beAttack(Merchant *m) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 70);
	if (hit) health -= damage;
}

void Goblin::beAttack(Dragon *d) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 20);
	if (hit) health -= damage;
}

void Goblin::beAttack(Halfling *h) {
	int hit = rand() % 2 + 0;
	int damage = ceil((100 / (100 + defence)) * 15);
	if (hit) health -= damage;
}
