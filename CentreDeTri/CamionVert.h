#pragma once
#include "Camion.h"
#include "Compteur.h"
#include "DechetTraiteNonRecyclable.h"

class CamionVert :
	public Camion
{
public:
	CamionVert() :Camion(10) { Compteur::ajouterConstructeur(); }
	~CamionVert() { Compteur::ajouterDestructeur(); }
	bool ajouterDechet(DechetTraiteNonRecyclable *d) { return Camion::ajouterDechet(d); }

};
