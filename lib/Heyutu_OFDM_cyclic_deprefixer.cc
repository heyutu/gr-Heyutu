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
#include <Heyutu_OFDM_cyclic_deprefixer.h>
#include <iostream>


Heyutu_OFDM_cyclic_deprefixer_sptr
Heyutu_make_OFDM_cyclic_deprefixer (size_t input_size, size_t output_size)
{
	return Heyutu_OFDM_cyclic_deprefixer_sptr (new Heyutu_OFDM_cyclic_deprefixer (input_size, output_size));
}


Heyutu_OFDM_cyclic_deprefixer::Heyutu_OFDM_cyclic_deprefixer (size_t input_size, size_t output_size)
	: gr_sync_decimator ("OFDM_cyclic_deprefixer",
			    gr_make_io_signature (1, 1, sizeof(gr_complex)),
			    gr_make_io_signature (1, 1, output_size*sizeof(gr_complex)), 
			    input_size),
	d_input_size(input_size),
	d_output_size(output_size)
{
}
// Decimation Block:  the number of input_items = noutput_items*decimation = noutput_items*input_size
// input > output

int
Heyutu_OFDM_cyclic_deprefixer::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{

  gr_complex *in = (gr_complex *) input_items[0];
  gr_complex *out = (gr_complex *) output_items[0];

  size_t cp_size = d_input_size - d_output_size;

  unsigned int i=0, j=0, p_input=0, p_output=0;

  for(i=0; i < noutput_items; i++) {
//    for(j = 0; j<cp_size; j++){
//      p_input++;
//    }
    p_input += cp_size;
    for(j = 0; j<d_output_size; j++){
      out[p_output++] = in[p_input++];
    }
  }
  
//  consume_each(noutput_items);
//  consume_each(p_input);
//  return d_output_size;
  return noutput_items;
}


