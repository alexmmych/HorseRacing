CXX = g++
executable = HorseRacing

target: $(executable)

$(executable):
	mkdir build
	$(CXX) src/*.cpp -Iinclude -o build/$(executable)

clean:
	rm build/$(executable)
