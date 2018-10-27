#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation3 :
	public Operation
{
public:
	Operation3(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	~Operation3() { Compteur::ajouterDestructeur(); }
	Operation3(Operation3 const& autre) :Operation(autre) { Compteur::ajouterConstructeurCopie(); }
	Operation3* makeObject(Operation3 const& autre) { return new Operation3(autre); }
	bool effectuerOperation(Dechet* dechet) override { return (dechet->getMateriel() == Dechet::PAPIER) || (dechet->getMateriel() == Dechet::CARTON); }
};
