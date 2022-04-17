#include <bangtal.h>
#include <stdlib.h>
#include <time.h>

SceneID dungeon, death, room, victory, askroom, fall;
ObjectID demon, door1, door2,  portal1, portal2, portal3, portal4, restart, end1, plank1, plank2, plank3, answer1, answer2, answer3, answer4, youwin;


void gameover()
{
	enterScene(death);

	restart = createObject("images/restart.png");
	locateObject(restart, death, 550, 320);
	showObject(restart);
	end1 = createObject("images/end.png");
	locateObject(end1, death, 550, 220);
	showObject(end1);
	
	showMessage("�����ص� ������. . . ��ȸ�� �󸶵��� ����. . . .");

}

void roomgame()
{
	enterScene(room);
	hideObject(portal2);
	door1 = createObject("images/door.png");
	door2 = createObject("images/door.png");
	locateObject(door1, room, 300, 200);
	locateObject(door2, room, 800, 200);
	showObject(door1);
	showObject(door2);
	portal2 = createObject("images/portal.png");

	showMessage("�� �濡�� ���� �ΰ��� ����. . . �ϳ��� �����ض�. . . . �� �����Ѵٸ� ���� �÷����� ���ϴ� ���� ��������. . . .  �׷��� ���ϸ�  ������ ��ٸ� ���̴�. . . . ");
}

void fallgame()
{
	enterScene(fall);
	hideObject(portal3);
	plank1 = createObject("images/plank.png");
	plank2 = createObject("images/plank.png");
	plank3 = createObject("images/plank.png");
	locateObject(plank1, fall, 300, 40);
	locateObject(plank2, fall, 600, 40);
	locateObject(plank3, fall, 900, 40);
	showObject(plank1);
	showObject(plank2);
	showObject(plank3);

	portal3 = createObject("images/portal.png");
	locateObject(portal3, fall, 600, 300);
	showMessage("���� �κ��� 3���� ����. . �ΰ��� ��� �ְ� �ϳ��� ưư��. . �ϳ��� ��� �Ѿ�� �� ũ��");

}

void askroomgame()
{
	enterScene(askroom);
	hideObject(portal4);
	showMessage("�̹� �ܰ�� ����������. . .�ʿ��� ������ �ϳ� ����. . ���� ������ ���� ����� �ϴ°� ���� �ž� ����\n���䳢�� �ݴ븻�� ��������? ? ?");
	answer1 = createObject("images/answer1.png");
	answer2 = createObject("images/answer2.png");
	answer3 = createObject("images/answer3.png");
	answer4 = createObject("images/answer4.png");
	locateObject(answer1, askroom, 600, 500);
	locateObject(answer2, askroom, 900, 500);
	locateObject(answer3, askroom, 600, 300);
	locateObject(answer4, askroom, 900, 300);
	showObject(answer1);
	showObject(answer2);
	showObject(answer3);
	showObject(answer4);
	locateObject(demon, askroom, 0, 300);

	portal4 = createObject("images/portal.png");
	locateObject(portal4, askroom, 400, 300);

}

