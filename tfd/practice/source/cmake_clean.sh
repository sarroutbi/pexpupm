test -f Makefile && make clean
rm -fr cmake_install.cmake
rm -fr src/cmake_install.cmake
rm -fr test/cmake_install.cmake
rm -fr CMakeFiles
rm -fr src/CMakeFiles
rm -fr test/CMakeFiles
rm -fr CMakeCache*
rm -fr Makefile
find . -iname "*~" -print | xargs rm -fr
