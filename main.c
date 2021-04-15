#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

struct vendingMachine//���Ǳ� ����ü ����
{
    char drink[20]; //char �� ���
    int price; //int �� ���
    int amount; //int �� ���
};

int totalMoney=0;//�����ݾ� �ʱⰪ ����
int flag=0;//flag �ʱⰪ ����

void printMenu(struct vendingMachine vmData[]);//���Ǳ� �̹��� �Լ�
void inputMoney(struct vendingMachine vmData[]);//�ݾ� ���� �Լ�
void selectMenuFunc(struct vendingMachine vmData[]);//�޴� ���� �Լ�
void countFunc(void);//ī��Ʈ�ٿ� �Լ�

int main()//main �Լ� ����
{
    int selectMenu=0;//�޴� ���� ���� �ʱⰪ ����
    int yesNo=0;//yesNo ���� �ʱⰪ ����
    struct vendingMachine vmData[SIZE]={{"�ݶ�",700,0},{"��������Ʈ",800,50},{"�ֽĽ�",900,50},{"��ġ��",1000,50}};//���Ǳ� ����ü(vmData) �ʱⰪ ����

    while(1)
    {
        printMenu(vmData);//���Ǳ� �̹��� �Լ�
        printf("�������. �Ա� ������ �ݾ��� 3���� ���� �Դϴ�.\n");//���ڿ� "�������. �Ա� ������ �ݾ��� 3���� ���� �Դϴ�." ���
        inputMoney(vmData);//�ݾ� ���� �Լ�
        selectMenuFunc(vmData);//�޴� ���� �Լ�
        //countFunc();//ī��Ʈ�ٿ� �Լ� ȣ��

        if(flag==1)//flag ������ Ȱ���Ͽ� ������ ����� ��,������ �Ǵ�
        {
            flag = 0;//���ǿ� ���� �����Ƿ� while ������ ��������
            system("cls");//�ý��� �ʱ�ȭ
            continue;
        }
    }
    return 0;//���α׷� ����
}

void printMenu(struct vendingMachine vmData[])//���Ǳ� �̹��� �Լ� ����
{
    printf("������������������������������������������������������������������������������\n");
    printf("��                                     ��\n");
    printf("��                                     ��\n");
    printf("��     ������������������������                    ��\n");
    printf("��     ��   �ݶ�   ��    1��   700��     ��\n");
    printf("��     ������������������������                    ��\n");
    printf("��                                     ��\n");
    printf("��     ������������������������                    ��\n");
    printf("��     ����������Ʈ��    2��   800��     ��\n");
    printf("��     ������������������������                    ��\n");
    printf("��                                     ��\n");
    printf("��     ������������������������                    ��\n");
    printf("��     ��  �ֽĽ�  ��     3��  900��     ��\n");
    printf("��     ������������������������                    ��\n");
    printf("��                                     ��\n");
    printf("��     ������������������������                    ��\n");
    printf("��     ��  ��ġ��  ��     4��  1000��    ��\n");
    printf("��     ������������������������                    ��\n");
    printf("��                                     ��\n");
    printf("��                                     ��\n");
    printf("��                       ������������        ��\n");
    printf("��                       ������������    ��   ��\n");
    printf("��                         ����   ���� ��\n");
    printf("��                                     ��\n");
    printf("��                            ������������   ��\n");
    printf("��                            ������������   ��\n");
    printf("��                             ��ȯ��  ��\n");
    printf("��                                     ��\n");
    printf("��                                     ��\n");
    printf("��                  EXIT               ��\n");
    printf("��            ����������������������������           ��\n");
    printf("��            ��            ��           ��\n");
    printf("��            ��            ��           ��\n");
    printf("��            ����������������������������           ��\n");
    printf("��                                     ��\n");
    printf("��                                     ��\n");
    printf("������������������������������������������������������������������������������\n");
    return ;
}


