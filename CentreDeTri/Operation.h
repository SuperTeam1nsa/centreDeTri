#pragma once
#include "Dechet.h"
class Operation
{
public:
	Operation(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) {
		this->operationSuivanteFalse = operationSuivanteFalse;
		this->operationSuivanteTrue = operationSuivanteFalse;
	};
	virtual bool effectuerOperation(Dechet* dechet);//fonction virtuelle pure //à voir avec le main #specs pas claires
	Operation *getOperationSuivante(bool choix)const { return choix ? operationSuivanteFalse : operationSuivanteFalse; }
	virtual ~Operation() { delete operationSuivanteFalse; delete operationSuivanteTrue; };

protected:
	Operation() { operationSuivanteFalse = NULL; operationSuivanteFalse = NULL; };
private:
	Operation* operationSuivanteTrue;
	Operation* operationSuivanteFalse;

};
