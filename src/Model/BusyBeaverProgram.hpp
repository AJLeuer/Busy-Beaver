//
//  Table.hpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 8/21/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <iostream>
#include <ostream>
#include <array>
#include <utility>
#include <map>

#include "Instruction.hpp"

using namespace std;

class BusyBeaverProgram : public Program {

private:
    
    /**
     * The instructions table contains map entries for each possible state ('A', 'B', 'C', etc.). Each map entry in turn contains two instructions, one to
     * read when the symbol at the current tape position is '0' (found at index zero of currentInstructionColumn), and one for when the current symbol is
     * '1'.
     */
    map<TuringMachine::State, array<Instruction, 2>>  instructionsTable;
    
    unsigned int programCounter = 0;
    
public:
    
    BusyBeaverProgram(const map<TuringMachine::State, array<Instruction, 2>> & instructionsTable) :
        instructionsTable(instructionsTable) {}
    
    void run(TuringMachine & tm) override;
    
};


#endif /* Table_hpp */
