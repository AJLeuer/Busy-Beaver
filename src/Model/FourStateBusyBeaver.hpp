//
//  4StateBusyBeaver.hpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 8/29/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#ifndef _StateBusyBeaver_hpp
#define _StateBusyBeaver_hpp

#include <iostream>

#include "BusyBeaverProgram.hpp"

using Instruction = TuringMachine::Instruction;
using State = TuringMachine::State;

/**
 * This is an implementation of the busy beaver program that was proven to run the maximum number of steps possible for a 4-state machine
 * 
 * The original description of this Busy Beaver can be found here: http://www.logique.jussieu.fr/~michel/ha.html#tm42, at the
 * very top of the table, with a Σ value of 107
 */
class FourStateBusyBeaver : public BusyBeaverProgram {
    
protected:
    
    const static map<State, array<Instruction, 2>> defaultInstructionTable;
    
public:
    
    FourStateBusyBeaver() :
        BusyBeaverProgram(defaultInstructionTable) {}
};

#endif /* _StateBusyBeaver_hpp */
