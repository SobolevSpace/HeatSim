#HeatSim项目实践报告
3170105264 乔俊鑫

###负责模块
Model&ViewModel

###实现功能
- 接受平面初始温度输入，并计算未来20秒内平面温度变化情况。
- 调整导热参数、边缘温度两种参数。
- 计算指定范围的均温在20秒内的变化情况。

###设计思路
对于前两次迭代实现的功能，利用common中的头文件workboard.h中定义的类WorkboardPass来获取输入的初始状态和本次计算改变的参数，调用Model中对应的函数来重新计算未来20秒内的温度分布。提供给更高层用于输出的是指向固定内存的，存储workboard类型的数据的shared_ptr，其中的值在初始条件或时间改变时改变。

对于第三次迭代实现的计算均温变化情况的功能，接受workboard.h中定义的pointParameters类组成的pair作为输入，以确定最终计算的范围。提供给更高层用于输出的是指向固定内存的，存储vector<double>类型的数据的shared_ptr。此vector长度固定为401。其中的值在初始条件或计算范围改变时改变。

###心得体会
通过本课程的学习，我学会了Github的使用，以及MVVM的开发模式的应用，并认识到了MVVM模式在团队开发中的优越性。

###改进意见
希望对MVVM模式的说明中能有一个层次总览的图片以便于理解。