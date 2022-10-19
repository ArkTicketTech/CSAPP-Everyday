*The ICU reads the instructions from an instruction cache—a special highspeed*

*memory containing the most recently accessed instructions. In general,*

*the ICU fetches well ahead of the currently executing instructions, so that it has*

*enough time to decode these and send operations down to the EU. One problem,*

*however, is that when a program hits a branch,**1* *there are two possible directions*

*the program might go. The branch can be taken, with control passing to the branch*

target. Alternatively, the branch can be not taken, with control passing to the next 

*instruction in the instruction sequence. Modern processors employ a technique*

*known as branch prediction, in which they guess whether or not a branch will be*

*taken and also predict the target address for the branch. Using a technique known*

*as speculative execution, the processor begins fetching and decoding instructions*

*at where it predicts the branch will go, and even begins executing these operations*

*before it has been determined whether or not the branch prediction was correct.*

*If it later determines that the branch was predicted incorrectly, it resets the state*

*to that at the branch point and begins fetching and executing instructions in the*

*other direction. The block labeled “Fetch control” incorporates branch prediction*

*to perform the task of determining which instructions to fetch.*