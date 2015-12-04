1. command lines 

simulation:

./simulation -x 50 -w 10 -y 4 -i set_test.params -s 2000 -S 0.01 -M 1 -V 600 -Y 600 -Z 600 -Q 600 -K 600 -r gradient1.txt -u perturb.txt -t -D output -L 1


things to know:

-V -Y -Z -Q -K are for specifing the induction point of overexperrion of different genes. Detailed information is in main.cpp and init.cpp.

"gradient1.txt" is the default gradient file. "gradient25.txt" should be used when the mesp genes start expressing at 25th column(by default they start at 30th column). "gradient60.txt" should be used when the total width of the tissue is set to 60.





sres (on cluster):

sample job submission file:

#PBS -N sres_15_one_mutant
#PBS -l nodes=1:ppn=10
#PBS -q biomath
#PBS -M jye@colgate.edu
#PBS -m bea
#PBS -j oe
#PBS -r n

cd $PBS_O_WORKDIR


mpirun -np 10 ./sres -r fguess.ranges -g 1200 -p 100 -P 15 -a -x 50 -w 10 -y 4 -M 1 -V 600 -Y 600 -Z 600 -Q 600 -K 600 -r ../simulation/gradient1.txt -u ../simulation/perturb.txt > output2.txt


things to know:

You should compile the sres on the cluster using command "scons mpi=1" in order to use parallel version.

fguess.ranges is the default range file.

biomath cluster can only handle simulation with less than 3 mutants due to insufficient memory. If you need to run with more mutants, ask Patrick Holloway for permission to another machine.








2. printing output


To change the output species for .cons files, change the print_con veriable in struct mutant_data in struct.cpp.

To change the output species for .cells files, change TWO lines in the function print_cell_columns in io.cpp.
time_point[line * ip.num_colls_print + col] = cl.cons[CMMESPA][time][line * sd.width_total + cur_col];






3. Python scripts for plotting.

plot_two.py: plot two different species in the same graph, (usually) use .cells file:
python plot_two.py -c filename1 filename2 folder sth sth



plot-snapshots-two.py: create snapshots of the tissue that contains expression level of two species, use .cons file:
python plot-snapshots-two.py filename1 filename2 folder

ffmpeg: create movie using snapshots created plot-tissue-snapshots.py or plot-snapshots-two.py:
ffmpeg -y -r 38 -i directory/%04d.png -qscale 5 -b 9600 name_of_movie 


refine-ranges.py: range-ranges based to specified range file and parameter sets file.
python refine-ranges.py -s params -c ranges -n new_ranges



















