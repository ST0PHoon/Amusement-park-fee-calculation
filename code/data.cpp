#include <stdio.h>
//���� ���� 
const int MAX = 100;

int count = 0, k=0, dayTotal=0;

int year[MAX], month[MAX], day[MAX],
	ticketTimeCaseArr[MAX],wooDaeArr[MAX],ageCaseArr[MAX],ticketSuArr[MAX],ticketPriceArr[MAX],
	ageTicketCase[50][50]={0}, wooDeaArrOut[30]={0}, dayDataOut[30][6]={0};
//�Լ� ���� 
void fileOpen() {

	FILE *fp = fopen("report.csv","r");

	while ( fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d",&year[count], &month[count], &day[count],
		&ticketTimeCaseArr[count], &wooDaeArr[count], &ageCaseArr[count], &ticketSuArr[count], &ticketPriceArr[count]) != -1) {

		count++;		
	}
	fclose(fp);
}

void totalDataPrint() {
	printf("\n========================= ������ =========================");
	printf("\n��¥           Ƽ��    ���   ����    �ż�      ����\n");
	for (int i = 0; i < count; i ++) {
		printf ("%d��%2d��%2d��\t%d\t%d\t%d\t%d\t%d\n",year[i], month[i], day[i],
		ticketTimeCaseArr[i], wooDaeArr[i], ageCaseArr[i], ticketSuArr[i], ticketPriceArr[i]);
	}
	printf("\n==========================================================\n");
}

