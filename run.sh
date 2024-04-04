#this file for run and compile program

pathcpp="main.cpp"
pathdir="bulid"

g++ main.cpp -o main

mv main ./bulid/main

chmod +x ./bulid/main

./bulid/main

echo ""
echo ""

#read -p "Press any key for end program..."

#clear
