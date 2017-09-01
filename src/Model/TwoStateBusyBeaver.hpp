//
//  Example2Symbol2StateBusyBeaver.hpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 8/29/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#ifndef Example2Symbol2StateBusyBeaver_hpp
#define Example2Symbol2StateBusyBeaver_hpp

#include <iostream>
#include <map>

#include "BusyBeaverProgram.hpp"

/**
 * An example Busy Beaver program with two-states and a complete instruction table
 */
class TwoStateBusyBeaver : public BusyBeaverProgram {

protected:
    
    const static map<TuringMachine::State, array<TuringMachine::Instruction, 2>> defaultInstructionTable;
    
public:
    
    TwoStateBusyBeaver() :
        BusyBeaverProgram(defaultInstructionTable) {}
    
};

#endif /* Example2Symbol2StateBusyBeaver_hpp */
