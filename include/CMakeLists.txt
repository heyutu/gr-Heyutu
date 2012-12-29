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

########################################################################
# Install public header files
########################################################################
install(FILES
    Heyutu_api.h
    Heyutu_QPSK_Mapper_vbc.h
    Heyutu_OFDM_Mapper_bcv.h
    Heyutu_OFDM_cyclic_prefixer.h
    Heyutu_null_adder.h
    Heyutu_zero_adder.h
    Heyutu_svZeroAdder.h
    Heyutu_OFDM_cyclic_deprefixer.h
    Heyutu_svZeroAdder_inv.h
    Heyutu_OFDM_Sampler.h
#    Heyutu_dab_ofdm_sampler.h 
	DESTINATION include/Heyutu
)
