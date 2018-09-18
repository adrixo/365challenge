#!/usr/bin/python

dependencies = {

}
# 1st value = issue
# 2nd < values = dependencies

tasks = {

}

line = "-"

while line != "":

    line = str(input(""))
    if line == "":
        break

    key = line.split(':')[0]
    dependenciesArray = line.split(':')[1].split()
    dependencies.update( {key:dependenciesArray} )

    tasks.update( {key:len(dependenciesArray)} )
    for t in dependenciesArray:
        try:
            tasks.update( {t:tasks[t]} )
        except:
            tasks.update( {t:0} )


i = 0
finish = False
while not finish:
    finish = True
    i +=1
    for d in tasks:
        if tasks[d] == 0:
            print(i,"task:", d)

            #delete it from dependencies / actualice task
            tasks.update( {d:-1} )

            for v in dependencies:
                try:
                    dependencies[v].remove(d)
                except:
                    print(end='')
                tasks.update( {v:len(dependencies[v])} )
        else:
            if tasks[d] != -1:
                finish = False
