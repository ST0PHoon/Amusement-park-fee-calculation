#include <stdio.h>

int main () {
	//report ���� �� �ҷ����� 
	FILE *fp = fopen("report.csv","r");
	const int MAX = 100;
	int count = 0, cir=0;
	int year[MAX], month[MAX], day[MAX],
		ticketTimeCaseArr[MAX],wooDaeArr[MAX],ageCaseArr[MAX],ticketSuArr[MAX],ticketPriceArr[MAX],
		ageTicketCase[MAX][MAX]={0};
	int wooDae1=0,wooDae2=0,wooDae3=0,wooDae4=0,wooDae5=0,wooDae6=0,
		parkMoney=0, parkAllMoney=0, oneDayMoney=0, After4Money=0,
		k, dayTotal=0, totalTicketSu=0,
		parkTicketSu,parkAllTicketSu,oneDayTicketSu, After4TicketSu;
		
	while ( fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d",&year[count], &month[count], &day[count],
		&ticketTimeCaseArr[count], &wooDaeArr[count], &ageCaseArr[count], &ticketSuArr[count], &ticketPriceArr[count]) != -1) {

		count++;		
	}
	fclose(fp);
	
	//�޾ƿ� ������ ��� 
	printf("\n========================= ������ =========================");
	printf("\n��¥           Ƽ��    ���   ����    �ż�      ����\n");
	for (int i = 0; i < count; i ++) {
		printf ("%d��%2d��%2d��\t%d\t%d\t%d\t%d\t%d\n",year[i], month[i], day[i],
		ticketTimeCaseArr[i], wooDaeArr[i], ageCaseArr[i], ticketSuArr[i], ticketPriceArr[i]);
	}
	printf("\n==========================================================\n");
	
	
	for(int i = 0; i < count; i++) {
	//Ƽ�� ���� ��, ���ɴ� ���� �м� / �ð��� �� �����
		switch(ticketTimeCaseArr[i]) {
			case 1: //���� + 1Day 
				switch(ageCaseArr[i]) {
					case 1: //�
						ageTicketCase[0][0] += ticketSuArr[i];
						ageTicketCase[2][0] += ticketSuArr[i];
						break;
 					case 2: //û�ҳ� 
						ageTicketCase[0][1] += ticketSuArr[i];
						ageTicketCase[2][1] += ticketSuArr[i];
						break;	
					case 3: //��� 
						ageTicketCase[0][2] += ticketSuArr[i];
						ageTicketCase[2][2] += ticketSuArr[i];
						break;
					case 4: //���� 
						ageTicketCase[0][3] += ticketSuArr[i];
						ageTicketCase[2][3] += ticketSuArr[i];
						break;
					case 5: //���� 
						ageTicketCase[0][4] += ticketSuArr[i];
						ageTicketCase[2][4] += ticketSuArr[i];
						break;
					case 6: //����  
						ageTicketCase[0][5] += ticketSuArr[i];
						ageTicketCase[2][5] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				parkAllMoney += ticketPriceArr[i];
				oneDayMoney += ticketPriceArr[i];
				break;
			case 2: //���� + 4���� 
				switch(ageCaseArr[i]) {
					case 1: //�
						ageTicketCase[0][0] += ticketSuArr[i];
						ageTicketCase[3][0] += ticketSuArr[i];
						break;
 					case 2: //û�ҳ� 
						ageTicketCase[0][1] += ticketSuArr[i];
						ageTicketCase[3][1] += ticketSuArr[i];
						break;	
					case 3: //��� 
						ageTicketCase[0][2] += ticketSuArr[i];
						ageTicketCase[3][2] += ticketSuArr[i];
						break;
					case 4: //���� 
						ageTicketCase[0][3] += ticketSuArr[i];
						ageTicketCase[3][3] += ticketSuArr[i];
						break;
					case 5: //���� 
						ageTicketCase[0][4] += ticketSuArr[i];
						ageTicketCase[3][4] += ticketSuArr[i];
						break;
					case 6: //����  
						ageTicketCase[0][5] += ticketSuArr[i];
						ageTicketCase[3][5] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				parkAllMoney += ticketPriceArr[i];
				After4Money += ticketPriceArr[i];
				break;
			case 3: //��ũ + 1Day
				switch(ageCaseArr[i]) {
					case 1: //�
						ageTicketCase[1][0] += ticketSuArr[i];
						ageTicketCase[2][0] += ticketSuArr[i];
						break;
 					case 2: //û�ҳ� 
						ageTicketCase[1][1] += ticketSuArr[i];
						ageTicketCase[2][1] += ticketSuArr[i];
						break;	
					case 3: //��� 
						ageTicketCase[1][2] += ticketSuArr[i];
						ageTicketCase[2][2] += ticketSuArr[i];
						break;
					case 4: //���� 
						ageTicketCase[1][3] += ticketSuArr[i];
						ageTicketCase[2][3] += ticketSuArr[i];
						break;
					case 5: //���� 
						ageTicketCase[1][4] += ticketSuArr[i];
						ageTicketCase[2][4] += ticketSuArr[i];
						break;
					case 6: //����  
						ageTicketCase[1][5] += ticketSuArr[i];
						ageTicketCase[2][5] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				parkMoney += ticketPriceArr[i];
				oneDayMoney += ticketPriceArr[i];
				break;
			case 4: //��ũ + 4����
				switch(ageCaseArr[i]) {
					case 1: //�
						ageTicketCase[1][0] += ticketSuArr[i];
						ageTicketCase[3][0] += ticketSuArr[i];
						break;
 					case 2: //û�ҳ� 
						ageTicketCase[1][1] += ticketSuArr[i];
						ageTicketCase[3][1] += ticketSuArr[i];
						break;	
					case 3: //��� 
						ageTicketCase[1][2] += ticketSuArr[i];
						ageTicketCase[3][2] += ticketSuArr[i];
						break;
					case 4: //���� 
						ageTicketCase[1][3] += ticketSuArr[i];
						ageTicketCase[3][3] += ticketSuArr[i];
						break;
					case 5: //���� 
						ageTicketCase[1][4] += ticketSuArr[i];
						ageTicketCase[3][4] += ticketSuArr[i];
						break;
					case 6: //����  
						ageTicketCase[1][5] += ticketSuArr[i];
						ageTicketCase[3][5] += ticketSuArr[i];
						break;
					default:
						break; 
				}
				parkMoney += ticketPriceArr[i];
				After4Money += ticketPriceArr[i];
				break;
			default:
				break;
		}

	//�� Ƽ�� �Ǹ� ��, ���ú� Ƽ�ϼ� �м�
		//������ �ο����� count ��
		//���ÿ� ���� Ƽ���� ������. 
			switch (wooDaeArr[i]) {
				case 1:
					wooDae1 += ticketSuArr[i];
					break;
				case 2:
					wooDae2 += ticketSuArr[i];
					break;
				case 3:
					wooDae3 += ticketSuArr[i];
					break;
				case 4:
					wooDae4 += ticketSuArr[i];
					break;
				case 5:
					wooDae5 += ticketSuArr[i];
					break;
				case 6:
					wooDae6 += ticketSuArr[i];
					break;
				default:
					break;
			}
	}
	
	// ���� �� �� Ƽ�� ��
	parkTicketSu = ageTicketCase[1][5]+ageTicketCase[1][3]+ageTicketCase[1][2]+ageTicketCase[1][1]+ageTicketCase[1][0]+ageTicketCase[1][4];
	parkAllTicketSu = ageTicketCase[0][5]+ageTicketCase[0][3]+ageTicketCase[0][2]+ageTicketCase[0][1]+ageTicketCase[0][0]+ageTicketCase[0][4];
	oneDayTicketSu = ageTicketCase[2][5]+ageTicketCase[2][3]+ageTicketCase[2][2]+ageTicketCase[2][1]+ageTicketCase[2][0]+ageTicketCase[2][4];
	After4TicketSu =  ageTicketCase[3][5]+ageTicketCase[3][3]+ageTicketCase[3][2]+ageTicketCase[3][1]+ageTicketCase[3][0]+ageTicketCase[3][4];
	//�� Ƽ�� ��
	totalTicketSu = wooDae1+wooDae2+wooDae3+wooDae4+wooDae5+wooDae6;
	
	// �޽��� ��±���

	//Ƽ�� ���� ��, ���ɴ� ���� �м� / �ð��� �� ����� + �Ʒ� �� ���ϱ� ���� ������ ���� ����  
	printf("\n======================= ���� �� �Ǹ� ��Ȳ =======================\n");
	printf("���ձ� �� %d��\n",parkAllTicketSu);
	printf("���� %d��,���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",ageTicketCase[0][5],
						ageTicketCase[0][3],ageTicketCase[0][2],ageTicketCase[0][1],ageTicketCase[0][0],ageTicketCase[0][4]);
	printf("���ձ� ���� : %d��\n\n",parkAllMoney);
	
	printf("��ũ�� �� %d��\n",parkTicketSu);
	printf("���� %d��,���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",ageTicketCase[1][5],
						ageTicketCase[1][3],ageTicketCase[1][2],ageTicketCase[1][1],ageTicketCase[1][0],ageTicketCase[1][4]);
	printf("��ũ�� ���� : %d��\n\n",parkMoney); 

	printf("1Day�� �� %d��\n",oneDayTicketSu);
	printf("���� %d��,���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",ageTicketCase[2][5],
						ageTicketCase[2][3],ageTicketCase[2][2],ageTicketCase[2][1],ageTicketCase[2][0],ageTicketCase[2][4]);
	printf("1Day�� ���� : %d��\n\n",oneDayMoney); 

	printf("4�ñ� �� %d��\n",After4TicketSu);
	printf("���� %d��,���� %d��, ��� %d��, û�ҳ� %d��, � %d��, ���� %d��\n",ageTicketCase[3][5],
						ageTicketCase[3][3],ageTicketCase[3][2],ageTicketCase[3][1],ageTicketCase[3][0],ageTicketCase[3][4]);
	printf("4�ñ� ���� : %d��\n",After4Money); 
	printf("================================================================\n"); 
	
	//�� Ƽ�� �Ǹ� ��, ���ú� Ƽ�ϼ� �м�
	printf("\n=================== ������ �м� ===================\n");
	printf("�� Ƽ�� �Ǹż�       : %d��\n",totalTicketSu);
	printf("������ ����        : %d��\n",wooDae1);
	printf("����� ���          : %d��\n",wooDae2);
	printf("���������� ���      : %d��\n",wooDae3);
	printf("�ް��庴 ���        : %d��\n",wooDae4);
	printf("�ӻ�� ���          : %d��\n",wooDae5);
	printf("�ٵ��� �ູī�� ��� : %d��\n",wooDae6);
	printf("======================================================\n");
	
	//���� �� �� ���� 
		// ��¥�� ���� �������� �Ǿ��ִٰ� ����, k�� ������ �ǹ�, k�� -1�� ��� 0���� ���
	printf("\n================ ��¥ �� ���� ================\n");
	for(int i = 0; i < count; i++) {
		k= i-1;
		if (k == -1) {
			k = 0;
		}

		if (year[i]==year[k]&& month[i]==month[k]&& day[i]==day[k]) {
			dayTotal += ticketPriceArr[i];
			//������ ���� ������ ���� ��� > ���� ���ϰ� ���
			if (i==count-1) {
				printf("%d��%2d��%2d���� ���� �Ѿ�:  %d��\n",year[k],month[k],day[k], dayTotal);
			} 
		} else {
			//������ ���� ������ �ٸ� ��� > ������ Ƽ�� ������ ��� 
			if (i==count-1) {
				printf("%d��%2d��%2d���� ���� �Ѿ�:  %d��\n",year[i],month[i],day[i], ticketPriceArr[i]);
			} else {
				printf("%d��%2d��%2d���� ���� �Ѿ�:  %d��\n",year[k],month[k],day[k], dayTotal);
				dayTotal=0;
				dayTotal +=ticketPriceArr[i];
			}
		} 
	}
	printf("==============================================\n");
	
	return 0;
}

