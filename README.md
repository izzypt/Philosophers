# Philosophers

### Core concepts

- <ins>***Mutex***</ins>
  - In computer programming, a mutual exclusion (mutex) is a program object that <ins>***prevents multiple threads from accessing the same shared resource simultaneously***</ins> . 
- <ins>***Shared Resource***</ins>
  - A shared resource in this context is a code element with a critical section, the part of the code that should not be executed by more than one thread at a time. 
  - For example, a critical section might update <ins>***a global variable***</ins>, modify <ins>***a table in a database***</ins> or write a file to a network server. 
  - In such cases, access to the shared resource must be controlled to prevent problems to the data or the program itself.
- <ins>***Mutex object***</ins>
  - A mutex is a mechanism used to ensure that multiple concurrent threads do not try to execute a critical section of code simultaneously.
- <ins>***Race condition***</ins>
  - If a mutex is not applied, the program might be subject to a race condition, a situation in which multiple threads try to access a shared resource at the same time. When this happens, unintended results can occur, such as data being read or written incorrectly or the program misbehaving or crashing.
  - So, in summary : Use a mutex when you (thread) want to execute code that should not be executed by any other thread at the same time.

- <ins>***What is a Thread?***</ins>
  - A thread is a basic unit of execution of any process. 
  - A program comprises many processes and all the processes comprise much simpler units known as threads. 
  - So, the thread can be referred to as the basic unit of a process or it is the simpler unit that tother makes the CPU utilization
  - Threads allow for parallel execution of multiple tasks within a single process.


- <ins>***Thread elements***</ins>
  - A thread ID: 
    - It is a unique ID of the thread that is created during the creation of the thread and it remains for the whole life of that particular thread.
  - Program Counter: 
    - It is a value that loads into the hardware.
  - A registered set: 
    - It is a set of general registers.
  - A stack: 
    - It is the memory of that particular thread.

![image](https://github.com/izzypt/Philosophers/assets/73948790/324ea47d-77a1-4d44-9ebf-8c895241c43f)

- <ins>***What are the differences between processes and thread?***</ins> 
  - Threads are not independent from each other unlike processes. 
  - As a result, threads shares with other threads their code section, data section and OS resources like open files and signals. 
  - But, like processes, a thread has its own program counter (PC), a register set, and a stack space.

 <ins>***Why Multithreading?***</ins> 
 
- Threads are popular way to improve application through parallelism. 
- For example, in a browser, multiple tabs can be different threads. MS word uses multiple threads, one thread to format the text, other thread to process inputs, etc. 
- Threads operate faster than processes due to following reasons: 
  - Thread creation is much faster. 
  - Context switching between threads is much faster. 
  - Threads can be terminated easily 
  - Communication between threads is faster.

# Getting start with threads

1 - To use threads in C , you need to include the <pthread.h> header file in your program.

```
 #include <pthread.h>
```

2 - Define the function that will be executed by the thread. This function should have a void* return type and take a void* argument. For example
```
void* thread_function(void* arg) {
    // Code to be executed by the thread
    // You can typecast arg to the appropriate data type if needed
    return NULL;  // Return value of the thread
}
```
3 - In your main program, create a thread object and start the thread using the ```pthread_create``` function:
```
int main() {
    pthread_t thread;
    int status;

    status = pthread_create(&thread, NULL, thread_function, NULL);
    if (status != 0) {
        // Handle error
    }

    // Continue with the main program

    pthread_exit(NULL);  // Wait for the thread to finish before exiting
}
```
