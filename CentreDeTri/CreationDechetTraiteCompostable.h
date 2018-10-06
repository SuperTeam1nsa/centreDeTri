#pragma once
#include "OperationTraitement.h"
class CreationDechetTraiteCompostable :
	public OperationTraitement
{
public:
	CreationDechetTraiteCompostable(UsineTraitement* usineTraitement) :OperationTraitement(usineTraitement) {};
	bool effectuerOperation(Dechet* dechet) override { creerDechetTraiteCompostable(dechet); return true; }
	virtual ~CreationDechetTraiteCompostable() {};

};
