     	       多控制方式的智能窗帘系统

大概功能如题，该文本将从以下方面介绍此系统：
1.用户体验描述
2.软件架构及模块分析
3.单片机IO口汇总




1.用户体验描述：
	    用户能与该系统进行四项信息的交互：  a控制窗帘的打开，关闭 ； b远程控制窗帘的定时时间 ； c实时读取窗外的光强指数；d实时读取室内的温度。
	其中功能a当然是最主要的部分，实现的逻辑也最为复杂。如果你现在对功能b一头雾水，没有关系，请继续阅读功能a。
	功能c和功能d不需要用户操作，只是用来提醒用户目前的室内外环境,通过显示器显示。

	    在功能a中，我们提供了三种调节窗帘开关的方法——a1：手动按键调节窗帘打开或者关闭。  a2：手机蓝牙串口远程调节窗帘打开或者关闭。 a3：根据环境温度，光强,时间等因素自动调节。
	它们的优先级排序为：a1>a2>a3.
	    这里再介绍一下a3的算法：在6:00之前和22:00之后（晚上）是不能打开窗帘的，白天则根据环境温度和光强来决定窗帘是否打开——当两者中任一个超过了预定值之后，窗帘都会关闭。
	    现在我们可以解释b功能了。窗帘控制器成本有限，没有必要让窗帘加入物联网获取本地时间，用户只需要通过手机蓝牙串口为窗帘设置时间即可，系统中自带的模块会持续计时。（于情于理，误差
	绝对应该在可接受范围内）


2.软件架构及模块分析：
	系统构建在Keil开发环境之上，总体目录结构如下：
                |system
	|-----delay
	|----------delay.c
	|----------delay.h
	|-----i2c
	|----------i2c.c
	|----------i2c.h
	|-----control          
	|----------control.c
	|----------control.h
	|hardware
	|-----motordriver
	|----------motordriver.c
	|----------motordriver.h
	|-----lumination
	|----------lumination.c
	|----------lumination.h
	|-----temperature
	|----------temperature.c
	|----------temperature.h
	|-----lcd12864
	|----------lcd12864.c
	|----------lcd12864.h
	|-----usart
	|----------usart.c
	|----------usart.h
	|-----clock
	|----------clock.c
	|----------clock.h
	|uproj
	|main.c



	    system文件夹中包含了一些通用模块和控制模块，有通用延时函数delay.c，通信协议i2c.c，总体控制模块control.c
	    hardware文件夹中包含了一些硬件配置驱动模块，有步进电机驱动motordriver.c，光敏电阻驱动lumination.c，热敏电阻驱动temperature.c,显示器驱动lcd1602.c或lcd12864.c，蓝牙串口通信usart.c，时钟控制模块clock.c

	项目工程和主函数没有什么好介绍的了。
	重点介绍一些模块：



3.单片机IO口汇总

LCD1602：全P0口，P3.4，P3.5，P3.6
DS18B20（温度模块）：P2.2
步进电机模块：
光敏模块：
串口：





4.贡献者： 兰铖，缪宜辰。
			   ----2020.09.07

	