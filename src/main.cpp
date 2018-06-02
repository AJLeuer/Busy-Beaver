//
//  main.cpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 7/31/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.

#include <iostream>

#include "./Model/TuringMachine.hpp"
#include "./Model/BusyBeaverProgram.hpp"
#include "./Model/TwoStateBusyBeaver.hpp"
#include "./Model/FourStateBusyBeaver.hpp"
#include "./Model/FiveStateBusyBeaver.hpp"

using namespace std;

int main(int argumentCount, char ** arguments) {
    TuringMachine tm;
    
    FiveStateBusyBeaver busyBeaver;
    
    tm.run(busyBeaver, & cout);
    
    cout << "Program counter: " << tm.getProgramCounterValue() << endl;
    
    return 0;
}
