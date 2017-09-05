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


#include "TuringMachine.hpp"

using namespace std;

using Instruction = TuringMachine::Instruction;
using Direction = TuringMachine::DirectionToMove;
using State = TuringMachine::State;


class BusyBeaverProgram : public Program {

public:

    using Program::Program;

};


#endif /* Table_hpp */
