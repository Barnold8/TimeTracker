# TimeTracker
This is a program that helps track allocated time for modules in a semester for university. It is a CLI tool that will read data written by the user and inform them on what they need to improve on and how they can allocate their time.

# How to build

You can use the ``python build.py`` file to automatically compile the program and run it on your system. Alternitavely you can use the already compiled file (its compiled on debian linux) or you can compile it by hand with `` gcc main.c fileRDR.c dataSTRUC.c -Wall -pedantic-errors -o main``

# How to run

Once the program has been compiled you can use ``./main`` to run the program. As of right now the program takes no arguments to do anything different, if this changes, a section on command line arguments will be added

# How the data file works

To keep it simple, I decided that a module should have three attributes:

```
Module name
Module credits
Module hours completed
```

The module hours to complete are 100 hours per 10 credits as per the system my university suggets (this may be different for other universities and I could implement a config file structure later)

A sample file may look like

```
Module One
10
0
Module Two
20
23
Module Three
10
10
EOF
```

Note: EOF is needed at the end of the file to ensure that the file is valid and the data within it isnt corrupted, this is far from fullproof but I found it was adequate enough.
