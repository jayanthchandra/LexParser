#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char stack[1000];
char production[45][20];
int top=1;
char table[85][50][5];

int reduce(int p,FILE *fp1);
void shift(char ch,int p,FILE *fp1);
int action(char ch,FILE *fp1);
int ret_column(char c);
void error_msg(char ch);
int main()
{
	FILE *fp1;
	fp1=fopen("logfile.txt","w");
	int a=0;
	FILE *fp;
	int i,j,k;
	int act;
	int count=0,line_no=0,odd=0;
	char ch,prevch;
	
	stack[0]='$';
	stack[1]='0';
	
	fp=fopen("output.c","r");
	
	for(i=0;i<85;i++)
	{
		for(j=0;j<50;j++)
		{
		
				strcpy(table[i][j],"-1");
		
		}
	}

//intializing table

	
	

strcpy(table[0][10],"s2");
strcpy(table[0][26],"1");
strcpy(table[1][25],"acc");
strcpy(table[2][14],"s3");
strcpy(table[3][1],"s4");
strcpy(table[4][2],"s5");
strcpy(table[5][23],"s7");
strcpy(table[5][27],"6");
strcpy(table[6][25],"r1");
strcpy(table[7][8],"r4");
strcpy(table[7][10],"r4");
strcpy(table[7][12],"r4");
strcpy(table[7][13],"r4");
strcpy(table[7][16],"r4");
strcpy(table[7][17],"r4");
strcpy(table[7][19],"r4");
strcpy(table[7][23],"r4");
strcpy(table[7][24],"r4");
strcpy(table[7][28],"8");
strcpy(table[8][8],"r9");
strcpy(table[8][10],"s12");
strcpy(table[8][11],"r9");
strcpy(table[8][13],"r9");
strcpy(table[8][16],"r9");
strcpy(table[8][17],"r9");
strcpy(table[8][19],"r9");
strcpy(table[8][23],"r9");
strcpy(table[8][24],"r9");
strcpy(table[8][29],"9");
strcpy(table[8][30],"10");
strcpy(table[8][31],"11");
strcpy(table[9][8],"s21");
strcpy(table[9][12],"s22");
strcpy(table[9][13],"s23");
strcpy(table[9][16],"s24");
strcpy(table[9][17],"s25");
strcpy(table[9][19],"s26");
strcpy(table[9][23],"s7");
strcpy(table[9][24],"r35");
strcpy(table[9][27],"13");
strcpy(table[9][32],"14");
strcpy(table[9][33],"15");
strcpy(table[9][34],"16");
strcpy(table[9][35],"17");
strcpy(table[9][36],"18");
strcpy(table[9][38],"19");
strcpy(table[9][44],"20");
strcpy(table[10][8],"r3");
strcpy(table[10][10],"r3");
strcpy(table[10][12],"r3");
strcpy(table[10][13],"r3");
strcpy(table[10][16],"r3");
strcpy(table[10][17],"r3");
strcpy(table[10][19],"r3");
strcpy(table[10][23],"r3");
strcpy(table[10][24],"r3");
strcpy(table[11][8],"s27");
strcpy(table[12][8],"r7");
strcpy(table[13][8],"r11");
strcpy(table[13][12],"r11");
strcpy(table[13][13],"r11");
strcpy(table[13][16],"r11");
strcpy(table[13][17],"r11");
strcpy(table[13][19],"r11");
strcpy(table[13][23],"r11");
strcpy(table[13][24],"r11");
strcpy(table[14][8],"r8");
strcpy(table[14][12],"r8");
strcpy(table[14][13],"r8");
strcpy(table[14][16],"r8");
strcpy(table[14][17],"r8");
strcpy(table[14][19],"r8");
strcpy(table[14][23],"r8");
strcpy(table[14][24],"r8");
strcpy(table[15][8],"r8");
strcpy(table[15][12],"r10");
strcpy(table[15][13],"r10");
strcpy(table[15][16],"r10");
strcpy(table[15][17],"r10");
strcpy(table[15][19],"r10");
strcpy(table[15][23],"r10");
strcpy(table[15][24],"r10");
strcpy(table[16][8],"r12");
strcpy(table[16][12],"r12");
strcpy(table[16][13],"r12");
strcpy(table[16][16],"r12");
strcpy(table[16][17],"r12");
strcpy(table[16][19],"r12");
strcpy(table[16][23],"r12");
strcpy(table[16][24],"r12");
strcpy(table[17][8],"r13");
strcpy(table[17][12],"r13");
strcpy(table[17][13],"r13");
strcpy(table[17][16],"r13");
strcpy(table[17][17],"r13");
strcpy(table[17][19],"r13");
strcpy(table[17][23],"r13");
strcpy(table[17][24],"r13");
strcpy(table[18][8],"r14");
strcpy(table[18][12],"r14");
strcpy(table[18][13],"r14");
strcpy(table[18][16],"r14");
strcpy(table[18][17],"r14");
strcpy(table[18][19],"r14");
strcpy(table[18][23],"r14");
strcpy(table[18][23],"r14");
strcpy(table[19][5],"s28");
strcpy(table[20][24],"s29");
strcpy(table[21][2],"r28");
strcpy(table[21][4],"r28");
strcpy(table[21][5],"r28");
strcpy(table[21][6],"s30");
strcpy(table[21][7],"r28");
strcpy(table[21][20],"r28");
strcpy(table[21][21],"r28");
strcpy(table[21][22],"r28");
strcpy(table[22][1],"s31");
strcpy(table[23][1],"s32");
strcpy(table[24][1],"s33");
strcpy(table[25][4],"s34");
strcpy(table[25][8],"s21");
strcpy(table[25][15],"s38");
strcpy(table[25][37],"35");
strcpy(table[25][38],"36");
strcpy(table[25][39],"37");
strcpy(table[26][1],"s39");
strcpy(table[27][4],"s40");
strcpy(table[27][6],"s41");
strcpy(table[28][8],"s21");
strcpy(table[28][15],"s38");
strcpy(table[28][37],"42");
strcpy(table[28][38],"36");
strcpy(table[28][39],"37");
strcpy(table[29][8],"r2");
strcpy(table[29][11],"r2");
strcpy(table[29][12],"r2");
strcpy(table[29][13],"r2");
strcpy(table[29][16],"r2");
strcpy(table[29][17],"r2");
strcpy(table[29][19],"r2");
strcpy(table[29][23],"r2");
strcpy(table[29][24],"r2");
strcpy(table[29][25],"r2");
strcpy(table[30][8],"s21");
strcpy(table[30][38],"43");
strcpy(table[31][2],"r19");
strcpy(table[31][4],"r19");
strcpy(table[31][8],"s21");
strcpy(table[31][15],"s38");
strcpy(table[31][37],"44");
strcpy(table[31][38],"36");
strcpy(table[31][39],"37");
strcpy(table[31][48],"45");
strcpy(table[32][8],"s21");
strcpy(table[32][15],"s38");
strcpy(table[32][37],"46");
strcpy(table[32][38],"36");
strcpy(table[32][39],"37");
strcpy(table[56][2],"r29");
strcpy(table[56][4],"r29");
strcpy(table[56][5],"r29");
strcpy(table[56][7],"r29");
strcpy(table[56][20],"r29");
strcpy(table[56][21],"r29");
strcpy(table[56][22],"r29");
strcpy(table[57][2],"r19");
strcpy(table[57][4],"r19");
strcpy(table[57][8],"s21");
strcpy(table[57][15],"s38");
strcpy(table[57][37],"44");
strcpy(table[57][38],"36");
strcpy(table[57][39],"37");
strcpy(table[57][48],"65");
strcpy(table[58][23],"s7");
strcpy(table[58][27],"66");
strcpy(table[59][0],"r36");
strcpy(table[59][9],"r36");
strcpy(table[59][45],"67");
strcpy(table[60][0],"r38");
strcpy(table[60][9],"r38");
strcpy(table[61][0],"r44");
strcpy(table[61][9],"r44");
strcpy(table[62][2],"r24");
strcpy(table[62][4],"r24");
strcpy(table[63][23],"s7");
strcpy(table[63][27],"68");
strcpy(table[64][4],"s69");
strcpy(table[65][4],"s70");
strcpy(table[66][8],"r15");
strcpy(table[66][11],"s71");
strcpy(table[66][12],"r15");
strcpy(table[66][13],"r15");
strcpy(table[66][16],"r15");
strcpy(table[66][17],"r15");
strcpy(table[66][19],"r15");
strcpy(table[66][23],"r15");
strcpy(table[66][24],"r15");
strcpy(table[67][0],"s72");
strcpy(table[67][9],"s74");
strcpy(table[67][47],"73");
strcpy(table[68][8],"r17");
strcpy(table[68][12],"r17");
strcpy(table[68][13],"r17");
strcpy(table[68][16],"r17");
strcpy(table[68][17],"r17");
strcpy(table[68][19],"r17");
strcpy(table[68][23],"r17");
strcpy(table[68][24],"r17");
strcpy(table[69][8],"r6");
strcpy(table[69][8],"r6");
strcpy(table[69][10],"r6");
strcpy(table[69][12],"r6");
strcpy(table[69][13],"r6");
strcpy(table[69][16],"r6");
strcpy(table[69][17],"r6");
strcpy(table[69][19],"r6");
strcpy(table[69][23],"r6");
strcpy(table[69][24],"r6");
strcpy(table[70][2],"r19");
strcpy(table[70][4],"r19");
strcpy(table[70][8],"s21");
strcpy(table[70][15],"s38");
strcpy(table[70][37],"44");
strcpy(table[70][38],"36");
strcpy(table[70][39],"37");
strcpy(table[70][48],"75");
strcpy(table[33][0],"s47");
strcpy(table[34][8],"r21");
strcpy(table[34][12],"r21");
strcpy(table[34][13],"r21");
strcpy(table[34][16],"r21");
strcpy(table[34][17],"r21");
strcpy(table[34][19],"r21");
strcpy(table[34][23],"r21");
strcpy(table[34][24],"r21");
strcpy(table[35][4],"s48");
strcpy(table[36][2],"r26");
strcpy(table[36][2],"r26");
strcpy(table[36][4],"r26");
strcpy(table[36][20],"r26");
strcpy(table[36][21],"r26");
strcpy(table[36][22],"r26");
strcpy(table[37][2],"r25");
strcpy(table[37][4],"r25");
strcpy(table[37][20],"s50");
strcpy(table[37][21],"s51");
strcpy(table[37][22],"s52");
strcpy(table[37][40],"49");
strcpy(table[38][2],"r27");
strcpy(table[38][4],"r27");
strcpy(table[38][20],"r27");
strcpy(table[38][21],"r27");
strcpy(table[38][22],"r27");

strcpy(table[33][21],"r27");
strcpy(table[39][8],"s21");
strcpy(table[39][15],"s38");
strcpy(table[39][37],"53");
strcpy(table[39][38],"36");
strcpy(table[39][39],"37");
strcpy(table[40][8],"r5");
strcpy(table[40][10],"r5");
strcpy(table[40][12],"r5");
strcpy(table[40][13],"r5");
strcpy(table[40][16],"r5");
strcpy(table[40][17],"r5");
strcpy(table[40][19],"r5");
strcpy(table[40][23],"r5");
strcpy(table[40][24],"r5");
strcpy(table[41][15],"s54");
strcpy(table[42][4],"s55");
strcpy(table[43][7],"s56");
strcpy(table[44][2],"r20");
strcpy(table[44][4],"r20");
strcpy(table[45][4],"s57");
strcpy(table[46][2],"s58");
strcpy(table[47][0],"r34");
strcpy(table[47][8],"s60");
strcpy(table[47][9],"r34");
strcpy(table[47][15],"s61");
strcpy(table[47][42],"59");
strcpy(table[48][8],"r22");
strcpy(table[48][12],"r22");
strcpy(table[48][13],"r22");
strcpy(table[48][16],"r22");
strcpy(table[48][17],"r22");
strcpy(table[48][19],"r22");
strcpy(table[48][23],"r22");
strcpy(table[48][24],"r22");
strcpy(table[49][8],"s21");
strcpy(table[49][15],"s38");
strcpy(table[49][38],"36");
strcpy(table[49][39],"62");
strcpy(table[50][8],"r30");
strcpy(table[50][15],"r30");
strcpy(table[51][8],"r31");
strcpy(table[51][15],"r31");
strcpy(table[52][8],"r32");
strcpy(table[52][15],"r32");
strcpy(table[53][2],"s63");
strcpy(table[54][7],"s64");
strcpy(table[55][8],"r23");
strcpy(table[55][12],"r23");
strcpy(table[55][13],"r23");
strcpy(table[55][16],"r23");
strcpy(table[55][17],"r23");
strcpy(table[55][19],"r23");
strcpy(table[55][23],"r23");
strcpy(table[55][24],"r23");
strcpy(table[84][2],"r40");
strcpy(table[84][3],"r40");
strcpy(table[83][24],"r33");
strcpy(table[82][8],"r18");
strcpy(table[82][12],"r18");
strcpy(table[82][13],"r18");
strcpy(table[82][16],"r18");
strcpy(table[82][17],"r18");
strcpy(table[82][19],"r18");
strcpy(table[82][23],"r18");
strcpy(table[82][24],"r18");
strcpy(table[81][8],"s84");
strcpy(table[80][4],"s83");
strcpy(table[79][23],"s7");
strcpy(table[79][27],"s82");
strcpy(table[78][0],"r37");
strcpy(table[78][9],"r37");
strcpy(table[77][2],"s80");
strcpy(table[77][3],"s81");
strcpy(table[76][8],"r16");
strcpy(table[76][12],"r16");
strcpy(table[76][13],"r16");
strcpy(table[76][16],"r16");
strcpy(table[76][17],"r16");
strcpy(table[76][19],"r16");
strcpy(table[76][23],"r16");
strcpy(table[76][24],"r16");
strcpy(table[75][2],"s79");
strcpy(table[74][0],"r39");
strcpy(table[74][8],"r39");
strcpy(table[74][9],"r39");
strcpy(table[74][15],"r39");
strcpy(table[73][0],"r34");
strcpy(table[73][8],"s60");
strcpy(table[73][9],"r34");
strcpy(table[73][15],"s61");
strcpy(table[73][42],"78");
strcpy(table[72][2],"r41");
strcpy(table[72][3],"r41");
strcpy(table[72][41],"77");
strcpy(table[71][23],"s7");
strcpy(table[71][27],"76");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");
strcpy(table[55][24],"r23");

//intializing production array

strcpy(production[0],"A'A");
strcpy(production[1],"Adm()B");
strcpy(production[2],"B{CDT}");
strcpy(production[3],"CCE");
strcpy(production[4],"Cc");
strcpy(production[5],"EFa;");
strcpy(production[6],"EFa[n];");
strcpy(production[7],"Fd");
strcpy(production[8],"DDG");
strcpy(production[9],"Dc");
strcpy(production[10],"GH");
strcpy(production[11],"GB");
strcpy(production[12],"GI");
strcpy(production[13],"GJ");
strcpy(production[14],"GK");
strcpy(production[15],"Ii(L)B");
strcpy(production[16],"Ii(L)BeB");
strcpy(production[17],"Jw(L)B");
strcpy(production[18],"Jf(Z;Z;Z)B");
strcpy(production[19],"Zc");
strcpy(production[20],"ZL");
strcpy(production[21],"Kr;");
strcpy(production[22],"KrL;");
strcpy(production[23],"HN=L");
strcpy(production[24],"LOPO");
strcpy(production[25],"LO");
strcpy(production[26],"ON");
strcpy(production[27],"On");
strcpy(production[28],"Na");
strcpy(production[29],"Na[N]");
strcpy(production[30],"Px");
strcpy(production[31],"Py");
strcpy(production[32],"Pz");
strcpy(production[33],"Tp(\"RV\"Q);");
strcpy(production[34],"Rc");
strcpy(production[35],"Tc");
strcpy(production[36],"Vc");
strcpy(production[37],"VVXR");
strcpy(production[38],"Ra");
strcpy(production[39],"Xb");
strcpy(production[40],"QQ,a");
strcpy(production[41],"Qc");
strcpy(production[42],"Ss(\"V\",W);");
strcpy(production[43],"Wza");
strcpy(production[44],"Rn");





ch=fgetc(fp);
++line_no;
ch=fgetc(fp);

while(1)
{
	if(!(ch =="  "||ch =="\n"))
	act=action(ch,fp1);
	fprintf(fp1,"action number: %d\n",++a);//to file
	if(act==1)
	continue;
	prevch=ch;
	ch=fgetc(fp);
	++count;
	while(ch>=48&&ch<=57)
	{
		ch=fgetc(fp);
		count=0;
		if(line_no<=9)
		{	++line_no;
			continue;		
		}
		if(line_no>9)
		{
			if((odd%2)==0)
			{
				++odd;
				++line_no;
				continue;			
			}
		++odd;
		continue;
		}	
		if(line_no>=100)	
		{	if(odd%2!=0)
			{
				++odd;
				++line_no;
				continue;			
			}
		++odd;
		continue;
		}

	}
	if(act==-1)
	{
		printf("\n\nProgram is syntactically wrong\n");
		if(line_no>10)
		printf("Error in or before line number:%d\nBefore token:%d\n",--line_no,count);
		else
		printf("Error in or before line number:%d\nBefore token:%d\n",line_no,count);
		error_msg(prevch);
        return 0;
	}	
	if(act==5)
		{printf("\n\nProgram is syntactically correct\n\n");return 0;}
}
}




