# stc89c52_BuzzerMusic_LCD1602
51单片机音乐播放器 蜂鸣器+LCD1602歌词显示 Yellow-Coldplay</br>
* bilibili: https://www.bilibili.com/video/BV1wT411X7tE
* CSDN: https://blog.csdn.net/Stella030/article/details/131949472
## 0. 引言
The song sings, "Look at the stars, look how they shine for you."</br>
Some light is not eternal. It's actually a fallacy.</br>
The stars no longer shine for specific someone, but I hope they can light up the much more wider world. It is, and will be, far more meaningful than it ever was.</br>
## 1. 项目说明
本项目代码基于江科大教程魔改，关于51单片机的详细教程可以搜索江科大自化协。</br>
代码部分包含：main.c, delay.c, delay.h, LCD1602.c, LCD1602.h, timer0.c, timer0.h（各自的功能如其名称所示）。
## 2. 引脚冲突问题解决方案
我当时的初版bug是歌词字符显示不全。如果是这个问题的话解决方法也很简单，并不需要任何复杂的设置，只需要调整音符的节拍就行了。在我的代码里每段显示歌词的代码在对应旋律播放代码之前，通过将前一段旋律最后一个节拍置为休止符（也可以是1/2节拍 or 1/4节拍，总之必须有一个位置不调用蜂鸣器发音）歌词就能正常显示了。
