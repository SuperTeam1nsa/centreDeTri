#pragma once
#include "OperationTraitement.h"
#include "Compteur.h"

class CreationDechetTraiteRecyclable :
	public OperationTraitement
{
public:
	CreationDechetTraiteRecyclable(UsineTraitement* usineTraitement) : OperationTraitement(usineTraitement) { Compteur::ajouterConstructeur(); };
	bool effectuerOperation(Dechet* dechet) override { creerDechetTraiteRecyclable(dechet); return true; }
	~CreationDechetTraiteRecyclable() { Compteur::ajouterDestructeur(); };
	CreationDechetTraiteRecyclable(CreationDechetTraiteRecyclable const& autre) :OperationTraitement(autre) { Compteur::ajouterConstructeurCopie(); }
	CreationDechetTraiteRecyclable* makeObject(CreationDechetTraiteRecyclable const& autre) { return new CreationDechetTraiteRecyclable(autre); }
};
