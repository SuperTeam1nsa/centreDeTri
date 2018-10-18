#pragma once
#include <stack>
#include "DechetTraite.h"

class Camion
{
public:
	Camion(int maxCapacite);
	Camion(Camion& c); //pas de const à cause de la pile qui doit être dépilée pour être copiée
	virtual ~Camion();
	bool ajouterDechet(DechetTraite *d);
	int viderCamion();
	//Rq: on aurait pu s'éviter les camions bleus verts etc via le polymorphisme des déchets 
	//=> ou bien en virtual et redéfinir les fonctions ajouterDechet avec les sous types de DechetTraite

protected:
	int maxCapacite;
	int capacite;
	std::stack<DechetTraite*> pile_dechets;

};
