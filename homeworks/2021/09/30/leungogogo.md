# 1.8 Systems Communicate with Other Systems Using Networks
* Network can be viewed as just another I/O device.
  * Example: Running the `hello` program on a remote machine
    * Connect the telnet client on our local machine to a telnet server on a remote machine.
    * We input `hello` to the client, and client sends the string to server.
    * Server receives the string from network, and passes it to the shell program.
    * Remote shell runs the program.
    * Server forwards the output string across the network to client, and client prints the output on our local machine.
    
    
    
