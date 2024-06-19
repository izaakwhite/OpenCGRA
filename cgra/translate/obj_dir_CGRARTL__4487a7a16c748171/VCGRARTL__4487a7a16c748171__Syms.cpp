// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VCGRARTL__4487a7a16c748171__Syms.h"
#include "VCGRARTL__4487a7a16c748171.h"
#include "VCGRARTL__4487a7a16c748171___024unit.h"



// FUNCTIONS
VCGRARTL__4487a7a16c748171__Syms::VCGRARTL__4487a7a16c748171__Syms(VCGRARTL__4487a7a16c748171* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
