# REPORT(window&view)

-------------------

### 解决方案

- 在window层中创建四个属于view层的子窗口，分别实现绘制热源与隔热器(qt_gui_class)、显示温度分布图(view)、选中区域均温随时间变化的二维坐标图(Coorview)以及设置边界温度和热传导系数α(Settingview)
- 为了实现在温度分布图(view)中用户能够实现时间的选择，来实现显示不同时间的温度分布图
- 显示不同的子窗口通过相应的功能按钮实现：generate按钮实现温度图的显示，用来显示子窗口view(此处view不代表view层，而代表显示温度分布图的子窗口)； qt_gui_class在程序打开的时候就加载到mainwindow中，绘图在该处实现；Average按钮实现坐标图的显示，用来显示子窗口Coorview
- 通过Transport调用m_cmdCalc来实现更新温度分布图
- 通过askAverageTem调用m_cmdAverage来实现均温数据的获取

------------------------

### 设计思路

&emsp;&emsp;整个温度分布图由100*100的像素点组成。
- 在qt_gui_class中，实现简单的绘图板功能，并在figure类中存储热力学参数，包括是热源还是隔热器，以及起始的温度
- 在Settingview中，当用户更改边界温度或者热传导系数α之后，emit信号sendTemAndAlpha，由MainWindow接收，更新初始条件
- 在view中，用户可以通过拖拽滑块（SliderSelectTime）来选择显示某个时间的温度分布图。当滑块被拖动的时候，emit信号SendTime，由MainWindow接收，直接调用Transport，参数为选择的时间
- 在view中，点击buttonPlay，将会emit信号StartPlayHeatdim，由MainWindow接收，启动计时器，每隔一段时间调用上一条的更改时间函数，实现温度分布图的播放
&emsp;&emsp;在用户点击Generate按钮之后，MainWindow接受点击信号，Updatewb()函数根据已经存储的figure类的数组信息来初始化温度分布图（initial_condition），并通过Transport函数来调用m_cmdCalc->Exec()。在viewmodel层发射"heat_Result"之后，由MainWindow层中的m_sinkProperty来更新view中的温度分布图。而Transport的参数则由前面几条相应的参数决定（CType type, double changeval）。
&emsp;&emsp;在选中qt_gui_class的某一区域之后，单击Average按钮，MainWindow会调用askAverageTem来触发命令（m_cmdAverage->Exec()）。在m_sinkProperty接收到"avg_Result"之后，便会调用Coorview->Update()来更新均温随时间变化的二维坐标图。

