m
#!/usr/bin/python
#reads in 1. number of lines of input 2. Nmber for strings
# prints event count with a space and then odd count letters

count = int(input().strip())

words = []
for testCase in range(0,count):
    str = input().strip()
    words.append(str)

for word in words:
    length = len(word)
    index = 0
    while index<length :
        print(word[index],end='')
        index += 2

    print (" ",end='')

    index = 1
    while (index<length):
        print(word[index],end='')
        index += 2

    print ("\n", end='')
