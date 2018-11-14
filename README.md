# How to count CPU cores

This is a sample project that I started to satisfy my curiosity: "How to count
CPU cores by building and using a shared library?"

My curiosity was triggered by a few things:

* [cl-cpus](https://github.com/muyinliu/cl-cpus), a Common Lisp feature to get
number of CPUs.
* [An example from The Common Lisp cookbook](https://lispcookbook.github.io/cl-cookbook/process.html#preamble---get-the-number-of-cores-with-a-call-to-cffi).
* Learn a bit more about [sysconf](http://man7.org/linux/man-pages/man3/sysconf.3.html), and
[getconf](https://linux.die.net/man/1/getconf).

First I became curious about the origin of "84" in
[cl-cpus-linux.lisp](https://github.com/muyinliu/cl-cpus/blob/master/cl-cpus-linux.lisp),
and then I also wanted to see how I can build and consume a shared library but
by using GCC on Linux (the Common Lisp Cookbook example uses Clang on Mac OS X).

## How to build
Please clone this git repository to your computer and then run `make`, e.g.:

    $ git clone https://github.com/emres/cpucount
    $ cd cpucount
    $ make

After that you can run the resulting program:

    $ ./call_cpucount_lib

## Dependencies
This software has been tested on an Ubuntu GNU/Linux 17.10, using GCC 7.2.0 and
GNU Make 4.1. There are no other dependencies.

