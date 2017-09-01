//
//  Table.cpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 8/21/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#include "BusyBeaverProgram.hpp"

void BusyBeaverProgram::run(TuringMachine & tm) {
    
    auto & instructionsForCurrentState = instructionsTable.at(tm.getState());
    
    unsigned currentSymbol = tm.getSymbolAtCurrentPosition() - '0'; //either zero or one
    
    TuringMachine::Instruction & instruction = instructionsForCurrentState.at(currentSymbol);
    
    tm.writeSymbolToTape(instruction.symbolToPrint);
    
    tm.moveHead(instruction.directionToMove);
    
    tm.setState(instruction.newState);
}