void inputMoney(struct vendingMachine vmData[])//�ݾ� ���� �Լ� ����
{
    int money=0, yesNo=0;//��, yesNo ���� �ʱ�ȭ
    while(1)//�ݺ��� ���
    {
        printf("���� �Է��ϼ���\n"); scanf_s("%d", &money);//���ڿ� "���� �Է��ϼ���." ��� & �Է� �ޱ�
        if(money>30000 || money<=0)//������ �ݾ��� 3���� �ʰ� �̰ų� 0�� ���� �� ��
        {
            printf("�� �� �Է��ϼ̽��ϴ�.\n");//���ڿ� "�� �� �Է��ϼ̽��ϴ�." ���
            continue;//�ݺ��� ó������ ���ư��� ���ǿ� ���� �� ���� ��� ����
        }
        totalMoney = totalMoney+money;//totalMoney ���� ����
        printf("�� �Ա��� �ݾ��� %d �� �Դϴ�\n", totalMoney);//�� �Ա��� �ݾ� ���

        printf("���� �߰��� �Ա��Ͻðڽ��ϱ�?");//���ڿ� "���� �߰��� �Ա��Ͻðڽ��ϱ�?"���
        printf("yes=1, no=0\n"); scanf("%d", &yesNo);//yes, no ��� & �Է¹ޱ�
        if(yesNo==0)//yesNo�� ���� 0�̸�
            break;//�ݺ��� ����
        else//yesNo�� ���� 0�� �ƴϸ�
            continue;//�ݾ� �����Լ� ó������ ���ư� �ٽ� ����
      }
      return ;//�ݾ� ���� �Լ� ����
}

