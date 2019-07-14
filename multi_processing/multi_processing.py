from multiprocessing import Process
import os

def run_process(name):
    print("Run process %s (%s)" % (name, os.getpid()))

if __name__ == '__main__':
    print("Parent process is %s" % os.getpid())
    p = Process(target = run_process, args = ('test', ))
    print("Process will start....")
    p.start()
    #p.join()
    print("Process end.") 