#pragma once
#include "DechetTraite.h"
#include "Compteur.h"

class DechetTraiteCompostable :
	public DechetTraite
{
public:
	DechetTraiteCompostable(Dechet* dechet) : DechetTraite(dechet) { Compteur::ajouterConstructeur(); }
	~DechetTraiteCompostable() { Compteur::ajouterDestructeur(); }
};
