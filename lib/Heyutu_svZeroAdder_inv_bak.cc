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
}
// Interpolation Block: the number of input_items = noutput_items/interpolation

int k=1;

int
Heyutu_svZeroAdder_inv::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
  size_t zero_length = (d_fft_length - d_nitems_per_block)/2;

  size_t produced = 0;

  size_t block_size = d_item_size;	// sizeof(gr_complex) * d_fft_length
//  size_t block_size = output_signature()->sizeof_stream_item (0);	//sizeof(gr_complex) = 8
//  std::cout<<block_size<<' '<<d_item_size<<' '<<sizeof(int)<<std::endl;

  const char *in = (const char *) input_items[0];
  char *out = (char *) output_items[0];
//  const gr_complex *in = (const gr_complex *) input_items[0];
//  gr_complex *out = (gr_complex *) output_items[0];

//  std::cout<<k++<<' '<<noutput_items<<' '<<noutput_items/d_fft_length<<' '<<d_nitems_per_block<<std::endl;
//  std::cout<<noutput_items/d_fft_length-(d_fft_length-d_nitems_per_block)<<std::endl;


/* 
  for (int i=0; i<noutput_items; i++){
    memcpy(out, in, block_size); 
     out = out + d_item_size;
     in = in + d_item_size;
  }
*/ //equals to memcpy (out, in, noutput_items * block_size);       DO NOT EDIT


/*
  in = in + zero_length*d_item_size;

  unsigned int i=0, j=0, p_input=0, p_output=0;
  while(i<noutput_items){
 
    for(j = 0; j<zero_length; j++){
      p_input++;
      i++;
    }
    for(j = 0; j<d_nitems_per_block; j++){
      out[p_output++] = in[p_input++];
      i++;
    }
    for(j = 0; j<(d_fft_length-d_nitems_per_block-zero_length); j++){
      p_input++;
      i++;
    }

  }
//  std::cout<<noutput_items*block_size<<' '<<noutput_items<<' '<<block_size<<' '<<p_output<<' '<<p_input<<std::endl;
  return noutput_items;
//  return p_output;
*/

  in = in + zero_length*d_item_size;
//for (int j=0; j<noutput_items/d_nitems_per_block; j++){
//for (int j=0; j<noutput_items/d_fft_length; j++){
int j=0;
do{
/*
  in = in + zero_length*d_item_size;
  for (int i=0; i<d_nitems_per_block; i++){
     memcpy(out, in, d_item_size);
     out = out + d_item_size;
     in = in + d_item_size;
//   std::cout<<j<<std::endl;
  }
   in = in+(d_fft_length-d_nitems_per_block-zero_length)*d_item_size;
*/

  memcpy(out, in, d_nitems_per_block*d_item_size);
  in = in+d_fft_length*d_item_size;
  out = out+d_nitems_per_block*d_item_size;
  produced += d_nitems_per_block;
//  std::cout<<j<<":\t"<<produced<<std::endl;
//  in = in+(d_fft_length-d_nitems_per_block-zero_length)*d_item_size;
  j++;
} while(j<noutput_items/d_fft_length);

//  memcpy (out, in, noutput_items * block_size);
//   in = in + zero_length*d_item_size;
//   for (int i=0; i<d_nitems_per_block; i++){
//    memcpy (out, in, noutput_items * block_size);
//    in = in + d_fft_length * d_item_size;
//    out = out + noutput_items * block_size;

  //} 
//  std::cout<<produced<<std::endl;
  return produced;  
//  return noutput_items;
//  return (noutput_items/d_fft_length-(d_fft_length-d_nitems_per_block))*d_fft_length;
//  return d_fft_length*d_nitems_per_block;


/*
  unsigned int i=0, j=0, k=0, p_input=0, p_output=0;
for (k=0; k<d_nitems_per_block; k++){
  for(i=0; i < noutput_items/d_nitems_per_block; i++) {
    for(j = 0; j<zero_length; j++){
      p_input++;
    }
    for(j = 0; j<d_nitems_per_block; j++){
      out[p_output++] = in[p_input++];
    }
    for(j = 0; j<d_fft_length-d_nitems_per_block-zero_length; j++){
      p_input++;
    }
  }
//    std::cout<<'#'<<k++<<'#'<<' '<<"out:"<<i<<'='<<out[i]<<' '<<"in:"<<j<<in[j]<<std::endl;
}
  std::cout<<p_output<<' '<<noutput_items<<' '<<d_fft_length<<' '<<p_input<<std::endl;


  return noutput_items;
*/
}

