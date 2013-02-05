# Copyright 2011 Free Software Foundation, Inc.
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
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX
add_library(gnuradio-Heyutu SHARED Heyutu_svZeroAdder.cc Heyutu_QPSK_Mapper_vbc.cc Heyutu_OFDM_Mapper_bcv.cc Heyutu_OFDM_cyclic_prefixer.cc Heyutu_null_adder.cc Heyutu_zero_adder.cc Heyutu_OFDM_cyclic_deprefixer.cc Heyutu_svZeroAdder_inv.cc Heyutu_OFDM_Sampler.cc Heyutu_peak_detector_fb.cc Heyutu_symbol_finder_ff.cc)# Heyutu_dab_ofdm_sampler.cc )
target_link_libraries(gnuradio-Heyutu ${Boost_LIBRARIES} ${GRUEL_LIBRARIES} ${GNURADIO_CORE_LIBRARIES})
set_target_properties(gnuradio-Heyutu PROPERTIES DEFINE_SYMBOL "gnuradio_Heyutu_EXPORTS")

########################################################################
# Install built library files
########################################################################
install(TARGETS gnuradio-Heyutu
    LIBRARY DESTINATION lib${LIB_SUFFIX} # .so/.dylib file
    ARCHIVE DESTINATION lib${LIB_SUFFIX} # .lib file
    RUNTIME DESTINATION bin              # .dll file
)

########################################################################
# Build and register unit test
########################################################################
find_package(Boost COMPONENTS unit_test_framework)

include(GrTest)
set(GR_TEST_TARGET_DEPS gnuradio-Heyutu)
#turn each test cpp file into an executable with an int main() function
add_definitions(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN)

add_executable(qa_Heyutu_QPSK_Mapper_vbc qa_Heyutu_QPSK_Mapper_vbc.cc)
target_link_libraries(qa_Heyutu_QPSK_Mapper_vbc gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_QPSK_Mapper_vbc qa_Heyutu_QPSK_Mapper_vbc)

add_executable(qa_Heyutu_OFDM_Mapper_bcv qa_Heyutu_OFDM_Mapper_bcv.cc)
target_link_libraries(qa_Heyutu_OFDM_Mapper_bcv gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_OFDM_Mapper_bcv qa_Heyutu_OFDM_Mapper_bcv)

add_executable(qa_Heyutu_OFDM_cyclic_prefixer qa_Heyutu_OFDM_cyclic_prefixer.cc)
target_link_libraries(qa_Heyutu_OFDM_cyclic_prefixer gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_OFDM_cyclic_prefixer qa_Heyutu_OFDM_cyclic_prefixer)

add_executable(qa_Heyutu_null_adder qa_Heyutu_null_adder.cc)
target_link_libraries(qa_Heyutu_null_adder gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_null_adder qa_Heyutu_null_adder)

add_executable(qa_Heyutu_zero_adder qa_Heyutu_zero_adder.cc)
target_link_libraries(qa_Heyutu_zero_adder gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_zero_adder qa_Heyutu_zero_adder)

add_executable(qa_Heyutu_svZeroAdder qa_Heyutu_svZeroAdder.cc)
target_link_libraries(qa_Heyutu_svZeroAdder gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_svZeroAdder qa_Heyutu_svZeroAdder)

add_executable(qa_Heyutu_OFDM_cyclic_deprefixer qa_Heyutu_OFDM_cyclic_deprefixer.cc)
target_link_libraries(qa_Heyutu_OFDM_cyclic_deprefixer gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_OFDM_cyclic_deprefixer qa_Heyutu_OFDM_cyclic_deprefixer)

add_executable(qa_Heyutu_svZeroAdder_inv qa_Heyutu_svZeroAdder_inv.cc)
target_link_libraries(qa_Heyutu_svZeroAdder_inv gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_svZeroAdder_inv qa_Heyutu_svZeroAdder_inv)

add_executable(qa_Heyutu_OFDM_Sampler qa_Heyutu_OFDM_Sampler.cc)
target_link_libraries(qa_Heyutu_OFDM_Sampler gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_OFDM_Sampler qa_Heyutu_OFDM_Sampler)

add_executable(qa_Heyutu_peak_detector_fb qa_Heyutu_peak_detector_fb.cc)
target_link_libraries(qa_Heyutu_peak_detector_fb gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_peak_detector_fb qa_Heyutu_peak_detector_fb)

add_executable(qa_Heyutu_symbol_finder_ff qa_Heyutu_symbol_finder_ff.cc)
target_link_libraries(qa_Heyutu_symbol_finder_ff gnuradio-Heyutu ${Boost_LIBRARIES})
GR_ADD_TEST(qa_Heyutu_symbol_finder_ff qa_Heyutu_symbol_finder_ff)
