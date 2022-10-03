import os
import sys

source = [x for x in os.listdir(".") if ".c" in x]
buildStr = ""

for elem in source:
    buildStr += elem + " "

f = "gcc {} -Wall -pedantic-errors -o main && ./main".format(buildStr)
os.system(f)

if len(sys.argv) > 1:
    if sys.argv[1].lower() == "-v":
        os.system("valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./main")
