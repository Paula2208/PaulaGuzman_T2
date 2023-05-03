# Entries ##############
problem="2d"
#######################
gcc ./src/resolver/Generator$problem.c -o ./src/out/Generator$problem
./src/out/Generator$problem

# run in linux, wsl or macOS terminal
#If a permissions problem run chmod a=rwx ./run.sh in the folder