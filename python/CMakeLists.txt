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
# Include python install macros
########################################################################
include(GrPython)
if(NOT PYTHONINTERP_FOUND)
    return()
endif()

########################################################################
# Install python sources
########################################################################
GR_PYTHON_INSTALL(
    FILES
    __init__.py
    Heyutu_OFDM_Sync.py
    Heyutu_OFDM_Receiver.py
    DESTINATION ${GR_PYTHON_DIR}/Heyutu
)

########################################################################
# Handle the unit tests
########################################################################
include(GrTest)

set(GR_TEST_TARGET_DEPS gnuradio-Heyutu)
set(GR_TEST_PYTHON_DIRS ${CMAKE_BINARY_DIR}/swig)
GR_ADD_TEST(qa_QPSK_Mapper_vbc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_QPSK_Mapper_vbc.py)
GR_ADD_TEST(qa_OFDM_Mapper_bcv ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_OFDM_Mapper_bcv.py)
GR_ADD_TEST(qa_OFDM_cyclic_prefixer ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_OFDM_cyclic_prefixer.py)
GR_ADD_TEST(qa_null_adder ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_null_adder.py)
GR_ADD_TEST(qa_zero_adder ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_zero_adder.py)
GR_ADD_TEST(qa_svZeroAdder ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_svZeroAdder.py)
GR_ADD_TEST(qa_OFDM_cyclic_deprefixer ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_OFDM_cyclic_deprefixer.py)
GR_ADD_TEST(qa_svZeroAdder_inv ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_svZeroAdder_inv.py)
GR_ADD_TEST(qa_OFDM_Sampler ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_OFDM_Sampler.py)
GR_ADD_TEST(qa_peak_detector_fb ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_peak_detector_fb.py)
GR_ADD_TEST(qa_symbol_finder_ff ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_Heyutu_symbol_finder_ff.py)
