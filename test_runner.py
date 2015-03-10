#!/usr/bin/python
import subprocess
import random
import time
import string

SAMPLE_SIZE = 10
STR_LENS = [8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384]
TEST_PROGRAMS = ["./simple", "./complex"]

def main():
    subprocess.call(["make"])

    for str_len in STR_LENS:
        print "For N = " + str(str_len) + ":\n"
        testPrograms(str_len)
        print "---------------------------------------------"

        

'''
Tests each string-compare program in TEST_PROGRAMS with strings
of the given length. Prints the average times for each program.
'''
def testPrograms(str_len):
    avg_times = {}

    print "Program:\t\t",
    for program in TEST_PROGRAMS:
        print "{0:20}".format(program),
        avg_times[program] = testProgram(program, str_len)

    print "\nAvg time:\t\t",
    for program in TEST_PROGRAMS:
        print "{0:20}".format(str(avg_times[program]) + " ms"),
    print


'''
Tests the given string-compare program with strings of the
given length.  Runs SAMPLE_SIZE tests.  Returns the average
time, in milliseconds, that it took to execute (wall-clock time).
'''
def testProgram(program, str_len):
    times = []
    for x in range(SAMPLE_SIZE):
        test_string1 = randomChars(str_len)
        test_string2 = randomChars(str_len)
        times.append(timeExecute(program, test_string1, test_string2))

    avg = sum(times) / float(len(times))
    return (avg)

'''
Executes the given string-compare program with the provided
arguments (the strings to compare).Returns the wall-clock
time it took to execute (in milliseconds).
'''
def timeExecute(program, string1, string2):
    start = time.time()
    subprocess.call([program, string1, string2], stdout = subprocess.PIPE)
    end = time.time()

    return (end - start) * 1000.0 # Seconds -> Milliseconds

'''
Returns a string of random chars of the specified length.
'''
def randomChars(length):
    return "".join(random.choice(string.printable) for _ in range(length))

if __name__ == "__main__":
    main()
