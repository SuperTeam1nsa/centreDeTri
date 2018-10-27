#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation2 :
	public Operation
{
public:
	Operation2(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	~Operation2() { Compteur::ajouterDestructeur(); }
	Operation2(Operation2 const& autre) :Operation(autre) { Compteur::ajouterConstructeurCopie(); }
	Operation2* makeObject(Operation2 const& autre) { return new Operation2(autre); }
	bool effectuerOperation(Dechet* dechet)  override { return dechet->getMateriel() == Dechet::PLASTIQUE; }

};
