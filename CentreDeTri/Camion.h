#pragma once
#include <stack>
#include "DechetTraite.h"
#include "Compteur.h"

class Camion
{
public:
	Camion(int maxCapacite);
	Camion(Camion& c); //pas de const à cause de la pile qui doit être dépilée pour être copiée
	virtual ~Camion();
	bool ajouterDechet(DechetTraite *d);
	int viderCamion();

protected:
	int maxCapacite;
	int capacite;
	std::stack<DechetTraite*> pile_dechets;

};
