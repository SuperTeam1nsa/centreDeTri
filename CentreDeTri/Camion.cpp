#include "Camion.h"
//#include <stdexcept>

Camion::Camion(int capacite) :maxCapacite(capacite), capacite(0)
{
	Compteur::ajouterConstructeur();
}

Camion::~Camion()
{
	Compteur::ajouterDestructeur();
}


bool Camion::ajouterDechet(DechetTraite* d)
{
	capacite++;
	if (capacite < maxCapacite)
	{
		pile_dechets.push(d);
		return true;
	}
	/*else
		throw "CAMION_PLEIN";*/
	return false;
}

int Camion::viderCamion()
{
	int poidsTot = 0;
	while (!pile_dechets.empty())
	{
		poidsTot += pile_dechets.top()->getPoids();
		pile_dechets.pop();
	}
	return poidsTot;
}
