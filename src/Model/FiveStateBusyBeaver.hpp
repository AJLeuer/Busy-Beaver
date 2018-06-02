#pragma once

#include <iostream>

#include "BusyBeaverProgram.hpp"

using Instruction = TuringMachine::Instruction;
using State = TuringMachine::State;


class FiveStateBusyBeaver : public BusyBeaverProgram {
    
protected:

	/**
	* The instruction table for an implementation of the busy beaver program that was proven to run for 47,176,870 steps,
	* the highest yet found for a 5 state, 2 symbol busy beaver
	*
	* The original definition can be found here: http://www.logique.jussieu.fr/~michel/ha.html#tm52, at the
	* very top of the table, the entry with a Σ value of 47,176,870
	*/
	const static map<State, array<Instruction, 2>> championInstructionTable;

	/**
	* The instruction table for an implementation of the busy beaver program that was proven to run for 134,467 steps
	*
	* The original definition can be found here: http://www.logique.jussieu.fr/~michel/ha.html#tm52, at the
	* very bottom of the table, the entry with a Σ value of 134,467
	*/
    const static map<State, array<Instruction, 2>> defaultInstructionTable;
    
public:
    
    FiveStateBusyBeaver() :
        BusyBeaverProgram(championInstructionTable) {}
};
