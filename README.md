# Philosophers

# The problem

- One or more philosophers sit at a round table.
- There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying!

![image](https://github.com/izzypt/Philosophers/assets/73948790/a8bf1018-e804-41a8-8407-7f9fb58d904e)


# Project rules

![image](https://github.com/izzypt/Philosophers/assets/73948790/c0f85277-6e26-437c-8af4-3b5794540df1)


- Each philosopher should be a thread.
- There is one fork between each pair of philosophers. 
- If there are several philosophers, each philosopher has a fork on their left side and a fork on their right
side. 
- If there is only one philosopher, there should be only one fork on the table.
- To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.
- Your(s) program(s) should take the following arguments:
  - number_of_philosophers 
  - time_to_die 
  - time_to_eat 
  - time_to_sleep
  - number_of_times_each_philosopher_must_eat
- Philosopher number 1 sits next to philosopher ```number_of_philosophers```.
- Any other philosopher number ```N``` sits between philosopher number ```N - 1``` and philosopher number ```N + 1```.

# Core concepts

- <ins>***What is a Thread?***</ins>

To talk about thread, we must also be familiar with processes (In case, you're not, check out [this link](https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/) by another 42 student)
  - A thread is a basic unit of execution of any process. 
  - A program comprises many processes and all the processes comprise much simpler units known as threads. 
  - So, the thread can be referred to as the basic unit of a process or it is the simpler unit that tother makes the CPU utilization
  - Threads allow for parallel execution of multiple tasks within a single process.

![image](https://github.com/izzypt/Philosophers/assets/73948790/d63d984b-e2f8-48c1-9e42-56d376f31ba9)


- <ins>***Thread elements***</ins>
  - A thread ID: 
    - It is a unique ID of the thread that is created during the creation of the thread and it remains for the whole life of that particular thread.
  - Program Counter: 
    - Also known as the instruction pointer, is a special register that keeps track of the address of the next instruction to be executed by a thread. 
    - It points to the current position in the program's execution flow.
  - A registered set: 
    -  Refers to the collection of registers that store the thread's current execution context. 
    -  These registers typically include the program counter, general-purpose registers, and other architecture-specific registers. 
    -  The register set allows the thread to save and restore its execution state during context switches.
  - A stack: 
    - It is the memory of that particular thread.
    - A region of memory used by a thread to store local variables, function calls, and other related data.
    - Each thread typically has its own stack
    - The stack grows and shrinks dynamically as the thread executes


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

- <ins>***Mutex***</ins>
  - In computer programming, a mutual exclusion (mutex) is a program object that <ins>***prevents multiple threads from accessing the same shared resource simultaneously***</ins> . 
- <ins>***Shared Resource***</ins>
  - A shared resource in this context is a code element with a critical section, the part of the code that should not be executed by more than one thread at a time. 
  - For example, a critical section might update <ins>***a global variable***</ins>, modify <ins>***a table in a database***</ins> or write a file to a network server. 
  - In such cases, access to the shared resource must be controlled to prevent problems to the data or the program itself.
- <ins>***Mutex object***</ins>
  - A mutex is a mechanism used to ensure that multiple concurrent threads do not try to execute a critical section of code simultaneously.
- <ins>***Race condition***</ins>
  - A race condition refers to a situation where the behavior or outcome of a program becomes unpredictable or incorrect due to the simultaneous and uncoordinated access to shared resources by multiple threads or processes.
  - Race conditions typically occur when two or more threads access and manipulate a shared resource concurrently, without proper synchronization mechanisms in place. 
  - This can lead to unexpected results because the order and timing of the operations become unpredictable. 
  - If a mutex is not applied, the program might be subject to a race condition, a situation in which multiple threads try to access a shared resource at the same time. When this happens, unintended results can occur, such as data being read or written incorrectly or the program misbehaving or crashing.
  - Example :
    - For example, let's consider a scenario where two threads are incrementing a shared variable simultaneously. If the threads perform the following steps:

     - Read the current value of the shared variable.
    - Increment the value.
    - Write the updated value back to the shared variable.
    - A race condition can occur if both threads read the value simultaneously, then increment it separately, and finally write back their results. 
    - In this case, the final value of the shared variable may not be the sum of the increments from both threads, as expected. The outcome will depend on the interleaving of instructions from different threads, leading to data corruption or incorrect results.

- To mitigate race conditions, synchronization mechanisms like locks, semaphores, or mutexes can be used to enforce mutual exclusion and coordinate access to shared resources. 
- These mechanisms ensure that only one thread/process can access the shared resource at a time, preventing conflicts and maintaining the desired consistency in the program's execution.

# Getting started with threads

1 - To use threads in C , you need to include the <pthread.h> header file in your program.
  - When compiling , dont forget to include the flag ```-pthread```.
```
 #include <pthread.h>
```

2 - The first thing it happens when you create a thread is : it executes a function.
  - Define the function that will be executed by the thread. This function should have a ```void*``` return type and take a ```void*``` argument. For example
```
void* thread_function(void* arg) {
    // Code to be executed by the thread
    // You can typecast arg to the appropriate data type if needed
    return NULL;  // Return value of the thread
}
```
3 - We will need to create a variable which will hold some information about the thread. 
  - It will be a  ```pthread_t``` type variable (a type we imported from the ```<pthread.h>```).
  - Start the thread using the ```pthread_create``` function:
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

4 - It is also important to wait for the thread to finish executing (Imagine your program finishes before the thread)
  - We can use ```pthread_join()``` to do that.
 
# Getting start with Mutex

This is a chatGPT example :

Here's a short example that demonstrates the usage of mutex with the `pthread.h` library in C:

```c
#include <stdio.h>
#include <pthread.h>

// Global variables
int counter = 0;
pthread_mutex_t mutex;

// Thread function
void *threadFunction(void *arg) {
    // Lock the mutex before accessing the shared variable
    pthread_mutex_lock(&mutex);

    // Critical section: increment the counter
    counter++;

    // Print the updated counter value
    printf("Thread ID: %lu, Counter: %d\n", pthread_self(), counter);

    // Unlock the mutex after finishing the critical section
    pthread_mutex_unlock(&mutex);

    // Terminate the thread
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create five threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadFunction, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
```

- In this example, we have a global variable `counter` that is accessed by multiple threads. 
- The `pthread_mutex_t` variable `mutex` is used to protect the critical section where the `counter` is incremented.
- Each thread locks the mutex before accessing the critical section and unlocks it after finishing the critical section.

- The `threadFunction` is the entry point for each thread. 
- It increments the `counter` and prints the updated value. 
- The `main` function creates five threads, waits for them to finish using `pthread_join`, and then destroys the mutex.

Note that the `pthread_mutex_init` function initializes the mutex, `pthread_mutex_lock` locks the mutex, `pthread_mutex_unlock` unlocks the mutex, and `pthread_mutex_destroy` destroys the mutex.

By using the mutex, we ensure that only one thread can access the critical section at a time, preventing race conditions and ensuring the integrity of the shared variable.

# A summary on the allowed functions from <pthread.h>

- pthread_create(): 
  - This function is used to create a new thread of execution within a program. 
  - It takes a function pointer as an argument, which specifies the starting point of the new thread's execution. 
  - The newly created thread runs concurrently with the main thread, allowing for parallel execution.
  - On success, it returns 0, and on failure, it returns an error code. 
 
- pthread_join(): 
  - It is used to wait for a thread to terminate and retrieve its exit status. 
  - When a thread is joined, the calling thread blocks until the specified thread finishes execution. 
  - It allows for synchronization between threads and enables the retrieval of any return value or exit status from the joined thread.
  - When a pthread_join() returns successfully, the target thread has been terminated. 
  - The results of multiple simultaneous calls to pthread_join() specifying the same target thread are undefined.
  - Return values : On success, it returns 0, and on failure, it returns an error code.

- pthread_detach(): 
  - This function is used to detach a thread, allowing it to run independently and release its resources when it terminates.
  - Once a thread is detached, its resources are automatically reclaimed by the system upon termination, and it cannot be joined using pthread_join().

- pthread_mutex_init(): 
  - It initializes a mutex (short for mutual exclusion), which is a synchronization primitive used to protect shared resources from simultaneous access by multiple threads. 
  - It sets up the mutex variable with the required attributes before it can be used.

- pthread_mutex_destroy(): 
   - This function is used to destroy a mutex object, releasing any resources associated with it. 
   - It should be called when a mutex is no longer needed to ensure proper cleanup and prevent resource leaks.

- pthread_mutex_lock(): 
  - It acquires a lock on a mutex, making the calling thread the owner of the mutex. 
  - If the mutex is already locked by another thread, the calling thread will block until it can acquire the lock. This function is used to enforce mutual exclusion and ensure that only one thread can access a critical section of code at a time.

- pthread_mutex_unlock(): 
  - This function releases the lock on a mutex, allowing other threads to acquire the mutex and access the protected resource.
  - It should be called after a critical section of code has been executed to release the lock and enable other threads to proceed.

Another resource:

https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

https://www.scaler.com/topics/multithreading-in-c/

https://www.youtube.com/watch?v=LOfGJcVnvAk&ab_channel=NesoAcademy

https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788
