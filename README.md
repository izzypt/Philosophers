# Philosophers

### Core concepts

- Mutex 
  - In computer programming, a mutual exclusion (mutex) is a program object that <ins>***prevents multiple threads from accessing the same shared resource simultaneously***</ins> . 
  - A <ins>***shared resource***</ins> in this context is a code element with a critical section, the part of the code that should not be executed by more than one thread at a time. 
  - For example, a critical section might update a global variable, modify a table in a database or write a file to a network server. 
  - In such cases, access to the shared resource must be controlled to prevent problems to the data or the program itself.
- Mutex object
  - A mutex is <ins>***a mechanism used to ensure that multiple concurrent threads do not try to execute a critical section of code simultaneously***</ins>.
  - If a mutex is not applied, the program might be subject to a <ins>***race condition***</ins>, a situation in which multiple threads try to access a shared resource at the same time. When this happens, unintended results can occur, such as data being read or written incorrectly or the program misbehaving or crashing.

So, in summary : Use a mutex when you (thread) want to execute code that should not be executed by any other thread at the same time.
