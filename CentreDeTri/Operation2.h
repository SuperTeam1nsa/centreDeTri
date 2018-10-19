#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation2 :
	public Operation
{
public:
	Operation2(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) { Compteur::ajouterConstructeur(); };
	virtual~Operation2() {};
	bool effectuerOperation(Dechet* dechet)  override { Compteur::ajouterDestructeur(); return dechet->getMateriel() == Dechet::PLASTIQUE; }

};
