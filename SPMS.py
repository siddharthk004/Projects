# # # # # # # # # # # # # # # # # 

# Name :- Kardile siddharth satish

# # # # # # # # # # # # # # # # # 

import getpass  
import os 
USER_NAME = getpass.getuser()
import time  
import psutil 
import urllib.request as urllib2 
import smtplib 
import schedule  
from sys import *  
from email import encoders 
from email.mime.text import MIMEText 
from email.mime.base import MIMEBase 
from email.mime.multipart import MIMEMultipart 

def is_connected():
    try:
        urllib2.urlopen('http://216.58.192.142',timeout=1)
        return True
    except urllib2.URLError as err:
        return True
    
def MailSender(Filename,time):
    try:
        fromaddr = "studentdemo9850@gmail.com"
        toaddr = "pradipdarkunde86@gmail.com"
        
        msg = MIMEMultipart()
        msg['From'] = fromaddr
        msg['To'] = toaddr
        
        body = """
        Hello,
        -- Siddharth --
        
        Welcome to the SLMS .
        Siddharth and Our Company will congrats to you for choosing our application        
        please find attached document which contain log of Running processes
        
        Virtual Process Log file is created at : %s
        
        This Mail is auto generated mail so this mail contains all your process
        file that are executed on your machine please read the process name 
        that you know who will use your machine in your absense
        
        Again thank you from Siddharth
        
        Thanks & Regards,
        Kardile Siddharth Satish
           ... SPMS System...
        """ %(time)
        
        Subject = """
        --  Siddharth Process Mail System  --
        """
        
        msg['Subject'] = Subject
        msg.attach(MIMEText(body,'plain'))
        attachment = open(Filename,"rb")
        P = MIMEBase('application','octet-stream')
        P.set_payload((attachment).read())
        encoders.encode_base64(P)
        P.add_header('Content-Disposition',"attachment : filename")
        msg.attach(P)
        s = smtplib.SMTP('smtp.gmail.com',587)
        s.ehlo()
        s.starttls()
        s.login(fromaddr,"fyrg tlbt epht syzs")
        text = msg.as_string()
        s.sendmail(fromaddr,toaddr,text)
        s.quit()
        
        print("Log File is Successfully Sent Through Mail")
        
    except Exception as E:
        print("Sorry : Unable to send mail.",E)

def processlog(log_dir = 'Siddharth'):
    listprocess = []
    
    if not os.path.exists(log_dir):
        try:
            os.mkdir(log_dir)
        except:
            pass
        
    separator = "-"*80 
    log_path = os.path.join(log_dir,"SiddharthLog%s.txt"%(time.time()))
    f = open(log_path,'w')
    f.write(separator+"\n")
    f.write("Siddharth kardile process logger : "+time.ctime()+"\n")
    f.write(separator+"\n")
    f.write("\n")
    
    for proc in psutil.process_iter():
        try:
            pinfo = proc.as_dict(attrs=['pid','name','username'])
            listprocess.append(pinfo);
        
        except(psutil.NoSuchProcess,psutil.AccessDenied,psutil.ZombieProcess):
            pass
      
    for element in listprocess:
        f.write("%s\n"% element)

    connected = is_connected()
    
    if connected:
        startTime = time.time()
        try: 
            schedule.every(10).minutes.do(MailSender(log_path,time.ctime()))
            while True:
                schedule.run_pending()
                time.sleep(1)
            
        except ValueError:
            print("Error : Invalid datatype of input")
            
        except Exception as E:
            print("Error : Invalid input",E)
            
        endTime = time.time()        
        print("Took %s seconds to send mail "%(endTime-startTime))
    else:
        print("there is no internet connection")
    
def add_to_startup():
        try: 
            schedule.every(1).minutes.do(processlog)
            while True:
                schedule.run_pending()
                time.sleep(1)
            
        except ValueError:
            print("Error : Invalid datatype of input")
            
        except Exception as E:
            print("Error : Invalid input",E)

def main():
    print("This is Laptop Function call \n")
    print("Minimise it using  -  this Symbol   Thank you \n")
    add_to_startup()
    
if __name__ == "__main__":
    main()