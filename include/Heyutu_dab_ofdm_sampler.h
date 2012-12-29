/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef INCLUDED_HEYUTU_DAB_OFDM_SAMPLER_H
#define INCLUDED_HEYUTU_DAB_OFDM_SAMPLER_H

#include <gr_block.h>

class Heyutu_dab_ofdm_sampler;

typedef boost::shared_ptr<Heyutu_dab_ofdm_sampler> Heyutu_dab_ofdm_sampler_sptr;

Heyutu_dab_ofdm_sampler_sptr Heyutu_dab_make_ofdm_sampler (unsigned int fft_length, unsigned int cp_length, unsigned int symbols_per_frame, unsigned int gap);

/*!
 * \brief cuts stream of DAB samples into symbol vectors
 * \ingroup DAB
 * \param fft_length length of the output vectors - number of samples per symbol without cyclic prefix
 * \param cp_length lengith of the cyclic prefix
 * \param symbols_per_frame number of symbols in a DAB frame, without Null symbol
 * \param gap If the gap is > 0, leave a gap at the end of the symbol, i.e. return some of the cyclic prefix instead of the end of the symbol
 *
 * input: port 0: complex - actual data; port 1: byte stream with trigger signal indicating the start of a frame
 * output: port 0: complex vectors - sampled data; port 1: byte stream with trigger signal indicating the start of a frame
 */
class Heyutu_dab_ofdm_sampler : public gr_block
{
  private:
    // The friend declaration allows Heyutu_dab_make_ofdm_sampler to
    // access the private constructor.

    friend Heyutu_dab_ofdm_sampler_sptr Heyutu_dab_make_ofdm_sampler (unsigned int fft_length, unsigned int cp_length, unsigned int symbols_per_frame, unsigned int gap);

    Heyutu_dab_ofdm_sampler (unsigned int fft_length, unsigned int cp_length, unsigned int symbols_per_frame, unsigned int gap);    // private constructor

    enum state_t {STATE_NS, STATE_CP, STATE_SYM};

    state_t d_state;
    unsigned int d_pos;                     // position inside OFDM symbol
    unsigned int d_fft_length;
    unsigned int d_cp_length;
    unsigned int d_symbols_per_frame;       // total number of symbols in a DAB frame
    unsigned int d_sym_nr;                  // number of symbol inside DAB frame
    unsigned int d_gap;                     // gap from next symbol -> if gap>0: sample before end of frame
    unsigned int d_gap_left;                // gap left to next symbol?

  public:
    void forecast (int noutput_items, gr_vector_int &ninput_items_required);

    int general_work (int noutput_items,
                      gr_vector_int &ninput_items,
                      gr_vector_const_void_star &input_items,
                      gr_vector_void_star &output_items);
};

#endif /* INCLUDED_DAB_OFDM_SAMPLER_H */
