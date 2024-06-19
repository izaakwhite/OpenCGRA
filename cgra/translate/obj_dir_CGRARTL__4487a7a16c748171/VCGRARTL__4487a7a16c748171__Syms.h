// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VCGRARTL__4487A7A16C748171__SYMS_H_
#define _VCGRARTL__4487A7A16C748171__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VCGRARTL__4487a7a16c748171.h"
#include "VCGRARTL__4487a7a16c748171___024unit.h"

// SYMS CLASS
class VCGRARTL__4487a7a16c748171__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VCGRARTL__4487a7a16c748171*    TOPp;
    
    // CREATORS
    VCGRARTL__4487a7a16c748171__Syms(VCGRARTL__4487a7a16c748171* topp, const char* namep);
    ~VCGRARTL__4487a7a16c748171__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
