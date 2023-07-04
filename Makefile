CXX = g++
executable = HorseRacing

target: $(executable)

$(executable):
	$(CXX) src/*.cpp -Iinclude -o build/$(executable)

clean:
	rm build/$(executable)