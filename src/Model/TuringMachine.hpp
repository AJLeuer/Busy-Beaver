//
//  TuringMachine.hpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 7/31/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.
//

#ifndef TuringMachine_hpp
#define TuringMachine_hpp

#include <iostream>
#include <vector>
#include <thread>
#include <sstream>

using namespace std;

/* Forward decl */
class Program;

class TuringMachine {
    
public:
    
    /**
     * The tape represents the Turing Machine's memory. It is theoretically unbounded in both directions (though obviously in the real world we're limited
     * by the amount of physical memory we have available). The tape is divided into squares or cells, each of which can contain a single character. The
     * read/write head of the Turing Machine moves along the tape one cell at a time.
     */
    vector<char> tape;
    
    enum class DirectionToMove : short {
        RIGHT = 1,
        LEFT = -1
    };
    
    /**
     * Represents the possible states of the Turing Machine
     */
    enum class State : char32_t {
        A = 'A',
        B = 'B',
        C = 'C',
        D = 'D',
        E = 'E',
        F = 'F',
        /**
         * Signifies that the Turing Machine's state should remain unchanged
         */
        UNCHANGED = u'␀',
        /**
         * Signifies that the Turing Machine should halt
         */
        HALT = u'␄'
    } state;
    
    struct Instruction {
        
        char symbolToPrint;
        
        DirectionToMove directionToMove;
        
        State newState;
        
    };
    
    unsigned long programCounter;
    
    vector<char>::iterator currentHeadPosition;
    
    vector<char>::iterator lowestTapePositionWritten;
    
    vector<char>::iterator highestTapePositionWritten;
    
    TuringMachine();
    
    TuringMachine(const TuringMachine & turingMachine);
    
    TuringMachine & operator = (const TuringMachine & other);
    
    ~TuringMachine();
    
    void initializePositionMarkers();
    
    void reset();
    
    void load(Program & program);
    
    /**
     * Executes the given instruction. One execution cycle can do up to three things (writing a new symbol, moving the head,
     * and setting the new state), but only moving the head is guarunteed to occur. If the symbolToPrint equals the null character (0x00),
     * symbolToPrint is treated as a NOP and the symbol under the head is left unchanged. If the newState is equal to UNCHANGED (or its underlying
     * representation, ␀), newState is treated as a NOP and the machine state is left unchanged
     */
    void execute(const Instruction & instruction);
    
    State getState() const { return this->state; }
    
    inline unsigned long getProgramCounterValue() { return this->programCounter ; }
    
    char getSymbolAtCurrentPosition() const { return * currentHeadPosition ; }
    
    /**
     * Writes the symbol from every cell on the tape that has been modified so far (ignores all the untouched squares), starting from
     * the lowest-indexed cell on the left to the highest index on the right
     *
     * @param outputStream The output stream to write
     * @param padding How far outside the highest and lowest values written on the tape to read from. By default this is two.
     */
    void writeTapeToOutput(ostream & outputStream, unsigned padding = 2);
    
    
protected:
    
    void writeSymbolToTape(char symbol);
    
    /**
     * Moves head to the left or right. Turing machines always move one position on the tape at a time.
     */
    void moveHead(DirectionToMove direction);
    
    void setState(State state) { this->state = state; }
    
};

class Program {
public:
    virtual void run(TuringMachine & tm) = 0;
};

#endif /* TuringMachine_hpp */
