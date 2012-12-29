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

// 采样点时钟完全正确 可以消除延迟

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
   d_fft_length(fft_length),
   d_cp_length(cp_length),
   d_state(STATE_NO_SIG)
{
   set_relative_rate(1.0/(double) fft_length);   // buffer allocator hint
}
/*
void
Heyutu_OFDM_Sampler::forecast (int noutput_items, gr_vector_int &ninput_items_required)
{
  // FIXME do we need more
  //int nreqd  = (noutput_items-1) * d_symbol_length + d_fft_length;
  int nreqd  = d_cp_length + d_fft_length;  //d_symbol_length=fft_length+cp_length
  unsigned ninputs = ninput_items_required.size ();
  for (unsigned i = 0; i < ninputs; i++)
    ninput_items_required[i] = nreqd;
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
//  size_t block_size_1 = output_signature()->sizeof_stream_item (1);  // sizeof(float)

//  std::cout<<noutput_items<<'\t'<<block_size_1<<'\t'<<sizeof(float)<<std::endl;


  unsigned int index = 0;

//  memcpy (o_trigger, trigger, noutput_items * block_size_1);


/*
for (int i = 0; i<noutput_items; i = i+1){
//  while(index <= (d_symbol_length)) {
	std::cout<<"index:   "<<index<<'\t'<<"Trigger: "<<trigger[index]<<std::endl;
    if(*trigger) {
      std::cout<<"++++++++++++++++++++++"<<std::endl;
      o_trigger[index] = 1;
//      break;
    }
    else
      index++;
 }
*/

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
  // Do not edit !!!!!!

// std::cout<<flag<<std::endl;
*/
  int i = 0;
  int produced = noutput_items;
  int j = 0;
if (d_state == STATE_NO_SIG) {
  for (i=0; i<d_symbol_length+d_fft_length; i++){
	if (*trigger != 1){
		j++;
		iptr++;
		trigger++;
		produced--;
	}
	else{ 
		d_state = STATE_FRAME;
		break;
		
	}
  }
  std::cout<<i<<std::endl;
  iptr = iptr - d_symbol_length+1;
}


  std::cout<<noutput_items<<std::endl;
//  memcpy(o_trigger, trigger, (produced)*sizeof(float));
//  memcpy(optr, iptr, (produced)*sizeof(gr_complex));

for (int i = 0; i<produced; i++){
	*o_trigger++ = *trigger++;
	*optr++ = *iptr++;
}



/*
  while (i < noutput_items){
//	memcpy(o_trigger, trigger, sizeof(float));
	
//	if (*trigger==1){
//		std::cout<<i<<'\t'<<*trigger<<std::endl;
		*o_trigger++ = *trigger++;
//		for (int j = 0; j<d_symbol_length; j++){
			*optr++ = *iptr++;
//			produced++;
//		}
//		memcpy(optr, iptr, d_symbol_length*sizeof(gr_complex));
//		optr = optr+d_symbol_length;
//		iptr = iptr+d_symbol_length;
		i = i++;
//	}
//	else{
//	*o_trigger++=0;
//	trigger++;
//	*optr++ = *iptr++;
//	iptr++;
//	optr++;
//	i++;
//	}
  }
*/
//  std::cout<<"index:   "<<index<<std::endl;
  
/*
  int pos = index;
 while(pos < d_symbol_length) {
      *optr++ = iptr[pos++];
    }

  if (*trigger){
	for (int i=0; i<d_symbol_length; i++){
		*optr++ = *iptr++;
		trigger++;
	}
//	memcpy(optr, iptr, d_symbol_length*sizeof(gr_complex)*noutput_items);
//	optr = optr+d_symbol_length*sizeof(gr_complex)*noutput_items;
//	iptr = iptr+d_symbol_length*sizeof(gr_complex)*noutput_items;
	std::cout<<j++<<'\t'<<*trigger<<"++++++++++++++++++++++++++++"<<std::endl;
  }
  else{
	iptr++;
	trigger++;
  }
*/

 

//  if (trigger[index])
//  	memcpy (optr, iptr, noutput_items * block_size);	
  // Tell runtime system how many input items we consumed on
  // each input stream.
  consume_each (noutput_items);
//  consume_each(d_symbol_length-index);
//  std::cout<<"noutput_items: "<<noutput_items<<'\t'<<"Trigger: "<<*trigger<<std::endl;

  // Tell runtime system how many output items we produced.
  return produced;
//  return noutput_items;
}

