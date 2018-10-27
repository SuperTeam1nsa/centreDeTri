#pragma once
#include "Operation.h"
#include "Compteur.h"


class Operation4 :
	public Operation
{
public:
	Operation4(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	~Operation4() { Compteur::ajouterDestructeur(); }
	Operation4(Operation4 const& autre) :Operation(autre) { Compteur::ajouterConstructeurCopie(); }
	Operation4* makeObject(Operation4 const& autre) { return new Operation4(autre); }
	bool effectuerOperation(Dechet* dechet)  override {
		return (dechet->getCouleur() == "brun") &&
			(dechet->getMateriel() == Dechet::NOURRITURE);
	}

};
