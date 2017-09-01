//
//  4StateBusyBeaver.cpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 8/29/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#include "FourStateBusyBeaver.hpp"

using namespace std;

using State = TuringMachine::State;
using Direction = TuringMachine::DirectionToMove;


const std::map<TuringMachine::State, array<TuringMachine::Instruction, 2>> FourStateBusyBeaver::defaultInstructionTable {
    { State::A, array<TuringMachine::Instruction, 2>{ TuringMachine::Instruction{'1', Direction::RIGHT, State::B}, TuringMachine::Instruction{'1', Direction::LEFT, State::B} }},
    { State::B, array<TuringMachine::Instruction, 2>{ TuringMachine::Instruction{'1', Direction::LEFT, State::A}, TuringMachine::Instruction{'0', Direction::LEFT, State::C} }},
    { State::C, array<TuringMachine::Instruction, 2>{ TuringMachine::Instruction{'1', Direction::RIGHT, State::HALT}, TuringMachine::Instruction{'1', Direction::LEFT, State::D} }},
    { State::D, array<TuringMachine::Instruction, 2>{ TuringMachine::Instruction{'1', Direction::RIGHT, State::D}, TuringMachine::Instruction{'0', Direction::RIGHT, State::A} }}
} ;
