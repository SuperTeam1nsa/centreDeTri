#pragma once
#include "OperationTraitement.h"
#include "Compteur.h"

class CreationDechetTraiteRecyclable :
	public OperationTraitement
{
public:
	CreationDechetTraiteRecyclable(UsineTraitement* usineTraitement) : OperationTraitement(usineTraitement) { Compteur::ajouterConstructeur(); };
	bool effectuerOperation(Dechet* dechet) override { creerDechetTraiteRecyclable(dechet); return true; }
	virtual ~CreationDechetTraiteRecyclable() { Compteur::ajouterDestructeur(); };
};
