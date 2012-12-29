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
#include <Heyutu_OFDM_Sampler.h>


Heyutu_OFDM_Sampler_sptr
Heyutu_make_OFDM_Sampler (unsigned int fft_length, unsigned int cp_length)
{
	return Heyutu_OFDM_Sampler_sptr (new Heyutu_OFDM_Sampler (fft_length, cp_length));
}


Heyutu_OFDM_Sampler::Heyutu_OFDM_Sampler (unsigned int fft_length, unsigned int cp_length)
	: gr_block ("ofdm_sampler",
	      gr_make_io_signature2 (2, 2, sizeof (gr_complex), sizeof(float)),
	      gr_make_io_signature2 (2, 2, sizeof (gr_complex), sizeof(float))),
   d_state(STATE_NS), d_fft_length(fft_length), d_cp_length(cp_length)
{
  set_relative_rate(1/float(fft_length+cp_length));   // buffer allocator hint
}

/*
void
Heyutu_OFDM_Sampler::forecast (int noutput_items, gr_vector_int &ninput_items_required)
{
  // FIXME do we need more
  int in_req  = noutput_items * (d_fft_length+d_cp_length);
//  int nreqd  = d_cp_length + d_fft_length;  //d_symbol_length=fft_length+cp_length
  unsigned ninputs = ninput_items_required.size ();
  for (unsigned i = 0; i < ninputs; i++)
    ninput_items_required[i] = in_req;
}
*/


int
Heyutu_OFDM_Sampler::general_work (int noutput_items,
			       gr_vector_int &ninput_items,
			       gr_vector_const_void_star &input_items,
			       gr_vector_void_star &output_items)
{

  int d_symbol_length = d_fft_length + d_cp_length;

  const gr_complex *iptr = (const gr_complex *) input_items[0];
  const float *trigger = (const float *) input_items[1];

  gr_complex *optr = (gr_complex *) output_items[0];
  float *o_trigger = (float *) output_items[1];

  
  size_t block_size = output_signature()->sizeof_stream_item (0);


/* // Do not edit !!!!!!

  for (int i = 0; i < noutput_items; i++){
//	memcpy(o_trigger, trigger, sizeof(float));
	
	if (*trigger==1){
		std::cout<<i<<'\t'<<*trigger<<std::endl;
		*o_trigger++ = *trigger++;
	}
	else{
	*o_trigger++=0;
	trigger++;
	}
  }
*/ // Do not edit !!!!!!


// std::cout<<flag<<std::endl;

  int i = 0;
  int produced = noutput_items;

if (d_state == STATE_NS) {
  for (i=0; i<d_symbol_length+d_fft_length; i++)
//  while(1)
  {
 	if (*trigger != 1){
		iptr++;
		trigger++;
		produced--;
	}
	else{ 
		d_state = STATE_SYM;
		break;
		
	}
  }
//  std::cout<<i<<"|||||||||||||||||||||||||||"<<std::endl;
  iptr = iptr - d_symbol_length+1;
}


  std::cout<<noutput_items<<'\t'<<produced<<std::endl;

for (int i = 0; i<produced; i++){
	*o_trigger++ = *trigger++;
	*optr++ = *iptr++;
}

  consume_each (noutput_items);
  return produced;
//  return noutput_items;



/*
  unsigned int n_in = (ninput_items[0]<ninput_items[1])?ninput_items[0]:ninput_items[1];
//  unsigned int n_in = ninput_items[0];
  unsigned int index = 0;
  unsigned int out = 0;

  switch (d_state) {
    case(STATE_NS):
      while (index<n_in && trigger[index] != 1){
        index++;
	*o_trigger++ = 0;
	}
      if (trigger[index] == 1){ 
        d_state = STATE_SYM;
	iptr = iptr - d_symbol_length+1;
	*o_trigger++ = *trigger++;
	}
      else
        break;
    case(STATE_SYM):
      if (index + d_symbol_length <= n_in) {
        memcpy(&optr[out], &iptr[index], d_symbol_length*sizeof(gr_complex));
        index += d_symbol_length;
        out += d_symbol_length;
        d_state = STATE_NS;
      }
      break;
  }
  std::cout<<index<<std::endl;
  consume_each(index);
  return out;
*/
}




