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
#include <Heyutu_null_adder.h>


Heyutu_null_adder_sptr
Heyutu_make_null_adder (size_t input_size, size_t output_size)
{
	return Heyutu_null_adder_sptr (new Heyutu_null_adder (input_size, output_size));
}


Heyutu_null_adder::Heyutu_null_adder (size_t input_size, size_t output_size)
	: gr_sync_interpolator ("null_adder",
				gr_make_io_signature (1, 1, input_size*sizeof(gr_complex)),
			 	gr_make_io_signature (1, 1, output_size*sizeof(gr_complex)),
			  	output_size), 
    d_input_size(input_size),
    d_output_size(output_size)
{
}


int
Heyutu_null_adder::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
	gr_complex *in = (gr_complex *) input_items[0];
	gr_complex *out = (gr_complex *) output_items[0];
	size_t zero_size = (d_output_size - d_input_size)/2;
//	size_t zero_size = d_output_size - d_input_size;

	unsigned int i=0, j=0;
//	unsigned int i=0;
	
//	gr_complex *temp = new gr_complex[d_output_size];
	
//	memset(temp, 0, d_output_size*sizeof(gr_complex));	
//	memmove(temp+zero_size, temp, zero_size);

//	memset(out, 0, d_output_size*sizeof(gr_complex));

//	for(i=0; i < d_input_size; i++) {
//	  if (i==d_input_size){
//		continue;
//		}
//	  out[i+zero_size] = in[i];
//	  out[i] = in[i];
//	}

	
	j = 0;
	for(i=0; i < zero_size; i++,j++) {
	  out[j] = 0;
	}
	
	for(i=0; i < d_input_size; i++,j++) {
	  out[j] = in[i];
	}

	for(i=0; i < zero_size; i++, j++) {
	  out[j] = 0;
	}
	
	


//	delete[] temp;

//	size_t block_size = output_signature()->sizeof_stream_item (0);
//	memcpy (out, in, noutput_items * block_size);

	return d_output_size;
}
