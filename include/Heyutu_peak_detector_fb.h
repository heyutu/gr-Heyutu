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

#ifndef INCLUDED_HEYUTU_PEAK_DETECTOR_FB_H
#define INCLUDED_HEYUTU_PEAK_DETECTOR_FB_H

#include <Heyutu_api.h>
#include <gr_sync_block.h>

class Heyutu_peak_detector_fb;
typedef boost::shared_ptr<Heyutu_peak_detector_fb> Heyutu_peak_detector_fb_sptr;

HEYUTU_API Heyutu_peak_detector_fb_sptr Heyutu_make_peak_detector_fb (float threshold_factor_rise = 0.25,
				 float threshold_factor_fall = 0.40,
				 int look_ahead = 10,
				 float alpha = 0.001);

/*!
 * \brief <+description+>
 *
 */
class HEYUTU_API Heyutu_peak_detector_fb : public gr_sync_block
{
	friend HEYUTU_API Heyutu_peak_detector_fb_sptr Heyutu_make_peak_detector_fb (float threshold_factor_rise,
					  float threshold_factor_fall,
					  int look_ahead, float alpha);

	Heyutu_peak_detector_fb (float threshold_factor_rise,
	  float threshold_factor_fall,
	  int look_ahead, float alpha);

  private:
	  float d_threshold_factor_rise;
	  float d_threshold_factor_fall;
	  int d_look_ahead;
	  float d_avg_alpha;
	  float d_avg;
	  unsigned char d_found;

 public:
	~Heyutu_peak_detector_fb ();

/*! \brief Set the threshold factor value for the rise time
   *  \param thr new threshold factor
   */
  void set_threshold_factor_rise(float thr) { d_threshold_factor_rise = thr; }

  /*! \brief Set the threshold factor value for the fall time
   *  \param thr new threshold factor
   */
  void set_threshold_factor_fall(float thr) { d_threshold_factor_fall = thr; }

  /*! \brief Set the look-ahead factor
   *  \param look new look-ahead factor
   */
  void set_look_ahead(int look) { d_look_ahead = look; }

  /*! \brief Set the running average alpha
   *  \param alpha new alpha for running average
   */
  void set_alpha(int alpha) { d_avg_alpha = alpha; }

  /*! \brief Get the threshold factor value for the rise time
   *  \return threshold factor
   */
  float threshold_factor_rise() { return d_threshold_factor_rise; }

  /*! \brief Get the threshold factor value for the fall time
   *  \return threshold factor
   */
  float threshold_factor_fall() { return d_threshold_factor_fall; }

  /*! \brief Get the look-ahead factor value
   *  \return look-ahead factor
   */
  int look_ahead() { return d_look_ahead; }

  /*! \brief Get the alpha value of the running average
   *  \return alpha
   */
  float alpha() { return d_avg_alpha; }

	int work (int noutput_items,
		gr_vector_const_void_star &input_items,
		gr_vector_void_star &output_items);
};

#endif /* INCLUDED_HEYUTU_PEAK_DETECTOR_FB_H */

