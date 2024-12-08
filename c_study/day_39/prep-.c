//
// Created by 20212 on 2024/5/1.
//
//程序环境与预处理  program environment and preprocessing
//翻译环境，使test.c -> test.exe
//Translation environment
//test.c contact.c common.c
//test.c -> txt.exe 依赖于翻译环境 Dependent on the translation environment
//编译（编译器） Compiler (Compiler) cl.exe  链接器(link.exe)
//源文件通过编译 链接 最后形成可执行文件
///The source files are compiled through a link and finally formed into an executable file


//预处理阶段完成了头文件的包含
//The preprocessing phase completes the inclusion of the header file
//#define定义的符号和宏的替换完成于预处理阶段
//The substitution of symbols and macros defined by define is done during the pre-processing phase
//预处理阶段会删除注释 The comments are deleted during the preprocessing phase

//编译 把c语言代码转化成汇编代码
//Compilation: Converts C code into assembly code

//汇编 把汇编代码转换成机器指令（二进制指令）
//Assemble Converts assembly code into machine instructions (binary instructions)
//汇编阶段 会生成符号表
//assemble -> text.obj -.elf ->readelf
//链接阶段
//合并段表 符号表的合并和重定位 把有效的符号进行保留
//extern 声明外部符号

//linux -> 操作系统
//vim -> 编辑器
//gcc -> 编译器

//运行时分配的空间 运行时堆栈 -> 函数栈帧