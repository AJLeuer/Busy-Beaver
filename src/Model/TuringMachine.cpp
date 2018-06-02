//
//  TuringMachine.cpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 7/31/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#include "TuringMachine.hpp"

using namespace std;

TuringMachine::TuringMachine() :
    tape(),
    state(State::A), //Always starts in state 'A'
    programCounter(0),
    currentHeadPosition(),
    lowestTapePositionWritten(),
    highestTapePositionWritten(),
	timer()
{
    tape = vector<char>(tapeSize, '0'); //Tape starts out with each each symbol zeroed out...
    initializePositionMarkers();
}

TuringMachine::TuringMachine(const TuringMachine & turingMachine) :
    tape(turingMachine.tape),
    state(turingMachine.getState()),
    programCounter(turingMachine.programCounter)
{
    initializePositionMarkers();
}

TuringMachine & TuringMachine::operator = (const TuringMachine & other) {
    if (this != & other) {
        this->tape = other.tape;
        this->state = other.getState();
        this->programCounter = other.programCounter;
        initializePositionMarkers();
    }
    return * this;
}

TuringMachine::~TuringMachine() {
    tape = vector<char>{};
    state = State::A;
    programCounter = 0;
    currentHeadPosition = vector<char>::iterator();
    lowestTapePositionWritten = vector<char>::iterator();
    highestTapePositionWritten = vector<char>::iterator();
}

void TuringMachine::initializePositionMarkers() {
    currentHeadPosition = tape.begin() + (tape.size() / 2); // ... and the turing machine will always start reading at the zero in the center of the tape
    lowestTapePositionWritten = currentHeadPosition;
    highestTapePositionWritten = currentHeadPosition;
}

void TuringMachine::reset() {
    * this = TuringMachine();
}

void TuringMachine::run(Program & program, ostream * outputStream) {
	startTimer();
    while (getState() != State::HALT) {
        const Instruction & currentInstruction =
            program.getInstructionsForStateAndSymbol(getState(), getSymbolUnderHead());
        
        execute(currentInstruction);
        
        programCounter++;
        
        if (outputStream != nullptr) {
            writeTapeToOutput(* outputStream);
        }
    }
	stopTimer(* outputStream);
}

void TuringMachine::execute(const Instruction & instruction) {
    
    if (instruction.symbolToPrint != 0x00) {
        writeSymbolToTape(instruction.symbolToPrint);
    }
    
    moveHead(instruction.directionToMove);
    
    if (instruction.newState != State::UNCHANGED) {
        setState(instruction.newState);
    }
}

void TuringMachine::writeSymbolToTape(char symbol) {
    * currentHeadPosition = symbol;
    
    if (currentHeadPosition < lowestTapePositionWritten) {
        lowestTapePositionWritten = currentHeadPosition;
    }
    else if (currentHeadPosition > highestTapePositionWritten) {
        highestTapePositionWritten = currentHeadPosition;
    }
}

void TuringMachine::moveHead(TuringMachine::DirectionToMove direction) {
    if (direction == DirectionToMove::RIGHT) {
        currentHeadPosition++;
    }
    else /* if (direction == DirectionToMove::LEFT) */ {
        currentHeadPosition--;
    }
}

void TuringMachine::writeTapeToOutput(ostream & outputStream, unsigned padding) {
	if (ConsoleOutputEnabled == false) {
		return;
	}
    outputStream << "Program output: " ;
    for (auto symbolIterator = (lowestTapePositionWritten - padding); symbolIterator <= (highestTapePositionWritten + padding); symbolIterator++) {
        
        stringstream output;
        
        if (symbolIterator == currentHeadPosition) {
            output << '*' << * symbolIterator << '*' ;
        }
        else {
            output << * symbolIterator ;
        }
        
        outputStream <<  output.str() << ' ' ;
    }
    outputStream << endl ;
}


void TuringMachine::startTimer() {
	if (TimerEnabled) {
		timer.startTimer();
	}
}

void TuringMachine::stopTimer(ostream & outputStream) {
	if (TimerEnabled) {
		std::chrono::nanoseconds timeElapsed = timer.stopTimer();

		outputStream << "Time taken to halt, in nanoseconds: " << timeElapsed.count() << endl;
	}
}

const TuringMachine::Instruction & InstructionTable::getInstructionsForStateAndSymbol(const State state, const char symbol) const {
    unsigned symbolAsIndex = symbol - '0';
    return getInstructionsForState(state).at(symbolAsIndex);
}


const array<TuringMachine::Instruction, 2> & InstructionTable::getInstructionsForState(const State state) const {
    return instructions.at(state);
}












