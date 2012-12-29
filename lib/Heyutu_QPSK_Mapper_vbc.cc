/* -*- c++ -*- */
/* 
 * Copyright 2012 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gr_io_signature.h>
#include <Heyutu_QPSK_Mapper_vbc.h>


Heyutu_QPSK_Mapper_vbc_sptr
Heyutu_make_QPSK_Mapper_vbc (int symbol_length)
{
	return Heyutu_QPSK_Mapper_vbc_sptr (new Heyutu_QPSK_Mapper_vbc (symbol_length));
}


Heyutu_QPSK_Mapper_vbc::Heyutu_QPSK_Mapper_vbc (int symbol_length)
	: gr_sync_block ("QPSK_Mapper_vbc",
		gr_make_io_signature (1, 1, sizeof (char)*symbol_length/4),
		gr_make_io_signature (1, 1, sizeof (gr_complex)*symbol_length)), 
	d_symbol_length(symbol_length)
{
	assert(symbol_length>0);
	assert(symbol_length%4==0);
}


int
Heyutu_QPSK_Mapper_vbc::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
  char const *in = (const char *) input_items[0];
  gr_complex *out = (gr_complex *) output_items[0];

  gr_complex symbol;
  char byte;

  for (int i=0; i<noutput_items; i++) {
    for (int j=0; j<d_symbol_length/4; j++) {
      byte = in[j];
      out[0] = gr_complex((byte&128)>0?-I_SQRT2:I_SQRT2,(byte&64)>0?-I_SQRT2:I_SQRT2);	//#define I_SQRT2 0.707106781187
      out[1] = gr_complex((byte&32)>0?-I_SQRT2:I_SQRT2, (byte&16)>0?-I_SQRT2:I_SQRT2);
      out[2] = gr_complex((byte&8)>0?-I_SQRT2:I_SQRT2,  (byte&4)>0?-I_SQRT2:I_SQRT2);
      out[3] = gr_complex((byte&2)>0?-I_SQRT2:I_SQRT2,  (byte&1)>0?-I_SQRT2:I_SQRT2);
      out+=4;
    }
    in  += d_symbol_length/4;
  }
 
  return noutput_items;
}

