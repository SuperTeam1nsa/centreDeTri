#pragma once
#include <stack>
class Camion
{
public:
	Camion(int capacite);
	~Camion();
	void ajouterDechet(DechetTraite d);

private:
	int maxCapacite;
	int capacite;
	std::stack<DechetTraite> pile_dechets;


};