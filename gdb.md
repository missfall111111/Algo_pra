# Here I take some notes about gbd,a debug tool in command line.

1. g++编译的时候，需要添加-g选项，否则不能使用gbd调试

2. 命令run/r 运行程序

3. 命令break 后接行数或者函数名，在某一行设置断点。

4. 命令next/n，运行本行，进入下一行。

5. 命令list/l+行数，会打印行数上下几行的代码，没有行数，行数即为当前运行的行数。

6. 命令print/p+变量或者表达式，会打印出变量的值,他明白C++的语法。

7. 命令quit/q,退出gdb

8. 命令up,看现在函数上一层函数的代码，即调用现函数的函数

9. 命令down,看现函数下一层函数调用的代码。

10. 命令display+变量,每走一步，就展示该变量的值，不用每次都p. undisplay+变量的序号，就不会每步展示。

11. 命令backtrace/bt，打印出所有的堆栈

12. 命令step,进入某一个函数，而不是next,直接经过。

13. 命令continue,一直运行代码，直到下一个断点出现。

14. 命令finish,当你完成了这个函数时，停下。

15. 命令watch,

16. 命令info

17. 命令delete

18. 命令what

19. 命令target record-full, reverse-next, 返回上一步

20. 命令set var 然后为一个变量赋值，就不用再回到源代码更改，然后再调试了！
