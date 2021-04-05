# PUSH_SWAP
42's project PUSH_SWAP
The algorithm used for size > 3 && <= 15 is kind of insertion sort.
The algorithm used for size > 15 is kind of quicksort, suitable for the stacks used in this project.
This project should not be used as a reference because it is not optimized.
Average number of strokes for a size of 100: 680 (can go above 700 in rare cases).
Average number of strokes for a size of 500: 5600 (may drop below 5500 in rare cases).

bash
make
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

The -f option with push_swap and checker allows to write/read instructions in a file.
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap -f file $ARG ; ./checker -f file $ARG

The -v option with checker allows you to display the status of the stacks each time.
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG

The -c option with checker displays the last instruction in color (goes with the -v option).
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v -c $ARG

-cvf works fine.
