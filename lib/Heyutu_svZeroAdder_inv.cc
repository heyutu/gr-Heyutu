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
#include <Heyutu_svZeroAdder_inv.h>
#include <string.h>

#include <iostream>


Heyutu_svZeroAdder_inv_sptr
Heyutu_make_svZeroAdder_inv (size_t item_size, size_t nitems_per_block, size_t fft_length)
{
	return Heyutu_svZeroAdder_inv_sptr (new Heyutu_svZeroAdder_inv (item_size, nitems_per_block, fft_length));
}


Heyutu_svZeroAdder_inv::Heyutu_svZeroAdder_inv (size_t item_size, size_t nitems_per_block, size_t fft_length)
	: gr_sync_interpolator ("svZeroAdder_inv",
		gr_make_io_signature (1, 1, item_size * fft_length),
		gr_make_io_signature (1, 1, item_size),
		nitems_per_block), d_fft_length(fft_length), d_nitems_per_block(nitems_per_block), d_item_size(item_size)
{
//  std::cout<<"svZeroAdder_inv block created..."<<std::endl;
}
// Interpolation Block: the number of input_items = noutput_items/interpolation

// Decimation Block:  the number of input_items = noutput_items*decimation = noutput_items*nitems_per_block

// The number of items produced is returned, this can be less than noutput_items


int
Heyutu_svZeroAdder_inv::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
  size_t zero_length = (d_fft_length - d_nitems_per_block)/2;

  const char *in = (const char *) input_items[0];
  char *out = (char *) output_items[0];

/*
  std::cout<<noutput_items<<std::endl;

  size_t block_size = output_signature()->sizeof_stream_item (0);
//  memcpy (out, in, noutput_items * block_size);

  std::cout<<block_size<<'\t'<<d_nitems_per_block*d_item_size<<std::endl;
  memcpy(out, in,d_item_size*noutput_items);

  int j=0;
  std::cout<<++k<<'\t'<<noutput_items<<std::endl;
  for (int i=0; i<noutput_items;i++){
     memcpy(out, in+zero_length*d_item_size, d_nitems_per_block*d_item_size);
     out = out + d_nitems_per_block*d_item_size;
     in = in+d_fft_length*d_item_size;
     std::cout<<j++<<"###########################"<<std::endl;
  }
  std::cout<<"++++++++++++++++++++++++++++++++++"<<std::endl;
*/


// for the Interpolation block
//  std::cout<<'#'<<noutput_items<<std::endl;
  int produced=0;
  for (int i=0; i<noutput_items/d_fft_length; i++){

     memcpy(out, in+zero_length*d_item_size, d_nitems_per_block*d_item_size);
     out = out + d_nitems_per_block*d_item_size;
     in = in + d_fft_length*d_item_size;
     produced = produced + d_nitems_per_block;
  }
  
//  std::cout<<produced<<'\t'<<noutput_items<<std::endl;
  return produced;  
//  return noutput_items;

/*

// for the Decimation block
  std::cout<<'#'<<noutput_items<<std::endl;
  int produced=0;	
  for (int i=0; i<noutput_items; i++){

     memcpy(out, in+zero_length*d_item_size, d_nitems_per_block*d_item_size);
     out = out + d_nitems_per_block*d_item_size;
     in = in + d_fft_length*d_item_size;
     produced = produced + d_nitems_per_block;
  }
  std::cout<<produced<<'\t'<<noutput_items<<std::endl;
  return produced;
*/
/*

// for the Synchronous block
  std::cout<<'#'<<noutput_items<<std::endl;
  int produced=0;	
  for (int i=0; i<noutput_items/d_fft_length; i++){
     
     memcpy(out, in+zero_length*d_item_size, d_nitems_per_block*d_item_size);
     out = out + d_nitems_per_block*d_item_size;
     in = in + d_fft_length*d_item_size;
     produced = produced + d_nitems_per_block;
  }
  std::cout<<produced<<'\t'<<noutput_items<<std::endl;
  return produced;
*/
}

