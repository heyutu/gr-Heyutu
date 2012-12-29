"""
QPSK modulation.

"""

from gnuradio import gr
from Heyutu import Heyutu_swig



class Heyutu_QPSK_Mapper(gr.hier_block2):

	def __init__(self, params):

		gr.hier_block2.__init__(self, "Heyutu_QPSK_Mapper",
				gr.io_signature(1, 1, gr.sizeof_char),       # Input signature
				gr.io_signature(1, 1, gr.sizeof_gr_complex)) # Output signature

		self.mapper = Heyutu_swig.QPSK_Mapper_vbc(params.symbol_length)

		self.connect((self,0), self.mapper)

