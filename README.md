tegaidogun at CHIBUDOM in ~/D/D/P/simple-algorithm-visualizer (main|✚14)
⋊  tree
.
├── include
│   ├── algorithms
│   │   ├── bubble_sort.h
│   │   ├── merge_sort.h
│   │   └── quick_sort.h
│   ├── data_structures
│   │   └── dynamic_array.h
│   ├── utils
│   │   ├── array_utils.h
│   │   └── timer.h
│   └── visualization
│       ├── graphics.h
│       └── visualizer.h
├── Makefile
├── README.md
├── src
│   ├── algorithms
│   │   ├── bubble_sort.c
│   │   ├── merge_sort.c
│   │   └── quick_sort.c
│   ├── data_structures
│   │   └── dynamic_array.c
│   ├── main.c
│   ├── utils
│   │   ├── array_utils.c
│   │   └── timer.c
│   └── visualization
│       ├── graphics.c
│       └── visualizer.c
this is a simple algorithm visualizer GUI project that im doing in C, lets fully go through what each part of of the program would do and talk about libraries being used in full and the functionality needed for everything to be robust

lets start form display graphics fully and properly, the application should create a window with a drop down option allowing me to select between the threee algorithm modes, and a start button, a randomize data button, it should have a dataset of 20 values represented in the form of vertical bars side by side and a spacing value I can adjust in code (only in code), dont support sorting functionality for now, i just want it to display something properly right now

make use of the visualization MODULE for implementing this

we will be implementing this in imgui

add support for passing values such as dataset and such here because REMEMBER THE WHOLE PROGRAM HAS TO MODULAR