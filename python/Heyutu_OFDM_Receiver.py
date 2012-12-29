#!/usr/bin/env python
#
# Copyright 2007,2008 Free Software Foundation, Inc.
# 
# This file is part of GNU Radio
# 
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

import math
from gnuradio import gr
import Heyutu
from Heyutu import Heyutu_OFDM_Sync
from Heyutu import Heyutu_swig

class ofdm_receiver(gr.hier_block2):
    def __init__(self, fft_length, cp_length):


	gr.hier_block2.__init__(self, "ofdm_receiver",
				gr.io_signature(1, 1, gr.sizeof_gr_complex), # Input signature
                                gr.io_signature2(2, 2, gr.sizeof_gr_complex, gr.sizeof_float)) # Output signature

#	nco_sensitivity = -1.0/fft_length   # correct for fine frequency	
#	self.nco = gr.frequency_modulator_fc(nco_sensitivity)
#	self.sigmix = gr.multiply_cc()
#	self.sampler = Heyutu.OFDM_Sampler(fft_length, cp_length)
#	self.sync = Heyutu.Heyutu_OFDM_Sync.ofdm_sync_ml(fft_length, cp_length)
	
#	self.connect(self, self.sync)
#	self.connect((self.sync,0), self.nco, (self.sigmix,1))   # use sync freq. offset output to derotate input signal
#	self.connect(self, (self.sigmix,0))                 # signal to be derotated
#       self.connect(self.sigmix, (self.sampler,0))                   # sample off timing signal detected in sync alg
#      self.connect((self.sync,1), (self.sampler,1))            # timing signal to sample at

	
	self.sync = Heyutu.Heyutu_OFDM_Sync.ofdm_sync_ml(fft_length, cp_length)

	self.sampler = Heyutu.OFDM_Sampler(fft_length, cp_length)

	self.connect(self, self.sync)

	self.connect(self, (self.sampler,0))

	self.connect(self.sync, (self.sampler, 1))

	self.connect((self.sampler, 0), (self, 0))

	self.connect((self.sampler, 1), (self, 1))



