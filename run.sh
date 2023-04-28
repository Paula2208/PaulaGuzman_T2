# Entries ##############
problem="A"
#######################
chmod a=rwx ./ci_cd.sh
gcc ./src/resolver/problem$problem.c -o ./src/out/problem$problem
./src/out/problem$problem

# run in linux, wsl or macOS terminal
#If a permissions problem run chmod a=rwx ./run.sh in the folder