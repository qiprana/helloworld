#!/usr/bin/python

#import libs
import sys

# Print to stdout
print "Hello world\n"

#-------- learning some math
a = 10
b = 20
print("Sum of a and b: ", a+b)
if(a > b):
    print("A > b \n")
elif (a < b):
    print("A < b")
else:
    print ("a = b")

#--------input from stdin
#raw_input reads in as string. use strip to remove the \0?
myName = raw_input("Enter your name: ")
print ("My name is %s" % myName)

num = float(raw_input("enter number "))
print("Num = ", num)

#strip - removes the chars specified, use it along with raw_input().strip();

# Logical operators - and or



#using sys lib to return different exit code.
sys.exit(2)
