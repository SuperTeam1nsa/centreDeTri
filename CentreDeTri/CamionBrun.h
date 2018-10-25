#pragma once
#include "Camion.h"
#include "DechetTraiteCompostable.h"
class CamionBrun :
	public Camion
{
public:
	CamionBrun() :Camion(10) { Compteur::ajouterConstructeur(); }
	~CamionBrun() { Compteur::ajouterDestructeur(); }
	bool ajouterDechet(DechetTraiteCompostable *d) { return Camion::ajouterDechet(d); }
};
