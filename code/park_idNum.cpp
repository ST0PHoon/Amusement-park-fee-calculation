//���̰��� ��� ��� 
#include <stdio.h>
#include <time.h>

int main () {
	//���� ����
	int ticketCase, enterTime, wooDae, manAge, ticketPrice, ageCase, ticketTimeCase, again, todayDate, idFront, idBack, yyyymmdd;
	const int DAY_ADULT = 56000, DAY_TEEN = 50000, DAY_KID = 46000, DAY_BABY = 15000, AFTER4_ADULT = 45000, AFTER4_TEEN = 40000, AFTER4_KID = 35000, AFTER4_BABY = 15000,
	    	  DAY_ADULT_ALL = 59000, DAY_TEEN_ALL = 52000, DAY_KID_ALL = 47000, DAY_BABY_ALL = 15000, AFTER4_ADULT_ALL = 48000, AFTER4_TEEN_ALL = 42000, AFTER4_KID_ALL = 36000, AFTER4_BABY_ALL = 15000,
			  OLDMAN_AGE=65, TEEN_AGE_MAX=18, TEEN_KID_AGE=13, KID_BABY_AGE=3, BABY_AGE_MIN=1;
	//�ð� �ҷ����� 
    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �����Ͽ� ��������� ��
    t = localtime(&timer); // �������� ���� ����ü�� �ֱ�

	do {
		//���� �ʱ� ȭ
		ticketCase = 0, enterTime=0, wooDae=0;
		
		do {
			// �̿�� ���� �����ϱ� (���� or ��ũ)
			printf("\n�̿���� ������ �������ּ���.\n");
			printf("1. �����̿�� (�Ե�����+�μӹڹ���)\n2. ��ũ�̿�� (�Ե�����)\n");
			scanf("%d",&ticketCase);
			
			//��,�߰��� ���� �޼��� ��� & �Է¹ޱ� 
			printf("\n����ð��� ���� �̿���� ������ �ּ���.\n");
			printf("1. 1Day\n2. After4 (����4�ú��� ����)\n");
			scanf("%d",&enterTime);
				
			//�ֹι�ȣ �Է� �ޱ� , ���� ��� 
			printf("\n�ֹε�Ϲ�ȣ�� �Է����ּ���. ('-'��� ��ĭ ����ּ���. ex) 051225 3152135)\n");
			scanf("%6d %7d",&idFront, &idBack);
				
			//��� ������ ����
			printf("\n�������� �������ּ���.\n1.����(*�� 65�� �̻��� ��̿�� ����)\n2.����� ���\n3.���������� ���\n4.�ް��庴 ���\n5.�ӻ�� ���\n6.�ٵ��� �ູī�� ���\n");
			scanf("%d",&wooDae);
				
			//�Է� ���� 
			if ( ticketCase> 2 || enterTime >2 || wooDae>6){
				printf("�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���\n\n");
			} 
		} while(ticketCase>2 || enterTime > 2|| wooDae>6) ;

		//�ð� �Է� 
		todayDate= (t->tm_year + 1900)*10000 + (t->tm_mon + 1)*100 + t->tm_mday;  //20220316 ���·� ���� 
		
		
		//1900���, 2000��� �з�
		if (idBack/1000000 >=3) { //2000���� 
			yyyymmdd = idFront + 20000000;
		} else {                  //1900���� 
			yyyymmdd = idFront + 19000000;
		} 
	
		//�� ���� ��� 
		manAge = (todayDate - yyyymmdd)/10000;
		
		//���� ���̽� ����
		// 0 ~ 12���� �̸� (�� 0��) �� ���� 
		// 12���� �̻� 36���� �̸� : ���̺�         (4)
		//36����(�� 3��)�̻� ~ �� 12�� : ��̿�� (3)
		//�� 13�� �̻� ~ �� 18�� : û�ҳ� ���      (2)
		//�� 65�� �̻� : ��̿��                 (1)
		if ( manAge <KID_BABY_AGE && manAge >=BABY_AGE_MIN) { 
			ageCase=4; // ���̺� 
		} else if ((manAge >= KID_BABY_AGE && manAge <TEEN_KID_AGE) || manAge >= OLDMAN_AGE ) {
			ageCase = 3; // ��� + ���� 
		} else if (manAge >= TEEN_KID_AGE && manAge <= TEEN_AGE_MAX) {
			ageCase = 2; //û�ҳ� 
		} else {
			ageCase = 1; // � 
		}
			
		//�̿�� ���� , �־߰��� ������ ���� ���̽� �з� 
		if (ticketCase==1 && enterTime==1) {
			ticketTimeCase = 1; //���� + 1Day 
		} else if (ticketCase==1 && enterTime==2) {
			ticketTimeCase =2; //���� + 4���� 
		} else if (ticketCase == 2 && enterTime == 1) {
			ticketTimeCase = 3; //��ũ + 1Day 
		} else {
			ticketTimeCase = 4; // ��ũ + 4���� 
		} 
		
		//������ ����, ��� ����
		if ( ageCase == 1) { // ��̰�  
			if (ticketTimeCase== 1) {        // ���� + 1Day 
				ticketPrice= DAY_ADULT_ALL;
			} else if (ticketTimeCase==2) {  //���� + 4����
				ticketPrice= AFTER4_ADULT_ALL;
			}else if (ticketTimeCase ==3) {  //��ũ + 1Day 
				ticketPrice= DAY_ADULT;
			} else {                        // ��ũ + 4���� 
				ticketPrice= AFTER4_ADULT;
			}
		} else if ( ageCase == 2) {  // û�ҳ�  
			if (ticketTimeCase== 1) {
				ticketPrice=DAY_TEEN_ALL;
			} else if (ticketTimeCase==2) {
				ticketPrice=AFTER4_TEEN_ALL;
			}else if (ticketTimeCase ==3) {
				ticketPrice=DAY_TEEN;
			} else {
				ticketPrice=AFTER4_TEEN;
			}
		} else if ( ageCase == 3) { //��� + ���� 
			if (ticketTimeCase== 1) {
				ticketPrice=DAY_KID_ALL;
			} else if (ticketTimeCase==2) {
				ticketPrice=AFTER4_KID_ALL;
			}else if (ticketTimeCase ==3) {
				ticketPrice=DAY_KID;
			} else {
				ticketPrice=AFTER4_KID;
			}
		} else {                  // �ֱ� 
			if (ticketTimeCase== 1) {
				ticketPrice=DAY_BABY_ALL;
			} else if (ticketTimeCase==2) {
				ticketPrice=AFTER4_BABY_ALL;
			}else if (ticketTimeCase ==3) {
				ticketPrice=DAY_BABY;
			} else {
				ticketPrice=AFTER4_BABY;
			}
		}
		
		//12���� �̸��� ���
		if ( manAge == 0) {
			ticketPrice = 0;
		} 
	
		//����ῡ ������ ����
		if (wooDae == 2) {
			ticketPrice = ticketPrice/2 ; // ��� Ƽ�� 50�� ��� 
		} else if (wooDae == 3) {
			ticketPrice = ticketPrice/2 ;
		} else if (wooDae == 4 && ticketCase==1) { //�����̿�Ǹ� ��� 
			ticketPrice = ticketPrice * 0.51;
		} else if (wooDae == 5 && ticketCase==1 ) {
			ticketPrice = ticketPrice/2;
		} else if (wooDae == 6 && ticketCase==1) {
			ticketPrice = ticketPrice*0.7;
		} else {
			printf("\n��� ������ �����ϴ�.\n");
		}
		
		//����� �Ѿ� ���.
		if (ticketPrice==0){
			printf("\n���� ���� �Դϴ�.\n");
		}
		else {
			printf ("\n������ %d�� �Դϴ�.\n",ticketPrice) ;
		}
		
		//�̾ �������� ���� 
		printf("\n�̾ �̿���� �����Ͻðڽ��ϱ�?\n1.��\n2.�ƴϿ�\n");
		scanf("%d",&again); 
	} while(again == 1);
	
	return 0; 
}