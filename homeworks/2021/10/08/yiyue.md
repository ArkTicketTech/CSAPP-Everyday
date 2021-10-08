_file_ - a sequence of bytes

run `hello` remotely
- type `hello` to telnet client
- client sends string to telnet server
- server receives string, passes it to remote shell program
- remote shell runs `hello`, passes output line back to the telnet server
- telnet server forwards the output string to telnet client, prints string on local terminal

### Amdahl's Law
- when speed up one part of system
- effect on the overall system performance depends on 
  - how significant this part was
  - how much it sped up

- A system executing some application requires time T<sub>old</sub>
- some part of this system requires a fraction &alpha; of this time
- improve this part by a factor of k
- this component originally requires &alpha;T<sub>old</sub>

T<sub>new</sub> = (1 - &alpha;)T<sub>old</sub> + (&alpha;T<sub>old</sub>)/k
                = T<sub>old</sub>[(1 - &alpha;) + &alpha; / k]

speedup S = T<sub>old</sub>/T<sub>new</sub>
          = 1 / ((1 - &alpha;) + &alpha; / k)

_concurrency_  - general concept of a system with multiple, simultaneous activities
_parallelism_ - use of concurrency to make a system run faster
