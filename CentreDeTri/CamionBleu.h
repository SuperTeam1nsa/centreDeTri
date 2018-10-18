#pragma once
#include "Camion.h"
#include "Compteur.h"
#include "DechetTraiteRecyclable.h"

class CamionBleu :public Camion
{
public:
	CamionBleu() :Camion(30) { Compteur::ajouterConstructeur(); };
	~CamionBleu() { Compteur::ajouterDestructeur(); };
	bool ajouterDechet(DechetTraiteRecyclable *d) { ajouterDechet(d) };


};
