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

/**
 * This is an implementation of the busy beaver program that was proven to run the maximum number of steps possible for a 4-state machine
 */
class FourStateBusyBeaver : public BusyBeaverProgram {
    
protected:
    
    const static map<TuringMachine::State, array<TuringMachine::Instruction, 2>> defaultInstructionTable;
    
public:
    
    FourStateBusyBeaver() :
        BusyBeaverProgram(defaultInstructionTable) {}
};

#endif /* _StateBusyBeaver_hpp */
