from multiprocessing import Pool
import os, time, random

def run_process(name):
    print("Run process %s (%s)..." % (name, os.getpid()))
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print("Process %s runs %0.2f seconds." % (name, (end - start)))

if __name__ == '__main__':
    print("Parent process is %s" % os.getpid())
    p = Pool(10)
    for i in range(10):
        p.apply_async(run_process, args = (i, ))
    print("Wait for process finished...")
    p.close()
    p.join()
    print("All processes done.")