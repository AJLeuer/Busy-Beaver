//
//  Example2Symbol2StateBusyBeaver.cpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 8/29/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#include "TwoStateBusyBeaver.hpp"

using namespace std;


using Direction = TuringMachine::DirectionToMove;


const std::map<State, array<Instruction, 2>> TwoStateBusyBeaver::defaultInstructionTable {
    { State::A, array<Instruction, 2>{ Instruction{'1', Direction::RIGHT, State::B}, Instruction{'1', Direction::LEFT, State::B}} },
    { State::B, array<Instruction, 2>{ Instruction{'1', Direction::LEFT, State::A}, Instruction{'1', Direction::RIGHT, State::HALT} }}
} ;

