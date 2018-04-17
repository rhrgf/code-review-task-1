main: main.cpp tools.cpp
	$(CXX) $(CFLAGS) $? $(LDFLAGS) -o $(@)

test: tools_test.cpp tools.cpp
	$(CXX) $(CFLAGS) $? $(LDFLAGS) -o $(@)
	-./$(@)
	rm $(@)

clean: main
	rm main