int action(char ch,FILE *fp1)
{ 	
	int state=0,count=1,i;
	int row=0;
	int temp=top;
	
	for(i=temp;stack[i]>='0'&&stack[i]<='9';i--)
	{
		row=row+((int)(stack[i]-48))*count;
		count*=10;
		
	}
	fprintf(fp1,"\nRow Number = %d\n",row);//to file
	fprintf(fp1,"\ninput character= %c\n",ch);//to file
	if(table[row][ret_column(ch)][0]=='s')
	{
		for(i=1;table[row][ret_column(ch)][i]!='\0';i++)
		{
			state=state*10+(int)(table[row][ret_column(ch)][i])-48;
		}
		fprintf(fp1,"action=shift\n");//to file
		shift(ch,state,fp1);
		
		return 0;
	}
	else if(table[row][ret_column(ch)][0]=='r')
	{
		for(i=1;table[row][ret_column(ch)][i]!='\0';i++)
		{
			state=state*10+(int)(table[row][ret_column(ch)][i])-48;
		}
		fprintf(fp1,"action=reduce\n");//to file
		reduce(state,fp1);
		
		
		return 1;
	}
	else if(table[row][ret_column(ch)][0]=='-')
	{
		return -1;
	}
	else return 5;
}

//SHIFT OPERATION
void shift(char ch, int state,FILE *fp1)
{
	stack[++top]=ch;
	if(state/10==0)
		stack[++top]=state+48;
	else
	{
		stack[++top]=state/10 + 48;
		state=state%10;
		stack[++top]=state + 48;
		
	}
	stack[top+1]='\0';
	fprintf(fp1,"stack contents: %s\n",stack);//to file
}

