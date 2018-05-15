#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct dispStr
{
	int numOfLines;
	char allStr[50][64];
};

struct dispStr bufferDisplayStr(FILE* fp);
void display(dispStr);
void transitionAmida(char, dispStr);


int main(void) {
	// あみだくじテンプレートを開く
	FILE *templeFilePointer, *resultFilePointer; // FILE型構造体
	char amidaTempleteFile[] = "C:\\Users\\bthirai1\\Desktop\\あみだくじ1.txt";
	char amidaResultFile[] = "C:\\Users\\bthirai1\\Desktop\\あみだくじ結果1.txt";
	char choiceChar;

	templeFilePointer = fopen(amidaTempleteFile, "r");
	resultFilePointer = fopen(amidaResultFile, "r");
	if (templeFilePointer == NULL || resultFilePointer == NULL) {
		printf("ファイルオープン失敗\n");
		return -1;
	}

	//ファイル内容をバッファ領域に格納
	struct dispStr dispTemplete;
	dispTemplete = bufferDisplayStr(templeFilePointer);

	// ファイルの内容を出力（あみだくじのテンプレート）
	display(dispTemplete);
	
	// くじの選択
	printf("\nくじを選んでください。：");
	scanf("%c", &choiceChar);
	printf("\n");
	rewind(stdin);

	transitionAmida(choiceChar, dispTemplete);

	// 結果の出力
	//display(resultFilePointer);
		
	// file close
	fclose(templeFilePointer);
	getchar();

	return 0;
}

struct dispStr bufferDisplayStr(FILE* fp) {
	char lineStr[64];
	struct dispStr dispStr;
	int i = 0;
	while ((fgets(lineStr, 64, fp)) != NULL) {
		memcpy(dispStr.allStr[i], lineStr, 64);
		i = i + 1;
	}
	dispStr.numOfLines = i;
	return dispStr;
}

void display(dispStr dispStr) {
	int i = 0;
	for (i = 0;i < dispStr.numOfLines;i++) {
		printf("%s", dispStr.allStr[i]);
	}
}

void transitionAmida(char choice, dispStr dispTemplete) {
	bool duringTransition= TRUE;
	int a = 0;
	int i = 0;
	
	printf("あみだくじの開始です。");
	Sleep(1 * 1000);

	while (duringTransition) {
		//画面クリア
		system("cls");
		int i = 0;
		for (i = 0;i < dispTemplete.numOfLines;i++) {

			printf("%s", dispTemplete.allStr[i]);
		}

		//for debug
		a = a + 1;
		printf("debug:%d", a);
		//マーカー移動のインターバル
		Sleep(1 * 1000);
	}
	//選択した番号の下にマーカー(*)を配置する。

}