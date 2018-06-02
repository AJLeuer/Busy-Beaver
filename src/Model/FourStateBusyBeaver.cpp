//
//  4StateBusyBeaver.cpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 8/29/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#include "FourStateBusyBeaver.hpp"

using namespace std;


using Direction = TuringMachine::DirectionToMove;


const std::map<State, array<Instruction, 2>> FourStateBusyBeaver::defaultInstructionTable {
    { State::A, array<Instruction, 2>{ Instruction{'1', Direction::RIGHT, State::B}, Instruction{'1', Direction::LEFT, State::B} }},
    { State::B, array<Instruction, 2>{ Instruction{'1', Direction::LEFT, State::A}, Instruction{'0', Direction::LEFT, State::C} }},
    { State::C, array<Instruction, 2>{ Instruction{'1', Direction::RIGHT, State::HALT}, Instruction{'1', Direction::LEFT, State::D} }},
    { State::D, array<Instruction, 2>{ Instruction{'1', Direction::RIGHT, State::D}, Instruction{'0', Direction::RIGHT, State::A} }}
} ;
