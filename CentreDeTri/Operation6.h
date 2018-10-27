#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation6 :
	public Operation
{
public:
	Operation6(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	~Operation6() { Compteur::ajouterDestructeur(); }
	Operation6(Operation6 const& autre) :Operation(autre) { Compteur::ajouterConstructeurCopie(); }
	Operation6* makeObject(Operation6 const& autre) { return new Operation6(autre); }
	bool effectuerOperation(Dechet* dechet)  override {
		return (dechet->getMateriel() == Dechet::PLASTIQUE &&
			(dechet->getType() == 0 || dechet->getType() == 6));
	}
};
