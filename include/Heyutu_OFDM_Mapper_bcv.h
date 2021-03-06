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

#ifndef INCLUDED_HEYUTU_OFDM_MAPPER_BCV_H
#define INCLUDED_HEYUTU_OFDM_MAPPER_BCV_H

#include <Heyutu_api.h>
#include <gr_sync_block.h>
#include <gr_message.h>
#include <gr_msg_queue.h>

class Heyutu_OFDM_Mapper_bcv;
typedef boost::shared_ptr<Heyutu_OFDM_Mapper_bcv> Heyutu_OFDM_Mapper_bcv_sptr;

HEYUTU_API Heyutu_OFDM_Mapper_bcv_sptr 
Heyutu_make_OFDM_Mapper_bcv (const std::vector<gr_complex> &constellation, unsigned msgq_limit, 
			      unsigned occupied_carriers, unsigned int fft_length);

/*!
 * \brief <+description+>
 *
 */
class HEYUTU_API Heyutu_OFDM_Mapper_bcv : public gr_sync_block
{
	friend HEYUTU_API Heyutu_OFDM_Mapper_bcv_sptr Heyutu_make_OFDM_Mapper_bcv (const std::vector<gr_complex> &constellation, unsigned msgq_limit, unsigned occupied_carriers, unsigned int fft_length);

 protected:

	Heyutu_OFDM_Mapper_bcv (const std::vector<gr_complex> &constellation, unsigned msgq_limit, 
			   unsigned occupied_carriers, unsigned int fft_length);

 private:
  std::vector<gr_complex> d_constellation;  //gr_complex.h  typedef std::complex<float> gr_complex
  gr_msg_queue_sptr	d_msgq;   //sptr  boost::shared_ptr<T> Class Template
  gr_message_sptr	d_msg;
  unsigned		d_msg_offset;
  bool			d_eof;
  
  unsigned int 		d_occupied_carriers;
  unsigned int 		d_fft_length;
  unsigned int 		d_bit_offset;
  int			d_pending_flag;

  unsigned long  d_nbits;
  unsigned char  d_msgbytes;
  
  unsigned char d_resid;
  unsigned int d_nresid;

  std::vector<int> d_subcarrier_map;

  int randsym();

 public:
	~Heyutu_OFDM_Mapper_bcv (void);

	gr_msg_queue_sptr	msgq() const { return d_msgq; }

	int work (int noutput_items,
		gr_vector_const_void_star &input_items,
		gr_vector_void_star &output_items);
};

#endif /* INCLUDED_HEYUTU_OFDM_MAPPER_BCV_H */