void calTicketData() {
 	for(int i = 0; i < count; i++) {
		switch(ticketTimeCaseArr[i]) {
			case 1: //���� + 1Day 
				switch(ageCaseArr[i]) {
					case 1: //�
						ageTicketCase[0][1] += ticketSuArr[i];
						ageTicketCase[2][1] += ticketSuArr[i];
						break;
 					case 2: //û�ҳ� 
						ageTicketCase[0][2] += ticketSuArr[i];
						ageTicketCase[2][2] += ticketSuArr[i];
						break;	
					case 3: //��� 
						ageTicketCase[0][3] += ticketSuArr[i];
						ageTicketCase[2][3] += ticketSuArr[i];
						break;
					case 4: //���� 
						ageTicketCase[0][4] += ticketSuArr[i];
						ageTicketCase[2][4] += ticketSuArr[i];
						break;
					case 5: //���� 
						ageTicketCase[0][5] += ticketSuArr[i];
						ageTicketCase[2][5] += ticketSuArr[i];
						break;
					case 6: //����  
						ageTicketCase[0][6] += ticketSuArr[i];
						ageTicketCase[2][6] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				ageTicketCase[0][7] += ticketPriceArr[i];  //Ƽ�� ������ ���� 
				ageTicketCase[2][7] += ticketPriceArr[i];
				ageTicketCase[0][0] += ticketSuArr[i];     // Ƽ�� ������ �ż� 
				ageTicketCase[2][0] += ticketSuArr[i];
				break;
			case 2: //���� + 4���� 
				switch(ageCaseArr[i]) {
					case 1: //�
						ageTicketCase[0][1] += ticketSuArr[i];
						ageTicketCase[3][1] += ticketSuArr[i];
						break;
 					case 2: //û�ҳ� 
						ageTicketCase[0][2] += ticketSuArr[i];
						ageTicketCase[3][2] += ticketSuArr[i];
						break;	
					case 3: //��� 
						ageTicketCase[0][3] += ticketSuArr[i];
						ageTicketCase[3][3] += ticketSuArr[i];
						break;
					case 4: //���� 
						ageTicketCase[0][4] += ticketSuArr[i];
						ageTicketCase[3][4] += ticketSuArr[i];
						break;
					case 5: //���� 
						ageTicketCase[0][5] += ticketSuArr[i];
						ageTicketCase[3][5] += ticketSuArr[i];
						break;
					case 6: //����  
						ageTicketCase[0][6] += ticketSuArr[i];
						ageTicketCase[3][6] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				ageTicketCase[0][7] += ticketPriceArr[i];
				ageTicketCase[3][7] += ticketPriceArr[i];
				ageTicketCase[0][0] += ticketSuArr[i];
				ageTicketCase[3][0] += ticketSuArr[i];
				break;
			case 3: //��ũ + 1Day
				switch(ageCaseArr[i]) {
					case 1: //�
						ageTicketCase[1][1] += ticketSuArr[i];
						ageTicketCase[2][1] += ticketSuArr[i];
						break;
 					case 2: //û�ҳ� 
						ageTicketCase[1][2] += ticketSuArr[i];
						ageTicketCase[2][2] += ticketSuArr[i];
						break;	
					case 3: //��� 
						ageTicketCase[1][3] += ticketSuArr[i];
						ageTicketCase[2][3] += ticketSuArr[i];
						break;
					case 4: //���� 
						ageTicketCase[1][4] += ticketSuArr[i];
						ageTicketCase[2][4] += ticketSuArr[i];
						break;
					case 5: //���� 
						ageTicketCase[1][5] += ticketSuArr[i];
						ageTicketCase[2][5] += ticketSuArr[i];
						break;
					case 6: //����  
						ageTicketCase[1][6] += ticketSuArr[i];
						ageTicketCase[2][6] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				ageTicketCase[1][7] += ticketPriceArr[i];
				ageTicketCase[2][7] += ticketPriceArr[i];
				ageTicketCase[1][0] += ticketSuArr[i];
				ageTicketCase[2][0] += ticketSuArr[i];
				break;
			case 4: //��ũ + 4����
				switch(ageCaseArr[i]) {
					case 1: //�
						ageTicketCase[1][1] += ticketSuArr[i];
						ageTicketCase[3][1] += ticketSuArr[i];
						break;
 					case 2: //û�ҳ� 
						ageTicketCase[1][2] += ticketSuArr[i];
						ageTicketCase[3][2] += ticketSuArr[i];
						break;	
					case 3: //��� 
						ageTicketCase[1][3] += ticketSuArr[i];
						ageTicketCase[3][3] += ticketSuArr[i];
						break;
					case 4: //���� 
						ageTicketCase[1][4] += ticketSuArr[i];
						ageTicketCase[3][4] += ticketSuArr[i];
						break;
					case 5: //���� 
						ageTicketCase[1][5] += ticketSuArr[i];
						ageTicketCase[3][5] += ticketSuArr[i];
						break;
					case 6: //����  
						ageTicketCase[1][6] += ticketSuArr[i];
						ageTicketCase[3][6] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				ageTicketCase[1][7] += ticketPriceArr[i];
				ageTicketCase[3][7] += ticketPriceArr[i];
				ageTicketCase[1][0] += ticketSuArr[i];
				ageTicketCase[3][0] += ticketSuArr[i];
				break;
			default:
				break;
		}
	//�� Ƽ�� �Ǹ� ��, ���ú� Ƽ�ϼ� �м�
		switch (wooDaeArr[i]) {
			case 1:
				wooDeaArrOut[1] += ticketSuArr[i];
				break;
			case 2:
				wooDeaArrOut[2] += ticketSuArr[i];
				break;
			case 3:
				wooDeaArrOut[3] += ticketSuArr[i];
				break;
			case 4:
				wooDeaArrOut[4] += ticketSuArr[i];
				break;
			case 5:
				wooDeaArrOut[5] += ticketSuArr[i];
				break;
			case 6:
				wooDeaArrOut[6] += ticketSuArr[i];
				break;
			default:
				break;
		}
	
	}
} 

void calDiscountData() {
	for(int i = 0; i < count; i++) {
		switch (wooDaeArr[i]) {
			case 1:
				wooDeaArrOut[1] += ticketSuArr[i];
				break;
			case 2:
				wooDeaArrOut[2] += ticketSuArr[i];
				break;
			case 3:
				wooDeaArrOut[3] += ticketSuArr[i];
				break;
			case 4:
				wooDeaArrOut[4] += ticketSuArr[i];
				break;
			case 5:
				wooDeaArrOut[5] += ticketSuArr[i];
				break;
			case 6:
				wooDeaArrOut[6] += ticketSuArr[i];
				break;
			default:
				break;
		}	
	}
	//�� Ƽ�� ��
	for (int i =1; i<=6; i++) {
		wooDeaArrOut[0]+=wooDeaArrOut[i];
	} 
}

void calDayMoneyData() {
	dayDataOut[0][0]=year[0], dayDataOut[0][1]=month[0], dayDataOut[0][2]=day[0], dayDataOut[0][3]=ticketPriceArr[0];
	
	for(int j = 1; j < count; j++) {
		if (dayDataOut[k][0]==year[j] && dayDataOut[k][1]==month[j] && dayDataOut[k][2]==day[j]){ //���� ���� ��¥�� ������? 
			dayDataOut[k][3]+=ticketPriceArr[j];
		} else {
			k++; // ��¥�� �ٸ��ٸ� ���� �࿡ ���ο� ��¥,���� �Է� 
			dayDataOut[k][0]=year[j], dayDataOut[k][1]=month[j], dayDataOut[k][2]=day[j], dayDataOut[k][3]=ticketPriceArr[j];
		}	
	}
}

void ticketDataPrint() {
	//Ƽ�� ���� ��, ���ɴ� ���� �м� / �ð��� �� ����� 
	printf("\n======================= ���� �� �Ǹ� ��Ȳ =======================\n");
	printf("���ձ� �� %d��\n",ageTicketCase[0][0]);
	printf("���� %d��,���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",ageTicketCase[0][5],
						ageTicketCase[0][3],ageTicketCase[0][2],ageTicketCase[0][1],ageTicketCase[0][0],ageTicketCase[0][4]);
	printf("���ձ� ���� : %d��\n\n",ageTicketCase[0][7]);
	
	printf("��ũ�� �� %d��\n",ageTicketCase[1][0]);
	printf("���� %d��,���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",ageTicketCase[1][5],
						ageTicketCase[1][3],ageTicketCase[1][2],ageTicketCase[1][1],ageTicketCase[1][0],ageTicketCase[1][4]);
	printf("��ũ�� ���� : %d��\n\n",ageTicketCase[1][7]); 

	printf("1Day�� �� %d��\n",ageTicketCase[2][0]);
	printf("���� %d��,���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",ageTicketCase[2][5],
						ageTicketCase[2][3],ageTicketCase[2][2],ageTicketCase[2][1],ageTicketCase[2][0],ageTicketCase[2][4]);
	printf("1Day�� ���� : %d��\n\n",ageTicketCase[2][7]); 

	printf("4�ñ� �� %d��\n",ageTicketCase[3][0]);
	printf("���� %d��,���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",ageTicketCase[3][5],
						ageTicketCase[3][3],ageTicketCase[3][2],ageTicketCase[3][1],ageTicketCase[3][0],ageTicketCase[3][4]);
	printf("4�ñ� ���� : %d��\n",ageTicketCase[3][7]); 
	printf("================================================================\n"); 
}

void discountDataPrint() {
	//�� Ƽ�� �Ǹ� ��, ���ú� Ƽ�ϼ� �м�
	printf("\n=================== ������ �м� ===================\n");
	printf("�� Ƽ�� �Ǹż�       : %d��\n",wooDeaArrOut[0]);
	printf("������ ����        : %d��\n",wooDeaArrOut[1]);
	printf("����� ���          : %d��\n",wooDeaArrOut[2]);
	printf("���������� ���      : %d��\n",wooDeaArrOut[3]);
	printf("�ް��庴 ���        : %d��\n",wooDeaArrOut[4]);
	printf("�ӻ�� ���          : %d��\n",wooDeaArrOut[5]);
	printf("�ٵ��� �ູī�� ��� : %d��\n",wooDeaArrOut[6]);
	printf("======================================================\n");	
}

void dayMoneyDataPrint() {
//��¥ ��, ����� �м�		
	printf("\n================ ��¥ �� ���� ================\n");
	for (int i=0;i<=k;i++) {
		printf("%d�� %02d�� %02d�� %d��\n",dayDataOut[i][0],dayDataOut[i][1],dayDataOut[i][2],dayDataOut[i][3]);		
	}
	printf("==============================================\n");
}

void ticketDataReport(){
//Ƽ��_���� �� �ż��� ����
	FILE *filePointer1 = fopen("ticketdata.csv","w");
	for ( int i = 0; i <=7;i++) {
		fprintf(filePointer1,"%d,%d,%d,%d,%d\n",i,ageTicketCase[0][i],ageTicketCase[1][i],ageTicketCase[2][i],ageTicketCase[3][i]);
	}
	fclose(filePointer1);
}

void discountDataReport() {
	//��� ������ ���
	FILE *filePointer2 = fopen("woodaedata.csv","w");
	for (int i = 0; i<=6;i++) {
		fprintf(filePointer2,"%d,%d\n",i,wooDeaArrOut[i]);
	}
	fclose(filePointer2);	
}

void dayMoneyDataReport() {
	//��¥ ���
	FILE *filePointer3=fopen("daydata.csv","w");
	for (int i=0;i<=k;i++){
		fprintf(filePointer3,"%d,%d,%d,%d\n",dayDataOut[i][0],dayDataOut[i][1],dayDataOut[i][2],dayDataOut[i][3]);
	} 
	fclose(filePointer3);	
}

// ���� ���� // 

int main () {
	//report ���� �� �ҷ�����
	fileOpen();
	totalDataPrint();
	
	// ��� ���� // 
	calTicketData();
	calDiscountData();
	calDayMoneyData();
	
	// �޼��� ��±��� //
	ticketDataPrint();
	discountDataPrint();
	dayMoneyDataPrint();

	//������ ��±���
	ticketDataReport();
	discountDataReport();
	dayMoneyDataReport();

	return 0;
}