void selectMenuFunc(struct vendingMachine vmData[])//�޴� ���� �Լ� ����
{
    int selectMenu=0, yesNo=0;//�޴� ����, yesNo ���� �ʱ�ȭ

    while(1)//�ݺ��� ���
    {
        system("cls");//�ý��� �ʱ�ȭ

        printMenu(vmData);//���Ǳ� �̹��� �Լ� ȣ��
        printf("�� �Ա��� �ݾ��� %d �� �Դϴ�\n", totalMoney);//�� �Ա��� �ݾ� ���
        printf("�޴��� �������ּ���: "); scanf_s("%d", &selectMenu);//���ڿ� "�޴��� �������ּ���" ��� & ������ �޴� �Է¹���
        if(selectMenu>4 || selectMenu<1)//������ �޴� ��ȣ�� 4�� �ʰ��ϰų� 1 �̸��� ���� ����
        {
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���.\n");//���ڿ� "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." ���
            getchar();//����Ű�� �Է��Ͽ� ���� �ܰ�� �����ϰ� ��
            getchar();//����Ű�� �Է��Ͽ� ���� �ܰ�� �����ϰ� ��
            continue;//�޴� �����ϴ� �κ����� ���� ��� ����
        }
        else if(vmData[selectMenu-1].amount<=0)//������ �޴��� ��� ������
        {
            printf("�����ִ� %s �� �����ϴ�. ���͸� �����ּ���.\n", vmData[selectMenu-1].drink);//���ڿ�"�����ִ� �޴� �� �����ϴ�" ���
            getchar();//����Ű�� �Է��Ͽ� ���� �ܰ�� �����ϰ� ��
            getchar();//����Ű�� �Է��Ͽ� ���� �ܰ�� �����ϰ� ��
            continue;//������ �޴��� ��� ���� �ÿ� �޴��� �������ּ��� �ܰ�� ���� �ٽ� ����
        }
        else if(vmData[selectMenu-1].price>totalMoney)//������ �޴��� �ݾ��� ���Ǳ⿡ ������� �� �ݾ׺��� ������
        {
            printf("-%d �ܾ��� �����մϴ�.", vmData[selectMenu-1].price-totalMoney);//������ �ܾװ� ���ڿ� "�ܾ��� �����մϴ�." ���
            printf("�����Ͻðڽ��ϱ�? yes=1, no=0: "); scanf("%d", &yesNo); //�����Ͽ� �ٽ� ���� �� ������ ���� ���ڿ� ��� & �Է� �ޱ�
            if(yesNo==1)//yesNo�� ���� 1�̸�
            {
                inputMoney(vmData);//�ݾ� ���� �Լ��� ȣ��
                continue;//�ݾ� ���� �ܰ� ����
            }
            else//yesNo�� ���� 1�� �ƴϸ�
            {
                printf("�ܾ��� %d�� �Դϴ�. �����մϴ�. �ٽ� �����Ϸ��� ���͸� �����ּ���",totalMoney);//���ڿ� "�ܾ��� %d�� �Դϴ�. �����մϴ�. �ٽ� �����Ϸ��� ���͸� �����ּ���" ���
                getchar();//����Ű�� �Է��Ͽ� ���� �ܰ�� �����ϰ� ��
                getchar();//����Ű�� �Է��Ͽ� ���� �ܰ�� �����ϰ� ��
                totalMoney = 0;//�ܾ� ��ȯ �� �� �ݾ��� 0���� �ʱ�ȭ
                flag = 1;
                break;// �޴� ���� ����
            }
        }

        totalMoney = totalMoney - vmData[selectMenu-1].price;//�޴� ���� �� �� totalMoney �缳��
        vmData[selectMenu-1].amount = vmData[selectMenu-1].amount-1;//�޴� ���� �� �� ��� �缳��
        countFunc();//�޴� ��� �� ī��Ʈ�ٿ� �Լ� ȣ��
        printf("��ٷ� �ּż� �����մϴ�.\n");//���ڿ� "��ٷ� �ּż� �����մϴ�." ���
        sleep(1);//Sleep �Լ� ����Ͽ� �ð� ����
        printf("�ֹ��Ͻ� %s�� �غ�Ǿ����ϴ�.\n", vmData[selectMenu-1].drink);//���ڿ� "�ֹ��Ͻ� �޴� �� �غ�Ǿ����ϴ�." ���
        printf("���� �ݾ��� %d �Դϴ�.\n", totalMoney);//"���� �ݾ��� �Դϴ�." ���

        sleep(2);//Sleep �Լ� ����Ͽ� �ð� ����
        printf("����Ͻðڽ��ϱ�? \n");//���ڿ� "����Ͻðڽ��ϱ�?" ���
        printf("yes=1, no=0: \n"); scanf("%d", &yesNo); //yes, no ��� & �Է¹ޱ�
        if(yesNo==0)//yesNo�� ���� 0�̸�
        {
            printf("�ܾ��� %d�� �Դϴ�. �����մϴ�. �ٽ� �����Ϸ��� ���͸� �����ּ���",totalMoney);//���ڿ� "�ܾ��� %d�� �Դϴ�. �����մϴ�. �ٽ� �����Ϸ��� ���͸� �����ּ���" ���
            totalMoney = 0;//�ܾ� ��ȯ �� �� �ݾ��� 0���� �ʱ�ȭ
            getchar();//����Ű�� �Է��Ͽ� ���� �ܰ�� �����ϰ� ��
            getchar();//����Ű�� �Է��Ͽ� ���� �ܰ�� �����ϰ� ��
            flag = 1;
            break;// �޴� ���� ����
        }
    }
    return ;//�޴� ���� �Լ� ����
}

void countFunc(void)//ī��Ʈ�ٿ� �Լ� ����
{
    for(int i=3; i>0; i--)//�ݺ����� ����Ͽ� 3�ʺ��� 1�ʱ��� 1�� �پ��鼭 ī��Ʈ �ٿ�
    {
        if(i>0)//i�� 0 �ʰ� �϶�
        {
            sleep(1);//Sleep �Լ� ����Ͽ� �ð� ���� ��
            printf(" %d", i);//3�ʺ��� 1�ʱ��� 1�� �پ��鼭 ī��Ʈ �ٿ� ���
        }
        else//i�� 0�� ���ų� ������
        {
            break;//ī��Ʈ �ٿ� �ݺ��� ����
        }
    }
    printf("\a");//ī��Ʈ �ٿ� �� �˸��� ���

    sleep(1);//Sleep �Լ� ����Ͽ� �ð� ����

    printf("\n");//���� �� ���

    return ;//ī��Ʈ �ٿ� �Լ� ����
}
