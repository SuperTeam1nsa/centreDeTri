#pragma once
#include <stack>
class Camion
{
public:
	Camion(int capacite);
	~Camion();
	void ajouterDechet(const DechetTraite &d);//sert pour les sous camions à get D.T_recyclable etc sans redéfinition via polymorphisme
	//=> ou bien en virtual et redéfinir les fonctions ajouterDechet avec les sous types de DechetTraite

protected:
	int maxCapacite;
	int capacite;
	std::stack<DechetTraite> pile_dechets;

};