// REDUCE OPERATION

int reduce(int p,FILE *fp1)
{
	int temp=top,count=1,row=0,i,state=0;
	char a=production[p][1];
	if(p==4||p==9||p==19||p==34||p==35||p==36||p==41)
	{	
		stack[++top]=production[p][0];
		temp=top;	
		for(i=temp-1;stack[i]>='0'&&stack[i]<='9';i--)
		{
			row=row+(stack[i]-48)*count;
			count*=10;
			
		}
		
	
		for(i=0;table[row][ret_column(stack[temp])][i]!='\0';i++)
		{ 
			stack[++top]=table[row][ret_column(stack[temp])][i];
		
		}
		stack[top+1]='\0';
		fprintf(fp1,"stack contents: %s\n",stack);//to file
		if(i>1)
			return 1;
		return 0;
	}
	else
	{
		while(stack[temp]!=a)
		{	
			stack[temp]='\0';
			--temp;
		}
	

		if(p==24)
		{--temp;
			while(stack[temp]!=a)
			{		
				stack[temp]='\0';
				--temp;
			}
		}
		top=temp;
		stack[temp]=production[p][0];
	}
	
	for(i=top-1;stack[i]>='0'&&stack[i]<='9';i--)
	{
		row=row+(stack[i]-48)*count;
		count*=10;
		
	}
	fprintf(fp1,"stack element replaced in reduce: %c\n",stack[temp]);//to file
	for(i=0;table[row][ret_column(stack[temp])][i]!='\0';i++)
	{
		stack[++top]=table[row][ret_column(stack[temp])][i];
		
	}
	stack[top+1]='\0';
	fprintf(fp1,"stack contents: %s\n",stack);//to file
	if(i>1)
		return 1;
	return 0;
	
}

	


