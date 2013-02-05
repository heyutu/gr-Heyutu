
/*
 * This file was automatically generated using swig_doc.py.
 *
 * Any changes to it will be lost next time it is regenerated.
 */




%feature("docstring") Heyutu_null_adder "<+description+>"

%feature("docstring") Heyutu_null_adder::Heyutu_null_adder "

Params: (input_size, output_size)"

%feature("docstring") Heyutu_null_adder::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_null_adder "<+description+>

Params: (input_size, output_size)"

%feature("docstring") Heyutu_OFDM_cyclic_deprefixer "<+description+>"

%feature("docstring") Heyutu_OFDM_cyclic_deprefixer::Heyutu_OFDM_cyclic_deprefixer "

Params: (input_size, output_size)"

%feature("docstring") Heyutu_OFDM_cyclic_deprefixer::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_OFDM_cyclic_deprefixer "<+description+>

Params: (input_size, output_size)"

%feature("docstring") Heyutu_OFDM_cyclic_prefixer "<+description+>"

%feature("docstring") Heyutu_OFDM_cyclic_prefixer::Heyutu_OFDM_cyclic_prefixer "

Params: (input_size, output_size)"

%feature("docstring") Heyutu_OFDM_cyclic_prefixer::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_OFDM_cyclic_prefixer "<+description+>

Params: (input_size, output_size)"

%feature("docstring") Heyutu_OFDM_Mapper_bcv "<+description+>"

%feature("docstring") Heyutu_OFDM_Mapper_bcv::Heyutu_OFDM_Mapper_bcv "

Params: (constellation, msgq_limit, occupied_carriers, fft_length)"

%feature("docstring") Heyutu_OFDM_Mapper_bcv::randsym "

Params: (NONE)"

%feature("docstring") Heyutu_OFDM_Mapper_bcv::~Heyutu_OFDM_Mapper_bcv "

Params: ()"

%feature("docstring") Heyutu_OFDM_Mapper_bcv::msgq "

Params: (NONE)"

%feature("docstring") Heyutu_OFDM_Mapper_bcv::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_OFDM_Mapper_bcv "<+description+>

Params: (constellation, msgq_limit, occupied_carriers, fft_length)"

%feature("docstring") Heyutu_OFDM_Sampler "<+description+>"

%feature("docstring") Heyutu_OFDM_Sampler::Heyutu_OFDM_Sampler "

Params: (fft_length, cp_length)"

%feature("docstring") Heyutu_OFDM_Sampler::forecast "

Params: (noutput_items, ninput_items_required)"

%feature("docstring") Heyutu_OFDM_Sampler::general_work "

