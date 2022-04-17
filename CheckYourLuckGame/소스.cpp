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
	
	showMessage("실패해도 괜찮아. . . 기회는 얼마든지 주지. . . .");

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

	showMessage("이 방에는 문이 두개가 있지. . . 하나를 선택해라. . . . 잘 선택한다면 다음 시련으로 향하는 길이 열리지만. . . .  그렇지 못하면  죽음이 기다릴 뿐이다. . . . ");
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
	showMessage("여기 널빤지 3개가 있지. . 두개는 썩어 있고 하나는 튼튼해. . 하나를 골라서 넘어와 봐 크킄");

}

void askroomgame()
{
	enterScene(askroom);
	hideObject(portal4);
	showMessage("이번 단계는 수수께끼다. . .너에게 질문을 하나 하지. . 내가 만족할 만한 대답을 하는게 좋을 거야 흐흐\n산토끼의 반대말은 무엇이지? ? ?");
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
	showMessage("이 시련을 모두 극복한 것인가? 놀랍군. . . 행운은 준비와 기회를 만났을 때 비로소 나타난다는 것을 명심하고 계속 도전해서 원하는 것을 얻어내라. . . 여기까지 오느라 수고했다..");
	locateObject(end1, victory, 700, 450);
	locateObject(demon, victory, 100, 100);
	youwin = createObject("images/youwin.png");
	locateObject(youwin, victory, 500, 570);
	showObject(youwin);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action)
{
	//포탈
	if (object == portal1) {
		roomgame();
	}

	//게임오버 장면
	if (object == restart) {
		roomgame();
	}
	if (object == end1) {
		endGame();
	}

	// 문 선택
	if (object == door1) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 2;
		if (percent < 1) {
			hideObject(door1);
			hideObject(door2);
			locateObject(portal2, room, 280, 180);
			showObject(portal2);
			showMessage("호오. . . 좀 하는구만. . . . .");
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
			showMessage("호오. . . 좀 하는구만. . . . .");
		}
		else {
			gameover();
		}
	}
	else if (object == portal2) {
		fallgame();
	}

	// 판자 선택
	if (object == plank1) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 3;
		if (percent < 1) {
			hideObject(plank1);
			hideObject(plank2);
			hideObject(plank3);
			showObject(portal3);
			showMessage("튼튼한 판자를 찾았군! ! ! 다른 판자는 건드리지 말고 넘어 오라고~ ~");
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
			showMessage("튼튼한 판자를 찾았군! ! ! 다른 판자는 건드리지 말고 넘어 오라고~ ~");
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
			showMessage("튼튼한 판자를 찾았군! ! ! 다른 판자는 건드리지 말고 넘어 오라고~ ~");
		}
		else {
			gameover();
		}
	}
	else if (object == portal3) {
		askroomgame();
	}

	//아재개그 답하기
	if (object == answer1) {
		srand((unsigned int)time(NULL));
		int percent = rand() % 4;
		if (percent < 2) {
			hideObject(answer1);
			hideObject(answer2);
			hideObject(answer3);
			hideObject(answer4);
			showMessage("크. . . 크하하하! 끼토산이라고? 단순하지만 그럴듯하군. . . 맘에 들었어!  지나가도 좋아!");
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
			showMessage("크. . . 크하하하! 죽은 토끼라고? 재치있구만. . .맘에 들었어!  지나가도 좋아!");
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
			showMessage("크. . . 크하하하! 바다 토끼라고? 그건 생각 못했는데. . . 맘에 들었어!  지나가도 좋아!");
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
			showMessage("크. . . 크하하하! 알칼리 토끼라고? 이녀석 틀림없이 이과구만. . . 맘에 들었어!  지나가도 좋아!");
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

	dungeon = createScene("선택의 기로", "images/dungeon.jpg");
	death = createScene("GAME OVER", "images/death.jpg");
	room = createScene("진짜 문은 무엇일까?", "images/room.jpg");
	fall = createScene("강을 건너자", "images/fall.jpg");
	askroom = createScene("수수께끼의 방", "images/askroom.jpg");
	victory = createScene("성공", "images/victory.jpg");

	demon = createObject("images/demon.png");
	locateObject(demon, dungeon, 300, 200);
	showObject(demon);
	portal1 = createObject("images/portal.png");
	locateObject(portal1, dungeon, 800, 220);
	showObject(portal1);

	showMessage("어서오게나... 우리는 인생을 살아가며 많은 선택의 기로를 마주하지.....  우리는 최선책을 선택해야 하고...  그 선택에는 운이 따라야 하지....  이 시련을 통과하면서 너의 행운을 시험해 보려면 오른쪽 포탈로 들어가....");

	startGame(dungeon);

}