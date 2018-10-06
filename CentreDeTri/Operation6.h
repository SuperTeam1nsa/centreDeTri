#pragma once
#include "Operation.h"
class Operation6 :
	public Operation
{
public:
	Operation6(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {};
	virtual ~Operation6() {};
	bool effectuerOperation(Dechet* dechet) const override {
		return (dechet->getMateriel() == Dechet::PLASTIQUE &&
			(dechet->getType() == 0 || dechet->getType() == 6));
	}
};
