// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCGRARTL__4487a7a16c748171.h for the primary calling header

#ifndef _VCGRARTL__4487A7A16C748171___024UNIT_H_
#define _VCGRARTL__4487A7A16C748171___024UNIT_H_  // guard

#include "verilated.h"

//==========

class VCGRARTL__4487a7a16c748171__Syms;

//----------

VL_MODULE(VCGRARTL__4487a7a16c748171___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    VCGRARTL__4487a7a16c748171__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VCGRARTL__4487a7a16c748171___024unit);  ///< Copying not allowed
  public:
    VCGRARTL__4487a7a16c748171___024unit(const char* name = "TOP");
    ~VCGRARTL__4487a7a16c748171___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(VCGRARTL__4487a7a16c748171__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
