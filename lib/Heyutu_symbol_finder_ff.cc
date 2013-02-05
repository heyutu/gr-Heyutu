/* -*- c++ -*- */
/* 
 * Copyright 2013 <+YOU OR YOUR COMPANY+>.
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
#include <Heyutu_symbol_finder_ff.h>


Heyutu_symbol_finder_ff_sptr
Heyutu_make_symbol_finder_ff (size_t fft_length, size_t cp_length)
{
	return Heyutu_symbol_finder_ff_sptr (new Heyutu_symbol_finder_ff (fft_length, cp_length));
}


Heyutu_symbol_finder_ff::Heyutu_symbol_finder_ff (size_t fft_length, size_t cp_length)
	: gr_sync_block ("symbol_finder_ff",
		gr_make_io_signature (1, 1, sizeof (float)),
		gr_make_io_signature (1, 1, sizeof (float))),
	d_fft_length(fft_length),
	d_cp_length(cp_length)
{
}


Heyutu_symbol_finder_ff::~Heyutu_symbol_finder_ff ()
{
}

bool find = false;
int remain = 0;
int
Heyutu_symbol_finder_ff::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
	const float *in = (const float *) input_items[0];
	float *out = (float *) output_items[0];

  	memset(out, 0, noutput_items*sizeof(float));
	int i = 0;
	int delay = 0;
	int sum = noutput_items;

	std::cout<<"noutput_items  "<<noutput_items<<std::endl;


	if (find && (remain != 0)){
		i = d_fft_length + d_cp_length - remain;
		sum = sum - remain;
	}

	std::cout<<"sum  "<<sum<<std::endl;

	std::cout<<"+++++++++++++++++++++++++++"<<std::endl;

	while (i < noutput_items){
		if (find == false){
			if (not in[i]){
//				out[i] = 0;
				i++;
				sum--;
			}
			else{
//				out[i] = 1;
				find = true;
				delay = i;
				std::cout<<"delay   "<<delay<<std::endl;
//				i = i + d_fft_length + d_cp_length;
			}
			
		}
		else{
/*
			if (((i-delay+remain)%(d_fft_length+d_cp_length))==0){
				out[i] = 1;
				sum = sum - d_fft_length - d_cp_length;
			}
			else{
				remain = sum;
				out[i] = 0;
			}
*/
		out[i] = 1;
		i = i + d_fft_length + d_cp_length;
		if (sum - d_fft_length - d_cp_length >0){
			sum = sum - d_fft_length - d_cp_length;
		}
		std::cout<<sum<<std::endl;
		}

//	out[i] = in[i];

//	std::cout<<in[i]<<std::endl;
	}

	remain = sum;
	std::cout<<"remain   "<<remain<<std::endl;

/*
  for (i=0; i<noutput_items;i++){
     memcpy(out, in, sizeof(float));
     out = out+sizeof(float);
     in = in + sizeof(float);
  }
*/
	// Tell runtime system how many output items we produced.
	return noutput_items;
}
