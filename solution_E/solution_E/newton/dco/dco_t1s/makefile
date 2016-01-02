CPPC=g++ -O3

main : dco_t1s_type.o main.o
	$(CPPC) -o $@ $^

%.o : %.cpp
	$(CPPC) -c -g $<

clean :
	rm -f *.o main 

