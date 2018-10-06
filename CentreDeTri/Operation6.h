#pragma once
#include "Operation.h"
class Operation6 :
	public Operation
{
public:
	Operation6(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {};
	~Operation6() {};
	bool effectuerOperation(Dechet* dechet) override {
		return (dechet->getMateriel() == Dechet::PLASTIQUE &&
			(dechet->getType() == 0 || dechet->getType() == 6));
	}
};
