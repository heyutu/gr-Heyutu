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
#include <Heyutu_zero_adder.h>


Heyutu_zero_adder_sptr
Heyutu_make_zero_adder (size_t input_size, size_t output_size)
{
	return Heyutu_zero_adder_sptr (new Heyutu_zero_adder (input_size, output_size));
}


Heyutu_zero_adder::Heyutu_zero_adder (size_t input_size, size_t output_size)
	: gr_sync_block ("zero_adder",
			gr_make_io_signature (1, 1, input_size*sizeof(gr_complex)),
			gr_make_io_signature (1, 1, output_size*sizeof(gr_complex))), 
    d_input_size(input_size),
    d_output_size(output_size)
{
}


int
Heyutu_zero_adder::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
	gr_complex *in = (gr_complex *) input_items[0];
	gr_complex *out = (gr_complex *) output_items[0];
	size_t cp_size = (d_output_size - d_input_size)/2;
//	size_t cp_size = d_output_size - d_input_size;

	unsigned int i=0, j=0;
//	unsigned int i=0;
	memset(out, 0, d_output_size*sizeof(gr_complex));

	for(i=0; i < d_input_size; i++) {
//	  if (i==d_input_size){
//		continue;
//		}
	  out[i+cp_size] = in[i];
//	  out[i] = in[i];
	}

/*	
	j = 0;
	for(i=0; i < cp_size; i++,j++) {
	  out[j] = 0;
	}

	j = cp_size + d_input_size;
	for(i=0; i < cp_size; i++, j++) {
	  out[j] = 0;
	}
	
	
	j = cp_size;
	for(i=0; i < d_input_size; i++,j++) {
	  out[j] = in[i];
	}
*/

	return d_output_size;
}