Params: (noutput_items, ninput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_OFDM_Sampler "<+description+>

Params: (fft_length, cp_length)"

%feature("docstring") Heyutu_peak_detector_fb "<+description+>"

%feature("docstring") Heyutu_peak_detector_fb::Heyutu_peak_detector_fb "

Params: (threshold_factor_rise, threshold_factor_fall, look_ahead, alpha)"

%feature("docstring") Heyutu_peak_detector_fb::~Heyutu_peak_detector_fb "

Params: (NONE)"

%feature("docstring") Heyutu_peak_detector_fb::set_threshold_factor_rise "Set the threshold factor value for the rise time.

Params: (thr)"

%feature("docstring") Heyutu_peak_detector_fb::set_threshold_factor_fall "Set the threshold factor value for the fall time.

Params: (thr)"

%feature("docstring") Heyutu_peak_detector_fb::set_look_ahead "Set the look-ahead factor.

Params: (look)"

%feature("docstring") Heyutu_peak_detector_fb::set_alpha "Set the running average alpha.

Params: (alpha)"

%feature("docstring") Heyutu_peak_detector_fb::threshold_factor_rise "Get the threshold factor value for the rise time.

Params: (NONE)"

%feature("docstring") Heyutu_peak_detector_fb::threshold_factor_fall "Get the threshold factor value for the fall time.

Params: (NONE)"

%feature("docstring") Heyutu_peak_detector_fb::look_ahead "Get the look-ahead factor value.

Params: (NONE)"

%feature("docstring") Heyutu_peak_detector_fb::alpha "Get the alpha value of the running average.

Params: (NONE)"

%feature("docstring") Heyutu_peak_detector_fb::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_peak_detector_fb "<+description+>

Params: (threshold_factor_rise, threshold_factor_fall, look_ahead, alpha)"

%feature("docstring") Heyutu_QPSK_Mapper_vbc "<+description+>"

%feature("docstring") Heyutu_QPSK_Mapper_vbc::Heyutu_QPSK_Mapper_vbc "

Params: (symbol_length)"

%feature("docstring") Heyutu_QPSK_Mapper_vbc::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_QPSK_Mapper_vbc "<+description+>

Params: (symbol_length)"

%feature("docstring") Heyutu_svZeroAdder "<+description+>"

%feature("docstring") Heyutu_svZeroAdder::Heyutu_svZeroAdder "

Params: (item_size, nitems_per_block, fft_length)"

%feature("docstring") Heyutu_svZeroAdder::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_svZeroAdder "<+description+>

Params: (item_size, nitems_per_block, fft_length)"

%feature("docstring") Heyutu_svZeroAdder_inv "<+description+>"

%feature("docstring") Heyutu_svZeroAdder_inv::Heyutu_svZeroAdder_inv "

Params: (item_size, nitems_per_block, fft_length)"

%feature("docstring") Heyutu_svZeroAdder_inv::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_svZeroAdder_inv "<+description+>

Params: (item_size, nitems_per_block, fft_length)"

%feature("docstring") Heyutu_symbol_finder_ff "<+description+>"

%feature("docstring") Heyutu_symbol_finder_ff::Heyutu_symbol_finder_ff "

Params: (fft_length, cp_length)"

%feature("docstring") Heyutu_symbol_finder_ff::~Heyutu_symbol_finder_ff "

Params: (NONE)"

%feature("docstring") Heyutu_symbol_finder_ff::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_symbol_finder_ff "<+description+>

Params: (fft_length, cp_length)"

%feature("docstring") Heyutu_zero_adder "<+description+>"

%feature("docstring") Heyutu_zero_adder::Heyutu_zero_adder "

Params: (input_size, output_size)"

%feature("docstring") Heyutu_zero_adder::work "

Params: (noutput_items, input_items, output_items)"

%feature("docstring") Heyutu_make_zero_adder "<+description+>

Params: (input_size, output_size)"

%feature("docstring") Heyutu_dab_make_ofdm_sampler "

Params: (fft_length, cp_length, symbols_per_frame, gap)"

%feature("docstring") std::allocator "STL class."

%feature("docstring") std::auto_ptr "STL class."

%feature("docstring") std::auto_ptr::operator-> "STL member.

Params: (NONE)"

%feature("docstring") std::bad_alloc "STL class."

%feature("docstring") std::bad_cast "STL class."

%feature("docstring") std::bad_exception "STL class."

%feature("docstring") std::bad_typeid "STL class."

%feature("docstring") std::basic_fstream "STL class."

%feature("docstring") std::basic_ifstream "STL class."

%feature("docstring") std::basic_ios "STL class."

%feature("docstring") std::basic_iostream "STL class."

%feature("docstring") std::basic_istream "STL class."

%feature("docstring") std::basic_istringstream "STL class."

%feature("docstring") std::basic_ofstream "STL class."

%feature("docstring") std::basic_ostream "STL class."

%feature("docstring") std::basic_ostringstream "STL class."

%feature("docstring") std::basic_string "STL class."

%feature("docstring") std::basic_stringstream "STL class."

%feature("docstring") std::bitset "STL class."

%feature("docstring") std::complex "STL class."

%feature("docstring") std::map::const_iterator "STL iterator class."

%feature("docstring") std::multimap::const_iterator "STL iterator class."

%feature("docstring") std::basic_string::const_iterator "STL iterator class."

%feature("docstring") std::set::const_iterator "STL iterator class."

%feature("docstring") std::multiset::const_iterator "STL iterator class."

%feature("docstring") std::string::const_iterator "STL iterator class."

%feature("docstring") std::vector::const_iterator "STL iterator class."

%feature("docstring") std::wstring::const_iterator "STL iterator class."

%feature("docstring") std::deque::const_iterator "STL iterator class."

%feature("docstring") std::list::const_iterator "STL iterator class."

%feature("docstring") std::map::const_reverse_iterator "STL iterator class."

%feature("docstring") std::multimap::const_reverse_iterator "STL iterator class."

%feature("docstring") std::set::const_reverse_iterator "STL iterator class."

%feature("docstring") std::basic_string::const_reverse_iterator "STL iterator class."

%feature("docstring") std::multiset::const_reverse_iterator "STL iterator class."

%feature("docstring") std::vector::const_reverse_iterator "STL iterator class."

%feature("docstring") std::string::const_reverse_iterator "STL iterator class."

%feature("docstring") std::deque::const_reverse_iterator "STL iterator class."

%feature("docstring") std::wstring::const_reverse_iterator "STL iterator class."

%feature("docstring") std::list::const_reverse_iterator "STL iterator class."

%feature("docstring") std::deque "STL class."

%feature("docstring") std::domain_error "STL class."

%feature("docstring") std::exception "STL class."

%feature("docstring") std::ios_base::failure "STL class."

%feature("docstring") std::fstream "STL class."

%feature("docstring") Heyutu_dab_ofdm_sampler "cuts stream of DAB samples into symbol vectors

input: port 0: complex - actual data; port 1: byte stream with trigger signal indicating the start of a frame output: port 0: complex vectors - sampled data; port 1: byte stream with trigger signal indicating the start of a frame"

%feature("docstring") Heyutu_dab_ofdm_sampler::Heyutu_dab_ofdm_sampler "

Params: (fft_length, cp_length, symbols_per_frame, gap)"

%feature("docstring") Heyutu_dab_ofdm_sampler::forecast "

Params: (noutput_items, ninput_items_required)"

%feature("docstring") Heyutu_dab_ofdm_sampler::general_work "

Params: (noutput_items, ninput_items, input_items, output_items)"

%feature("docstring") std::ifstream "STL class."

%feature("docstring") std::invalid_argument "STL class."

%feature("docstring") std::ios "STL class."

%feature("docstring") std::ios_base "STL class."

%feature("docstring") std::istream "STL class."

%feature("docstring") std::istringstream "STL class."

%feature("docstring") std::deque::iterator "STL iterator class."

%feature("docstring") std::set::iterator "STL iterator class."

%feature("docstring") std::basic_string::iterator "STL iterator class."

%feature("docstring") std::multiset::iterator "STL iterator class."

%feature("docstring") std::multimap::iterator "STL iterator class."

%feature("docstring") std::vector::iterator "STL iterator class."

%feature("docstring") std::string::iterator "STL iterator class."

%feature("docstring") std::wstring::iterator "STL iterator class."

%feature("docstring") std::list::iterator "STL iterator class."

%feature("docstring") std::map::iterator "STL iterator class."

%feature("docstring") std::length_error "STL class."

%feature("docstring") std::list "STL class."

%feature("docstring") std::logic_error "STL class."

%feature("docstring") std::map "STL class."

%feature("docstring") std::multimap "STL class."

%feature("docstring") std::multiset "STL class."

%feature("docstring") std::ofstream "STL class."

%feature("docstring") std::ostream "STL class."

%feature("docstring") std::ostringstream "STL class."

%feature("docstring") std::out_of_range "STL class."

%feature("docstring") std::overflow_error "STL class."

%feature("docstring") std::priority_queue "STL class."

%feature("docstring") std::queue "STL class."

%feature("docstring") std::range_error "STL class."

%feature("docstring") std::map::reverse_iterator "STL iterator class."

%feature("docstring") std::list::reverse_iterator "STL iterator class."

%feature("docstring") std::wstring::reverse_iterator "STL iterator class."

%feature("docstring") std::set::reverse_iterator "STL iterator class."

%feature("docstring") std::deque::reverse_iterator "STL iterator class."

%feature("docstring") std::multiset::reverse_iterator "STL iterator class."

%feature("docstring") std::basic_string::reverse_iterator "STL iterator class."

%feature("docstring") std::vector::reverse_iterator "STL iterator class."

%feature("docstring") std::string::reverse_iterator "STL iterator class."

%feature("docstring") std::multimap::reverse_iterator "STL iterator class."

%feature("docstring") std::runtime_error "STL class."

%feature("docstring") std::set "STL class."

%feature("docstring") std::smart_ptr "STL class."

%feature("docstring") std::smart_ptr::operator-> "STL member.

Params: (NONE)"

%feature("docstring") std::stack "STL class."

%feature("docstring") std::string "STL class."

%feature("docstring") std::stringstream "STL class."

%feature("docstring") std::underflow_error "STL class."

%feature("docstring") std::unique_ptr "STL class."

%feature("docstring") std::unique_ptr::operator-> "STL member.

Params: (NONE)"

%feature("docstring") std::valarray "STL class."

%feature("docstring") std::vector "STL class."

%feature("docstring") std::weak_ptr "STL class."

%feature("docstring") std::weak_ptr::operator-> "STL member.

Params: (NONE)"

%feature("docstring") std::wfstream "STL class."

%feature("docstring") std::wifstream "STL class."

%feature("docstring") std::wios "STL class."

%feature("docstring") std::wistream "STL class."

%feature("docstring") std::wistringstream "STL class."

%feature("docstring") std::wofstream "STL class."

%feature("docstring") std::wostream "STL class."

%feature("docstring") std::wostringstream "STL class."

%feature("docstring") std::wstring "STL class."

%feature("docstring") std::wstringstream "STL class."