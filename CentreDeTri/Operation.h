#pragma once
#include "Dechet.h"
class Operation
{
public:
	Operation(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) {
		this->operationSuivanteFalse = operationSuivanteFalse;
		this->operationSuivanteTrue = operationSuivanteFalse;
	};
	virtual bool effectuerOperation(Dechet* dechet);//fonction virtuelle pure
	Operation *getOperationSuivante(bool choix)const { return choix ? operationSuivanteFalse : operationSuivanteFalse; }
	virtual ~Operation();

protected:
	Operation();
private:
	Operation* operationSuivanteTrue;
	Operation* operationSuivanteFalse;

};
