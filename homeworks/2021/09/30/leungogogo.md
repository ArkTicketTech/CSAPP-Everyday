# CSAPP 9/30 Notes
## 1.8 Systems Communicate with Other Systems Using Networks
* Network can be viewed as just another I/O device.
  ![Screen Shot 2021-09-30 at 3 20 55 PM](https://user-images.githubusercontent.com/26990923/135537700-57489e30-3072-49a0-a3a7-8aec9192d507.png)

* Example: Running the `hello` program on a remote machine
    * Connect the telnet client on our local machine to a telnet server on a remote machine.
    * We input `hello` to the client, and client sends the string to server.
    * Server receives the string from network, and passes it to the shell program.
    * Remote shell runs the program.
    * Server forwards the output string across the network to client, and client prints the output on our local machine.
    ![Screen Shot 2021-09-30 at 3 20 13 PM](https://user-images.githubusercontent.com/26990923/135537609-eabab179-74dc-41c3-95dc-da4af6af36b6.png)
