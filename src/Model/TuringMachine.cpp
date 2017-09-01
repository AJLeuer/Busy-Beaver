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
    state(State::A), //Always starts in state 'A'
    tape(),
    programCounter(0),
    currentHeadPosition(),
    lowestTapePositionWritten(),
    highestTapePositionWritten()
{
    tape = vector<char>(/* 65536 */ 64, '0'); //Tape starts out with each each symbol zeroed out...
    initializePositionMarkers();
}

TuringMachine::TuringMachine(const TuringMachine & turingMachine) :
    state(turingMachine.getState()),
    tape(turingMachine.tape),
    programCounter(turingMachine.programCounter)
{
    initializePositionMarkers();
}

TuringMachine & TuringMachine::operator = (const TuringMachine & other) {
    if (this != & other) {
        this->state = other.getState();
        this->tape = other.tape;
        this->programCounter = other.programCounter;
        initializePositionMarkers();
    }
    return * this;
}

TuringMachine::~TuringMachine()
{
    state = State::A;
    tape = vector<char>{};
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

void TuringMachine::load(Program & program) {
    while (getState() != State::HALT) {
        program.run(* this);
        programCounter++;
    }
}

void TuringMachine::execute(const TuringMachine::Instruction & instruction) {
    
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












