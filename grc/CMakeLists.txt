# Copyright 2011 Free Software Foundation, Inc.
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
install(FILES
    Heyutu_QPSK_Mapper_vbc.xml
    Heyutu_OFDM_Mapper_bcv.xml
    Heyutu_OFDM_Modulator.xml
    Heyutu_OFDM_cyclic_prefixer.xml
    Heyutu_null_adder.xml
    Heyutu_zero_adder.xml
    Heyutu_svZeroAdder.xml
    Heyutu_OFDM_cyclic_deprefixer.xml
    Heyutu_OFDM_cyclic_deprefixer.xml
    Heyutu_svZeroAdder_inv.xml
    Heyutu_OFDM_Sampler.xml
    Heyutu_OFDM_Sync.xml
    Heyutu_OFDM_Receiver.xml
#    Heyutu_dab_ofdm_sampler.xml
    Heyutu_peak_detector_fb.xml
    Heyutu_symbol_finder_ff.xml DESTINATION share/gnuradio/grc/blocks
)
