#include <stdio.h>
#include <graphics.h>

//图像的大小
#define IMG_W 250
#define IMG_H 350
//每一小块的大小
#define BLOCK_W 55
#define BLOCK_H 50

//绘制填充具体颜色的带文字的矩形块
void drawBlock(int x, int y, int w, int h, COLORREF color, const char* str)
{
	//填充矩形块颜色
	setfillcolor(color);
	//画矩形函数，四角参数
	solidrectangle(x, y, x + w, y + h);

	//绘制文字
	settextstyle(BLOCK_H / 4, 0, "宋体");     //文字高度和宽度（宽度：0，自适应）
	settextcolor(BLACK);                      //设置文字颜色为黑色
	setbkmode(TRANSPARENT);                   //文字背景为透明
	int width = textwidth(str);               //获取文字的宽度
	int height = textheight(str);             //获取文字的高度

	//求文字的输出坐标
	int xx = x + (w - width) / 2;
	int yy = y + (h - height) / 2;
	outtextxy(xx, yy, str);
}



//替换函数
void replaceByBlock()
{
	IMAGE img;
	loadimage(&img, "瑶.jpg", IMG_W, IMG_H);

	//获取图像行和列
	int row = img.getheight();
	int cols = img.getwidth();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//获取每一个点的颜色，i,j
			SetWorkingImage(&img);  //设置图像是工作区
			COLORREF color = getpixel(j, i);
			//printf("COLOR:%lu", color);
			SetWorkingImage();       //关闭
			//通过这个颜色绘制一小块
			drawBlock(j * BLOCK_W, i * BLOCK_H, BLOCK_W, BLOCK_H, color, "喜欢你");
		}
	}
	//所有像素点都转换为一小块，绘制到窗口，直接保存到本地


	saveimage("测试.jpg");
}

int main()
{
	initgraph(IMG_W * BLOCK_W, IMG_H * BLOCK_H);
	replaceByBlock();           //替换函数回调

	while (1)
	{
		//防止闪屏
	}
	closegraph();
	return 0;
}