int ret_column(char c)
	{
		switch(c)
		{
		
		
		
			case '\"':return 0;
					break;
			case '(':return 1;
					break;
			case ')':return 2;
					break;
			case ',':return 3;
					break;
			case ';':return 4;
					break;
			case '=':return 5;
					break;
			case '[':return 6;
					break;
			case ']':return 7;
					break;
			case 'a':return 8;
					break;
			case 'b':return 9;
					break;
			case 'd':return 10;
					break;
			case 'e':return 11;
					break;
			case 'f':return 12;
					break;
			case 'i':return 13;
					break;
			case 'm':return 14;
					break;
			case 'n':return 15;
					break;
			case 'p':return 16;
					break;
			case 'r':return 17;
					break;
			case 's':return 18;
					break;
			case 'w':return 19;
					break;
			case 'x':return 20;
					break;
			case 'y':return 21;
					break;
			case 'z':return 22;
					break;
			case '{':return 23;
					break;
			case '}':return 24;
					break;
			case '$':return 25;
					break;
			case 'A':return 26;
					break;
			case 'B':return 27;
					break;
			case 'C':return 28;
					break;
			case 'D':return 29;
					break;
			case 'E':return 30;
					break;
			case 'F':return 31;
					break;
			case 'G':return 32;
					break;
			case 'H':return 33;
					break;
			case 'I':return 34;
					break;
			case 'J':return 35;
					break;
			case 'K':return 36;
					break;
			case 'L':return 37;
					break;
			case 'N':return 38;
					break;
			case 'O':return 39;
					break;
			case 'P':return 40;
					break;
			case 'Q':return 41;
					break;
			case 'R':return 42;
					break;
			case 'S':return 43;
					break;
			case 'T':return 44;
					break;
			case 'V':return 45;
					break;
			case 'W':return 46;
					break;
			case 'X':return 47;
					break;
			case 'Z':return 48;
					break;
	}
}

