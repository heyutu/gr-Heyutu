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
#include <Heyutu_svZeroAdder.h>
#include <iostream>


Heyutu_svZeroAdder_sptr
Heyutu_make_svZeroAdder (size_t item_size, size_t nitems_per_block, size_t fft_length)
{
	return Heyutu_svZeroAdder_sptr (new Heyutu_svZeroAdder (item_size, nitems_per_block, fft_length));
}


Heyutu_svZeroAdder::Heyutu_svZeroAdder (size_t item_size, size_t nitems_per_block, size_t fft_length)
	: gr_sync_decimator ("svZeroAdder",
		gr_make_io_signature (1, 1, item_size),
		gr_make_io_signature (1, 1, item_size * fft_length),
		nitems_per_block), d_fft_length(fft_length), d_nitems_per_block(nitems_per_block), d_item_size(item_size)
{
}

// Interpolation Block: the number of input_items = noutput_items/interpolation
// input < output
// Decimation Block:  the number of input_items = noutput_items*decimation
// input > output

//int k=0;

int
Heyutu_svZeroAdder::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
  size_t zero_length = (d_fft_length - d_nitems_per_block)/2;

//  std::cout<<"Zero Length: "<<zero_length<<'\t'<<"FFT Length: "<<d_fft_length<<'\t'<<"nitems_per_block: "<<d_nitems_per_block<<std::endl;
 
//  std::cout<<d_nitems_per_block*d_item_size<<'\t'<<2*zero_length*d_item_size<<'\t'<<d_item_size*d_fft_length<<std::endl;
//  std::cout<<noutput_items<<std::endl;
//  std::cout<<sizeof(int)<<' '<<sizeof(char)<<' '<<d_item_size<<' '<<std::endl;

  size_t block_size = d_fft_length*d_item_size;

//  const gr_complex *in = (gr_complex *) input_items[0];
//  gr_complex *out = (gr_complex *) output_items[0];
  const char *in = (const char *) input_items[0];
  char *out = (char *) output_items[0];
//  const int *in = (const int *) input_items[0];
//  int *out = (int *) output_items[0];


//  memset(out, 0, block_size);

//  memcpy(out+zero_length*d_item_size, in, d_nitems_per_block*d_item_size);  // zero on the right position, do not edit

// All data = d_fft_length*d_item_size*noutput_items


//   size_t produced = 0;

//std::cout<<noutput_items<<std::endl;


for (int i=0; i<noutput_items;i++){
   memcpy(out+zero_length*d_item_size, in, d_nitems_per_block*d_item_size);
   out = out+d_fft_length*d_item_size;
   in = in + d_nitems_per_block*d_item_size;
//   std::cout<<k++<<std::endl;
//   produced = produced + d_fft_length;
}

//  memmove(out+zero_length*d_item_size, in, zero_length*d_item_size);
//  memcpy(out+block_size-d_nitems_per_block*d_item_size/2, in, d_nitems_per_block*d_item_size);
//  memcpy(out, in, d_nitems_per_block*d_item_size);
//  memcpy(out, in, d_nitems_per_block*d_item_size*noutput_items);
//  memcpy(out, in, block_size*noutput_items);


/*
for (int j=0; j<d_nitems_per_block; j++){
  for (int i=0; i<d_fft_length; i++){
	if (i<zero_length){
		out[i] = 0;
	}
	else if ((i>=zero_length)&&(i<zero_length+d_nitems_per_block)){
		out[i] = in[i-zero_length];
	}
	else
		out[i] = 0;
  }
}



for (int j=0; j<noutput_items; j++){
  for (int i=0; i<d_fft_length; i++){
	memcpy(out, in, d_item_size);
        in = in + d_item_size;
        out = out + d_item_size;
  }
}
*/

  return noutput_items;
//  return produced;
}

