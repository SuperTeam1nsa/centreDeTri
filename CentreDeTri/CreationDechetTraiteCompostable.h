#pragma once
#include "OperationTraitement.h"
#include "Compteur.h"

class CreationDechetTraiteCompostable :
	public OperationTraitement
{
public:
	CreationDechetTraiteCompostable(UsineTraitement* usineTraitement) :OperationTraitement(usineTraitement) { Compteur::ajouterConstructeur(); };
	bool effectuerOperation(Dechet* dechet) override { creerDechetTraiteCompostable(dechet); return true; }
	virtual ~CreationDechetTraiteCompostable() { Compteur::ajouterDestructeur(); };

};
