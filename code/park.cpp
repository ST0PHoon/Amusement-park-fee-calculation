//���̰��� ��� ��� 
#include <stdio.h>
int main () {
	//���� ����
	int ticketCase, enterTime, id, wooDae, myYear, myMonthDay, manAge, realAge, ticketPrice;
	int ageCase, ticketTimeCase1;
	const int dayAdult = 56000, dayTeen = 50000, dayKid = 46000, dayBaby = 15000, a4Adult = 45000, a4Teen = 40000, a4Kid = 35000, a4Baby = 15000,
	    	  dayAdultAll = 59000, dayTeenAll = 52000, dayKidAll = 47000, dayBabyAll = 15000, a4AdultAll = 48000, a4TeenAll = 42000, a4KidAll = 36000, a4BabyAll = 15000;

	// �̿�� ���� �����ϱ� (���� or ��ũ)
	printf("�̿���� ������ �������ּ���.\n");
	printf("1. �����̿�� (�Ե�����+�μӹڹ���)\n2. ��ũ�̿�� (�Ե�����)\n");
	scanf("%d",&ticketCase);

	//��,�߰��� ���� �޼��� ��� & �Է¹ޱ� 
	printf("\n����ð��� ���� �̿���� ������ �ּ���.\n");
	printf("1. 1Day\n2. After4 (����4�ú��� ����)\n");
	scanf("%d",&enterTime);
	
	//�ֹι�ȣ �Է� �ޱ� , ���� ��� 
	printf("\n�ֹε�Ϲ�ȣ�� �Է����ּ���. (6�ڸ�)\n");
	scanf("%d",&id);
	
	myYear = id/10000;       // ex) 950306 > 95 
	myMonthDay = id%10000;  // ex) 950306 > 306 
	
	realAge = 22- myYear+1;
	
	if (realAge <= 0) {
		//1900��� ������� ��� 
		realAge += 100;
	} 
	
	if ( myMonthDay <= 316) {
		manAge= realAge -1;
	} else {
		manAge= realAge-2;
	}
	
	//���� ���̽� ���� / 2022.03.16 ���� 
	//36����(�� 2��)�̻� ~ �� 12�� : ��̿�� (3)
	//�� 13�� �̻� ~ �� 18�� : û�ҳ� ���      (2)
	//�� 65�� �̻� : ��̿��                 (1)
	if ( manAge <2) {
		ticketPrice = 0;
		ageCase=4;
	} else if ((manAge >= 2 && manAge <13) || manAge >= 65 ) {
		ageCase = 3; // ��� 
	} else if (manAge >= 13 && manAge <= 18) {
		ageCase = 2; //û�ҳ� 
	} else {
		ageCase = 1;  //� 
	}
	
	//�ֹι�ȣ�� �� ���� �Ǵ��Ͽ� ����� ����


	//��� ������ ����
	printf("\n�������� �������ּ���.\n1.����(*�� 65�� �̻��� ��̿�� ����)\n2.����� ���\n3.���������� ���\n4.�ް��庴 ���\n5.�ӻ�� ���\n6.�ٵ��� �ູī�� ���\n");
	scanf("%d",&wooDae);
	
	//����ῡ ������ ���� 
	
	//����� �Ѿ� ���
	
	//�̾ �������� ���� 
	
	
	return 0; 
}
