#pragma once
#include <stack>
class Camion
{
public:
	Camion(int maxCapacite);
	~Camion();
	bool ajouterDechet(DechetTraite *d);
	int viderCamion();
	//Rq: on aurait pu s'éviter les camions bleus verts etc via le polymorphisme des déchets 
	//=> ou bien en virtual et redéfinir les fonctions ajouterDechet avec les sous types de DechetTraite

protected:
	int maxCapacite;
	int capacite;
	std::stack<DechetTraite*> pile_dechets;

};
