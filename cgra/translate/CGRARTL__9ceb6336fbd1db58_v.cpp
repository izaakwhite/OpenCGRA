//========================================================================
// VCGRARTL__9ceb6336fbd1db58_v.cpp
//========================================================================
// This file provides a template for the C wrapper used in the import
// pass. The wrapper exposes a C interface to CFFI so that a
// Verilator-generated C++ model can be driven from Python.
// This templated is based on PyMTL v2.

#include "obj_dir_CGRARTL__9ceb6336fbd1db58/VCGRARTL__9ceb6336fbd1db58.h"
#include "stdio.h"
#include "stdint.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// set to true when VCD tracing is enabled in Verilator
#define DUMP_VCD 0

// set to true when Verilog module has line tracing
#define VLINETRACE 0

#if VLINETRACE
#include "obj_dir_CGRARTL__9ceb6336fbd1db58/VCGRARTL__9ceb6336fbd1db58__Syms.h"
#include "svdpi.h"
#endif

//------------------------------------------------------------------------
// CFFI Interface
//------------------------------------------------------------------------
// simulation methods and model interface ports exposed to CFFI

extern "C" {
  typedef struct {

    // Exposed port interface
    unsigned char * clk;
    unsigned char * reset;
    unsigned char * recv_waddr___05Fen[4];
    unsigned char * recv_waddr___05Fmsg[4];
    unsigned char * recv_waddr___05Frdy[4];
    unsigned char * recv_wopt___05Fen[4];
    unsigned long * recv_wopt___05Fmsg[4];
    unsigned char * recv_wopt___05Frdy[4];

    // Verilator model
    void * model;

    // VCD state
    int _vcd_en;

    // VCD tracing helpers
    #if DUMP_VCD
    void *        tfp;
    unsigned int  trace_time;
    unsigned char prev_clk;
    #endif

  } VCGRARTL__9ceb6336fbd1db58_t;

  // Exposed methods
  VCGRARTL__9ceb6336fbd1db58_t * create_model( const char * );
  void destroy_model( VCGRARTL__9ceb6336fbd1db58_t *);
  void eval( VCGRARTL__9ceb6336fbd1db58_t * );
  void assert_en( bool en );

  #if VLINETRACE
  void trace( VCGRARTL__9ceb6336fbd1db58_t *, char * );
  #endif

}

//------------------------------------------------------------------------
// sc_time_stamp
//------------------------------------------------------------------------
// Must be defined so the simulator knows the current time. Called by
// $time in Verilog. See:
// http://www.veripool.org/projects/verilator/wiki/Faq

vluint64_t g_main_time = 0;

double sc_time_stamp()
{

  return g_main_time;

}

//------------------------------------------------------------------------
// create_model()
//------------------------------------------------------------------------
// Construct a new verilator simulation, initialize interface signals
// exposed via CFFI, and setup VCD tracing if enabled.

VCGRARTL__9ceb6336fbd1db58_t * create_model( const char *vcd_filename ) {

  VCGRARTL__9ceb6336fbd1db58_t * m;
  VCGRARTL__9ceb6336fbd1db58   * model;

  Verilated::randReset( 0 );

  m     = (VCGRARTL__9ceb6336fbd1db58_t *) malloc( sizeof(VCGRARTL__9ceb6336fbd1db58_t) );
  model = new VCGRARTL__9ceb6336fbd1db58();

  m->model = (void *) model;

  // Enable tracing. We have added a feature where if the vcd_filename is
  // "" then we don't do any VCD dumping even if DUMP_VCD is true.

  m->_vcd_en = 0;
  #if DUMP_VCD
  if ( strlen( vcd_filename ) != 0 ) {
    m->_vcd_en = 1;
    Verilated::traceEverOn( true );
    VerilatedVcdC * tfp = new VerilatedVcdC();

    model->trace( tfp, 99 );
    tfp->spTrace()->set_time_resolution( "10ps" );
    tfp->open( vcd_filename );

    m->tfp        = (void *) tfp;
    m->trace_time = 0;
    m->prev_clk   = 0;
  }
  #endif

  // initialize exposed model interface pointers
  m->clk = &model->clk;
  m->reset = &model->reset;
  for ( int i_0 = 0; i_0 < 4; i_0++ )

    m->recv_waddr___05Fen[i_0] = &model->recv_waddr___05Fen[i_0];

  for ( int i_0 = 0; i_0 < 4; i_0++ )

    m->recv_waddr___05Fmsg[i_0] = &model->recv_waddr___05Fmsg[i_0];

  for ( int i_0 = 0; i_0 < 4; i_0++ )

    m->recv_waddr___05Frdy[i_0] = &model->recv_waddr___05Frdy[i_0];

  for ( int i_0 = 0; i_0 < 4; i_0++ )

    m->recv_wopt___05Fen[i_0] = &model->recv_wopt___05Fen[i_0];

  for ( int i_0 = 0; i_0 < 4; i_0++ )

    m->recv_wopt___05Fmsg[i_0] = &model->recv_wopt___05Fmsg[i_0];

  for ( int i_0 = 0; i_0 < 4; i_0++ )

    m->recv_wopt___05Frdy[i_0] = &model->recv_wopt___05Frdy[i_0];


  return m;

}

