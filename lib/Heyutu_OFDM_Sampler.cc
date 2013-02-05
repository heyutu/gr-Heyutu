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


int x=-1;
int y=0;

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
  int index = 0;

switch(d_state) {
	case (STATE_NS): {
	  index = d_fft_length;
	//  for (i=0; i<d_symbol_length+d_fft_length; i++)
	  while((d_state == STATE_NS) && (index <= (d_symbol_length+d_fft_length)))
	  {
		if (trigger[index] != 1){
			produced--;
			index++;
//			consume(1, noutput_items-produced);
			std::cout<<++y<<'\t'<<"Finding trigger ..."<<std::endl;
		}
		else{ 
			std::cout<<"d_state = STATE_SYM"<<'\t'<<std::endl;
	   		for(i = (index - d_symbol_length + 1); i <= index; i++) {
	   		   *optr++ = iptr[i];
//	   		   std::cout<<++y<<"!!!!!!!!!!!!!!!"<<std::endl;
	   		}
			d_state = STATE_SYM;
//			consume_each(index - d_fft_length + 1);
			consume(0, index - d_symbol_length + 1);
//			return 1;
		}
	  }
//	  break;	
	}


//  std::cout<<noutput_items<<'\t'<<produced<<'\t'<<*trigger<<std::endl;
//  std::cout<<*trigger<<'\t'<<delay<<std::endl;
	case  (STATE_SYM): {
	  for (int i = 0; i<produced; i++){
	//	*optr++ = *iptr++;
		*optr++ = iptr[index];
		if (trigger[index]==1)
	//		std::cout<<++x<<'\t'<<"*trigger == 1"<<std::endl;
	//	*o_trigger++ =  *trigger++;
		*o_trigger++ = trigger[index];
		index++;
	  }
	  consume_each (produced);
	  return produced;
	  break;
	}
}


//  iptr = iptr + 1;
/*
  int num = d_symbol_length;
  int d_trigger = 0;
  int m = 0;
  const float *p_trigger = trigger;
  while(i<produced){
//	if (*trigger == 1){
	if (d_state == STATE_SYM){
/*		p_trigger = trigger;
		d_trigger = 0;
		m = i;
		do{
//			*o_trigger++ =  *trigger++;
//			num++;
		std::cout<<x++<<'\t'<<"in while"<<std::endl;
			d_trigger++;
			m++;
		std::cout<<"*p_trigger: "<<*p_trigger++<<std::endl;
		}while((*p_trigger ==1)||(m+num>=produced));
		
		std::cout<<"d_trigger:"<<d_trigger<<std::endl;
/
		if (i+num<produced){
			for (int j = 0; j<num; j++){
				*optr++ = *iptr++;
				x = x + 2;
				if (*trigger==1)
					std::cout<<++y<<'\t'<<x<<'\t'<<"*trigger == 1"<<std::endl;
				*o_trigger++ =  *trigger++;
			}
			i = i+num;
//			num = 0;
		}
		else{
			int k = produced - i;
			for (int j = 0; j<k; j++){
				*optr++ = *iptr++;
				x = x + 2;
				if (*trigger==1)
					std::cout<<++y<<'\t'<<x<<'\t'<<"*trigger == 1"<<'\t'<<k<<std::endl;
				*o_trigger++ =  *trigger++;
			}
			i = i+k;
		}
	}
//	*o_trigger++ =  *trigger++;
  }
*/

/*
int j;
  while(i<produced){
//	if (*trigger==1){
		for (j = 0; j<d_symbol_length; j++){
			*optr++ = *iptr++;
			*o_trigger++ = *trigger++;
//			if (*trigger==1)
//				break;
		}
	i = i+j;
//	}
				
  }
*/
//  consume_each(noutput_items);
//  return produced;
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




