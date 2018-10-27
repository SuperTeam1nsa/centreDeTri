#pragma once
#include "CamionBleu.h"
#include"CamionBrun.h"
#include "CamionVert.h"
#include "Compteur.h"
#include <iostream>

class Depot
{
public:
	Depot() :totalIDTCompostable(0), totalIDTNonRecyclable(0), totalIDTRecyclable(0) { Compteur::ajouterConstructeur(); }
	Depot(Depot const& c) :totalIDTCompostable(c.totalIDTCompostable), totalIDTNonRecyclable(c.totalIDTNonRecyclable), totalIDTRecyclable(c.totalIDTRecyclable)
	{
		Compteur::ajouterConstructeurCopie();
	}
	~Depot() { Compteur::ajouterDestructeur(); }
	CamionBleu* getCamionBleu() const { return new CamionBleu(); }
	CamionBrun* getCamionBrun() const { return new CamionBrun(); }
	CamionVert* getCamionVert() const { return new CamionVert(); }
	void depotDechetsTraites(CamionVert* camion) { totalIDTNonRecyclable += camion->viderCamion(); delete camion; }
	void depotDechetsTraites(CamionBleu* camion) { totalIDTRecyclable += camion->viderCamion(); delete camion; }
	void depotDechetsTraites(CamionBrun* camion) { totalIDTCompostable += camion->viderCamion(); delete camion; }
	std::ostream& operator <<(std::ostream& out) const {
		return out << std::endl << "--DEPOT--" << std::endl << "totalIDTRecyclable	:" << totalIDTRecyclable
			<< std::endl << "totalIDTNonRecyclable	:" << totalIDTNonRecyclable
			<< std::endl << "totalIDTCompostable	:" << totalIDTCompostable;
		//rq: le poids total est différent du poids total des déchets créés car tous ne sont pas encore
			//arrivés au dépôt (on envoie le camion au dépôt seulement quand il est plein, d'où une différence
			//possible de 3* capacité camion (si identique pour les 3 camions), ici 3*10=30 (check avec les dechets 
			//restants dans les camions =OK)
	}

private:
	int totalIDTRecyclable;
	int totalIDTNonRecyclable;
	int totalIDTCompostable;

};
