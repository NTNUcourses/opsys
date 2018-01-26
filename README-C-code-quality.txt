https://en.wikipedia.org/wiki/List_of_tools_for_static_code_analysis
+ Stack Overflow


eksempel thread0.c

gcc -Wall 

cppcheck --enable=all ./thread0.c

clang-tidy-5.0 -checks='*' thread0.c -- -std=c11

valgrind --leak-check=yes ./thread0

valgrind --tool=helgrind ./thread0
