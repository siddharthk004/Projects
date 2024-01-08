from sys import *
import os
import hashlib
import time

def DeleteFiles(dict1):
    results = list(filter(lambda x: len(x) > 1,dict1.values()))
    
    icnt = 0
    ifound = 0
    if len(results) > 0:
        for result in results:
            for subresult in result:
                icnt += 1
                if icnt >= 2:
                    os.remove(subresult)
                    ifound+=1
            icnt = 0
        print("number of duplicate file found : ",ifound)
    else:
        print("no duplicate files are found")
    
def hashfile(path,blocksize = 1024):
    afile = open(path,'rb')
    hasher = hashlib.md5()
    buf = afile.read(blocksize)

    while len(buf) > 0:
        hasher.update(buf)
        buf = afile.read(blocksize)
    afile.close()
    
    return hasher.hexdigest()

def findDup(path):
    flag = os.path.isabs(path)
    
    if flag == False:
        path = os.path.abspath(path)
        
        exists = os.path.isdir(path)
        
        dups = {}
        
        if exists:
            for dirname,subdirs,fileList in os.walk(path):
                print("current folder is : "+dirname)
                for filen in fileList:
                    path = os.path.join(dirname,filen)
                    file_hash = hashfile(path)
                    
                    if file_hash in dups:
                        dups[file_hash].append(path)
                    else:
                        dups[file_hash] = [path]
                    
        return dups
    else:
        print("invalid path")

def PrintResults(dict1):
    ifound = 0
    results = list(filter(lambda x: len(x) > 1,dict1.values()))
    
    if len(results) > 0:
        print("Duplicate found")
        print("the following file are duplicate")
        for result in results:
            for subresult in result:
                print('\t\t%s'%subresult)                
                ifound+=1
        print("number of duplicate file found : ",ifound)
    else:
        print("no duplicate file are found")
        
def main():
    print("----------Siddharth Kardile-----------")
    
    print("Application name : "+argv[0])
    
    if(len(argv) != 2):
        print("Error : Invalid number of arguments")
        exit()
        
    if(argv[1] == "-h") or (argv[1] == "-H"):
        print("this script is used to traverse specific directory and delete duplicate files")
        exit()
            
    elif(argv[1] == "-u" or argv[1] == "-U"):
        print("usage : ApplicationName  AbsolutePath_of_Directory Extension")
        exit()
        
    try:
        arr = {}
        startTime = time.time()
        arr = findDup(argv[1])
        PrintResults(arr)
        #DeleteFiles(arr)
        endTime = time.time()
        
        print('Took %s Seconds to evalute.'%(endTime-startTime))
    
    except ValueError:
        print("Error : Invalid datatype of input")
        
    except Exception as E:
        print("Error : Invalid input",E)
        
if __name__ == "__main__":
    main()