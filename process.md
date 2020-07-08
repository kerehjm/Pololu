https://waterproofman.wordpress.com/2007/02/07/avr-interrupts-in-c/

stk500

/dev/tty.MathewsBeatsStudio3-SPP	/dev/tty.usbmodem000700031
/dev/tty.MathewsBeatsStudio3-Wir	/dev/tty.usbmodem000700033
screen /dev/tty.usbmodem000700031 9600


avrdude -c stk500 -P /dev/tty.usbmodem000700033 -p atmega328p -U flash:w:pololu.hex

avrdude -p m328p -c stk500 -P /dev/tty.usbmodem000700031 -U flash:w:pololu.hex

avrdude -p m328p -c stk500 -P /dev/tty.usbmodem000700031 -U flash:w:pololu.hex

6qptgr57z6d2ki73ttjxsewnbljvbpgmsjvafg64ig32bp4oc45a

6qptgr57z6d2ki73ttjxsewnbljvbpgmsjvafg64ig32bp4oc45a

attr -c vsts-agent-osx-x64-2.170.1.tar.gz

https://www.avrfreaks.net/forum/missing-debug-symbols-after-linking

https://github.com/CppCon/CppCon2017/blob/master/Tutorials/Using%20Modern%20CMake%20Patterns%20to%20Enforce%20a%20Good%20Modular%20Design/Using%20Modern%20CMake%20Patterns%20to%20Enforce%20a%20Good%20Modular%20Design%20-%20Mathieu%20Ropert%20-%20CppCon%202017.pdf


https://github.com/CppCon/CppCon2017

https://stackoverflow.com/questions/23995019/what-is-the-modern-method-for-setting-general-compile-flags-in-cmake

https://cliutils.gitlab.io/modern-cmake/modern-cmake.pdf

http://mariobadr.com/creating-a-header-only-library-with-cmake.html


cmake .. -DCMAKE_CXX_STANDARD=14 -DCMAKE_CXX_COMPILER=avr-g++ -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_CLANG_TIDY="clang-tidy;-checks=*;-fix"

cmake .. -DCMAKE_CXX_STANDARD=14 -DCMAKE_CXX_COMPILER=g++ -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_BUILD_TYPE=Debug


cmake -DCMAKE_CXX_CLANG_TIDY="clang-tidy;-checks=*;-fix" ..

https://askubuntu.com/questions/355565/how-do-i-install-the-latest-version-of-cmake-from-the-command-line

http://www.mariobadr.com/using-clang-tidy-with-cmake-36.html


https://stackoverflow.com/questions/3065154/undefined-reference-to-vtable/3065223#3065223

