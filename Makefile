CXX = g++
executable = HorseRacing
WINDOWS = false;

ifdef OS
	CXX = x86_64-w64-mingw32-g++
	executable = HorseRacing.exe
else
	ifeq ($(WINDOWS),true)
		CXX = x86_64-w64-mingw32-g++
		executable = HorseRacing.exe
	endif
endif

target: $(executable)

$(executable):
	$(CXX) src/*.cpp -Iinclude -o build/$(executable)
clean:
	rm build/$(executable)*
