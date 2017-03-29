# create a 'fork'
- point browser at https://github.com/SussexMPhys2016/go
- click on fork
- click on yourself

# clone repository and add upstream repository
mkdir MyLovelyReport
cd MyLovelyReport
git clone https://github.com/dorksquith/go (dorksquith->yourname!)

cd go/
git remote add upstream  https://github.com/SussexMPhys2016/go

# like svn up
git fetch upstream

cd Report

# basics - example for adding a figure. Always make before checking anything in!
git add figures/myfigure.pdf
git commit -m "checking in myfigure.pdf"
git push

# not sure what you added already?
git status



