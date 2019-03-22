**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

asleep - The process is alive, but in a period of inactivity. It will resume when the time it was ordered to sleep has elapsed or it is otherwise interrupted. 

ready to run - The process is prepared to run, but isn't abled to be scheduled in yet because the system is preoccupied with other processes. These processes are on the sidelines like "put me in coach!"

running - The process is finally having its instructions executed by the CPU; this is the state the process has been waiting for.

zombie - The process is no longer actively running, but cannot terminate because of some unfinished business: its uncollected exit status.

terminated - the process has ended and is taken off of the process table.


**2. What is a zombie process?**

A zombie process, as introduced above, is one which is in limbo between the states of running and terminated. It's stuck on the process table until it has been reaped by its parent.


**3. How does a zombie process get created? How does one get destroyed?**

Zombie processes get created every time a child process finishes running and its parent has yet to wait for it and collect its exit status. The zombie child becomes orphaned and then adopted by init if the parent process terminates without waiting.

To destroy a zombie process, the parent has to reap it by waiting for the child to deliver its final pieces of information. Even if the exit status is disregarded, the zombie process still needs to offload it in order to terminate.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled languages are more efficient because once they're compiled, the resulting executable file can be run repeatedly with no need to recompile the original program. Non-compiled languages require more intermediate steps to process the program into machine readable code, steps which have to be carried out each runtime. Taking the time to compile our code upfront saves time later when the program is run. 

I imagine that the efficiency returns increase with the number of times the program will be executed. If you want to run the exact same program a billion times, it would make a great deal of sense to use a compiled languages so you only have to compile it once before running it all those times. 

Another benefit that I appreciate about compiling code beforehand is that the compiler will sometimes warn you if there is a problem so you can avoid ever executing that broken code. It won't throw warnings or errors for every mistake, but those messages are still a helpful checkpoint.
