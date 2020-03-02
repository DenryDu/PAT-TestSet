read -p "Enter the name of old project:" PName
cd $PName
touch "build.sh"
echo "g++ -g $PName.cpp -o $PName" >> build.sh
touch "run.sh"
echo "./$PName" >> run.sh
touch "gdb.sh"
echo "gdb $PName" >> gdb.sh
