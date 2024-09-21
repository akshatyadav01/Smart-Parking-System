import serial

import time
import datetime as dt
import mysql.connector as m
import pywhatkit



my=m.connect(host="localhost",user="root",database="parking_system",password="85246")
mc=my.cursor()
ads=serial.Serial('com3',9600)
time.sleep(1)
i=1
while(True):
    


    while(ads.in_waiting==0):
        pass
    
    fid='FT1632'
    sl="12A"


    pack=ads.readline()
    pack=str(pack,'utf-8')
    pack=pack.strip('\r\n')
    if(pack=="Entry"):
        if(i>1):

            q="select name,last_name,mobile_no,HSRP_no from fastagdatabase where fastagid='{}'".format(fid)
            mc.execute(q)
            name,surname,mob,vno=mc.fetchone()

            ct=dt.datetime.now()
            year=ct.year
            mo=ct.month
            day=ct.day
            hour=ct.hour
            minute=ct.minute
            msg1="Dear "+name+" "+" "+surname+" your Parking spot is 31A alloted at "+str(hour)+":"+str(minute)+" IST, Please park at alloted spot only. Parking system Rajwada "
        
            pywhatkit.sendwhatmsg("+91"+mob,msg1,hour,minute+1)
            q2="update Parking_Rajwada set state='filled',name='{}',surname='{}',vehicle_no='{}',mobile='{}',etime_hour='{}',etime_minute='{}',fastag_id='{}' where slot='{}'".format(name,surname,vno,mob,hour,minute,fid,sl)
            mc.execute(q2)
            my.commit()
            print(msg1)
        
        
        
        
        print("done1")
            
            
    if(pack=="Exit"):
        if(i>1):

            q1=f"select name,surname,vehicle_no,mobile,etime_hour,etime_minute from parking_rajwada where fastag_id='{fid}'"
            mc.execute(q1)
            name,surname,vno,mob,eth,etm=mc.fetchone()
            ct1=dt.datetime.now()
            year=ct1.year
            mo=ct1.month
            day=ct1.day
            exth=ct1.hour
            extm=ct1.minute
            #amt=+str(((eth-exth)*0.5+((etm-extm)*0.5))
            date1=str(day)+'/'+str(mo)+'/'+str(year)
            msg2="Mr "+name+" "+surname+" ,\nYour charges for parking from \n"+str(eth)+":"+str(etm)+" to "+str(exth)+":"+str(extm)+"\nis : 30 Rs Dated on "+date1+"\nThe amount will be deducted from your FAStag account shotly,\nTHANK YOU,Parking System Rajwada"

        
            pywhatkit.sendwhatmsg("+91"+mob,msg2,exth,extm+1,20)
        
            ett=str(eth)+":"+str(etm)
            extt=str(exth)+":"+str(extm)
            qa="insert into record_table values('{}','{}','{}','{}','{}','{}','{}','30')".format(fid,vno,name,surname,ett,extt,date1)
            mc.execute(qa)
            my.commit()
        print("done2")
        i=i+1

        
    
    
        
        
        
    
    
