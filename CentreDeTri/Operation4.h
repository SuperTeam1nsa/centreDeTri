#pragma once
#include "Operation.h"
class Operation4 :
	public Operation
{
public:
	Operation4(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {};
	~Operation4() {};
	bool effectuerOperation(Dechet* dechet) override { return (dechet->getCouleur() == "brun" | dechet->getMateriel() == Dechet::NOURRITURE); }

};
