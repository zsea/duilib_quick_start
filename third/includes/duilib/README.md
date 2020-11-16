# 常见问题

1. error C2760：语法错误: 意外的令牌“标识符”，预期的令牌为“类型说明符”

解决办法：
C/C++ -> 语言 -> 符合模式，修改为否

2. error LNK2038: 检测到“RuntimeLibrary”的不匹配项:  值“MTd_StaticDebug”不匹配值“MDd_DynamicDebug”

解决办法：

在工程上右键-》属性-》c/c++-》代码生成-》运行库

有四个选项及含义分别如下：


多线程调试Dll (/MDd) 对应的是MD_DynamicDebug

多线程Dll (/MD) 对应的是MD_DynamicRelease

多线程(/MT) 对应的是MD_StaticRelease

多线程(/MTd)对应的是MD_StaticDebug