void victorygame()
{
	enterScene(victory);
	showMessage("�� �÷��� ��� �غ��� ���ΰ�? �����. . . ����� �غ�� ��ȸ�� ������ �� ��μ� ��Ÿ���ٴ� ���� ����ϰ� ��� �����ؼ� ���ϴ� ���� ����. . . ������� ������ �����ߴ�..");
	locateObject(end1, victory, 700, 450);
	locateObject(demon, victory, 100, 100);
	youwin = createObject("images/youwin.png");
	locateObject(youwin, victory, 500, 570);
	showObject(youwin);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action)
{
	//��Ż
	if (object == portal1) {
		roomgame();
	}

	//���ӿ��� ���
	if (object == restart) {
		roomgame();
	}
	if (object == end1) {
		endGame();
	}

	// �� ����
	if (object == door1) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 2;
		if (percent < 1) {
			hideObject(door1);
			hideObject(door2);
			locateObject(portal2, room, 280, 180);
			showObject(portal2);
			showMessage("ȣ��. . . �� �ϴ±���. . . . .");
		}
		else {
			gameover();
		}
	}
	else if (object == door2) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 2;
		if (percent < 1) {
			hideObject(door1);
			hideObject(door2);
			locateObject(portal2, room, 780, 180);
			showObject(portal2);
			showMessage("ȣ��. . . �� �ϴ±���. . . . .");
		}
		else {
			gameover();
		}
	}
	else if (object == portal2) {
		fallgame();
	}

	// ���� ����
	if (object == plank1) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 3;
		if (percent < 1) {
			hideObject(plank1);
			hideObject(plank2);
			hideObject(plank3);
			showObject(portal3);
			showMessage("ưư�� ���ڸ� ã�ұ�! ! ! �ٸ� ���ڴ� �ǵ帮�� ���� �Ѿ� �����~ ~");
		}
		else {
			gameover();
		}
	}
	else if (object == plank2) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 3;
		if (percent < 1) {
			hideObject(plank1);
			hideObject(plank2);
			hideObject(plank3);
			showObject(portal3);
			showMessage("ưư�� ���ڸ� ã�ұ�! ! ! �ٸ� ���ڴ� �ǵ帮�� ���� �Ѿ� �����~ ~");
		}
		else {
			gameover();
		}
	}
	else if (object == plank3) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 3;
		if (percent < 1) {
			hideObject(plank3);
			hideObject(plank3);
			hideObject(plank3);
			showObject(portal3);
			showMessage("ưư�� ���ڸ� ã�ұ�! ! ! �ٸ� ���ڴ� �ǵ帮�� ���� �Ѿ� �����~ ~");
		}
		else {
			gameover();
		}
	}
	else if (object == portal3) {
		askroomgame();
	}

	//���簳�� ���ϱ�
	if (object == answer1) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 4;
		if (percent < 2) {
			hideObject(answer1);
			hideObject(answer2);
			hideObject(answer3);
			hideObject(answer4);
			showMessage("ũ. . . ũ������! ������̶��? �ܼ������� �׷����ϱ�. . . ���� �����!  �������� ����!");
			showObject(portal4);
		}
		else {
			gameover();
		}
	}
	else if (object == answer2) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 4;
		if (percent < 2) {
			hideObject(answer1);
			hideObject(answer2);
			hideObject(answer3);
			hideObject(answer4);
			showMessage("ũ. . . ũ������! ���� �䳢���? ��ġ�ֱ���. . .���� �����!  �������� ����!");
			showObject(portal4);
		}
		else {
			gameover();
		}
	}
	else if (object == answer3) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 4;
		if (percent < 2) {
			hideObject(answer1);
			hideObject(answer2);
			hideObject(answer3);
			hideObject(answer4);
			showMessage("ũ. . . ũ������! �ٴ� �䳢���? �װ� ���� ���ߴµ�. . . ���� �����!  �������� ����!");
			showObject(portal4);
		}
		else {
			gameover();
		}
	}
	else if (object == answer4) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 4;
		if (percent < 2) {
			hideObject(answer1);
			hideObject(answer2);
			hideObject(answer3);
			hideObject(answer4);
			showMessage("ũ. . . ũ������! ��Į�� �䳢���? �̳༮ Ʋ������ �̰�����. . . ���� �����!  �������� ����!");
			showObject(portal4);
		}
		else {
			gameover();
		}
	}
	else if (object == portal4) {
		victorygame();
	}

	
}

int main()
{
	setMouseCallback(mouseCallback);

	dungeon = createScene("������ ���", "images/dungeon.jpg");
	death = createScene("GAME OVER", "images/death.jpg");
	room = createScene("��¥ ���� �����ϱ�?", "images/room.jpg");
	fall = createScene("���� �ǳ���", "images/fall.jpg");
	askroom = createScene("���������� ��", "images/askroom.jpg");
	victory = createScene("����", "images/victory.jpg");

	demon = createObject("images/demon.png");
	locateObject(demon, dungeon, 300, 200);
	showObject(demon);
	portal1 = createObject("images/portal.png");
	locateObject(portal1, dungeon, 800, 220);
	showObject(portal1);

	showMessage("����Գ�... �츮�� �λ��� ��ư��� ���� ������ ��θ� ��������.....  �츮�� �ּ�å�� �����ؾ� �ϰ�...  �� ���ÿ��� ���� ����� ����....  �� �÷��� ����ϸ鼭 ���� ����� ������ ������ ������ ��Ż�� ��....");

	startGame(dungeon);

}