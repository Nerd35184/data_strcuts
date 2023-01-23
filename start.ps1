rm test.exe
# ./test
gcc -g `
    main.tmp.c `
    sq_list.c `
    link_list.c `
    life_cycle.c `
    binary_tree.c `
    -o test `
    -Wall
./test.exe