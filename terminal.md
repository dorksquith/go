##### Tips and hints for mac terminal
###### ... and (probably?) windows cmd

Open a terminal by going to spotlight, typing terminal, and then clicking the black window icon. Now you can type commands on the _command line_.


1. Print Working Directory : this tells you the path of where you are right now:

```
pwd
```

2. List contents of working directory : passing the argument -l gives you extra info. Putting man before any command just shows you the manual for that command. To exit the man page ctrl-x-z.

```
ls
ls -l
man ls
```

3. Make a Directory called TestFolder1 in the current working directory :

```
mkdir TestFolder1
```


4. Change Directory (navigate) to the directory you just made, or to home (~/ means home), or to desktop, or to the directory you were in last :

```
cd TestFolder1
cd ~/
cd ~/Desktop
cd -
```

5. Launch python on the command line

```
python
```

6. Now you can play around in python. To end the python session ctrl-d

```
print("Hello") # press enter and Hello will be printed
a=3 # press enter
b=4 # press enter
a*b # press enter and a*b will be printed
sin(a) # press enter and you will get an error message saying python doesn't know what sin is.
import numpy as np # press enter
np.sin(a) # press enter and sin(3) will be printed
```




