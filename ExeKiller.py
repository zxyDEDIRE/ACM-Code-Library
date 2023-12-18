# coding=utf-8
import csv
import random
import sys
import time
import os
import time
import gzip
import datetime

ans=[]
def walkdir(file):
    for root, dirs, files in os.walk(file):
        for f in files:
            m = os.path.join(root, f)
            print("m=",m)
            ss=os.path.splitext(m)
            print("ss = ",ss)
            dirname = ss[0]#文件夹
            print("dirname = ",dirname)
            a = os.path.basename(m)#文件名，带后缀

            if a.find(".") == -1:
                pass
                # ans.append(m)
                # os.remove(m)
                # print("file-name:",a)
                # print("删")
            else:
                file_name = a.split('.')[0]
                houzui = a.split('.')[1]
                print("file_name = ",file_name , "--------houzui = ",houzui)
                print("a=",a)
                suffix = file.split('.')[-1]
                # 指定删除ev4的后缀名文件
                if houzui=='exe' or houzui =='cp':
                # if houzui != 'cpp' and houzui != 'md' :
                    ans.append(m)
                    print("删")
                    os.remove(m)
if __name__ == "__main__":
    print("start")
    print(sys.argv)
    walkdir(r'C:\\Users\\tob\\Documents\\CODE')
    print('\n')
    for i in ans:
        print(i)
