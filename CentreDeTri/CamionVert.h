#pragma once
#include "Camion.h"
#include "Compteur.h"
#include "DechetTraiteNonRecyclable.h"

class CamionVert :
	public Camion
{
public:
	CamionVert() :Camion(40) { Compteur::ajouterConstructeur(); };
	~CamionVert() { Compteur::ajouterDestructeur(); };
	bool ajouterDechet(DechetTraiteNonRecyclable *d) { ajouterDechet(d); };

};
