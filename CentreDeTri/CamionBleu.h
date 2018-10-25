#pragma once
#include "Camion.h"
#include "Compteur.h"
#include "DechetTraiteRecyclable.h"

class CamionBleu :public Camion
{
public:
	CamionBleu() :Camion(10) { Compteur::ajouterConstructeur(); }
	~CamionBleu() { Compteur::ajouterDestructeur(); }
	bool ajouterDechet(DechetTraiteRecyclable *d) { return Camion::ajouterDechet(d); }


};
