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

#ifndef INCLUDED_HEYUTU_ZERO_ADDER_H
#define INCLUDED_HEYUTU_ZERO_ADDER_H

#include <Heyutu_api.h>
#include <gr_sync_block.h>
#include <stdio.h>

class Heyutu_zero_adder;
typedef boost::shared_ptr<Heyutu_zero_adder> Heyutu_zero_adder_sptr;

HEYUTU_API Heyutu_zero_adder_sptr Heyutu_make_zero_adder (size_t input_size, size_t output_size);

/*!
 * \brief <+description+>
 *
 */
class HEYUTU_API Heyutu_zero_adder : public gr_sync_block
{
	friend HEYUTU_API Heyutu_zero_adder_sptr Heyutu_make_zero_adder (size_t input_size, size_t output_size);

 protected:

	Heyutu_zero_adder (size_t input_size, size_t output_size);

 private:
	size_t d_input_size;
	size_t d_output_size;

 public:

	int work (int noutput_items,
		gr_vector_const_void_star &input_items,
		gr_vector_void_star &output_items);
};

#endif /* INCLUDED_HEYUTU_ZERO_ADDER_H */

