read -p "Enter the name of new project:" PName
tag=".cpp"
mkdir $PName
cd $PName
touch "$PName$tag"
touch "build.sh"
echo "g++ -g $PName.cpp -o $PName" >> build.sh
touch "run.sh"
echo "./$PName" >> run.sh
touch "gdb.sh"
echo "gdb $PName" >> gdb.sh
