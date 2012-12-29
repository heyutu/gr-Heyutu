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
		fft_length), d_fft_length(fft_length), d_nitems_per_block(nitems_per_block), d_item_size(item_size)
{
}


int
Heyutu_svZeroAdder::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
  size_t zero_length = (d_fft_length - d_nitems_per_block)/2;

  std::cout<<"Zero Length: "<<zero_length<<std::endl;
 
//  size_t block_size = output_signature()->sizeof_stream_item (0);
  size_t block_size = d_fft_length*d_item_size;
  
//  const gr_complex **inv = (const gr_complex **) &input_items[0];
  const gr_complex *in = (gr_complex *) input_items[0];
  gr_complex *out = (gr_complex *) output_items[0];


  gr_complex *temp = new gr_complex[block_size];
//  gr_complex *head = temp;
  memset(out, 0, block_size);
//  memset(temp, 0, block_size);
//  memcpy(temp,in, d_nitems_per_block*d_item_size);
//  memset(temp,0, zero_length*sizeof(gr_complex));
//  memset(temp+d_nitems_per_block*d_item_size,0, zero_length*sizeof(gr_complex));
//  memcpy(temp+zero_length*d_item_size, in, d_nitems_per_block*d_item_size);

//  memset(out,0, zero_length*sizeof(gr_complex));
//  memset(out+d_nitems_per_block*d_item_size,0, zero_length*sizeof(gr_complex));

// memcpy(out,in, noutput_items * block_size);
//  memcpy(out, in, d_nitems_per_block*d_item_size*noutput_items);

//  memcpy(out, in, block_size);
//  memcpy(out, temp, block_size);
  memcpy(out+zero_length*sizeof(gr_complex), in, d_nitems_per_block*d_item_size);

/*
  out = out+zero_length*sizeof(gr_complex);
  for (int i = 0; i < d_nitems_per_block; i++){
	memcpy(out, in, d_item_size);
//  	inv[i] += d_item_size;
    	out += d_item_size;
  }
*/
//  temp = head;
  

//  memset(temp+block_size/2-sizeof(gr_complex),0, 3*sizeof(gr_complex));

//  memcpy(temp, in, sizeof(gr_complex)*d_fft_length);
//  memmove(temp+zero_length, in, d_nitems_per_block*d_item_size);
//  memset(temp, 0, zero_length*d_item_size);
//  memcpy (temp, in, d_nitems_per_bolck * block_size);

//  memcpy (out, temp, noutput_items * block_size);

//  memcpy (out, in, noutput_items * block_size);

//  memcpy(out, temp, block_size);

  delete[] temp;


/*
  size_t item_size = input_signature()->sizeof_stream_item(0);

  const char **inv = (const char **) &input_items[0];
  char *out = (char *) output_items[0];


  for (int i = 0; i < d_nitems_per_block; i++){
    memcpy(out, inv[i], item_size);
    inv[i] += item_size;
    out += item_size;
  }

*/

  return noutput_items;
}

