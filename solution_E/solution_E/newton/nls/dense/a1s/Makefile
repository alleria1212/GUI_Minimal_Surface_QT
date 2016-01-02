newton :  newton.cpp residual_jacobian.cpp 
	ln -fs ../../../patterns patterns
	ln -fs ../../../gauss/gauss.hpp gauss.hpp
	ln -fs ../../../gauss/gauss.cpp gauss.cpp	
	ln -fs ../../residual.hpp residual.hpp
	ln -fs ../../sparsity_pattern.hpp sparsity_pattern.hpp
	ln -fs ../../sparsity_pattern.cpp sparsity_pattern.cpp	
	ln -fs ../../../dco/dco_a1s/dco_a1s_type.hpp dco_a1s_type.hpp
	ln -fs ../../../dco/dco_a1s/dco_a1s_type.cpp dco_a1s_type.cpp
	ln -fs ../../../utils/utils.hpp utils.hpp
	ln -fs ../../../utils/utils.cpp utils.cpp
	ln -fs ../../../dco/dco_timings.hpp
	g++ -g -O3 -o $@ *.cpp

clean:
	rm -fr newton; find -type l -delete;

.PHONY: clean