void error_msg(char ch)
	{
		switch(ch)
		{
			case '\"':printf("Error might be: missing '(' after printf or scanf\n\n");
				break;
			case '(':printf("Error might be: missing main function\nor missing 'if','for','while','printf' or 'scanf'\n\n");
				break;
			case ')':printf("Error might be: missing '(' after 'main'\nor illegal expression in if,for or while statements\nor missing \" in printf or scanf statement\n\n");
				break;
			case ',':printf("Error might be: missing \" in printf or scanf statement\nor missing identifier in declaration list\n\n");
				break;
			case ';':printf("Error might be: missing identifier in variable declaration\nor missing ')' in printf or scanf statement\nor illegal expression in for statement\n\n");
				break;
			case '=':printf("Error might be: missing variable before '=' to store value of assignment\nor illegal expression\nor illegal declaration statement\n\n");
				break;
			case '[':printf("Error might be: missing array name\n\n");
				break;
			case ']':printf("Error might be: missing array index\n\n");
				break;
			case 'a':printf("Error might be: missing data type for variable declaration\nor missing \" in printf or scanf statement\n");
				printf("or missing identifier after , in printf or scanf statement\nillegal expression\nor missing '(' in if,for or while statement\n\n");
				break;

			case 'b':printf("Error might be: missing \" in printf or scanf statement\n\n");
				break;
			case 'd':printf("Error might be: missing '{'\nor missing terminating character\n\n");
				break;

			case 'e':printf("Error might be: missing '}'\n or dangling else\n\n");
				break;
			case 'f':printf("Error might be: missing '{' or '}'\n\n");
				break;
			case 'i':printf("Error might be: missing '{' or '}'\n\n");
				break;
			case 'm':printf("Error might be: missing 'int' in 'int main'\n\n");
				break;
			case 'n':printf("Error might be: illegal expression\n\n");
				break;
			case 'p':printf("Error might be: missing '{' before printf or scanf\n\n");
				break;
			case 'r':printf("Error might be: missing '}'\n\n");
				break;
			case 'w':printf("Error might be: missing '{' or '}'\n\n");
				break;
			case 'x':printf("Error might be: illegal expression\n\n");
				break;
			case 'y':printf("Error might be: illegal expression\n\n");
				break;
			case 'z':printf("Error might be: illegal expression\n\n");
				break;
			case '{':printf("Error might be: missing ')'after main\nor missing terminating character\nor missing '(' in if,for or while statement\nor missing '}'\n\n");
				break;
			case '}':printf("Error might be: missing ';'\n\n");
				break;
			case '$':printf("Error might be: missing ';'\n or missing '}'\n\n");
				break;	
		}
	}	
