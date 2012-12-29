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

//  std::cout<<"Zero Length: "<<zero_length<<'\t'<<"FFT Length: "<<d_fft_length<<'\t'<<"nitems_per_block: "<<d_nitems_per_block<<std::endl;
 
//  std::cout<<d_nitems_per_block*d_item_size<<'\t'<<2*zero_length*d_item_size<<'\t'<<d_item_size*d_fft_length<<std::endl;
//  std::cout<<noutput_items<<std::endl;

  size_t block_size = d_fft_length*d_item_size;

  const gr_complex *in = (gr_complex *) input_items[0];
  gr_complex *out = (gr_complex *) output_items[0];

//  memset(out, 0, block_size);

//  memcpy(out+zero_length*sizeof(gr_complex), in, d_nitems_per_block*d_item_size);
//  memcpy(out+zero_length*d_item_size, in, d_nitems_per_block*d_item_size);
//  memcpy(out+block_size-d_nitems_per_block*d_item_size/2, in, d_nitems_per_block*d_item_size);
  memcpy(out, in, d_nitems_per_block*d_item_size);
//  memcpy(out, in, block_size*noutput_items);


  return noutput_items;
}

