# Pascal

a pascal compiler implemented by LLVM 3.5.1.

> This is the final project of the course **Compiler Course Design** in ZJU. 
> Sorry for bugs and lacking of documents

**Current Status**: in Updating docs

# Authors

- Li Yiting ([@lyt9304](http://github.com/lyt9304))
- Zhang yuhao ([@denil1111](http://github.com/denil1111))
- Gong Deli ([@Gnnng](http://github.com/Gnnng))

# Build

- llvm 3.5.1 (must be)
- `-std=stdc++11` (see more in `makefile`)
- Mac OSX (recommended)

# Pascal Grammar Support 

> Details about grammar support can be found in yacc source file `pascal.y`

## Type 

* Integer
* Real
* Char
* Bool
* Record (imperfectly)
* Array (imperfectly)

## Control flow

* if statement
* for statement
* repeat statement
* while statement
* case statement
* goto statement (imperfectly)

## Others

* function/procedure declaration/execution
* binary operators
* system functions
    * read/readln
    * write/writeln

# References

* LLVM官网教程

http://llvm.org/docs/tutorial/index.html

* 使用 LLVM 框架创建一个工作编译器，这里有IR的教程

http://www.ibm.com/developerworks/cn/opensource/os-createcompilerllvm1/

* 一个完整的flex+bison+llvm的例子

http://www.cppblog.com/woaidongmao/archive/2009/11/11/100693.aspx

* 例子源代码

https://github.com/lsegal/my_toy_compiler

* 另外一个例子

http://my.oschina.net/linlifeng/blog/97457



