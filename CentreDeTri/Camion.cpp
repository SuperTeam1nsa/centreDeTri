#include "Camion.h"
//#include <stdexcept>

Camion::Camion(int capacite) :maxCapacite(capacite), capacite(0)
{
	Compteur::ajouterConstructeur();
}

Camion::Camion(Camion& c) : maxCapacite(c.maxCapacite), capacite(c.capacite)
{
	std::stack<DechetTraite*> aux;
	while (!c.pile_dechets.empty())
	{
		aux.push(c.pile_dechets.top());
		c.pile_dechets.pop();
	}
	while (!aux.empty())
	{
		c.pile_dechets.push(aux.top());
		pile_dechets.push(new DechetTraite(*aux.top()));
		aux.pop();
	}
	Compteur::ajouterConstructeurCopie();
}

Camion::~Camion()
{
	Compteur::ajouterDestructeur();
	while (!pile_dechets.empty())
	{
		delete pile_dechets.top();
		pile_dechets.pop();
	}
}


bool Camion::ajouterDechet(DechetTraite* d)
{

	if ((capacite + (d->getDechet())->getPoids()) <= maxCapacite)
	{
		pile_dechets.push(d);
		capacite += (d->getDechet())->getPoids();
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
		poidsTot += pile_dechets.top()->getDechet()->getPoids();
		pile_dechets.pop();
	}
	capacite = 0;
	return poidsTot;
}
