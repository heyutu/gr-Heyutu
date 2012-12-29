/* -*- c++ -*- */

#define HEYUTU_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "Heyutu_swig_doc.i"


%{
#include "Heyutu_QPSK_Mapper_vbc.h"
#include "Heyutu_OFDM_Mapper_bcv.h"
#include "Heyutu_OFDM_cyclic_prefixer.h"
#include "Heyutu_null_adder.h"
#include "Heyutu_zero_adder.h"
#include "Heyutu_svZeroAdder.h"
#include "Heyutu_OFDM_cyclic_deprefixer.h"
#include "Heyutu_svZeroAdder_inv.h"
#include "Heyutu_OFDM_Sampler.h"
#include "Heyutu_dab_ofdm_sampler.h"
#include "Heyutu_OFDM_cyclic_deprefixer.h"
#include "Heyutu_svZeroAdder_inv.h"
#include "Heyutu_OFDM_Sampler.h"
#include "Heyutu_dab_ofdm_sampler.h"
%}

GR_SWIG_BLOCK_MAGIC(Heyutu,QPSK_Mapper_vbc);
%include "Heyutu_QPSK_Mapper_vbc.h"

GR_SWIG_BLOCK_MAGIC(Heyutu,OFDM_Mapper_bcv);
%include "Heyutu_OFDM_Mapper_bcv.h"

GR_SWIG_BLOCK_MAGIC(Heyutu,OFDM_cyclic_prefixer);
%include "Heyutu_OFDM_cyclic_prefixer.h"

GR_SWIG_BLOCK_MAGIC(Heyutu,null_adder);
%include "Heyutu_null_adder.h"

GR_SWIG_BLOCK_MAGIC(Heyutu,zero_adder);
%include "Heyutu_zero_adder.h"

GR_SWIG_BLOCK_MAGIC(Heyutu,svZeroAdder);
%include "Heyutu_svZeroAdder.h"

GR_SWIG_BLOCK_MAGIC(Heyutu,OFDM_cyclic_deprefixer);
%include "Heyutu_OFDM_cyclic_deprefixer.h"

GR_SWIG_BLOCK_MAGIC(Heyutu,svZeroAdder_inv);
%include "Heyutu_svZeroAdder_inv.h"

GR_SWIG_BLOCK_MAGIC(Heyutu,OFDM_Sampler);
%include "Heyutu_OFDM_Sampler.h"

//GR_SWIG_BLOCK_MAGIC(Heyutu,dab_ofdm_sampler);
//%include "Heyutu_dab_ofdm_sampler.h"
