# mLogger

mllogger is a library for saving information both in memory and in a log file

## Help


it is very easy to compile the library, just use the CMakefile that I will 
leave and follow these steps

```
mkdir build
cd build
cmake .. ; make
```

let's go to use our library, You save information like `warning`, `sucess`, `about`, `informations`, `error`Let's check how the message proposed by the log will be issued

* Warning

    ![Warning](assets/warning.png)

* Sucess 

    ![Sucess](assets/sucess.png)

* Information

    ![Information](assets/information.png)

* Error

    ![Information](assets/error.png)

* About

    ![About](assets/about.png)


## Usage Library 

if you want your log only in memory, just set the 3 parameter for true in the constructor

```C
    mLogger log("test.log", 0, true);`
```

by default it is false, so you need to pass the file to be saved the log and if you wanted to configure the permissions for opening this file, you can do that using the 2nd parameter of the constructor, by default it will create a file with permissions of Reading and writing

```C 
    mLogger log("test.log", 1025);
```

let's use a function that is intended to report a successful creation of a user

```C 
    std::cout << log.mlogger_sucess("User Created ") << std::endl;
```

it will return a pointer to the buffer allocated on the heap and with our success log, just print, good to point out that it will not save the log and break the line to the next information saved in the file, so make sure you do the line break before saving, this server for all library functions


## Todo
- [ ]  Data time 
