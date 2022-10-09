import os 
import sys

source = [x for x in os.listdir(".") if ".c" in x]
buildStr = ""

for elem in source:
    buildStr += elem + " "

args = sys.argv[::-1]
args.pop()

comms = []
pedantic = False


for v in args:

    if v.lower() == "-vv":
        os.system("valgrind -s --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./main")
        exit()
    if v.lower() == "-p":
        pedantic = True
    
    if v.lower() == "-v":
        comms.append("valgrind -s --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./main")


if pedantic:
    comms.append("gcc {} -Wall -pedantic -g -o main && ./main".format(buildStr))
else:
    comms.append("gcc {} -g -o main && ./main".format(buildStr))

for i in range(len(comms)):
    comms.append(comms.pop(i))

#print(comms)

for elem in comms:
     
    os.system(elem)


#f = "gcc {} -Wall -pedantic -g -o main && ./main".format(buildStr)
#os.system(f)

#if len(sys.argv) > 1:
#    if sys.argv[1].lower() == "-v":
#        os.system("valgrind -s --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./main")
