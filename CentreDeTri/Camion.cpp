#include "Camion.h"
#include <stdexcept>

Camion::Camion(int capacite) :maxCapacite(capacite), capacite(0)
{
}

Camion::~Camion()
{
}

void Camion::ajouterDechet(DechetTraite d)
{
	capacite++;
	if (capacite < maxCapacite)
	{
		pile_dechets.push(d);
	}
	throw "CAMION_PLEIN";
}
