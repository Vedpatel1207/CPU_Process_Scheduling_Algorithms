
<h1>CPU Scheduling Algorithms in C</h1>

This repository contains C implementations of several CPU scheduling algorithms, including:

First Come First Serve (FCFS)
Shortest Job First (SJF)
Shortest Remaining Time First (SRTF)
Longest Remaining Time First (LRTF)
Priority Scheduling
Round Robin (RR)
These algorithms are fundamental in operating system design and are crucial for efficient resource management in multitasking environments.


<h1>Algorithms</h1>
1. First Come First Serve (FCFS)
FCFS is a non-preemptive scheduling algorithm that schedules according to the arrival time of processes. It simply queues processes in the order they arrive and executes them one by one.

2. Shortest Job First (SJF)
SJF is a non-preemptive or preemptive scheduling algorithm that selects the process with the smallest execution time next. It can be preemptive if the scheduler selects the shortest remaining time instead of the total execution time.

3. Shortest Remaining Time First (SRTF)
SRTF is a preemptive version of SJF where the scheduler selects the process with the shortest remaining time whenever a new process arrives or a running process completes.

4. Longest Remaining Time First (LRTF)
LRTF is the opposite of SRTF. It selects the process with the longest remaining time to execute next.

5. Priority Scheduling
Priority scheduling assigns a priority to each process and executes the highest priority process first. It can be preemptive or non-preemptive.

6. Round Robin (RR)
RR is a preemptive scheduling algorithm where each process is assigned a fixed time slice (quantum) to execute. Once a process consumes its quantum, it's put back into the ready queue, and the scheduler selects the next process in the queue.