# <exectable-filename>: <dependent-filenames1>
#      g++ <dependent-filenames1> -o <executable-filename>

# <dependent-filename1>: <.cpp files>
#      g++ <.cpp> -I/<include-path> -L<library-path> -l<library>

# clean:
#      rm *.o <other-files>

final: main.o message.o
	g++ main.o message.o -o final

main.o: main.cpp
	g++ -c main.cpp

message.o: message.cpp message.h
	g++ -c message.cpp

clean:
	rm *.o final
