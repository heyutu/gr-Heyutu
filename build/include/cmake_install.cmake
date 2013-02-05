# Install script for directory: /media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Heyutu" TYPE FILE FILES
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_api.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_QPSK_Mapper_vbc.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_OFDM_Mapper_bcv.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_OFDM_cyclic_prefixer.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_null_adder.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_zero_adder.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_svZeroAdder.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_OFDM_cyclic_deprefixer.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_svZeroAdder_inv.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_OFDM_Sampler.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_peak_detector_fb.h"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/include/Heyutu_symbol_finder_ff.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

