#include "FiveStateBusyBeaver.hpp"

using namespace std;

using Direction = TuringMachine::DirectionToMove;


const std::map<State, array<Instruction, 2>> FiveStateBusyBeaver::defaultInstructionTable {
    { State::A, array<Instruction, 2>{ Instruction{'1', Direction::RIGHT,	State::B},	Instruction{'0', Direction::LEFT,	State::C} }},
    { State::B, array<Instruction, 2>{ Instruction{'1', Direction::RIGHT,	State::C},	Instruction{'1', Direction::RIGHT,	State::D} }},
    { State::C, array<Instruction, 2>{ Instruction{'1', Direction::LEFT,	State::A},	Instruction{'0', Direction::RIGHT,	State::B} }},
    { State::D, array<Instruction, 2>{ Instruction{'0', Direction::RIGHT,	State::E},	Instruction{'1', Direction::RIGHT,	State::HALT} }},
	{ State::E, array<Instruction, 2>{ Instruction{'1', Direction::LEFT,	State::C },	Instruction{'1', Direction::RIGHT,	State::A} }}
} ;
