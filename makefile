main: main.cpp
	$(CXX) $(CFLAGS) $? $(LDFLAGS) -o $(@)

clean: main
	rm main
