#include <stdio.h>

int main () {
	//report ���� �� �ҷ����� 
	FILE *fp = fopen("report.csv","r");
	const int MAX = 100;
	int count = 0;
	int year[MAX], month[MAX], day[MAX],
		ticketTimeCaseArr[MAX],wooDaeArr[MAX],ageCaseArr[MAX],ticketSuArr[MAX],ticketPriceArr[MAX];
	int wooDae1=0,wooDae2=0,wooDae3=0,wooDae4=0,wooDae5=0,wooDae6=0,
		k, dayTotal=0;
		
	while ( fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d",&year[count], &month[count], &day[count],
		&ticketTimeCaseArr[count], &wooDaeArr[count], &ageCaseArr[count], &ticketSuArr[count], &ticketPriceArr[count]) != -1) {

		count++;		
	}
	fclose(fp);
	
	//year[i], month[i], day[i], ticketTimeCaseArr[i], wooDaeArr[i], ageCaseArr[i], ticketSuArr[i], ticketPriceArr[i]
	for(int i = 0; i < count; i++) {
	//���� �� �� ���� 
		// ��¥�� ���� �������� �Ǿ��ִٰ� ����
		k= i-1;
		if (k == -1) {
			k = 0;
		}
		//������ ���� ������ ���� ��� > ���� ���ϰ� ���  
		//������ ���� ������ �ٸ� ��� > ������ Ƽ�� ������ ��� 
		
		if (year[i]==year[k]&& month[i]==month[k]&& day[i]==day[k]) {
			dayTotal += ticketPriceArr[i];
			if (i==count-1) {
				printf("%d-%d-%d, %d\n",year[k],month[k],day[k], dayTotal);
			} 
		} else {
			if (i==count-1) {
				printf("%d-%d-%d, %d\n",year[i],month[i],day[i], ticketPriceArr[i]);
			} else {
				printf("%d-%d-%d, %d\n",year[k],month[k],day[k], dayTotal);
				dayTotal=0;
				dayTotal +=ticketPriceArr[i];
			}
		}
	
	//Ƽ�� ���� ��, ���ɴ� ���� �м� / �ð��� �� �����
		//���ɿ� ���� ����, ��ũ and 1Day, After4 ���� ����� �����. (����6���� * Ƽ�� 4���� = 24���� ����)
		//�����鼭 ������ ���� �߰�, �м��ؼ� ���� ��������. 
	
	//�� Ƽ�� �Ǹ� ��, ���ú� Ƽ�ϼ� �м�
		//������ �ο����� count ��
		//���ÿ� ���� Ƽ���� ������. 
			switch (wooDaeArr[i]) {
				case 1:
					wooDae1++;
					break;
				case 2:
					wooDae2++;
					break;
				case 3:
					wooDae3++;
					break;
				case 4:
					wooDae4++;
					break;
				case 5:
					wooDae5++;
					break;
				case 6:
					wooDae6++;
					break;
				default:
					break;
			}
	}
	
	// �޽��� ��±���
	//���� �� �� ����
	
	//Ƽ�� ���� ��, ���ɴ� ���� �м� / �ð��� �� �����
	
	//�� Ƽ�� �Ǹ� ��, ���ú� Ƽ�ϼ� �м�
	printf("�� Ƽ�� �Ǹż�: %d\n",count);
	printf("������ ����: %d\n",wooDae1);
	printf("����� ���: %d\n",wooDae2);
	printf("���������� ���: %d\n",wooDae3);
	printf("�ް��庴 ���: %d\n",wooDae4);
	printf("�ӻ�� ���: %d\n",wooDae5);
	printf("�ٵ��� �ູī�� ���: %d\n",wooDae6);
	
	return 0;
}

