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

#ifndef INCLUDED_HEYUTU_OFDM_SAMPLER_H
#define INCLUDED_HEYUTU_OFDM_SAMPLER_H

#include <Heyutu_api.h>
#include <gr_block.h>

class Heyutu_OFDM_Sampler;
typedef boost::shared_ptr<Heyutu_OFDM_Sampler> Heyutu_OFDM_Sampler_sptr;

HEYUTU_API Heyutu_OFDM_Sampler_sptr Heyutu_make_OFDM_Sampler (unsigned int fft_length, unsigned int cp_length);

/*!
 * \brief <+description+>
 *
 */
class HEYUTU_API Heyutu_OFDM_Sampler : public gr_block
{
	friend HEYUTU_API Heyutu_OFDM_Sampler_sptr Heyutu_make_OFDM_Sampler (unsigned int fft_length, unsigned int cp_length);

	Heyutu_OFDM_Sampler (unsigned int fft_length, unsigned int cp_length);

 private:
//  	enum state_t {STATE_NO_SIG, STATE_FRAME, STATE_PREAMBLE};
	enum state_t {STATE_NS, STATE_CP, STATE_SYM};
	state_t d_state;

    unsigned int d_fft_length;
    unsigned int d_cp_length;


 public:

  void forecast (int noutput_items, gr_vector_int &ninput_items_required);

  int general_work (int noutput_items,
		    gr_vector_int &ninput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items);
};

#endif /* INCLUDED_HEYUTU_OFDM_SAMPLER_H */

