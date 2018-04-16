main: main.cpp tools.cpp
	$(CXX) $(CFLAGS) $? $(LDFLAGS) -o $(@)

clean: main
	rm main
