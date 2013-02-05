# Install script for directory: /media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/grc/blocks" TYPE FILE FILES
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_QPSK_Mapper_vbc.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_OFDM_Mapper_bcv.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_OFDM_Modulator.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_OFDM_cyclic_prefixer.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_null_adder.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_zero_adder.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_svZeroAdder.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_OFDM_cyclic_deprefixer.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_OFDM_cyclic_deprefixer.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_svZeroAdder_inv.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_OFDM_Sampler.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_OFDM_Sync.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_OFDM_Receiver.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_peak_detector_fb.xml"
    "/media/8f69c2e0-5d53-4852-be18-edf06675b7bb/home/heyutu/Masterarbeit/gnuradio/gnuradio/gr-Heyutu/grc/Heyutu_symbol_finder_ff.xml"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

