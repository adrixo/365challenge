#!/usr/bin/python


destination = open("destination.c", "w")

defsDict = {

}

writeline = True

with open("source.c", "r") as original:
    for line in original:

        #endif and else
        if line.startswith('#endif') or line.startswith('#else') :
            if line.startswith('#endif'):
                if writeline == False:
                    writeline = True
            if line.startswith('#else'):
                if writeline == False:
                    writeline = True
                else:
                    writeline = False
            continue

        if writeline == False:
            continue

        #if define
        if line.startswith('#ifdef'):
            arguments = line.split()
            for d in defsDict:
                if defsDict[d] == -1:
                    #is defined
                    writeline = True
                else:
                    writeline = False
            continue

        #define
        if line.startswith('#define'):
            arguments = line.split()
            if len(arguments) == 3:
                #has 2 arguments
                defsDict.update({ arguments[1] : arguments[2] })
            if len(arguments) == 2:
                #has only one
                defsDict.update({ arguments[1] : -1})
            continue

        #substition of a defined value
        for d in defsDict:
            if defsDict[d] != -1:
                if not line.startswith('#'):
                    line = line.replace(d, defsDict[d])

        #comment
        if line.find('//') != -1:
            destination.write( line[:line.find('//')-1] )
            destination.write("\n")
        else:
            destination.write(line)
