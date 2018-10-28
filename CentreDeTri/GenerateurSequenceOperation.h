#pragma once
#include "UsineTraitement.h"
#include "SequenceOperations.h"
#include "CreationDechetRecyclable.h"
#include "CreationDechetTraiteCompostable.h"
#include "CreationDechetTraiteNonRecyclable.h"
#include"Operation1.h"
#include"Operation2.h"
#include"Operation3.h"
#include"Operation4.h"
#include"Operation5.h"
#include"Operation6.h"
#include "Compteur.h"

class GenerateurSequenceOperation
{
public:
	GenerateurSequenceOperation() { Compteur::ajouterConstructeur(); };
	~GenerateurSequenceOperation() { Compteur::ajouterDestructeur(); };
	SequenceOperations* genererSequence(int id, UsineTraitement* usineTraitement) const {
		return id == 0 ? genererSequence0(usineTraitement) :
			genererSequence1(usineTraitement);
	};
private:
	SequenceOperations* genererSequence0(UsineTraitement* usineTraitement) const;
	SequenceOperations* genererSequence1(UsineTraitement* usineTraitement) const {
		return (new SequenceOperations())->ajouterOperation(new Operation1(new CreationDechetTraiteNonRecyclable(usineTraitement),
			new CreationDechetTraiteRecyclable(usineTraitement)));
	}
};


//on crée la séquence 0
SequenceOperations* GenerateurSequenceOperation::genererSequence0(UsineTraitement* usineTraitement) const
{
	SequenceOperations* seq = new SequenceOperations();
	Operation *op = new Operation1(new CreationDechetTraiteNonRecyclable(usineTraitement),
		new Operation2(new Operation6(new CreationDechetTraiteRecyclable(usineTraitement),
			new CreationDechetTraiteNonRecyclable(usineTraitement)),
			new Operation3(new CreationDechetTraiteRecyclable(usineTraitement),
				new Operation4(new CreationDechetTraiteCompostable(usineTraitement),
					new Operation5(new CreationDechetTraiteCompostable(usineTraitement),
						new CreationDechetTraiteNonRecyclable(usineTraitement))))));
	seq->ajouterOperation(op);
	return seq;
}
