#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation5 :
	public Operation
{
public:
	Operation5(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	~Operation5() { Compteur::ajouterDestructeur(); }
	Operation5(Operation5 const& autre) :Operation(autre) { Compteur::ajouterConstructeurCopie(); }
	Operation5* makeObject(Operation5 const& autre) { return new Operation5(autre); }
	bool effectuerOperation(Dechet* dechet)  override { return (dechet->getCouleur() == "vert") && (dechet->getMateriel() == Dechet::VEGETAL); }

};
