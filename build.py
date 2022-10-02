import os


source = [x for x in os.listdir(".") if ".c" in x]
buildStr = ""

for elem in source:
    buildStr += elem + " "

f = "gcc {} -Wall -pedantic-errors -o main && ./main".format(buildStr)
os.system(f)

