#include <stdio.h>
#include <graphics.h>

//ͼ��Ĵ�С
#define IMG_W 250
#define IMG_H 350
//ÿһС��Ĵ�С
#define BLOCK_W 55
#define BLOCK_H 50

//������������ɫ�Ĵ����ֵľ��ο�
void drawBlock(int x, int y, int w, int h, COLORREF color, const char* str)
{
	//�����ο���ɫ
	setfillcolor(color);
	//�����κ������Ľǲ���
	solidrectangle(x, y, x + w, y + h);

	//��������
	settextstyle(BLOCK_H / 4, 0, "����");     //���ָ߶ȺͿ�ȣ���ȣ�0������Ӧ��
	settextcolor(BLACK);                      //����������ɫΪ��ɫ
	setbkmode(TRANSPARENT);                   //���ֱ���Ϊ͸��
	int width = textwidth(str);               //��ȡ���ֵĿ��
	int height = textheight(str);             //��ȡ���ֵĸ߶�

	//�����ֵ��������
	int xx = x + (w - width) / 2;
	int yy = y + (h - height) / 2;
	outtextxy(xx, yy, str);
}



//�滻����
void replaceByBlock()
{
	IMAGE img;
	loadimage(&img, "��.jpg", IMG_W, IMG_H);

	//��ȡͼ���к���
	int row = img.getheight();
	int cols = img.getwidth();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//��ȡÿһ�������ɫ��i,j
			SetWorkingImage(&img);  //����ͼ���ǹ�����
			COLORREF color = getpixel(j, i);
			//printf("COLOR:%lu", color);
			SetWorkingImage();       //�ر�
			//ͨ�������ɫ����һС��
			drawBlock(j * BLOCK_W, i * BLOCK_H, BLOCK_W, BLOCK_H, color, "ϲ����");
		}
	}
	//�������ص㶼ת��ΪһС�飬���Ƶ����ڣ�ֱ�ӱ��浽����


	saveimage("����.jpg");
}

int main()
{
	initgraph(IMG_W * BLOCK_W, IMG_H * BLOCK_H);
	replaceByBlock();           //�滻�����ص�

	while (1)
	{
		//��ֹ����
	}
	closegraph();
	return 0;
}
