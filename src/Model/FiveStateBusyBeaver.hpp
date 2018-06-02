#pragma once

#include <iostream>

#include "BusyBeaverProgram.hpp"

using Instruction = TuringMachine::Instruction;
using State = TuringMachine::State;

/**
 * This is an implementation of the busy beaver program that was proven to run the in 134,467 steps
 * 
 * The original definition can be found here: http://www.logique.jussieu.fr/~michel/ha.html#tm52, at the
 * very bottom of the table, the entry with a Σ value of 134,467
 */
class FiveStateBusyBeaver : public BusyBeaverProgram {
    
protected:
    
    const static map<State, array<Instruction, 2>> defaultInstructionTable;
    
public:
    
    FiveStateBusyBeaver() :
        BusyBeaverProgram(defaultInstructionTable) {}
};
