# # # # # # # # # # # # # # # # # # # # # # # # 
# 
#  python demo.py Directory_name File_Extension
#  
# # # # # # # # # # # # # # # # # # # # # # # # 



# # # # # # # # # # # # # # # # # # # # 
# 
# Name :- Kardile Siddharth Satish
#  
# # # # # # # # # # # # # # # # # # # # 

# # # # # # # # # # # # # # # # # # # # 
# 
#   Import Library
#  
# # # # # # # # # # # # # # # # # # # # 
from sys import argv
import os
import time

# # # # # # # # # # # # # # # # # # # # 
# 
#  Function for file finder
#  
# # # # # # # # # # # # # # # # # # # # 
def SRWF(DirName, file):
    print("We are going to scan the directory:", DirName)

    flag = os.path.isabs(DirName)
    if not flag:
        DirName = os.path.abspath(DirName)
    exist = os.path.isdir(DirName)

    fnm = "simple.txt"
    ans = os.path.join(DirName, fnm)
    
    # Create the file if it does not exist
    if not os.path.exists(fnm):
        try:
            with open(fnm, "w"):
                pass
        except Exception as e:
            print(f"Error creating file: {e}")
    
    if exist:
        separator = "-" * 80
        if os.path.exists(fnm):
            with open(fnm, "a") as fobj:  # Use 'with' statement to automatically close the file
                fobj.write(separator + "\n"+time.ctime()+"\n")
                if fobj:
                    for foldername, subfoldername, filenames in os.walk(DirName):
                        for fname in filenames:
                            a,b = os.path.splitext(fname)
                            if file == b:
                                aws = os.path.join(foldername,fname)
                                fobj.write(aws + "\n")        
                else:
                    print("Can't write file name into the file")
        else:
            print("File can't be created")
    else:
        print("Invalid path")
# # # # # # # # # # # # # # # # # # # # 
# 
#  Main Function who operate script
#  
# # # # # # # # # # # # # # # # # # # # 
def main():
    print("---------Siddharth File Finder Script---------")

    print("Automation Script Name:", argv[0])
    print("Your Directory Name is:", argv[1])
    print("Your File To Search:", argv[2])

    if len(argv) != 3:
        print("Invalid number of arguments")
        exit()

    if argv[1] in ("-h", "-H"):  # Flag for displaying the help
        print("This automation script is used for file search and writing paths to a file.")
        exit()
    elif argv[1] in ("-u", "-U"):  # Flag for displaying the usage of the script
        print("Usage: python Name_of_script Directory_Name File_Name")
        print("Example: python demo.py /path/to/directory example.txt")
        exit()
    else:
        starttime = time.time()

        SRWF(argv[1], argv[2])

        Endtime = time.time()
        print("The script took time to execute as:", Endtime - starttime)

        print("Thank You")

if __name__ == "__main__":
    main()
