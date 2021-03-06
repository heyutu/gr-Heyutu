#!/usr/bin/env python

import math
from gnuradio import gr
from Heyutu import Heyutu_swig
import gnuradio.gr.gr_threading as _threading


class OFDM_Modulator(gr.hier_block2):
    """
    Modulates an OFDM stream. Based on the options fft_length, occupied_tones, and
    cp_length, this block creates OFDM symbols using a specified modulation option.
    
    Send packets by calling send_pkt
    """
    def __init__(self, fft_length, occupied_tones, msgq_limit=2):	#__init__ 在类的实例创建后被立即调用
	#Options参数从higher layer传递
        """
	Hierarchical block for sending packets

        Packets to be sent are enqueued by calling send_pkt.
        The output is the complex modulated signal at baseband.

        @param options: pass modulation options from higher layers (fft length, occupied tones, etc.) 
        @param msgq_limit: maximum number of messages in message queue
        @type msgq_limit: int
        @param pad_for_usrp: If true, packets are padded such that they end up a multiple of 128 samples
        """

	#gr_hier_block2::self()	 Return an object, representing the current block, which can be passed to connect.
	gr.hier_block2.__init__(self, "OFDM_Modulator",
				gr.io_signature(0, 0, 0),	# Input signature
				gr.io_signature(1, 1, gr.sizeof_gr_complex))	# Output signature

        self._fft_length = fft_length
        self._occupied_tones = occupied_tones
        self._cp_length = cp_length
	self._modulation = options.modulation



        win = [] #[1 for i in range(self._fft_length)]
         
        #symbol_length = fft_length + cp_length

 	symbol_length = options.fft_length + options.cp_length
        
        mods = {"bpsk": 2, "qpsk": 4, "8psk": 8, "qam8": 8, "qam16": 16, "qam64": 64, "qam256": 256}   # define Dictionary key:value
        arity = mods[self._modulation]	#从dictionary的key获得value	arity = {2,4,8,16,64,256}
        
        rot = 1
        if self._modulation == "qpsk":
            rot = (0.707+0.707j)
            
        # FIXME: pass the constellation objects instead of just the points
        if(self._modulation.find("psk") >= 0):	# str.find() return the lowest index in the string
            constel = psk.psk_constellation(arity)	#gnuradio.digital.psk.psk_constellation(m=4, mod_code='gray'), Creates a PSK constellation object.
            rotated_const = map(lambda pt: pt * rot, constel.points())	# print map.__doc__ Return a list of the results of applying the function to the items of the argument sequence(s).
        elif(self._modulation.find("qam") >= 0):
            constel = qam.qam_constellation(arity)	#gnuradio.digital.qam.qam_constellation(constellation_points=16, differential=True, mod_code='none')
            rotated_const = map(lambda pt: pt * rot, constel.points())


	# !!!!!!!!!!!!!!调用digital_make_ofdm_mapper_bcv?!!!!!!!!!!!!!!
        self.mapper = Heyutu_swig.OFDM_Mapper_bcv(rotated_const,
                                                       msgq_limit,
                                                       options.occupied_tones,
                                                       options.fft_length)
   
	# !!!!!!!!!!!!!!调用gr_fft_vcc?!!!!!!!!!!!!!!
	#fft_vcc_fftw::fft_vcc_fftw(int fft_size, bool forward, const std::vector<float> &window, bool shift, int nthreads=1)
        self.ifft = gr.fft_vcc(self._fft_length, False, win, True)
	# !!!!!!!!!!!!!!调用digital_make_ofdm_cyclic_prefixer?!!!!!!!!!!!!!!!!!!!!!
        self.cp_adder = Heyutu_swig.OFDM_cyclic_prefixer(self._fft_length, symbol_length)
        self.scale = gr.multiply_const_cc(1.0 / math.sqrt(self._fft_length))
        
	# void gr_hier_block2::connect(gr_basic_block_sptr src, int src_port, gr_basic_block_sptr dst, int dst_port)
        self.connect(self.ifft, self.cp_adder, self.scale, self)	# ???
  
