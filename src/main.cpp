//
//  main.cpp
//  Busy Beaver
//
//  Created by Adam J Leuer on 7/31/17.
//  Copyright © 2017 Adam J Leuer. All rights reserved.

#include <iostream>

#include "TuringMachine.hpp"
#include "BusyBeaverProgram.hpp"
#include "TwoStateBusyBeaver.hpp"
#include "FourStateBusyBeaver.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    TuringMachine tm;
    
    BusyBeaverProgram * busyBeaver = new FourStateBusyBeaver();
    
    tm.run(* busyBeaver, & cout);
    
    cout << "Program counter: " << tm.getProgramCounterValue() << endl;
    
    return 0;
}
