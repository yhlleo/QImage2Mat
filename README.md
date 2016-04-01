# QImage2Mat
The conversion between Qt QImage and OpenCV Mat. 

应一个朋友的要求，整理总结一下，Qt中的图像类`QImage`与OpenCV库中`Mat`的转换方法，测试工程已发布在GitHub：[yhlleo/QImage2Mat](https://github.com/yhlleo/QImage2Mat)

编译环境：

 - `VS2010`
 - `CMake (version >= 2.8.3)`
 - `Qt (version 4.8.6)`

运行结果如图：

![lena](http://img.blog.csdn.net/20160401202516344)

一共有四个测试函数及其对应的转换结果：

 - `qimageShow()` -> `QImage`加载图像，并显示在`Graphic View`中；
 - `mat2qImageShow()` -> `Mat to QImage`是OpenCV `Mat`加载图像，转化为`QImage`后在`Graphic View`中显示；
 - `qImage2MatShow()` -> `QImage to Mat 1`是使用`QImage`数据直接初始化`Mat`后，使用OpenCV的gui显示方法；
 - `qImage2MatPtrShow()` ->`QImage to Mat 2`是使用常用的指针数组的方式遍历`QImage`，然后为`Mat`矩阵赋值，再使用OpenCV的gui显示方法；


`mat2qImageShow()`和`qImage2MatShow()`函数中，转换源代码主要来自博客：[QImage 与 cv::Mat 之间的相互转换](http://blog.csdn.net/liyuanbhu/article/details/46662115)，博主写得很巧妙，值得一看。

另外，提供的常见的指针数组的访问方式（见函数`qImage2MatPtr()`），对于`QImage`数据格式不同于`Mat`，不能使用以往`(i*cols+j)*channels+k`这种方式访问，而是`i*byterPerLine+j*imgChannels + k`，其中`byterPerLine=(width*depth+31)/8`，也就是说，其中含有4个字节的补齐问题，请参见提供的详细代码。

关于QImage的`format()`类型，可以阅读help文档，解释的也比较清楚。
