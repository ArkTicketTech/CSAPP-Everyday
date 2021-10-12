1.8 network
1.8 network is another I/O device
a) user type "hello" in client keyboard
b) "hello" command sent from client to server
c) server sent "hello" to shell. shell run "hello", pass output "hello world\n to server
d) "hello world\n" sent from server to client
e) client print "hello world\n"

1.9 important themes
1.9.1 amdahl's law: ratio = [1 / (1 - a + a / k)]x
1.9.2
concurrency: multiple, simultaneous activities
parallelism: the use of concurrency to make a system run faster
level of parallelism:
a) thread-level concurrency
typically, four cores in one chip, each core has private L1 and L2 cache.
cores share L3 cache and interface to main memory.
L1 cache splits to two parts, d-cache(data) and i-cache(instructions)
conventional processor require 2w clock to shift between different threads, while hyper-threaded processor only need one clock.
one intel core i7 processor can have two threads
b) instruction-level parallelism
c) SIMD single instruction, multiple data. i.e. AMD processor can add 8 pair float together. vector data plus

prevalent 流行
conventional 传统的
