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

#ifndef INCLUDED_HEYUTU_SYMBOL_FINDER_FF_H
#define INCLUDED_HEYUTU_SYMBOL_FINDER_FF_H

#include <Heyutu_api.h>
#include <gr_sync_block.h>

class Heyutu_symbol_finder_ff;
typedef boost::shared_ptr<Heyutu_symbol_finder_ff> Heyutu_symbol_finder_ff_sptr;

HEYUTU_API Heyutu_symbol_finder_ff_sptr Heyutu_make_symbol_finder_ff (size_t fft_length, size_t cp_length);

/*!
 * \brief <+description+>
 *
 */
class HEYUTU_API Heyutu_symbol_finder_ff : public gr_sync_block
{
	friend HEYUTU_API Heyutu_symbol_finder_ff_sptr Heyutu_make_symbol_finder_ff (size_t fft_length, size_t cp_length);

	Heyutu_symbol_finder_ff (size_t fft_length, size_t cp_length);

 private:
	
	size_t d_fft_length;
	size_t d_cp_length;

 public:
	~Heyutu_symbol_finder_ff ();


	int work (int noutput_items,
		gr_vector_const_void_star &input_items,
		gr_vector_void_star &output_items);
};

#endif /* INCLUDED_HEYUTU_SYMBOL_FINDER_FF_H */

