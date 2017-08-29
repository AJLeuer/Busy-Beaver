//
//  Instruction.hpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 8/21/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#ifndef Instruction_hpp
#define Instruction_hpp

#include <iostream>

#include "TuringMachine.hpp"

struct Instruction {
    
    char symbolToPrint;
    
    TuringMachine::DirectionToMove directionToMove;
    
    TuringMachine::State newState;
    
};

#endif 
