//���̰��� ��� ��� 
#include <stdio.h>
#include <time.h>

int main () {
	//���� ����
	int ticketCase, enterTime, id, wooDae, myYear, myMonthDay, manAge, realAge, ticketPrice, ageCase, ticketTimeCase, again, todayYear, todayMonth, todayDate;
	const int dayAdult = 56000, dayTeen = 50000, dayKid = 46000, dayBaby = 15000, a4Adult = 45000, a4Teen = 40000, a4Kid = 35000, a4Baby = 15000,
	    	  dayAdultAll = 59000, dayTeenAll = 52000, dayKidAll = 47000, dayBabyAll = 15000, a4AdultAll = 48000, a4TeenAll = 42000, a4KidAll = 36000, a4BabyAll = 15000;
	//�ð� �ҷ����� 
    time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �����Ͽ� ��������� ��
    t = localtime(&timer); // �������� ���� ����ü�� �ֱ�

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
	printf("\n�ֹε�Ϲ�ȣ�� �Է����ּ���. (6�ڸ�)\n");
	scanf("%d",&id);
	
	//��� ������ ����
	printf("\n�������� �������ּ���.\n1.����(*�� 65�� �̻��� ��̿�� ����)\n2.����� ���\n3.���������� ���\n4.�ް��庴 ���\n5.�ӻ�� ���\n6.�ٵ��� �ູī�� ���\n");
	scanf("%d",&wooDae);
	
	//�ð� �Է� 
	todayYear = t->tm_year + 1900;
	todayMonth = t->tm_mon + 1;
	todayDate = t->tm_mday;
	
	//�� ���� ��� 
	myYear = id/10000;       // ex) 950306 > 95 
	myMonthDay = id%10000;  // ex) 950306 > 306 
	
	realAge = todayYear%100 - myYear+1;
	
	if (realAge <= 0) {
		//1900��� ������� ��� 
		realAge += 100;
	} 
	
	if ( myMonthDay <= (todayMonth*100+todayDate)) {
		manAge= realAge -1;
	} else {
		manAge= realAge-2;
	}
	
	//���� ���̽� ���� / 2022.03.16 ����
	// 0 ~ 12���� �̸� (�� 0��) �� ���� 
	// 12���� �̻� 36���� �̸� : ���̺�         (4)
	//36����(�� 3��)�̻� ~ �� 12�� : ��̿�� (3)
	//�� 13�� �̻� ~ �� 18�� : û�ҳ� ���      (2)
	//�� 65�� �̻� : ��̿��                 (1)
	if ( manAge <3 && manAge >=1) { 
		ageCase=4; // ���̺� 
	} else if ((manAge >= 3 && manAge <13) || manAge >= 65 ) {
		ageCase = 3; // ��� 
	} else if (manAge >= 13 && manAge <= 18) {
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
			ticketPrice= dayAdultAll;
		} else if (ticketTimeCase==2) {  //���� + 4����
			ticketPrice= a4AdultAll;
		}else if (ticketTimeCase ==3) {  //��ũ + 1Day 
			ticketPrice= dayAdult;
		} else {                        // ��ũ + 4���� 
			ticketPrice= a4Adult;
		}
	} else if ( ageCase == 2) {  // û�ҳ�  
		if (ticketTimeCase== 1) {
			ticketPrice=dayTeenAll;
		} else if (ticketTimeCase==2) {
			ticketPrice=a4TeenAll;
		}else if (ticketTimeCase ==3) {
			ticketPrice=dayTeen;
		} else {
			ticketPrice=a4Teen;
		}
	} else if ( ageCase == 3) { //��� + ���� 
		if (ticketTimeCase== 1) {
			ticketPrice=dayKidAll;
		} else if (ticketTimeCase==2) {
			ticketPrice=a4KidAll;
		}else if (ticketTimeCase ==3) {
			ticketPrice=dayKid;
		} else {
			ticketPrice=a4Kid;
		}
	} else {                  // �ֱ� 
		if (ticketTimeCase== 1) {
			ticketPrice=dayBabyAll;
		} else if (ticketTimeCase==2) {
			ticketPrice=a4BabyAll;
		}else if (ticketTimeCase ==3) {
			ticketPrice=dayBaby;
		} else {
			ticketPrice=a4Baby;
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
		printf("\n���� ���� �Դϴ�.");
	}
	else {
		printf ("\n������ %d�� �Դϴ�.",ticketPrice) ;
	}
	
	//�̾ �������� ���� 
	printf("\n�̾ �̿���� �����Ͻðڽ��ϱ�?\n1.��\n2.�ƴϿ�\n");
	scanf("%d",&again); 
	} while(again == 1);
	
	return 0; 
}
