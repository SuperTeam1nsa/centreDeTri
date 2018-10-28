#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation1 :
	public Operation
{
public:
	Operation1(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	~Operation1() { Compteur::ajouterDestructeur(); }
	Operation1(Operation1 const& autre) :Operation(autre) { Compteur::ajouterConstructeurCopie(); }
	Operation1* makeObject(Operation1 const& autre) { return new Operation1(autre); }
	bool effectuerOperation(Dechet* dechet)  override { return (dechet->estEnStyromousse() || dechet->estRigide()); }
};