//------------------------------------------------------------------------
// destroy_model()
//------------------------------------------------------------------------
// Finalize the Verilator simulation, close files, call destructors.

void destroy_model( VCGRARTL__9ceb6336fbd1db58_t * m ) {

  #if VM_COVERAGE
    VerilatedCov::write( "coverage.dat" );
  #endif

  VCGRARTL__9ceb6336fbd1db58 * model = (VCGRARTL__9ceb6336fbd1db58 *) m->model;

  // finalize verilator simulation
  model->final();

  #if DUMP_VCD
  if ( m->_vcd_en ) {
    // printf("DESTROYING %d\n", m->trace_time);
    VerilatedVcdC * tfp = (VerilatedVcdC *) m->tfp;
    tfp->close();
  }
  #endif

  // TODO: this is probably a memory leak!
  //       But pypy segfaults if uncommented...
  //delete model;

}

//------------------------------------------------------------------------
// eval()
//------------------------------------------------------------------------
// Simulate one time-step in the Verilated model.

void eval( VCGRARTL__9ceb6336fbd1db58_t * m ) {

  VCGRARTL__9ceb6336fbd1db58 * model = (VCGRARTL__9ceb6336fbd1db58 *) m->model;

  // evaluate one time step
  model->eval();

  #if DUMP_VCD
  if ( m->_vcd_en ) {

    // update simulation time only on clock toggle
    if (m->prev_clk != model->clk) {
      m->trace_time += 50;
      g_main_time += 50;
    }
    m->prev_clk = model->clk;

    // dump current signal values
    VerilatedVcdC * tfp = (VerilatedVcdC *) m->tfp;
    tfp->dump( m->trace_time );
    tfp->flush();

  }
  #endif

}

//------------------------------------------------------------------------
// assert_en()
//------------------------------------------------------------------------
// Enable or disable assertions controlled by --assert

void assert_en( bool en ) {

  Verilated::assertOn(en);

}

//------------------------------------------------------------------------
// trace()
//------------------------------------------------------------------------
// Note that we assume a trace string buffer of 512 characters. This is
// assumed in a couple of places, including the Python wrapper template
// and the Verilog vc/trace.v code. So if we change it, we need to change
// it everywhere.

#if VLINETRACE
void trace( VCGRARTL__9ceb6336fbd1db58_t * m, char* str ) {

  VCGRARTL__9ceb6336fbd1db58 * model = (VCGRARTL__9ceb6336fbd1db58 *) m->model;

  const int nchars = 512;
  const int nwords = nchars/4;

  uint32_t words[nwords];
  words[0] = nchars-1;

  // Setup scope for accessing the line tracing function throug DPI.
  // Note, I tried using just this:
  //
  //  svSetScope( svGetScopeFromName("TOP.v.verilog_module") );
  //
  // but it did not seem to work. We would see correct line tracing for
  // the first test case but not any of the remaining tests cases. After
  // digging around a bit, it seemed like the line_trace task was still
  // associated with the very first model as opposed to the newly
  // instantiated models. Directly setting the scope seemed to fix
  // this issue.
  //
  // Note that this issue implies that the mysterious extra .v is no
  // longer present:
  //
  //  https://www.veripool.org/issues/1050-Verilator-Extra-v-in-full-signal-pathnames
  //
  // So now we need to explicitly use the model name instead of
  // Vscope_v__verilog_module.

  // PP: also note that since we add a wrapper around the external Verilog
  // module, the scope we are trying to set is actually the _wrapped_ module
  // which is called `v`.

  svSetScope( &model->__VlSymsp->__Vscope_CGRARTL__9ceb6336fbd1db58__v );
  model->line_trace( words );

  // Note that the way the line tracing works, the line tracing function
  // will store how the last character used in the line trace in the
  // first element of the word array. The line tracing functions store
  // the line trace starting from the most-signicant character due to the
  // way that Verilog handles strings.

  int nchar_last  = words[0];
  int nchars_used = ( nchars - 1 - nchar_last );

  // We subtract since one of the words (i.e., 4 characters) is for
  // storing the nchars_used.

  assert ( nchars_used < (nchars - 4) );

  // Now we need to iterate from the most-significant character to the
  // last character written by the line tracing functions and copy these
  // characters into the given character array. So we are kind of
  // flipping the order of the characters due to the different between
  // how Verilog and C handle strings.

  int j = 0;
  for ( int i = nchars-1; i > nchar_last; i-- ) {
    char c = static_cast<char>( words[i/4] >> (8*(i%4)) );
    str[j] = c;
    j++;
  }
  str[j] = '\0';

}
#endif
