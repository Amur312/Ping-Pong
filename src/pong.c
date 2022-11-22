include <stdio.h>

int width = 80, height = 25;  // Ширина  Высота
char press;
int vec_ball_x = 1;
int vec_ball_y = 1;
int win = 21;
int pos_ball_x = 40;  // переменная хранит координату мяча по горизонтали
int pos_ball_y = 13;  // переменная хранит координату мяча по вертикали
int position_player_1 = 13;  // переменная хранит координату центра ракетки
                             // игрока 1 по вертикали
int position_player_2 = 13;  // переменная хранит координату центра ракетки
                             // игрока 2 по вертикал

int rock_h = 3;
int player1 = 0;
int player2 = 0;
int rocket_controls();
void pole();
int ball_controls();

int main() {
  while (press != 'e') {
    pole();
    rocket_controls();
    ball_controls();
    if (player1 == win) {
      printf("Победил первый игрок\n");
      break;
    } else if (player2 == win) {
      printf("Победил второй игрок\n");
      break;
    }

    printf("\e[H\e[2J\e[3J");
  }
  return 0;
}

void pole() {
  int rock_x = width / 5;
  int rock_y = (height - rock_h) / 2;

  // int position_player_1 = 13;
  // int position_player_2 = 13;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
        printf("#");  // Вывод сторон
      } else if (j == pos_ball_x && i == pos_ball_y) {
        printf("O");  // Вывод мяча
      } else if (j == 1 && i == position_player_1 - 1) {
        printf("|");  // вывод левой ракетки
      } else if (j == 1 && i == position_player_1) {
        printf("|");  // вывод левой ракетки
      } else if (j == 1 && i == position_player_1 + 1) {
        printf("|");  // вывод левой ракетки
      } else if (j == 78 && i == position_player_2 - 1) {
        printf("|");  // вывод правой ракетки
      } else if (j == 78 && i == position_player_2) {
        printf("|");  // вывод правой ракетки
      } else if (j == 78 && i == position_player_2 + 1) {
        printf("|");  // вывод правой ракетки
      } else if (j == 38 || j == 39) {
        printf("|");  //  Вывод стен посред
      } else {
        printf(" ");
      }
    }

    printf("\n");
  }
  for (int i = 0; i < 38; i++) {  // Табло счета
    printf(" ");
    if (i == 35) {
      printf("%d :: %d\n", player1, player2);
    }
  }
}

int rocket_controls() {
  press = getchar();
  if (press == 'a' || press == ' ' || press == 'z' || press == 'k' ||
      press == 'm' || press == 'A' || press == 'Z' || press == 'K' ||
      press == 'M') {
    if (press == 'a') {
      if (position_player_1 != 2)
        position_player_1--;
    } else if (press == 'z') {
      if (position_player_1 != height - 3)
        position_player_1++;
    } else if (press == 'k') {
      if (position_player_2 != 2)
        position_player_2--;
    } else if (press == 'm') {
      if (position_player_2 != height - 3)
        position_player_2++;
    }

    return 0;
  }
}

int ball_controls() {
  // int position_ball_x = 2;
  // int position_ball_y = 13;\
  //  position_player_1

  if (pos_ball_y == 1 || pos_ball_y == height - 2) {
    vec_ball_y = -vec_ball_y;
  } else if (pos_ball_x == 77 &&
             (pos_ball_y == position_player_2 - 1 ||
              pos_ball_y == position_player_2 ||
              pos_ball_y == position_player_2 + 1)) {  // Отскок от левой
    vec_ball_x = -vec_ball_x;
  } else if (pos_ball_x == 1 &&
             (pos_ball_y == position_player_1 - 1 ||
              pos_ball_y == position_player_1 ||
              pos_ball_y == position_player_1 + 1)) {  // Отскок от правой
    vec_ball_x = -vec_ball_x;
  }

  pos_ball_x += vec_ball_x;  // смещение по оси Х\У
  pos_ball_y += vec_ball_y;
  if (pos_ball_x < 1) {  // если положение мяча по Х меньше 1 , то засчитываются
                         // очки второму игроку
    player2 += 1;
    pos_ball_x = 40;  // возвращает начальное положение мяча по центру
    pos_ball_y = 13;
  }
  if (pos_ball_x >
      width - 2) {  // при вылете мяча, засчитываются очки первому игроку
    player1 += 1;
    pos_ball_x = 40;  // возвращает начальное положение мяча по центру
    pos_ball_y = 13;
  }

  return 0;
}

